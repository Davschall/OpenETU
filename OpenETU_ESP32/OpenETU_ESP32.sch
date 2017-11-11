EESchema Schematic File Version 2
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
LIBS:esp32-pico-d4
LIBS:ETrigger-smaliffying-cache
LIBS:OpenETU_ESP32-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP32-PICO-D4 U2
U 1 1 59FAC225
P 5750 3950
F 0 "U2" H 5750 2350 60  0000 C CNN
F 1 "ESP32-PICO-D4" H 5750 4200 60  0000 C CNN
F 2 "" H 5750 3950 60  0001 C CNN
F 3 "" H 5750 3950 60  0001 C CNN
	1    5750 3950
	1    0    0    -1  
$EndComp
$Comp
L LM1117-3.3 U1
U 1 1 59FAC8F0
P 3350 2850
F 0 "U1" H 3200 2975 50  0000 C CNN
F 1 "LM1117-3.3" H 3350 2975 50  0000 L CNN
F 2 "" H 3350 2850 50  0001 C CNN
F 3 "" H 3350 2850 50  0001 C CNN
	1    3350 2850
	1    0    0    -1  
$EndComp
$Comp
L CP C1
U 1 1 5A015521
P 3850 3000
F 0 "C1" H 3875 3100 50  0000 L CNN
F 1 "CP" H 3875 2900 50  0000 L CNN
F 2 "" H 3888 2850 50  0001 C CNN
F 3 "" H 3850 3000 50  0001 C CNN
	1    3850 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5A015A9D
P 3850 3150
F 0 "#PWR01" H 3850 2900 50  0001 C CNN
F 1 "GND" H 3850 3000 50  0000 C CNN
F 2 "" H 3850 3150 50  0001 C CNN
F 3 "" H 3850 3150 50  0001 C CNN
	1    3850 3150
	1    0    0    -1  
$EndComp
Text GLabel 4200 2850 2    60   Output ~ 0
VDD
Text GLabel 4700 2850 1    60   Input ~ 0
VDD
Text GLabel 5250 2750 0    60   Input ~ 0
VDD
NoConn ~ 5150 3800
NoConn ~ 5150 3900
NoConn ~ 5150 4000
NoConn ~ 5150 4100
$Comp
L Conn_01x02 J1
U 1 1 5A05E51B
P 2650 3500
F 0 "J1" H 2650 3600 50  0000 C CNN
F 1 "Conn_01x02" H 2650 3300 50  0000 C CNN
F 2 "" H 2650 3500 50  0001 C CNN
F 3 "" H 2650 3500 50  0001 C CNN
	1    2650 3500
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5A05EB45
P 4300 4150
F 0 "R1" V 4380 4150 50  0000 C CNN
F 1 "R" V 4300 4150 50  0000 C CNN
F 2 "" V 4230 4150 50  0001 C CNN
F 3 "" H 4300 4150 50  0001 C CNN
	1    4300 4150
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A05EEB2
P 4300 4450
F 0 "R2" V 4380 4450 50  0000 C CNN
F 1 "R" V 4300 4450 50  0000 C CNN
F 2 "" V 4230 4450 50  0001 C CNN
F 3 "" H 4300 4450 50  0001 C CNN
	1    4300 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5A05F061
P 4300 4750
F 0 "#PWR02" H 4300 4500 50  0001 C CNN
F 1 "GND" H 4300 4600 50  0000 C CNN
F 2 "" H 4300 4750 50  0001 C CNN
F 3 "" H 4300 4750 50  0001 C CNN
	1    4300 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5A05F1A1
P 2650 3300
F 0 "#PWR03" H 2650 3050 50  0001 C CNN
F 1 "GND" H 2650 3150 50  0000 C CNN
F 2 "" H 2650 3300 50  0001 C CNN
F 3 "" H 2650 3300 50  0001 C CNN
	1    2650 3300
	0    -1   -1   0   
$EndComp
$Comp
L +BATT #PWR04
U 1 1 5A05F1C1
P 2550 3300
F 0 "#PWR04" H 2550 3150 50  0001 C CNN
F 1 "+BATT" H 2550 3440 50  0000 C CNN
F 2 "" H 2550 3300 50  0001 C CNN
F 3 "" H 2550 3300 50  0001 C CNN
	1    2550 3300
	0    -1   -1   0   
