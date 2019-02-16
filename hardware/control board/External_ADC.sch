EESchema Schematic File Version 2
LIBS:Control_board_library
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:w_connectors
LIBS:Control board-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title "External SPI ADC"
Date "2018-07-05"
Rev "1.0"
Comp "Skoltech"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L AD7705 U4
U 1 1 5B1ABFED
P 5300 3450
F 0 "U4" H 5750 3500 60  0000 C CNN
F 1 "AD7705" H 5750 3600 60  0000 C CNN
F 2 "Control_board_footprints:SOICW-16" H 5300 3450 60  0001 C CNN
F 3 "" H 5300 3450 60  0001 C CNN
	1    5300 3450
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5B1AE0EB
P 3050 3450
F 0 "C10" H 3075 3550 50  0000 L CNN
F 1 "30pF" H 3075 3350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3088 3300 50  0001 C CNN
F 3 "" H 3050 3450 50  0001 C CNN
	1    3050 3450
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 5B1AE18B
P 3400 3450
F 0 "C11" H 3425 3550 50  0000 L CNN
F 1 "30pF" H 3425 3350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3438 3300 50  0001 C CNN
F 3 "" H 3400 3450 50  0001 C CNN
	1    3400 3450
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5B1AE1B7
P 3400 3050
F 0 "Y1" V 3400 2900 50  0000 C CNN
F 1 "Crystal" V 3150 3050 50  0000 C CNN
F 2 "Control_board_footprints:Crystal_HC49-S" H 3400 3050 50  0001 C CNN
F 3 "" H 3400 3050 50  0001 C CNN
	1    3400 3050
	0    1    1    0   
$EndComp
Text Label 2650 3600 0    60   ~ 0
GND
Text Label 6600 3500 2    60   ~ 0
GND
Text Label 6600 4100 2    60   ~ 0
GND
Text HLabel 4750 3500 0    60   Output ~ 0
SCLK
Text HLabel 6600 3700 2    60   Output ~ 0
MOSI
Text HLabel 6600 3800 2    60   Input ~ 0
MISO
Text Label 6600 3600 2    60   ~ 0
VDD
Text HLabel 3450 3800 0    60   Output ~ 0
~CS
$Comp
L R R27
U 1 1 5B1AE825
P 3700 3950
F 0 "R27" H 3550 3950 50  0000 C CNN
F 1 "1k" V 3700 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3630 3950 50  0001 C CNN
F 3 "" H 3700 3950 50  0001 C CNN
	1    3700 3950
	1    0    0    -1  
$EndComp
Text Label 3400 4100 0    60   ~ 0
GND
Text HLabel 6600 3900 2    60   Input ~ 0
~DRDY
$Comp
L ADR441 U5
U 1 1 5B1AF1E1
P 8500 4450
F 0 "U5" H 8700 4000 60  0000 C CNN
F 1 "ADR441" H 8700 3900 60  0000 C CNN
F 2 "Control_board_footprints:SOICN-8" H 8500 4450 60  0001 C CNN
F 3 "" H 8500 4450 60  0001 C CNN
	1    8500 4450
	-1   0    0    1   
$EndComp
$Comp
L C C12
U 1 1 5B1AF392
P 7250 4500
F 0 "C12" H 7275 4600 50  0000 L CNN
F 1 "0.1μF" H 7275 4400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7288 4350 50  0001 C CNN
F 3 "" H 7250 4500 50  0001 C CNN
	1    7250 4500
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 5B1AF56F
P 9000 4450
F 0 "C13" H 9025 4550 50  0000 L CNN
F 1 "0.1μF" H 9025 4350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9038 4300 50  0001 C CNN
F 3 "" H 9000 4450 50  0001 C CNN
	1    9000 4450
	1    0    0    -1  
$EndComp
Text Label 9300 4300 2    60   ~ 0
VDD
Text Label 7500 4750 2    60   ~ 0
GND
Text Label 9000 4100 2    60   ~ 0
GND
Text Label 9250 4700 2    60   ~ 0
GND
$Comp
L TEST_1P J4
U 1 1 5B1AF92B
P 7850 4650
F 0 "J4" H 7850 4920 50  0000 C CNN
F 1 "TEST_1P" H 7850 4850 50  0000 C CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 8050 4650 50  0001 C CNN
F 3 "" H 8050 4650 50  0001 C CNN
	1    7850 4650
	-1   0    0    1   
