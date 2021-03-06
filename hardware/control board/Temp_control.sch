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
Sheet 3 6
Title "Current driver and PWM for temperature control"
Date "2018-07-05"
Rev "1.0"
Comp "Skoltech"
Comment1 "All together they provide temperature control."
Comment2 "Right part drives Peltier coolers with constant current. "
Comment3 "Left part powers ceramic resistors with PWM signal."
Comment4 ""
$EndDescr
$Comp
L IRF530N Q3
U 1 1 5B1BFD27
P 3950 2050
F 0 "Q3" H 4200 2125 50  0000 L CNN
F 1 "IRF530N" H 4200 2050 50  0000 L CNN
F 2 "Control_board_footprints:TO-220-3_Horizontal" H 4200 1975 50  0001 L CIN
F 3 "" H 3950 2050 50  0001 L CNN
	1    3950 2050
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5B1BFE03
P 3450 2050
F 0 "R7" V 3530 2050 50  0000 C CNN
F 1 "10k" V 3450 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3380 2050 50  0001 C CNN
F 3 "" H 3450 2050 50  0001 C CNN
	1    3450 2050
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5B1BFE51
P 3250 1700
F 0 "R5" H 3350 1700 50  0000 C CNN
F 1 "10k" V 3250 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3180 1700 50  0001 C CNN
F 3 "" H 3250 1700 50  0001 C CNN
	1    3250 1700
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5B1BFEA3
P 2650 1700
F 0 "R1" H 2750 1700 50  0000 C CNN
F 1 "10k" V 2650 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2580 1700 50  0001 C CNN
F 3 "" H 2650 1700 50  0001 C CNN
	1    2650 1700
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 5B1BFFAB
P 2650 1450
F 0 "#PWR03" H 2650 1300 50  0001 C CNN
F 1 "+3.3V" H 2650 1590 50  0000 C CNN
F 2 "" H 2650 1450 50  0001 C CNN
F 3 "" H 2650 1450 50  0001 C CNN
	1    2650 1450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 5B1BFFD8
P 3250 1450
F 0 "#PWR04" H 3250 1300 50  0001 C CNN
F 1 "+5V" H 3250 1590 50  0000 C CNN
F 2 "" H 3250 1450 50  0001 C CNN
F 3 "" H 3250 1450 50  0001 C CNN
	1    3250 1450
	1    0    0    -1  
$EndComp
Text HLabel 2200 2050 0    60   Output ~ 0
TEC_PWM_1
$Comp
L R R2
U 1 1 5B1C0177
P 2650 2400
F 0 "R2" H 2750 2400 50  0000 C CNN
F 1 "1k" V 2650 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2580 2400 50  0001 C CNN
F 3 "" H 2650 2400 50  0001 C CNN
	1    2650 2400
	-1   0    0    1   
$EndComp
$Comp
L GNDD #PWR05
U 1 1 5B1C01CD
P 2650 2700
F 0 "#PWR05" H 2650 2450 50  0001 C CNN
F 1 "GNDD" H 2650 2575 50  0000 C CNN
F 2 "" H 2650 2700 50  0001 C CNN
F 3 "" H 2650 2700 50  0001 C CNN
	1    2650 2700
	1    0    0    -1  
