#include <Keyboard.h>

const int safetyPin = 4;
int counter = 0;

void setup() 
{
    pinMode(safetyPin, INPUT);
    Keyboard.begin();
    Serial.begin(9600);
}

void loop() 
{
    if(digitalRead(safetyPin) == LOW) {
        if(counter < 1){
            Serial.println("Executing main logic");
            Keyboard.print("");
            Keyboard.print('\n');
            counter = counter + 1;
        }
        else {
            Serial.println("Already done");
        }
    }
    else {
        Serial.println("Doing nothing");
    }

    delay(1000);
}

void navigate_to_desktop(char desktop_num) 
{
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.print(desktop_num);
    Keyboard.releaseAll();
    delay(20);
}

void open_terminal()
{
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.print('\n');
    Keyboard.releaseAll();
    Keyboard.print("htop");
    Keyboard.print('\n');
    delay(20);
}

void execute(String message)
{
    Keyboard.print(message); 
    Keyboard.print('\n');
    delay(20);
}
