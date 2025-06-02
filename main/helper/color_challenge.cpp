#include "challenges.h"

#define APDS9960_INT 2
#define I2C_SDA 21
#define I2C_SCL 22
#define I2C_FREQ 100000
#define AVG_ITERATIONS 5

TwoWire I2C_0 = TwoWire(0);
APDS9960 apds = APDS9960(I2C_0, APDS9960_INT);

enum {
    RED,
    GREEN,
    BLUE
};

int findMaxColor(int r, int g, int b) {
    if (r >= g && r >= b) {
        return RED;
    } else if (g >= r && g >= b) {
        return GREEN;
    } else {
        return BLUE;
    }
}

/*
* average and return which color has largest value
*/
int sampleColor() {
    // Wait until color is read from the sensor 
    int watchDogAtHome = 0;
    int avR = 0;
    int avG = 0;
    int avB = 0;
    int r, g, b, a; // throwaway values
    for(int i = 0; i < AVG_ITERATIONS; i++) {
        while (!apds.colorAvailable()) { 
            delay(5);
            watchDogAtHome++;
            if(watchDogAtHome > 1000) {
                Console.println("Color sensor broken lmao\n");
                needExit = true;
                return -1; // kill task
            }
        }
        watchDogAtHome = 0; // reset for next read

        apds.readColor(r, g, b, a);
        avR += r; 
        avG += g;
        avB += b;
        // Console.printf("RED: %d GREEN: %d BLUE: %d AMBIENT: %d\n", r, g, b, a);
    }

    avR /= AVG_ITERATIONS;
    avG /= AVG_ITERATIONS;
    avB /= AVG_ITERATIONS;
    return findMaxColor(avR, avG, avB);
}

void colorChallenge(ControllerPtr myController) {
    int targetColor = -1;
    int colorData = -1;

    I2C_0.begin(I2C_SDA, I2C_SCL, I2C_FREQ);
    apds.begin();

    targetColor = sampleColor();
    // goStraight();

    colorData = sampleColor();
    Console.printf("Target color: %d\n", targetColor);
    while(colorData == targetColor) { // continuously sample until not on starting color
        checkCancel(myController);
        if(needExit) return;
        colorData = sampleColor(); 
    }
    Console.printf("Searching for color: %d\n", targetColor);
    while(colorData != targetColor) { // continiuously sample while searching for target color
        checkCancel(myController); 
        if(needExit) return;
        colorData = sampleColor();
        if(colorData == targetColor) {
            Console.printf("Color %d Found! Exiting to main\n", targetColor);
            stop();
            return; // exit to main
        }
    }
}