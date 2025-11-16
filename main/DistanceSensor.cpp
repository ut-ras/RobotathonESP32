#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int pinLeft, int pinMiddle, int pinRight){
    IRSensorLeft = new ESP32SharpIR(ESP32SharpIR::GP2Y0A21YK0F, pinLeft);
    IRSensorMiddle = new ESP32SharpIR(ESP32SharpIR::GP2Y0A21YK0F, pinMiddle);
    IRSensorRight = new ESP32SharpIR(ESP32SharpIR::GP2Y0A21YK0F, pinRight);
}

std::array<int,3> DistanceSensor::getValues(){
    int distanceLeft = IRSensorLeft->getDistance();
    int distanceMiddle = IRSensorMiddle->getDistance();
    int distanceRight = IRSensorRight->getDistance();

    Serial.printf("Distance Sensor: Left: %d cm, Middle: %d cm, Right: %d cm\n", distanceLeft, distanceMiddle, distanceRight);

    return {distanceLeft, distanceMiddle, distanceRight};
}