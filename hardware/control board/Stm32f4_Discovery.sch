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
Sheet 5 6
Title "MCU"
Date "2018-07-05"
Rev "1.0"
Comp "Skoltech"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32F4_Discovery_Header J1
U 1 1 5B33FA15
P 6500 3700
F 0 "J1" H 6500 5250 60  0000 C CNN
F 1 "STM32F4_Discovery_Header" H 6500 5100 60  0000 C CNN
F 2 "Control_board_footprints:stm32f4_discovery_header" H 6500 4050 60  0001 C CNN
F 3 "" H 6500 4050 60  0000 C CNN
	1    6500 3700
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR037
U 1 1 5B33FA68
P 5600 2500
F 0 "#PWR037" H 5600 2250 50  0001 C CNN
F 1 "GNDA" H 5600 2350 50  0000 C CNN
F 2 "" H 5600 2500 50  0001 C CNN
F 3 "" H 5600 2500 50  0001 C CNN
	1    5600 2500
	1    0    0    -1  
$EndComp
Text HLabel 5300 2900 0    60   Input ~ 0
PWM_1
Text HLabel 5300 3000 0    60   Input ~ 0
PWM_2
Text HLabel 5300 3300 0    60   Input ~ 0
DAC_1
Text HLabel 5300 3200 0    60   Input ~ 0
DAC_2
Text HLabel 7700 4750 2    60   BiDi ~ 0
SDA
Text HLabel 7700 4650 2    60   Output ~ 0
SCL
$Comp
L R R26
U 1 1 5B33FBA9
P 7600 4400
F 0 "R26" V 7680 4400 50  0000 C CNN
F 1 "1k" V 7600 4400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7530 4400 50  0001 C CNN
F 3 "" H 7600 4400 50  0001 C CNN
	1    7600 4400
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 5B33FBE0
P 7400 4400
F 0 "R25" V 7480 4400 50  0000 C CNN
F 1 "1k" V 7400 4400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7330 4400 50  0001 C CNN
F 3 "" H 7400 4400 50  0001 C CNN
	1    7400 4400
	1    0    0    -1  
$EndComp
Text HLabel 7700 3500 2    60   Output ~ 0
~RESET_I2C
Text HLabel 7700 3300 2    60   Output ~ 0
A0
Text HLabel 7700 3400 2    60   Output ~ 0
A1
Text HLabel 7700 3200 2    60   Output ~ 0
A2
Text HLabel 5400 4250 0    60   Output ~ 0
SCLK
Text HLabel 5400 4350 0    60   Input ~ 0
MISO
Text HLabel 5400 4450 0    60   Output ~ 0
MOSI
Text HLabel 5400 3950 0    60   Output ~ 0
~RESET_ADC
Text HLabel 5400 4150 0    60   Input ~ 0
~DRDY
$Comp
L GNDD #PWR039
U 1 1 5B34005C
P 5850 5050
F 0 "#PWR039" H 5850 4800 50  0001 C CNN
F 1 "GNDD" H 5850 4925 50  0000 C CNN
F 2 "" H 5850 5050 50  0001 C CNN
F 3 "" H 5850 5050 50  0001 C CNN
	1    5850 5050
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR040
U 1 1 5B340073
P 7150 5050
F 0 "#PWR040" H 7150 4800 50  0001 C CNN
F 1 "GNDD" H 7150 4925 50  0000 C CNN
F 2 "" H 7150 5050 50  0001 C CNN
F 3 "" H 7150 5050 50  0001 C CNN
	1    7150 5050
	1    0    0    -1  
$EndComp
$Comp
L CWF-4 P17
U 1 1 5B342458
P 9850 2800
F 0 "P17" H 10000 2850 60  0000 C CNN
F 1 "CWF-4" H 10000 2950 60  0000 C CNN
F 2 "Control_board_footprints:CWF-4" H 9850 2800 60  0001 C CNN
F 3 "" H 9850 2800 60  0001 C CNN
	1    9850 2800
	1    0    0    -1  