$EndComp
$Comp
L IRF530N Q4
U 1 1 5B1C0552
P 3950 4550
F 0 "Q4" H 4200 4625 50  0000 L CNN
F 1 "IRF530N" H 4200 4550 50  0000 L CNN
F 2 "Control_board_footprints:TO-220-3_Horizontal" H 4200 4475 50  0001 L CIN
F 3 "" H 3950 4550 50  0001 L CNN
	1    3950 4550
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5B1C055E
P 3450 4550
F 0 "R8" V 3530 4550 50  0000 C CNN
F 1 "10k" V 3450 4550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3380 4550 50  0001 C CNN
F 3 "" H 3450 4550 50  0001 C CNN
	1    3450 4550
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5B1C0564
P 3250 4200
F 0 "R6" H 3350 4200 50  0000 C CNN
F 1 "10k" V 3250 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3180 4200 50  0001 C CNN
F 3 "" H 3250 4200 50  0001 C CNN
	1    3250 4200
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 5B1C056A
P 2650 4200
F 0 "R3" H 2750 4200 50  0000 C CNN
F 1 "10k" V 2650 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2580 4200 50  0001 C CNN
F 3 "" H 2650 4200 50  0001 C CNN
	1    2650 4200
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR06
U 1 1 5B1C0577
P 2650 3950
F 0 "#PWR06" H 2650 3800 50  0001 C CNN
F 1 "+3.3V" H 2650 4090 50  0000 C CNN
F 2 "" H 2650 3950 50  0001 C CNN
F 3 "" H 2650 3950 50  0001 C CNN
	1    2650 3950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 5B1C057E
P 3250 3950
F 0 "#PWR07" H 3250 3800 50  0001 C CNN
F 1 "+5V" H 3250 4090 50  0000 C CNN
F 2 "" H 3250 3950 50  0001 C CNN
F 3 "" H 3250 3950 50  0001 C CNN
	1    3250 3950
	1    0    0    -1  
$EndComp
Text HLabel 2200 4550 0    60   Output ~ 0
TEC_PWM_2
$Comp
L R R4
U 1 1 5B1C0587
P 2650 4900
F 0 "R4" H 2750 4900 50  0000 C CNN
F 1 "1k" V 2650 4900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2580 4900 50  0001 C CNN
F 3 "" H 2650 4900 50  0001 C CNN
	1    2650 4900
	-1   0    0    1   
$EndComp
$Comp
L GNDD #PWR08
U 1 1 5B1C058D
P 2650 5200
F 0 "#PWR08" H 2650 4950 50  0001 C CNN
F 1 "GNDD" H 2650 5075 50  0000 C CNN
F 2 "" H 2650 5200 50  0001 C CNN
F 3 "" H 2650 5200 50  0001 C CNN
	1    2650 5200
	1    0    0    -1  
$EndComp
Text HLabel 5750 2050 0    60   Output ~ 0
TEC_DAC_1
$Comp
L R R9
U 1 1 5B213058
P 6000 2050
F 0 "R9" V 6080 2050 50  0000 C CNN
F 1 "1k" V 6000 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5930 2050 50  0001 C CNN
F 3 "" H 6000 2050 50  0001 C CNN
	1    6000 2050
	0    1    1    0   
$EndComp
$Comp
L IRFML8244 Q1
U 1 1 5B2140FA
P 2950 1950
AR Path="/5B2140FA" Ref="Q1"  Part="1" 
AR Path="/5B1BED4C/5B2140FA" Ref="Q1"  Part="1" 
F 0 "Q1" V 3300 1950 50  0000 L CNN
F 1 "IRFML8244" V 3200 1750 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3200 1875 50  0001 L CIN
F 3 "" H 2950 1950 50  0001 L CNN
	1    2950 1950
	0    1    1    0   
$EndComp
$Comp
L IRFML8244 Q2
U 1 1 5B214223
P 2950 4450
AR Path="/5B214223" Ref="Q2"  Part="1" 
AR Path="/5B1BED4C/5B214223" Ref="Q2"  Part="1" 
F 0 "Q2" V 3300 4450 50  0000 L CNN
F 1 "IRFML8244" V 3200 4250 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3200 4375 50  0001 L CIN
F 3 "" H 2950 4450 50  0001 L CNN
	1    2950 4450
	0    1    1    0   
