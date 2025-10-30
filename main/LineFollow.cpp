#include "LineSensor.h"
#include "Drivetrain.h"
#include "Routine.h"

class LineFollow : public Routine{
    LineSensor* lineSensor;
    Drivetrain* drivetrain;

    int lastValue = 0;

    public:
    LineFollow(LineSensor* lineSensor, Drivetrain* drivetrain){
        this->lineSensor = lineSensor;
        this->drivetrain = drivetrain;
    }

    void update(){
        analogWrite(2, 255);
        
        std::array<uint16_t,4> sensors = lineSensor->getValues();

        if(sensors[1] > 800 || sensors[2] > 800){
            drivetrain->setSpeed(255, 255);
            lastValue = 0;
        }
        else if(sensors[0] > 800){
            drivetrain->setSpeed(-255, 255);
            lastValue = 1;
        }
        else if(sensors[3] > 800){
            drivetrain->setSpeed(255, -255);
            lastValue = 2;
        }
        else{
            if(lastValue == 1){
                drivetrain->setSpeed(-255, 255);
            }
            else{
                drivetrain->setSpeed(255, -255);
            }
        }
    }
};