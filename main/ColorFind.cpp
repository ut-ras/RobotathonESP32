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

        delay(100);

        colors = colorSensor->getColors();
        int rVal = std::abs(r - colors[0]);
        int gVal = std::abs(g - colors[1]);   
        int bVal = std::abs(b - colors[2]);
        int aVal = std::abs(a - colors[3]);

        drivetrain->setSpeed(190, 190);

        delay(1000);

        drivetrain->setSpeed(0, 0);
    }

    void update(){
        std::array<int,4> colors = colorSensor->getColors();
        int rVal = std::abs(r - colors[0]);
        int gVal = std::abs(g - colors[1]);   
        int bVal = std::abs(b - colors[2]);
        int aVal = std::abs(a - colors[3]);

        if(rVal < 200 && gVal < 200 && bVal < 200){
            drivetrain->setSpeed(0, 0);
        }
        else{
            drivetrain->setSpeed(190, 190);
        }
    }
};