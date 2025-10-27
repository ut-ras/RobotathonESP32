#include "LineSensor.h"
#include "Drivetrain.h"
#include "Routine.h"

class LineFollow : public Routine{
    LineSensor* lineSensor;
    Drivetrain* drivetrain;

    int lastValue;

    public:
    LineFollow(LineSensor* lineSensor, Drivetrain* drivetrain){
        this->lineSensor = lineSensor;
        this->drivetrain = drivetrain;
    }

    void update(){
        analogWrite(2, 255);
        
        uint16_t* value = lineSensor->getValues();

        auto& sensors = *reinterpret_cast<uint16_t(*)[4]>(value);

        if(sensors[1] > 50 || sensors[2] > 50){
            drivetrain->setSpeed(100, 100);
            lastValue = 0;
        }
        else if(sensors[0] > 50){
            drivetrain->setSpeed(-100, 100);
            lastValue = 1;
        }
        else if(sensors[3] > 50){
            drivetrain->setSpeed(100, -100);
            lastValue = 2;
        }
        else{
            if(lastValue == 1){
                drivetrain->setSpeed(-100, 100);
            }
            else{
                drivetrain->setSpeed(100, -100);
            }
        }
    }
};