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

        if(sensors[3] > 750 || sensors[4] > 750){
            drivetrain->setSpeed(210, 210);
            lastValue = 0;
        }
        else{
            int left = 0;
            int right = 0;
            if(sensors[0] > 750){
                left++;
            }
            if(sensors[1] > 750){
                left++;
            }
            if(sensors[2] > 750){
                left++;
            }
            if(sensors[5] > 750){
                right++;
            }
            if(sensors[6] > 750){
                right++;
            }
            if(sensors[7] > 750){
                right++;
            }
            if(left > right){
                drivetrain->setSpeed(-210, 210);
                lastValue = 1;
            }
            else if(right > left){
                drivetrain->setSpeed(210, -210);
                lastValue = 2;
            }
            else{
                if(lastValue == 1){
                    drivetrain->setSpeed(-210, 210);
                }
                else{
                    drivetrain->setSpeed(210, -210);
                }
            }
        }
        
    }
};