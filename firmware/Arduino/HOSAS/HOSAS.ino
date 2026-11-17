// 
// https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>

#define BUTTON_PIN_1 4
#define BUTTON_PIN_2 5
#define BUTTON_PIN_3 6
#define BUTTON_PIN_4 7
#define BUTTON_PIN_5 8
#define X_PIN A0
#define Y_PIN A1
#define RX_PIN A10
#define RY_PIN A9

Joystick_ Joystick(
  0x04,                  // Report ID
  JOYSTICK_TYPE_JOYSTICK,
  17,                    // Buttons count
  0,                     // Hatswitch count
  true,                  // X enabled
  true,                  // Y enabled
  false,                 // Z enabled
  true,                  // Rx enabled
  true,                  // Ry enabled
  false,                 // Rz enabled
  false,                 // Rudder enabled
  false,                  // Throttle enabled
  false,                 // Accelerator enabled
  false                  // Brake enabled
);

void setup() {
  delay(5000);

  Joystick.setXAxisRange(0, JOYSTICK_DEFAULT_AXIS_MAXIMUM);
  Joystick.setYAxisRange(0, JOYSTICK_DEFAULT_AXIS_MAXIMUM);
  Joystick.setRxAxisRange(0, JOYSTICK_DEFAULT_AXIS_MAXIMUM);
  Joystick.setRyAxisRange(0, JOYSTICK_DEFAULT_AXIS_MAXIMUM);

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  pinMode(BUTTON_PIN_5, INPUT_PULLUP);

  Joystick.begin();
}

void loop() {
  int xAxisValue = analogRead(X_PIN);
  int yAxisValue = analogRead(Y_PIN);
  int rxAxisValue = analogRead(RX_PIN);
  int ryAxisValue = analogRead(RY_PIN);

  int button1State = !digitalRead(BUTTON_PIN_1);
  int button2State = !digitalRead(BUTTON_PIN_2);
  int button3State = !digitalRead(BUTTON_PIN_3);
  int button4State = !digitalRead(BUTTON_PIN_4);
  int button5State = !digitalRead(BUTTON_PIN_5);

  Joystick.setXAxis(xAxisValue);
  Joystick.setYAxis(yAxisValue);
  Joystick.setRxAxis(invertAnalog(rxAxisValue));
  Joystick.setRyAxis(invertAnalog(ryAxisValue));

  Joystick.setButton(12, button1State);
  Joystick.setButton(13, button2State);
  Joystick.setButton(14, button3State);
  Joystick.setButton(15, button4State);
  Joystick.setButton(16, button5State);

  delay(10);
}

int invertAnalog(int value) {
  return JOYSTICK_DEFAULT_AXIS_MAXIMUM - value;
}