$EndComp
NoConn ~ 9650 2850
$Comp
L GNDD #PWR041
U 1 1 5B34253D
P 9500 3200
F 0 "#PWR041" H 9500 2950 50  0001 C CNN
F 1 "GNDD" H 9500 3075 50  0000 C CNN
F 2 "" H 9500 3200 50  0001 C CNN
F 3 "" H 9500 3200 50  0001 C CNN
	1    9500 3200
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR042
U 1 1 5B3428C9
P 7450 2500
F 0 "#PWR042" H 7450 2250 50  0001 C CNN
F 1 "GNDD" H 7450 2375 50  0000 C CNN
F 2 "" H 7450 2500 50  0001 C CNN
F 3 "" H 7450 2500 50  0001 C CNN
	1    7450 2500
	1    0    0    -1  
$EndComp
Text Label 7700 3900 0    60   ~ 0
UART_TX
Text Label 7700 3750 0    60   ~ 0
UART_RX
Text Label 9500 2950 2    60   ~ 0
UART_RX
Text Label 9500 3050 2    60   ~ 0
UART_TX
Text HLabel 5400 4050 0    60   Output ~ 0
~SS
Text Label 5250 3500 2    60   ~ 0
ADC_1
Text Label 5250 3600 2    60   ~ 0
ADC_2
Text Label 5250 3700 2    60   ~ 0
ADC_3
$Comp
L CWF-2 P14
U 1 1 5B34319E
P 2350 2650
F 0 "P14" H 2450 2850 60  0000 C CNN
F 1 "CWF-2" H 2450 2750 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 2350 2650 60  0001 C CNN
F 3 "" H 2350 2650 60  0001 C CNN
	1    2350 2650
	-1   0    0    -1  
$EndComp
Text Label 3450 2700 0    60   ~ 0
ADC_1
$Comp
L R R22
U 1 1 5B34349C
P 2950 2700
F 0 "R22" V 3030 2700 50  0000 C CNN
F 1 "1k" V 2950 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2880 2700 50  0001 C CNN
F 3 "" H 2950 2700 50  0001 C CNN
	1    2950 2700
	0    1    1    0   
$EndComp
$Comp
L C C7
U 1 1 5B3437EF
P 3250 2850
F 0 "C7" H 3275 2950 50  0000 L CNN
F 1 "0.15 µF" H 3275 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3288 2700 50  0001 C CNN
F 3 "" H 3250 2850 50  0001 C CNN
	1    3250 2850
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR043
U 1 1 5B344287
P 2950 3200
F 0 "#PWR043" H 2950 2950 50  0001 C CNN
F 1 "GNDA" H 2950 3050 50  0000 C CNN
F 2 "" H 2950 3200 50  0001 C CNN
F 3 "" H 2950 3200 50  0001 C CNN
	1    2950 3200
	1    0    0    -1  
$EndComp
$Comp
L CWF-2 P15
U 1 1 5B344479
P 2350 3600
F 0 "P15" H 2450 3800 60  0000 C CNN
F 1 "CWF-2" H 2450 3700 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 2350 3600 60  0001 C CNN
F 3 "" H 2350 3600 60  0001 C CNN
	1    2350 3600
	-1   0    0    -1  
$EndComp
Text Label 3450 3650 0    60   ~ 0
ADC_2
$Comp
L R R23
U 1 1 5B344481
P 2950 3650
F 0 "R23" V 3030 3650 50  0000 C CNN
F 1 "1k" V 2950 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2880 3650 50  0001 C CNN
F 3 "" H 2950 3650 50  0001 C CNN
	1    2950 3650
	0    1    1    0   
