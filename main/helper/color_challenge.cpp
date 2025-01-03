#include "challenges.h"

#define APDS9960_INT 2
#define I2C_SDA 21
#define I2C_SCL 22
#define I2C_FREQ 100000

TwoWire I2C_0 = TwoWire(0);
APDS9960 apds = APDS9960(I2C_0, APDS9960_INT);

void colorChallenge(ControllerPtr myController) {
    int r, g, b, a;
    //sets up color sensor
    I2C_0.begin(I2C_SDA, I2C_SCL, I2C_FREQ);
    // apds.setInterruptPin(APDS9960_INT); // do we need this?
    apds.begin();
    while(1) {
        BP32.update();
        // Wait until color is read from the sensor 
        int watchDogAtHome = 0;
        while (!apds.colorAvailable()) { 
            delay(5);
            watchDogAtHome++;
            if(watchDogAtHome > 1000) {
                Console.println("Color sensor broken lmao\n");
                break;
            }
        }
        apds.readColor(r, g, b, a);
        // Read color from sensor
        Console.printf("RED: %d GREEN: %d BLUE: %d AMBIENT: %d\n", r, g, b, a);
        delay(100);
        if(myController->b()) {
            Console.print("button b pressed - exiting to main\n");
            break;
        }
    }
}