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
        std::array<uint16_t,8> sensors = lineSensor->getValues();

        if(sensors[3] > 750 && sensors[4] > 750){
            drivetrain->setSpeed(180, 180);
            lastValue = 0;
        }
        else if(sensors[0] > 750 || sensors[1] > 750 || sensors[2] > 750){
            drivetrain->setSpeed(-180, 180);
            lastValue = 1;
        }
        else if(sensors[5] > 750 || sensors[6] > 750 || sensors[7] > 750){
            drivetrain->setSpeed(180, -180);
            lastValue = 2;
        }
        else{
            if(lastValue == 1){
                drivetrain->setSpeed(-180, 180);
            }
            else{
                drivetrain->setSpeed(180, -180);
            }
        }
    }
};