$EndComp
$Comp
L C C8
U 1 1 5B344487
P 3250 3800
F 0 "C8" H 3275 3900 50  0000 L CNN
F 1 "0.15 µF" H 3275 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3288 3650 50  0001 C CNN
F 3 "" H 3250 3800 50  0001 C CNN
	1    3250 3800
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR044
U 1 1 5B344494
P 2950 4150
F 0 "#PWR044" H 2950 3900 50  0001 C CNN
F 1 "GNDA" H 2950 4000 50  0000 C CNN
F 2 "" H 2950 4150 50  0001 C CNN
F 3 "" H 2950 4150 50  0001 C CNN
	1    2950 4150
	1    0    0    -1  
$EndComp
$Comp
L CWF-2 P16
U 1 1 5B344558
P 2350 4550
F 0 "P16" H 2450 4750 60  0000 C CNN
F 1 "CWF-2" H 2450 4650 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 2350 4550 60  0001 C CNN
F 3 "" H 2350 4550 60  0001 C CNN
	1    2350 4550
	-1   0    0    -1  
$EndComp
Text Label 3450 4600 0    60   ~ 0
ADC_3
$Comp
L R R24
U 1 1 5B344560
P 2950 4600
F 0 "R24" V 3030 4600 50  0000 C CNN
F 1 "1k" V 2950 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2880 4600 50  0001 C CNN
F 3 "" H 2950 4600 50  0001 C CNN
	1    2950 4600
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 5B344566
P 3250 4750
F 0 "C9" H 3275 4850 50  0000 L CNN
F 1 "0.15 µF" H 3275 4650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3288 4600 50  0001 C CNN
F 3 "" H 3250 4750 50  0001 C CNN
	1    3250 4750
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR045
U 1 1 5B344573
P 2950 5100
F 0 "#PWR045" H 2950 4850 50  0001 C CNN
F 1 "GNDA" H 2950 4950 50  0000 C CNN
F 2 "" H 2950 5100 50  0001 C CNN
F 3 "" H 2950 5100 50  0001 C CNN
	1    2950 5100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR046
U 1 1 5B344850
P 9000 2450
F 0 "#PWR046" H 9000 2300 50  0001 C CNN
F 1 "+5V" H 9000 2590 50  0000 C CNN
F 2 "" H 9000 2450 50  0001 C CNN
F 3 "" H 9000 2450 50  0001 C CNN
	1    9000 2450
	1    0    0    -1  
$EndComp
NoConn ~ 5950 2550
NoConn ~ 5950 2650
NoConn ~ 6000 2700
NoConn ~ 6000 2600
NoConn ~ 6000 2800
NoConn ~ 5950 2750
NoConn ~ 5950 2850
NoConn ~ 6000 2900
NoConn ~ 6000 3000
NoConn ~ 6000 3100
NoConn ~ 6000 3300
NoConn ~ 6000 3400
NoConn ~ 6000 3500
NoConn ~ 5950 3550
NoConn ~ 6000 3600
NoConn ~ 5950 3650
NoConn ~ 5950 3750
NoConn ~ 6000 3700
NoConn ~ 6000 3800
NoConn ~ 5950 3850
NoConn ~ 6000 3900
NoConn ~ 5950 3950
NoConn ~ 6000 4000
NoConn ~ 6000 4100
NoConn ~ 6000 4400
NoConn ~ 5950 4450
NoConn ~ 6000 4500
NoConn ~ 5950 4550
NoConn ~ 6000 4600
NoConn ~ 5950 4650
NoConn ~ 6000 4700
NoConn ~ 5950 4750
NoConn ~ 6000 4800
NoConn ~ 7000 4800
NoConn ~ 7000 4700
NoConn ~ 7050 4750
NoConn ~ 7050 4450
NoConn ~ 7050 4350
NoConn ~ 7050 4250
NoConn ~ 7000 4200
NoConn ~ 7000 4100
NoConn ~ 7050 4050
NoConn ~ 7050 4150
NoConn ~ 7000 4000
NoConn ~ 7050 3950
NoConn ~ 7050 3800
NoConn ~ 7050 3750
NoConn ~ 7000 3700
NoConn ~ 7050 3650
NoConn ~ 7000 3600
NoConn ~ 7000 3500
NoConn ~ 7000 3400
NoConn ~ 7000 3300
NoConn ~ 7000 3200
NoConn ~ 7050 3150
NoConn ~ 7000 3100
NoConn ~ 7050 3050
NoConn ~ 7000 3000
NoConn ~ 7000 2900
NoConn ~ 7050 2850
NoConn ~ 7000 2800
NoConn ~ 7050 2750
NoConn ~ 7000 2700
NoConn ~ 7050 2650
NoConn ~ 7000 3800
NoConn ~ 7050 4550
NoConn ~ 7000 4500
NoConn ~ 7000 4400
NoConn ~ 7000 4300
NoConn ~ 7050 3450
Wire Wire Line
	5600 2500 5600 2450
