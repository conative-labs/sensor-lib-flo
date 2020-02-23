![Jenkins](https://img.shields.io/jenkins/build?jobUrl=https%3A%2F%2Fbuild.conativelabs.com%2Fjob%2Fsensor-lib-flo%2Fjob%2Fmaster&style=plastic)
![Jenkins Coverage](https://img.shields.io/jenkins/coverage/cobertura?jobUrl=https%3A%2F%2Fbuild.conativelabs.com%2Fjob%2Fsensor-lib-flo%2Fjob%2Fmaster%2F&style=plastic)
# Flow Sensor library
This library is made to manage and calculate the liquid flow sensor.

# How it works!
The flow rate is calculated by counting the pulses of the rotating body, and using the formula and geometry factor to deduce the rate of flow.

The `lib_flo_cmd` is used to recieve cmds from the *parser or any caller library* and return the required output, To read sensor data, use `flo_read` command, you can use calibrate cmds `flo_cal_factor` to calibrate the sensor at runtime and use `flo_cal_clear` to restore the default calibration, also you can get the calibration status using `flo_cal_get` it should return `1` if all calibrated, lastly `flo_reset` resets all the device params back to default.

Notice: `MAGIC_NUMBER_DEFAULT` is used for data integrity check.

# How to use!
Copy lib_flo_config.template.h to lib_flo_config.h and implement the required functions, use INTERRUPT to increment the `pulses_counter` on each interupt from the sensor.

License
----

GNU General Public License v3.0

***Copyright (C) 2020 Conative Labs***