$EndComp
$Comp
L LMC7101 U2
U 1 1 5B214203
P 6800 2150
F 0 "U2" H 7000 2300 50  0000 C CNN
F 1 "LMC7101" H 7050 2000 50  0000 C CNN
F 2 "Control_board_footprints:SOT-23-5" H 6800 2150 50  0001 C CNN
F 3 "" H 6800 2150 50  0001 C CNN
	1    6800 2150
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5B21432F
P 7400 2150
F 0 "R13" V 7480 2150 50  0000 C CNN
F 1 "10k" V 7400 2150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7330 2150 50  0001 C CNN
F 3 "" H 7400 2150 50  0001 C CNN
	1    7400 2150
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 5B21436C
P 7650 2400
F 0 "R15" V 7730 2400 50  0000 C CNN
F 1 "100k" V 7650 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7580 2400 50  0001 C CNN
F 3 "" H 7650 2400 50  0001 C CNN
	1    7650 2400
	1    0    0    -1  
$EndComp
$Comp
L IRF530N Q5
U 1 1 5B2143C5
P 7950 2150
F 0 "Q5" H 8200 2225 50  0000 L CNN
F 1 "IRF530N" H 8200 2150 50  0000 L CNN
F 2 "Control_board_footprints:TO-220-3_Horizontal" H 8200 2075 50  0001 L CIN
F 3 "" H 7950 2150 50  0001 L CNN
	1    7950 2150
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 5B214917
P 8050 3050
F 0 "R17" V 8130 3050 50  0000 C CNN
F 1 "1" V 8050 3050 50  0000 C CNN
F 2 "Control_board_footprints:SQP" V 7980 3050 50  0001 C CNN
F 3 "" H 8050 3050 50  0001 C CNN
	1    8050 3050
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR09
U 1 1 5B214A0E
P 8050 3250
F 0 "#PWR09" H 8050 3000 50  0001 C CNN
F 1 "GNDA" H 8050 3100 50  0000 C CNN
F 2 "" H 8050 3250 50  0001 C CNN
F 3 "" H 8050 3250 50  0001 C CNN
	1    8050 3250
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR010
U 1 1 5B214BAE
P 7650 2600
F 0 "#PWR010" H 7650 2350 50  0001 C CNN
F 1 "GNDA" H 7650 2450 50  0000 C CNN
F 2 "" H 7650 2600 50  0001 C CNN
F 3 "" H 7650 2600 50  0001 C CNN
	1    7650 2600
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR011
U 1 1 5B215C8B
P 8050 1400
F 0 "#PWR011" H 8050 1250 50  0001 C CNN
F 1 "+12V" H 8050 1540 50  0000 C CNN
F 2 "" H 8050 1400 50  0001 C CNN
F 3 "" H 8050 1400 50  0001 C CNN
	1    8050 1400
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR012
U 1 1 5B215D1D
P 6700 1750
F 0 "#PWR012" H 6700 1600 50  0001 C CNN
F 1 "+9V" H 6700 1890 50  0000 C CNN
F 2 "" H 6700 1750 50  0001 C CNN
F 3 "" H 6700 1750 50  0001 C CNN
	1    6700 1750
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR013
U 1 1 5B215DE6
P 6700 2550
F 0 "#PWR013" H 6700 2300 50  0001 C CNN
F 1 "GNDA" H 6700 2400 50  0000 C CNN
F 2 "" H 6700 2550 50  0001 C CNN
F 3 "" H 6700 2550 50  0001 C CNN
	1    6700 2550
	1    0    0    -1  
$EndComp
Text HLabel 5750 4550 0    60   Output ~ 0
TEC_DAC_2
$Comp
L LMC7101 U3
U 1 1 5B216EFC
P 6800 4650
F 0 "U3" H 7000 4800 50  0000 C CNN
F 1 "LMC7101" H 7050 4500 50  0000 C CNN
F 2 "Control_board_footprints:SOT-23-5" H 6800 4650 50  0001 C CNN
F 3 "" H 6800 4650 50  0001 C CNN
	1    6800 4650
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 5B216F03
P 7400 4650
F 0 "R14" V 7480 4650 50  0000 C CNN
F 1 "10k" V 7400 4650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7330 4650 50  0001 C CNN
F 3 "" H 7400 4650 50  0001 C CNN
	1    7400 4650
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 5B216F09
P 7650 4900
F 0 "R16" V 7730 4900 50  0000 C CNN
F 1 "100k" V 7650 4900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7580 4900 50  0001 C CNN
F 3 "" H 7650 4900 50  0001 C CNN
	1    7650 4900
	1    0    0    -1  
