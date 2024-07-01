add_executable(test
        test.cpp
        )

# pull in common dependencies
target_link_libraries(test pico_stdlib)
target_link_libraries(test hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(test)

# add url via pico_set_program_url
example_auto_set_url(test)
