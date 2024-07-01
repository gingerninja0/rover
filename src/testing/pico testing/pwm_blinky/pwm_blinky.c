/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Output PWM signals on pins 0 and 1

#include "pico/stdlib.h"
#include "hardware/pwm.h"


int main() {
    /// \tag::setup_pwm[]

    // Tell GPIO 0 and 1 they are allocated to the PWM
    gpio_set_function(25, GPIO_FUNC_PWM);

    // Find out which PWM slice is connected to GPIO 0 (it's slice 0)
    uint slice_num = pwm_gpio_to_slice_num(25);

    // Set period of 4 cycles (0 to 3 inclusive)
    pwm_set_wrap(slice_num, 15);

    // Set initial B output high for three cycles before dropping
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 0);
    // Set the PWM running
    pwm_set_enabled(slice_num, true);
    /// \end::setup_pwm[]

    while(true)
    {
        for(int i = 0; i < 15; i++)
        {
            pwm_set_chan_level(slice_num, PWM_CHAN_B, i);
            sleep_ms(100);
        }

        for(int i = 15; i > 0; i--)
        {
            pwm_set_chan_level(slice_num, PWM_CHAN_B, i);
            sleep_ms(50);
        }
    }


    // Note we could also use pwm_set_gpio_level(gpio, x) which looks up the
    // correct slice and channel for a given GPIO.
}
