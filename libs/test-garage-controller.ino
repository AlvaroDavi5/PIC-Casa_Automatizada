// test sketch for garage controller

#include <GarageController.h>

// garage led
#define LED_PIN 10

// constants for servo
#define SERVO_PIN 8
#define SERVO_SPEED 15
#define SERVO_MAX_ANGLE 60

GarageController controller(SERVO_PIN, SERVO_SPEED, SERVO_MAX_ANGLE, LED_PIN);

void setup() {
  controller.attach();
  controller.init();
}

void loop() {
	controller.turnOnLed();
	controller.openGarage();
	delay(1000);
	controller.closeGarage();
	controller.turnOffLed();
}