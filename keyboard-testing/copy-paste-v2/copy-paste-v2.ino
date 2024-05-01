#include <Keyboard.h>

// Version

void setup(){
  // In the setup i am defining the pinModes (INPUt_PULLUP so i dont need to worry about a short circut when the button is closed). 
  // The functions (void copy and paste) are defined on the same layer as the setup. Otherwise it wouldn´t work
  // When the functions are called it can happen that they are executed multiple times due to the FALLING Event (FALLING ADGE and RISING EDGE is the expression for the change between the states HIGH and LOW in the current) being triggered multiple times from the Hardware (Idk if there is a solution for that i will research that).
  // I am also creating a variable with the type char. the variable stores the name of the Control Key. The variable is the type char (character) because the function Keyboard.press(); only takes char values.

  // I am also declaring two output Pins so i can make a light flash when copy or paste is pressed (Yellow light for copy, blue for paste). For the physical construction i used 220ohm Resistors

  // pin Declaration
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Starting the Keyboard Library
  Keyboard.begin();

  // Attaching Interrupts
  attachInterrupt(digitalPinToInterrupt(2), copy, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), paste, FALLING);
}

void loop(){


}

void copy(){
  // At first i use Keyboard.press(); to press the control key and c key. Then it copies the marked content to the clipboard. After that i release all pressed keys with Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("c"); // I used print because press doesn´t work.
  Keyboard.releaseAll();
  digitalWrite(9, HIGH); // Turning on the light
  delay(1000);// Delay so you can see the light flash
  digitalWrite(9,LOW); // Turning off the light
}

void paste(){
  // At first i use Keyboard.press(); to press the control key and v key. Then it copies the marked content to the clipboard. After that i release all pressed keys with Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("v"); // I used print because press doesn´t work.
  Keyboard.releaseAll();
  digitalWrite(10, HIGH); // Turning on the light
  delay(1000);// Delay so you can see the light flash
  digitalWrite(10,LOW); // Turning off the light
}

/*
This is the text to copy!
Copy:
This is the text to copy!
This is the text to copy!
This is the text to copy!
This is the text to copy!
This is the text to copy!


*/


// Julius Ball
// 12.06.2023
// Effort: ~15min