$EndComp
$Comp
L IRF530N Q6
U 1 1 5B216F0F
P 7950 4650
F 0 "Q6" H 8200 4725 50  0000 L CNN
F 1 "IRF530N" H 8200 4650 50  0000 L CNN
F 2 "Control_board_footprints:TO-220-3_Horizontal" H 8200 4575 50  0001 L CIN
F 3 "" H 7950 4650 50  0001 L CNN
	1    7950 4650
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 5B216F19
P 8050 5550
F 0 "R18" V 8130 5550 50  0000 C CNN
F 1 "1" V 8050 5550 50  0000 C CNN
F 2 "Control_board_footprints:SQP" V 7980 5550 50  0001 C CNN
F 3 "" H 8050 5550 50  0001 C CNN
	1    8050 5550
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR014
U 1 1 5B216F1F
P 8050 5750
F 0 "#PWR014" H 8050 5500 50  0001 C CNN
F 1 "GNDA" H 8050 5600 50  0000 C CNN
F 2 "" H 8050 5750 50  0001 C CNN
F 3 "" H 8050 5750 50  0001 C CNN
	1    8050 5750
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR015
U 1 1 5B216F25
P 7650 5100
F 0 "#PWR015" H 7650 4850 50  0001 C CNN
F 1 "GNDA" H 7650 4950 50  0000 C CNN
F 2 "" H 7650 5100 50  0001 C CNN
F 3 "" H 7650 5100 50  0001 C CNN
	1    7650 5100
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR016
U 1 1 5B216F2D
P 8050 3900
F 0 "#PWR016" H 8050 3750 50  0001 C CNN
F 1 "+12V" H 8050 4040 50  0000 C CNN
F 2 "" H 8050 3900 50  0001 C CNN
F 3 "" H 8050 3900 50  0001 C CNN
	1    8050 3900
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR017
U 1 1 5B216F33
P 6700 4250
F 0 "#PWR017" H 6700 4100 50  0001 C CNN
F 1 "+9V" H 6700 4390 50  0000 C CNN
F 2 "" H 6700 4250 50  0001 C CNN
F 3 "" H 6700 4250 50  0001 C CNN
	1    6700 4250
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR018
U 1 1 5B216F3A
P 6700 5050
F 0 "#PWR018" H 6700 4800 50  0001 C CNN
F 1 "GNDA" H 6700 4900 50  0000 C CNN
F 2 "" H 6700 5050 50  0001 C CNN
F 3 "" H 6700 5050 50  0001 C CNN
	1    6700 5050
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR019
U 1 1 5B214620
P 4050 3800
F 0 "#PWR019" H 4050 3650 50  0001 C CNN
F 1 "+12V" H 4050 3940 50  0000 C CNN
F 2 "" H 4050 3800 50  0001 C CNN
F 3 "" H 4050 3800 50  0001 C CNN
	1    4050 3800
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR020
U 1 1 5B2148BB
P 4050 1300
F 0 "#PWR020" H 4050 1150 50  0001 C CNN
F 1 "+12V" H 4050 1440 50  0000 C CNN
F 2 "" H 4050 1300 50  0001 C CNN
F 3 "" H 4050 1300 50  0001 C CNN
	1    4050 1300
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR021
U 1 1 5B214C05
P 4050 2700
F 0 "#PWR021" H 4050 2450 50  0001 C CNN
F 1 "GNDA" H 4050 2550 50  0000 C CNN
F 2 "" H 4050 2700 50  0001 C CNN
F 3 "" H 4050 2700 50  0001 C CNN
	1    4050 2700
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR022
U 1 1 5B214EB9
P 4050 5200
F 0 "#PWR022" H 4050 4950 50  0001 C CNN
F 1 "GNDA" H 4050 5050 50  0000 C CNN
F 2 "" H 4050 5200 50  0001 C CNN
F 3 "" H 4050 5200 50  0001 C CNN
	1    4050 5200
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5B214802
P 6250 2200
F 0 "R11" V 6330 2200 50  0000 C CNN
F 1 "100k" V 6250 2200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6180 2200 50  0001 C CNN
F 3 "" H 6250 2200 50  0001 C CNN
	1    6250 2200
	-1   0    0    1   
