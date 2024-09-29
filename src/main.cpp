/*
  Keyboard logout

  This sketch demonstrates the Keyboard library.

  When you connect pin 2 to ground, it performs a logout.
  It uses keyboard combinations to do this, as follows:

  On Windows, CTRL-ALT-DEL followed by ALT-l
  On Ubuntu, CTRL-ALT-DEL, and ENTER
  On OSX, CMD-SHIFT-q

  To wake: Spacebar.

  Circuit:
  - Arduino Leonardo or Micro
  - wire to connect D2 to ground

  created 6 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  This example is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardLogout
*/
#ifndef ARDUINO_USB_MODE
#error This ESP32 SoC has no Native USB interface
#elif ARDUINO_USB_MODE == 1
#warning This sketch should be used when USB is in OTG mode
void setup() {}
void loop() {}
#else

#define BOUNCE_WITH_PROMPT_DETECTION
#include "Arduino.h"
#include "USB.h"
#include "USBHIDKeyboard.h"
#include "Bounce2.h"
USBHIDKeyboard Keyboard;

Bounce2::Button leftFlipperButton = Bounce2::Button();
Bounce2::Button rightFlipperButton = Bounce2::Button();
Bounce2::Button plungerButton = Bounce2::Button();
Bounce2::Button startButton = Bounce2::Button();

void setup() {
  // make pin 0 an input and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  Keyboard.begin();
  USB.begin();

  Keyboard.setShiftKeyReports(false);

  leftFlipperButton.attach ( 3 , INPUT_PULLUP );
  leftFlipperButton.interval( 5 );
  leftFlipperButton.setPressedState( LOW ); 

  rightFlipperButton.attach ( 4 , INPUT_PULLUP );
  rightFlipperButton.interval( 5 );
  rightFlipperButton.setPressedState( LOW ); 

  plungerButton.attach ( 5 , INPUT_PULLUP );
  plungerButton.interval( 5 );
  plungerButton.setPressedState( LOW ); 

  startButton.attach ( 6 , INPUT_PULLUP );
  startButton.interval( 5 );
  startButton.setPressedState( LOW ); 

}

void loop() {

  leftFlipperButton.update();
  rightFlipperButton.update();
  plungerButton.update();
  startButton.update();

  if ( leftFlipperButton.pressed() ) {
    Keyboard.pressRaw(HID_KEY_SHIFT_LEFT); //Left Flipper
  }
  if (leftFlipperButton.released())
  {
    Keyboard.releaseRaw(HID_KEY_SHIFT_LEFT); //Left Flipper
  }

  if ( rightFlipperButton.pressed() ) {
    Keyboard.pressRaw(HID_KEY_SHIFT_RIGHT); //Right Flipper
  }
  if (rightFlipperButton.released())
  {
    Keyboard.releaseRaw(HID_KEY_SHIFT_RIGHT); //Right Flipper
  }
  if ( plungerButton.pressed() ) {
    Keyboard.press(KEY_RETURN); //Plunger
  }
  if (plungerButton.released())
  {
    Keyboard.release(KEY_RETURN); //Plunger
  }
  if (startButton.pressed() ) {
    Keyboard.press(0x31); //Start game
  }
  if (startButton.released())
  {
    Keyboard.release(0x31); //Start game
  }

}
#endif /* ARDUINO_USB_MODE */

  /*while (digitalRead(buttonPin) == HIGH) {
    // do nothing until pin 2 goes low
    delay(500);
  }
  delay(1000);*/

  /*switch (platform) {
    case OSX:
      Keyboard.press(KEY_LEFT_GUI);
      // Shift-Q logs out:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('Q');
      delay(100);
      Keyboard.releaseAll();
      // enter:
      Keyboard.write(KEY_RETURN);
      break;
    case WINDOWS:
      // CTRL-ALT-DEL:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      delay(100);
      Keyboard.releaseAll();
      // ALT-l:
      delay(2000);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('l');
      Keyboard.releaseAll();
      break;
    case UBUNTU:
      // CTRL-ALT-DEL:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      delay(1000);
      Keyboard.releaseAll();
      // Enter to confirm logout:
      Keyboard.write(KEY_RETURN);
      break;
  }*/

  // do nothing:
  //while (true) {
  //  delay(1000);
    //Keyboard.write(KEY_RETURN); //Plunger

    //Keyboard.write(KEY_LEFT_SHIFT); //Left Flipper

    //Keyboard.write(KEY_RIGHT_SHIFT); //Right Flipper

    //Keyboard.write(KEY_1); //Start game

    //Keyboard.write(KEY_5); //Add Credit

    //Keyboard.write(KEY_SPACE); //Nudge Up

    //Keyboard.write(KEY_Z); //Nudge Left

    //Keyboard.write(KEY_SLASH); //Nudge Right

  //}