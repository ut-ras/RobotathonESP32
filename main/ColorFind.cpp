#include "Routine.h"
#include "ColorSensor.h"
#include "Drivetrain.h"

class ColorFind : public Routine{
    ColorSensor* colorSensor;
    Drivetrain* drivetrain;

    public:
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0;

    ColorFind(ColorSensor* colorSensor, Drivetrain* drivetrain){
        this->colorSensor = colorSensor;
        this->drivetrain = drivetrain;

        std::array<int,4> colors = colorSensor->getColors();
        r = colors[0];
        g = colors[1];
        b = colors[2];
        a = colors[3];
    }

    void update(){
        std::array<int,4> colors = colorSensor->getColors();
        int rVal = std::abs(r - colors[0]);
        int gVal = std::abs(g - colors[1]);   
        int bVal = std::abs(b - colors[2]);
        int aVal = std::abs(a - colors[3]);

        if(rVal < 25 && gVal < 25 && bVal < 25 && aVal < 25){
            drivetrain->setSpeed(0, 0);
        }
        else{
            drivetrain->setSpeed(255, 255);
        }
    }
};