$EndComp
$Comp
L TEST_1P J5
U 1 1 5B1AF9AA
P 8700 4650
F 0 "J5" H 8700 4920 50  0000 C CNN
F 1 "TEST_1P" H 8700 4850 50  0000 C CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 8900 4650 50  0001 C CNN
F 3 "" H 8900 4650 50  0001 C CNN
	1    8700 4650
	-1   0    0    1   
$EndComp
Text HLabel 4500 3900 0    60   Input ~ 0
~RESET_ADC
$Comp
L R R28
U 1 1 5B1B0285
P 4600 4050
F 0 "R28" H 4450 4050 50  0000 C CNN
F 1 "1k" V 4600 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4530 4050 50  0001 C CNN
F 3 "" H 4600 4050 50  0001 C CNN
	1    4600 4050
	1    0    0    -1  
$EndComp
Text Label 4300 4200 0    60   ~ 0
GND
$Comp
L TEST_1P J3
U 1 1 5B1BC6AB
P 7600 5000
F 0 "J3" H 7600 5270 50  0000 C CNN
F 1 "TEST_1P" H 7600 5200 50  0000 C CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 7800 5000 50  0001 C CNN
F 3 "" H 7800 5000 50  0001 C CNN
	1    7600 5000
	-1   0    0    1   
$EndComp
$Comp
L GNDA #PWR047
U 1 1 5B1BC878
P 3250 4800
F 0 "#PWR047" H 3250 4550 50  0001 C CNN
F 1 "GNDA" H 3250 4650 50  0000 C CNN
F 2 "" H 3250 4800 50  0001 C CNN
F 3 "" H 3250 4800 50  0001 C CNN
	1    3250 4800
	1    0    0    -1  
$EndComp
Text Label 2900 4700 0    60   ~ 0
GND
Text Label 3650 5000 0    60   ~ 0
VDD
$Comp
L +3.3V #PWR048
U 1 1 5B3266A4
P 4000 4750
F 0 "#PWR048" H 4000 4600 50  0001 C CNN
F 1 "+3.3V" H 4000 4890 50  0000 C CNN
F 2 "" H 4000 4750 50  0001 C CNN
F 3 "" H 4000 4750 50  0001 C CNN
	1    4000 4750
	1    0    0    -1  
$EndComp
$Comp
L CWF-2 P19
U 1 1 5B326947
P 6800 5100
F 0 "P19" H 6900 5150 60  0000 C CNN
F 1 "CWF-2" H 6850 5250 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 6800 5100 60  0001 C CNN
F 3 "" H 6800 5100 60  0001 C CNN
	1    6800 5100
	1    0    0    -1  
$EndComp
$Comp
L CWF-2 P18
U 1 1 5B32698D
P 5450 5100
F 0 "P18" H 5550 5150 60  0000 C CNN
F 1 "CWF-2" H 5500 5250 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 5450 5100 60  0001 C CNN
F 3 "" H 5450 5100 60  0001 C CNN
	1    5450 5100
	1    0    0    -1  
$EndComp
$Comp
L POT RV4
U 1 1 5B326CD3
P 4750 5150
F 0 "RV4" H 4500 5150 50  0000 C CNN
F 1 "10 " V 4650 5150 50  0000 C CNN
F 2 "Control_board_footprints:Potentiometer_Trimmer_Bourns_3266W" H 4750 5150 50  0001 C CNN
F 3 "" H 4750 5150 50  0001 C CNN
	1    4750 5150
	1    0    0    -1  
$EndComp
$Comp
L POT RV5
U 1 1 5B3271D1
P 6150 5150
F 0 "RV5" H 5900 5150 50  0000 C CNN
F 1 "10" V 6050 5150 50  0000 C CNN
F 2 "Control_board_footprints:Potentiometer_Trimmer_Bourns_3266W" H 6150 5150 50  0001 C CNN
F 3 "" H 6150 5150 50  0001 C CNN
	1    6150 5150
	1    0    0    -1  
$EndComp
NoConn ~ 6150 5300
NoConn ~ 4750 5300
$Comp
L TEST_1P J2
U 1 1 5B32A9D8
P 6900 4400
F 0 "J2" H 6900 4670 50  0000 C CNN
F 1 "TEST_1P" H 6900 4600 50  0000 C CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm" H 7100 4400 50  0001 C CNN
F 3 "" H 7100 4400 50  0001 C CNN
	1    6900 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	5100 3600 4150 3600