$EndComp
$Comp
L L L?
U 1 1 5A060289
P 4250 3500
F 0 "L?" V 4200 3500 50  0000 C CNN
F 1 "L" V 4325 3500 50  0000 C CNN
F 2 "" H 4250 3500 50  0001 C CNN
F 3 "" H 4250 3500 50  0001 C CNN
	1    4250 3500
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C?
U 1 1 5A06032C
P 4450 3600
F 0 "C?" H 4460 3670 50  0000 L CNN
F 1 "C_Small" H 4460 3520 50  0000 L CNN
F 2 "" H 4450 3600 50  0001 C CNN
F 3 "" H 4450 3600 50  0001 C CNN
	1    4450 3600
	-1   0    0    1   
$EndComp
$Comp
L C_Small C?
U 1 1 5A0603F3
P 4050 3600
F 0 "C?" H 4060 3670 50  0000 L CNN
F 1 "C_Small" H 4060 3520 50  0000 L CNN
F 2 "" H 4050 3600 50  0001 C CNN
F 3 "" H 4050 3600 50  0001 C CNN
	1    4050 3600
	-1   0    0    1   
$EndComp
$Comp
L SW_SPST SW?
U 1 1 5A067086
P 4550 5200
F 0 "SW?" V 4550 5325 50  0000 C CNN
F 1 "SW_SPST" H 4550 5100 50  0000 C CNN
F 2 "" H 4550 5200 50  0001 C CNN
F 3 "" H 4550 5200 50  0001 C CNN
	1    4550 5200
	0    1    1    0   
$EndComp
$Comp
L SW_SPST SW?
U 1 1 5A0670ED
P 4800 5200
F 0 "SW?" H 4800 5325 50  0000 C CNN
F 1 "SW_SPST" V 4800 5100 50  0000 C CNN
F 2 "" H 4800 5200 50  0001 C CNN
F 3 "" H 4800 5200 50  0001 C CNN
	1    4800 5200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5A067516
P 4800 5400
F 0 "#PWR?" H 4800 5150 50  0001 C CNN
F 1 "GND" H 4800 5250 50  0000 C CNN
F 2 "" H 4800 5400 50  0001 C CNN
F 3 "" H 4800 5400 50  0001 C CNN
	1    4800 5400
	1    0    0    -1  
$EndComp
$Comp
L A1302KUA-T IC?
U 1 1 5A067DC6
P 5200 6100
F 0 "IC?" H 5200 6550 50  0000 L CNN
F 1 "A1302KUA-T" H 5200 6450 50  0000 L CNN
F 2 "" H 5200 5750 50  0000 L CIN
F 3 "" H 5100 6100 50  0000 C CNN
	1    5200 6100
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R?
U 1 1 5A06832A
P 4100 3000
F 0 "R?" H 4130 3020 50  0000 L CNN
F 1 "R_Small" H 4130 2960 50  0000 L CNN
F 2 "" H 4100 3000 50  0001 C CNN
F 3 "" H 4100 3000 50  0001 C CNN
	1    4100 3000
	1    0    0    -1  
$EndComp
$Comp
L LED D?
U 1 1 5A0683C3
P 4100 3250
F 0 "D?" H 4100 3350 50  0000 C CNN
F 1 "LED" H 4100 3150 50  0000 C CNN
F 2 "" H 4100 3250 50  0001 C CNN
F 3 "" H 4100 3250 50  0001 C CNN
	1    4100 3250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5A068443
P 4100 3400
F 0 "#PWR?" H 4100 3150 50  0001 C CNN
F 1 "GND" H 4100 3250 50  0000 C CNN
F 2 "" H 4100 3400 50  0001 C CNN
F 3 "" H 4100 3400 50  0001 C CNN
	1    4100 3400
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5A068CD8
P 5800 6200
F 0 "#PWR?" H 5800 5950 50  0001 C CNN
F 1 "GND" H 5800 6050 50  0000 C CNN
F 2 "" H 5800 6200 50  0001 C CNN
F 3 "" H 5800 6200 50  0001 C CNN
	1    5800 6200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A069779