$EndComp
$Comp
L GNDA #PWR023
U 1 1 5B214BD2
P 6250 2450
F 0 "#PWR023" H 6250 2200 50  0001 C CNN
F 1 "GNDA" H 6250 2300 50  0000 C CNN
F 2 "" H 6250 2450 50  0001 C CNN
F 3 "" H 6250 2450 50  0001 C CNN
	1    6250 2450
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 5B215046
P 6000 4550
F 0 "R10" V 6080 4550 50  0000 C CNN
F 1 "1k" V 6000 4550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5930 4550 50  0001 C CNN
F 3 "" H 6000 4550 50  0001 C CNN
	1    6000 4550
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 5B21504C
P 6250 4700
F 0 "R12" V 6330 4700 50  0000 C CNN
F 1 "100k" V 6250 4700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6180 4700 50  0001 C CNN
F 3 "" H 6250 4700 50  0001 C CNN
	1    6250 4700
	-1   0    0    1   
$EndComp
$Comp
L GNDA #PWR024
U 1 1 5B215055
P 6250 4950
F 0 "#PWR024" H 6250 4700 50  0001 C CNN
F 1 "GNDA" H 6250 4800 50  0000 C CNN
F 2 "" H 6250 4950 50  0001 C CNN
F 3 "" H 6250 4950 50  0001 C CNN
	1    6250 4950
	1    0    0    -1  
$EndComp
$Comp
L CWF-2 P11
U 1 1 5B321A74
P 8350 1800
F 0 "P11" H 8450 1550 60  0000 C CNN
F 1 "CWF-2" H 8400 1450 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 8350 1800 60  0001 C CNN
F 3 "" H 8350 1800 60  0001 C CNN
	1    8350 1800
	1    0    0    1   
$EndComp
$Comp
L CWF-2 P12
U 1 1 5B321D46
P 8350 4300
F 0 "P12" H 8450 4050 60  0000 C CNN
F 1 "CWF-2" H 8450 3950 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 8350 4300 60  0001 C CNN
F 3 "" H 8350 4300 60  0001 C CNN
	1    8350 4300
	1    0    0    1   
$EndComp
$Comp
L CWF-2 P10
U 1 1 5B321E82
P 4350 4200
F 0 "P10" H 4450 3950 60  0000 C CNN
F 1 "CWF-2" H 4450 3850 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 4350 4200 60  0001 C CNN
F 3 "" H 4350 4200 60  0001 C CNN
	1    4350 4200
	1    0    0    1   
$EndComp
$Comp
L CWF-2 P9
U 1 1 5B3220A0
P 4350 1700
F 0 "P9" H 4450 1450 60  0000 C CNN
F 1 "CWF-2" H 4450 1350 60  0000 C CNN
F 2 "Control_board_footprints:CWF-2R" H 4350 1700 60  0001 C CNN
F 3 "" H 4350 1700 60  0001 C CNN
	1    4350 1700
	1    0    0    1   
$EndComp
Wire Wire Line
	3600 2050 3750 2050
Wire Wire Line
	3150 2050 3300 2050
