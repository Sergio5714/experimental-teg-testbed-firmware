# Experimental TEG (thermoelectric generator) testbed firmware
**Author: Sergei Vostrikov**


This repository contains embedded software and the PCBs for the experimental testbed.

**The main function of the testbed:**
* Imitate heat exchange, thermoelectric and electric proceses 
in the wearable thermoelectric generator.

**Testbed's subsystems enable:**
* Low speed (>= _5 Hz_) temperature measurements with an accuracy better than _0.15°K_;
* Temperature difference stabilization (temperature swing <=_12°K_, stabilization error <= _0.1°K_);
* Two channels ADC measurements (accuracy >= _1 mv_) in a range of approximately _0 - 100 mV_;
* Real time [data visialization](https://github.com/Sergio5714/experimental-teg-testbed-gui).

**Used technologies/tools:** C, Keil uVision, STM32F4, FreeRTOS, Jupyter, KiCAD, Peltier modules.

Detailed description can be found in the 
[pdf manual](https://github.com/Sergio5714/experimental-teg-testbed-firmware/blob/master/docs/Description_experimental_teg_testbed.pdf).

**The main PCB:**

![alt text](https://github.com/Sergio5714/experimental-teg-testbed-firmware/blob/master/images/control_board_photo.jpg)

**The temperature sensor PCB:**

![alt text](https://github.com/Sergio5714/experimental-teg-testbed-firmware/blob/master/images/temp_sensor_photo.jpg)

**The testbed simplified schematic:**

![alt text](https://github.com/Sergio5714/experimental-teg-testbed-firmware/blob/master/images/Scheme.png)
