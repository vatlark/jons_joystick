#include <Keypad.h>
#include <Joystick.h>

// Define the number of buttons, rows, and columns
#define TOTAL_BUTTONS 24
#define TOTAL_ROWS 6 //Red wires
#define TOTAL_COLS 4 //Blue wires

// Define the layout of the buttons on the keypad
byte buttonLayout[TOTAL_ROWS][TOTAL_COLS] = {
  {0, 1, 2, 3},
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14, 15},
  {16, 17, 18, 19},
  {20, 21, 22, 23}
};


// Define the pins connected to the rows and columns of the keypad
byte rowConnections[TOTAL_ROWS] = {10, 11, 12, 13, 14, 15}; // Red wires
byte colConnections[TOTAL_COLS] = {2, 8, 9, 16}; // Blue wires

// Initialize the keypad object with the button layout and pin connections
Keypad keypad = Keypad(makeKeymap(buttonLayout), rowConnections, colConnections, TOTAL_ROWS, TOTAL_COLS);

// Initialize the joystick object with default settings
Joystick_ joystick(JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_JOYSTICK, 32, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);

#include <Joystick.h>  // Assuming you're using a Joystick library
#include <RotaryEncoder.h>  // Assuming you're using a Rotary Encoder library

Joystick joystick; // Create joystick object
RotaryEncoder encoder(pin1, pin2); // Define your pins for the rotary encoder

void setup() {
  // Start the joystick functionality
  joystick.begin();  // Assuming the joystick object has a begin method

  // Initialize the rotary encoder
  encoder.begin();  // If your rotary encoder library has this method

  // Initialize any additional components or settings
  rotary_init();  // Make sure this function is defined elsewhere in your code
}

void loop() {
  // Your main code goes here
}


void loop() {
  // Continuously check the state of all buttons
  checkButtonStates();
}

void checkButtonStates(void) {
  // Check if any keys are pressed on the keypad
  if (keypad.getKeys()) 
  {
    // Iterate through the list of keys
    for (int index = 0; index < LIST_MAX; index++) 
    {
      // Check if the state of the key has changed
      if (keypad.key[index].stateChanged) 
      {
        // Determine the new state of the key and update the joystick button state accordingly
        switch (keypad.key[index].kstate) 
        {
          case PRESSED:
          case HOLD:
            joystick.setButton(keypad.key[index].kchar, 1); // Button is pressed or held
            break;
          case RELEASED:
          case IDLE:
            joystick.setButton(keypad.key[index].kchar, 0); // Button is released or idle
            break;
        }
      }
    }
  }
}

