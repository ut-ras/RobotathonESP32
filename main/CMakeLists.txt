set(srcs
        "main.c"
        "arduino_main.cpp"
        "helper/color_challenge.cpp"
        "helper/line_challenge.cpp"
        "helper/IR_challenge.cpp"
        "helper/motors.cpp"
)

set(requires "bluepad32" "bluepad32_arduino" "arduino" "btstack" "callbacks")

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS "."
                    REQUIRES "${requires}")
