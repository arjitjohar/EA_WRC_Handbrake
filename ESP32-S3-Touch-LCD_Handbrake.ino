#include <Arduino.h>
#include "LCD_Test.h"
#include <WiFi.h>

UWORD Imagesize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;
UWORD *BlackImage;

const char* ssid = "WIFI_NAME";  // wifi name goes here
const char* password = "WIFI_PASSWORD"; // wifi password goes here
const char* host = "IP_ADDRESS"; //public ip address goes here
const uint16_t port = 5150; // port used for communcation between microcontroller and pc.
WiFiClient client;

CST816S touch(6, 7, 13, 5);  // sda, scl, rst, irq

bool touchPressed = false;    // Track touch state
bool touchReleased = true;    // Track release state

// Debouncing variables
const unsigned long DEBOUNCE_DELAY = 20;  // Adjust this value as needed
unsigned long lastDebounceTime = 0;
bool lastTouchState = false;
bool debouncedTouchState = false;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    touch.begin();
    
    // PSRAM Initialize
    if (psramInit()) {
        Serial.println("\nPSRAM is correctly initialized");
    } else {
        Serial.println("PSRAM not available");
    }
    
    if ((BlackImage = (UWORD *)ps_malloc(Imagesize)) == NULL) {
        Serial.println("Failed to apply for black memory...");
        exit(0);
    }
    
    if (DEV_Module_Init() != 0) {
        Serial.println("GPIO Init Fail!");
    } else {
        Serial.println("GPIO Init successful!");
    }
    
    LCD_1IN28_Init(HORIZONTAL);
    Paint_NewImage((UBYTE *)BlackImage, LCD_1IN28.WIDTH, LCD_1IN28.HEIGHT, 0, RED);
    Paint_SetScale(65);
    Paint_SetRotate(ROTATE_0);
}

void loop() {
    if (!client.connected()) {
        if (!client.connect(host, port)) {
            Serial.println("Connection to MCEC failed");
            delay(1000);
            return;
        }
        Serial.println("Connected to MCEC server");
    }

    while (client.connected()) {
        bool currentTouchState = touch.available();
        
        // Check if touch state changed
        if (currentTouchState != lastTouchState) {
            lastDebounceTime = millis();
        }
        
        // Only update the debounced state if enough time has passed
        if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
            // If the touch state has been stable for the debounce delay
            if (debouncedTouchState != currentTouchState) {
                debouncedTouchState = currentTouchState;
                
                // Handle the debounced touch state changes
                if (debouncedTouchState) {
                    sendCommand("mouse:mbd");
                    Serial.println("Screen touched");
                } else {
                    sendCommand("mouse:mbu");
                    Serial.println("Screen released");
                }
            }
        }
        
        lastTouchState = currentTouchState;

        if (client.available()) {
            String line = client.readStringUntil('\n');
            Serial.println("Received: " + line);
        }
        delay(10);
    }
}

void sendCommand(const char* command) {
    if (client.connected()) {
        client.println(command);
        Serial.print("Sent command: ");
        Serial.println(command);
    }
}
