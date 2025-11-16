#include "Drivetrain.h"
#include "DistanceSensor.h"
#include "Routine.h"

class MazeSolver : public Routine {
    public:
    DistanceSensor* distanceSensor;
    Drivetrain* drivetrain;

    MazeSolver(DistanceSensor* distanceSensor, Drivetrain* drivetrain){
        this->distanceSensor = distanceSensor;
        this->drivetrain = drivetrain;
    }

    void update(){
        std::array<int,3> distances = distanceSensor->getValues();

        if(distances[1] > 16){
            drivetrain->setSpeed(210, 210); // Move forward
        }
        else if(distances[0] < 8){
            drivetrain->setSpeed(210, -210); // Turn right
            delay(50);
        }
        else if(distances[2] < 8){
            drivetrain->setSpeed(-210, 210); // Turn left
            delay(50);

        }
        else{
            bool left = distances[0] > distances[2];
            for(int i = 30; i > 0; i--){
                int medium = distanceSensor->getValues()[1];
                if(left){
                    drivetrain->setSpeed(-200, 200); // Turn left
                }
                else{
                    drivetrain->setSpeed(200, -200); // Turn right
                }
                delay(30);
                int newMedium = distanceSensor->getValues()[1];
                if(newMedium > medium){
                    continue;
                }
                else{
                    break;
                }
            }
        }
    }
};