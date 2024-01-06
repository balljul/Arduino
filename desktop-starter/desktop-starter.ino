#include <Keyboard.h>

const int safetyPin = 4;

void setup() 
{
    pinMode(safetyPin, INPUT);
    Keyboard.begin();
    Serial.begin(9600);
}

void loop() 
{
    if(digitalRead(safetyPin) == LOW) {
        Serial.println("Executing main logic");
    }
    else {
        Serial.println("Doing nothing");
    }

    delay(1000);
}

void navigate_to_desktop(char desktop_num) 
{
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(desktop_num);
    Keyboard.releaseAll();
    //Serial.println("Switched to a desktop");
}

void open_terminal()
{
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('\n');
    //Serial.println("Opened Terminal");
}