Wire Wire Line
	5600 2450 5950 2450
Wire Wire Line
	6000 2500 5900 2500
Wire Wire Line
	5900 2500 5900 2450
Connection ~ 5900 2450
Wire Wire Line
	5700 2950 5950 2950
Wire Wire Line
	5700 2950 5700 2900
Wire Wire Line
	5700 2900 5300 2900
Wire Wire Line
	5950 3050 5650 3050
Wire Wire Line
	5650 3050 5650 3000
Wire Wire Line
	5650 3000 5300 3000
Wire Wire Line
	5950 3150 5650 3150
Wire Wire Line
	5650 3150 5650 3200
Wire Wire Line
	5650 3200 5300 3200
Wire Wire Line
	5700 3200 6000 3200
Wire Wire Line
	7000 4600 7350 4600
Wire Wire Line
	7050 4650 7300 4650
Wire Wire Line
	7300 4650 7300 4750
Wire Wire Line
	7300 4750 7700 4750
Wire Wire Line
	7350 4600 7350 4650
Wire Wire Line
	7350 4650 7700 4650
Connection ~ 7400 4650
Connection ~ 7600 4750
Wire Wire Line
	5750 4150 5950 4150
Wire Wire Line
	5400 4250 5950 4250
Wire Wire Line
	5950 4350 5750 4350
Wire Wire Line
	5750 4350 5750 4450
Wire Wire Line
	5750 4450 5400 4450
Wire Wire Line
	6000 4300 5700 4300
Wire Wire Line
	5700 4300 5700 4350
Wire Wire Line
	5700 4350 5400 4350
Wire Wire Line
	6000 4200 5700 4200
Wire Wire Line
	5700 4200 5700 4150
Wire Wire Line
	5700 4150 5400 4150
Wire Wire Line
	5750 4150 5750 4050
Wire Wire Line
	5750 4050 5400 4050
Wire Wire Line
	7000 4900 7150 4900
Wire Wire Line
	7150 4900 7150 5050
Wire Wire Line
	7050 4850 7050 4900
Connection ~ 7050 4900
Wire Wire Line
	6000 4900 5850 4900
Wire Wire Line
	5850 4850 5850 5050
Wire Wire Line
	5950 4850 5850 4850
Connection ~ 5850 4900
Wire Wire Line
	9500 3200 9500 3150
Wire Wire Line
	9500 3150 9650 3150
Wire Wire Line
	5700 3200 5700 3300
Wire Wire Line
	5700 3300 5300 3300
Wire Wire Line
	7050 2450 7450 2450
Wire Wire Line
	7000 2500 7100 2500
Wire Wire Line
	7100 2500 7100 2450
Connection ~ 7100 2450
Wire Wire Line
	7050 3850 7150 3850
Wire Wire Line
	7150 3850 7150 3750
Wire Wire Line
	5400 3950 5800 3950
Wire Wire Line
	5800 3950 5800 4050
Wire Wire Line
	5800 4050 5950 4050