Wire Wire Line
	3250 1850 3250 2050
Connection ~ 3250 2050
Wire Wire Line
	2200 2050 2750 2050
Wire Wire Line
	2650 1550 2950 1550
Wire Wire Line
	2950 1550 2950 1750
Wire Wire Line
	2650 1450 2650 1550
Wire Wire Line
	3250 1450 3250 1550
Connection ~ 2650 2050
Wire Wire Line
	2650 2550 2650 2700
Wire Wire Line
	3600 4550 3750 4550
Wire Wire Line
	3150 4550 3300 4550
Wire Wire Line
	3250 4350 3250 4550
Connection ~ 3250 4550
Wire Wire Line
	2200 4550 2750 4550
Wire Wire Line
	2650 4050 2950 4050
Wire Wire Line
	2950 4050 2950 4250
Wire Wire Line
	2650 3950 2650 4050
Wire Wire Line
	3250 3950 3250 4050
Connection ~ 2650 4550
Wire Wire Line
	2650 4350 2650 4750
Wire Wire Line
	2650 5050 2650 5200
Wire Wire Line
	7100 2150 7250 2150
Wire Wire Line
	7550 2150 7750 2150
Connection ~ 7650 2150
Wire Wire Line
	7650 2150 7650 2250
Wire Wire Line
	6700 1750 6700 1850
Wire Wire Line
	6700 2450 6700 2550
Wire Wire Line
	8050 1400 8050 1650
Wire Wire Line
	8050 1650 8150 1650
Wire Wire Line
	8150 1750 8050 1750
Wire Wire Line
	8050 1750 8050 1950
Wire Wire Line
	7650 2550 7650 2600
Wire Wire Line
	8050 2900 8050 2350
Wire Wire Line
	8050 3200 8050 3250
Wire Wire Line
	7100 4650 7250 4650
Wire Wire Line
	7550 4650 7750 4650
Connection ~ 7650 4650
Wire Wire Line
	7650 4650 7650 4750
Wire Wire Line
	6700 4250 6700 4350
Wire Wire Line
	6700 4950 6700 5050
Wire Wire Line
	8050 3900 8050 4150
Wire Wire Line
	8050 4150 8150 4150
Wire Wire Line
	8150 4250 8050 4250
Wire Wire Line
	8050 4250 8050 4450
Wire Wire Line
	7650 5050 7650 5100
Wire Wire Line
	8050 5400 8050 4850
Wire Wire Line
	8050 5700 8050 5750
Wire Wire Line
	4050 3800 4050 4050
Wire Wire Line
	4050 4050 4150 4050
Wire Wire Line
	4150 4150 4050 4150
Wire Wire Line
	4050 4150 4050 4350
Wire Wire Line
	4050 1300 4050 1550
Wire Wire Line
	4050 1550 4150 1550
Wire Wire Line
	4150 1650 4050 1650
Wire Wire Line
	4050 1650 4050 1850
Wire Wire Line
	4050 2250 4050 2700
Wire Wire Line
	4050 4750 4050 5200
Wire Wire Line
	2650 1850 2650 2250
Wire Wire Line
	5750 2050 5850 2050
Wire Wire Line
	6150 2050 6500 2050
Connection ~ 6250 2050
Wire Wire Line
	6250 2350 6250 2450
Wire Wire Line
	5750 4550 5850 4550
Wire Wire Line
	6150 4550 6500 4550
Connection ~ 6250 4550
Wire Wire Line
	6250 4850 6250 4950
Wire Wire Line
	6500 4750 6450 4750
Wire Wire Line
	6450 4750 6450 5350
Wire Wire Line
	6450 5350 8050 5350
Connection ~ 8050 5350
Wire Wire Line
	6500 2250 6450 2250
Wire Wire Line
	6450 2250 6450 2850
Wire Wire Line
	6450 2850 8050 2850
Connection ~ 8050 2850
$EndSCHEMATC