Connection ~ 3400 2900
Wire Wire Line
	3400 3200 3400 3300
Wire Wire Line
	3050 2900 3050 3300
Wire Wire Line
	6600 4100 6400 4100
Wire Wire Line
	6600 3500 6400 3500
Wire Wire Line
	5100 3500 4750 3500
Wire Wire Line
	6400 3700 6600 3700
Wire Wire Line
	6400 3800 6600 3800
Wire Wire Line
	6600 3600 6400 3600
Wire Wire Line
	2650 3600 3400 3600
Connection ~ 3050 3600
Wire Wire Line
	3400 4100 3700 4100
Wire Wire Line
	6400 4200 7850 4200
Wire Wire Line
	8700 4300 9300 4300
Connection ~ 9000 4300
Wire Wire Line
	8700 4100 9000 4100
Wire Wire Line
	7250 4650 7250 4750
Wire Wire Line
	7250 4750 7500 4750
Wire Wire Line
	9000 4600 9000 4700
Wire Wire Line
	9000 4700 9250 4700
Wire Wire Line
	8700 4400 8700 4650
Wire Wire Line
	7850 4400 7850 4650
Wire Wire Line
	3050 2900 4150 2900
Wire Wire Line
	4150 2900 4150 3600
Wire Wire Line
	5100 3700 4050 3700
Wire Wire Line
	4050 3700 4050 3200
Wire Wire Line
	4050 3200 3400 3200
Connection ~ 3700 3800
Wire Wire Line
	3450 3800 5100 3800
Wire Wire Line
	5100 3900 4500 3900
Connection ~ 4600 3900
Wire Wire Line
	4300 4200 4600 4200
Wire Wire Line
	5100 4000 4750 4000
Wire Wire Line
	4850 4100 4850 4700
Wire Wire Line
	4850 4100 5100 4100
Wire Wire Line
	5100 4200 4950 4200
Wire Wire Line
	4950 4200 4950 4600
Wire Wire Line
	4950 4600 6400 4600
Wire Wire Line
	2900 4700 3250 4700
Wire Wire Line
	3250 4700 3250 4800
Wire Wire Line
	3650 5000 4000 5000
Wire Wire Line
	4000 5000 4000 4750
Wire Wire Line
	6400 3900 6600 3900
Wire Wire Line
	7600 5000 7600 4100
Wire Wire Line
	7600 4100 7850 4100
Connection ~ 7250 4200
Wire Wire Line
	6400 4000 6700 4000
Wire Wire Line
	6700 4000 6700 4400
Connection ~ 5100 5150
Wire Wire Line
	6300 5150 6600 5150
Wire Wire Line
	7250 4200 7250 4350
Wire Wire Line
	6900 4200 6900 4400
Connection ~ 6900 4200
Connection ~ 6400 5150
Wire Wire Line
	6400 4600 6400 5150
Wire Wire Line
	4850 4700 6150 4700
Wire Wire Line
	6150 4700 6150 5000
Wire Wire Line
	6700 4400 5100 4400
Wire Wire Line
	5100 4400 5100 5150
Wire Wire Line
	4900 5150 5250 5150
Wire Wire Line
	4750 4000 4750 5000
Wire Wire Line
	4750 4900 4400 4900
Wire Wire Line
	4400 4900 4400 5400
Wire Wire Line
	4400 5400 5100 5400
Wire Wire Line
	5100 5400 5100 5250
Wire Wire Line
	5100 5250 5250 5250
Connection ~ 4750 4900
Wire Wire Line
	6150 4900 5800 4900
Wire Wire Line
	5800 4900 5800 5400
Wire Wire Line
	5800 5400 6400 5400
Wire Wire Line
	6400 5400 6400 5250
Wire Wire Line
	6400 5250 6600 5250
Connection ~ 6150 4900
Text Label 4750 4000 0    60   ~ 0
AIN2+
Text Label 5100 4400 0    60   ~ 0
AIN2-
Text Label 4850 4100 0    60   ~ 0
AIN1+
Text Label 6100 4600 0    60   ~ 0
AIN1-
$EndSCHEMATC
