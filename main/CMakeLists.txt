set(srcs
        "main.c"
        "arduino_main.cpp"
        "color_challenge.cpp"
)

set(requires "bluepad32" "bluepad32_arduino" "arduino" "btstack" "callbacks")

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS "."
                    REQUIRES "${requires}")