Wire Wire Line
	5250 3500 5750 3500
Wire Wire Line
	5750 3500 5750 3250
Wire Wire Line
	5750 3250 5950 3250
Wire Wire Line
	5950 3350 5800 3350
Wire Wire Line
	5800 3350 5800 3600
Wire Wire Line
	5800 3600 5250 3600
Wire Wire Line
	5950 3450 5850 3450
Wire Wire Line
	5850 3450 5850 3700
Wire Wire Line
	5850 3700 5250 3700
Wire Wire Line
	9500 2950 9650 2950
Wire Wire Line
	9500 3050 9650 3050
Wire Wire Line
	7700 3900 7000 3900
Wire Wire Line
	7150 3750 7700 3750
Wire Wire Line
	2550 2700 2800 2700
Wire Wire Line
	3100 2700 3450 2700
Connection ~ 3250 2700
Wire Wire Line
	2700 2800 2700 3100
Wire Wire Line
	2700 3100 3250 3100
Wire Wire Line
	3250 3100 3250 3000
Connection ~ 2950 3100
Wire Wire Line
	2950 3100 2950 3200
Wire Wire Line
	2550 3650 2800 3650
Wire Wire Line
	3100 3650 3450 3650
Connection ~ 3250 3650
Wire Wire Line
	2550 3750 2700 3750
Wire Wire Line
	2700 3750 2700 4050
Wire Wire Line
	2700 4050 3250 4050
Wire Wire Line
	3250 4050 3250 3950
Connection ~ 2950 4050
Wire Wire Line
	2950 4050 2950 4150
Wire Wire Line
	2550 4600 2800 4600
Wire Wire Line
	3100 4600 3450 4600
Connection ~ 3250 4600
Wire Wire Line
	2550 4700 2700 4700
Wire Wire Line
	2700 4700 2700 5000
Wire Wire Line
	2700 5000 3250 5000
Wire Wire Line
	3250 5000 3250 4900
Connection ~ 2950 5000
Wire Wire Line
	2950 5000 2950 5100
Wire Wire Line
	7450 2450 7450 2500
Wire Wire Line
	7050 2550 7250 2550
Wire Wire Line
	7250 2750 9000 2750
Wire Wire Line
	9000 2750 9000 2450
Wire Wire Line
	7000 2600 7100 2600
Wire Wire Line
	7100 2600 7100 2550
Connection ~ 7100 2550
Wire Wire Line
	7050 3550 7250 3550
Wire Wire Line
	7250 3550 7250 3500
Wire Wire Line
	7250 3500 7700 3500
Wire Wire Line
	7700 3400 7250 3400
Wire Wire Line
	7250 3400 7250 3350
Wire Wire Line
	7250 3350 7050 3350
Wire Wire Line
	7700 3300 7350 3300
Wire Wire Line
	7350 3300 7350 3250
Wire Wire Line
	7350 3250 7050 3250
Wire Wire Line
	7700 3200 7400 3200
Wire Wire Line
	7400 3200 7400 2950
Wire Wire Line
	7400 2950 7050 2950
Wire Wire Line
	7250 2550 7250 2750
Wire Wire Line
	2550 2800 2700 2800
Wire Wire Line
	7400 4200 7600 4200
$Comp
L +3.3V #PWR?
U 1 1 5B545E08
P 7500 4150
F 0 "#PWR?" H 7500 4000 50  0001 C CNN
F 1 "+3.3V" H 7500 4290 50  0000 C CNN
F 2 "" H 7500 4150 50  0001 C CNN
F 3 "" H 7500 4150 50  0001 C CNN
	1    7500 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 4150 7500 4200
Connection ~ 7500 4200
Wire Wire Line
	7600 4200 7600 4250
Wire Wire Line
	7400 4200 7400 4250
Wire Wire Line
	7400 4550 7400 4650
Wire Wire Line
	7600 4550 7600 4750
$EndSCHEMATC