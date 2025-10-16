set(srcs
        "main.c"
        "RobotController.cpp"
)

set(requires "bluepad32" "bluepad32_arduino" "arduino" "btstack" "callbacks")

idf_component_register(SRCS "Drivetrain.cpp" "RobotController.cpp" "ColorSensor.cpp" "${srcs}"
                    INCLUDE_DIRS "."
                    REQUIRES "${requires}")
