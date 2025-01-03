set(requires "bluepad32" "bluepad32_arduino" "arduino" "btstack")
idf_component_register(SRCS "controller_callbacks.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES ${requires})

