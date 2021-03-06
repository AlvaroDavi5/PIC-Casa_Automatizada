#include "Arduino.h"
#include "GarageControllerMillis.h"

#define START_POSITION 0

GarageControllerMillis::GarageControllerMillis(int servoPin, int servoSpeed, int servoMaxAngle, int ledPin, int mindDistance) {
  pinMode(servoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  _servoPin = servoPin;
  _servoSpeed = servoSpeed;
  _servoMaxAngle = servoMaxAngle;
  _ledPin = ledPin;
  _mindDistance = mindDistance;
}

void GarageControllerMillis::openGarage() {
  _servo.slowmove(_servoMaxAngle, _servoSpeed);
}

void GarageControllerMillis::closeGarage() {
  _servo.slowmove(START_POSITION, _servoSpeed);
}

void GarageControllerMillis::turnOnLed() {
  digitalWrite(_ledPin, HIGH);
}

void GarageControllerMillis::turnOffLed() {
  digitalWrite(_ledPin, LOW);
}

void GarageControllerMillis::attachServo() {
  _servo.attach(_servoPin);
}

void GarageControllerMillis::initServo() {
  _servo.write(START_POSITION);
}

bool GarageControllerMillis::isCarNear(int distance) {
  return (distance < _mindDistance);
}