P 4050 3700
F 0 "#PWR?" H 4050 3450 50  0001 C CNN
F 1 "GND" H 4050 3550 50  0000 C CNN
F 2 "" H 4050 3700 50  0001 C CNN
F 3 "" H 4050 3700 50  0001 C CNN
	1    4050 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A0697AE
P 4450 3700
F 0 "#PWR?" H 4450 3450 50  0001 C CNN
F 1 "GND" H 4450 3550 50  0000 C CNN
F 2 "" H 4450 3700 50  0001 C CNN
F 3 "" H 4450 3700 50  0001 C CNN
	1    4450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2850 4200 2850
Connection ~ 3850 2850
Wire Wire Line
	5150 3400 4700 3400
Wire Wire Line
	4150 3700 5150 3700
Connection ~ 4700 3400
Wire Wire Line
	5150 3600 4700 3600
Connection ~ 4700 3600
Wire Wire Line
	5450 3350 5450 2750
Wire Wire Line
	5250 2750 6350 2750
Wire Wire Line
	5750 2750 5750 3350
Wire Wire Line
	6350 2750 6350 3350
Connection ~ 5750 2750
Connection ~ 5450 2750
Wire Wire Line
	3050 2850 2550 2850
Wire Wire Line
	2550 2850 2550 3300
Wire Wire Line
	3350 3150 2650 3150
Wire Wire Line
	2650 3150 2650 3300
Connection ~ 3000 2850
Wire Wire Line
	3000 2850 3000 4000
Wire Wire Line
	3000 4000 4300 4000
Wire Wire Line
	4300 4300 5150 4300
Wire Wire Line
	4300 4600 4300 4750
Connection ~ 3350 3150
Connection ~ 4700 3700
Connection ~ 3050 2850
Wire Wire Line
	3600 3500 4100 3500
Connection ~ 4050 3500
Wire Wire Line
	5150 4400 4550 4400
Wire Wire Line
	4550 4400 4550 5000
Wire Wire Line
	5150 4500 4800 4500
Wire Wire Line
	4800 4500 4800 5000
Wire Wire Line
	5200 4550 5200 5800
Wire Wire Line
	4100 2850 4100 2900
Connection ~ 4100 2850
Wire Wire Line
	4800 6200 3650 6200
Wire Wire Line
	3650 6200 3650 2850
Wire Wire Line
	5600 6200 5800 6200
Wire Wire Line
	5150 3500 4400 3500
Connection ~ 4450 3500
Wire Wire Line
	4700 3400 4700 2850
Wire Wire Line
	4700 3600 4700 3700
Wire Wire Line
	4150 4250 4150 3700
$Comp
L C_Small C?
U 1 1 5A06AB7D
P 4150 4350
F 0 "C?" H 4160 4420 50  0000 L CNN
F 1 "C_Small" H 4160 4270 50  0000 L CNN
F 2 "" H 4150 4350 50  0001 C CNN
F 3 "" H 4150 4350 50  0001 C CNN
	1    4150 4350
	-1   0    0    1   
$EndComp
$Comp
L C_Small C?
U 1 1 5A06ABD8
P 3800 4350
F 0 "C?" H 3810 4420 50  0000 L CNN
F 1 "C_Small" H 3810 4270 50  0000 L CNN
F 2 "" H 3800 4350 50  0001 C CNN
F 3 "" H 3800 4350 50  0001 C CNN
	1    3800 4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3650 4250 4150 4250
Connection ~ 3650 4250
Connection ~ 3800 4250
$Comp
L GND #PWR?
U 1 1 5A06AD2D
P 3800 4450
F 0 "#PWR?" H 3800 4200 50  0001 C CNN
F 1 "GND" H 3800 4300 50  0000 C CNN
F 2 "" H 3800 4450 50  0001 C CNN
F 3 "" H 3800 4450 50  0001 C CNN
	1    3800 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A06AD68
P 4150 4450
F 0 "#PWR?" H 4150 4200 50  0001 C CNN
F 1 "GND" H 4150 4300 50  0000 C CNN
F 2 "" H 4150 4450 50  0001 C CNN
F 3 "" H 4150 4450 50  0001 C CNN
	1    4150 4450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
