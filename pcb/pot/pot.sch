EESchema Schematic File Version 2
LIBS:pot-rescue
LIBS:power
LIBS:device
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
LIBS:pot-cache
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
L RJ45_LEDS-RESCUE-pot-RESCUE-pot J1
U 1 1 5951851F
P 4250 2900
F 0 "J1" H 4250 2400 50  0000 C CNN
F 1 "Bus" H 4250 3300 50  0000 C CNN
F 2 "Connect:RJHSE538X" H 4250 2850 50  0001 C CNN
F 3 "" H 4250 2850 50  0000 C CNN
	1    4250 2900
	1    0    0    -1  
$EndComp
NoConn ~ 4550 3400
$Comp
L +12V #PWR01
U 1 1 59518AE4
P 1700 3600
F 0 "#PWR01" H 1700 3450 50  0001 C CNN
F 1 "+12V" H 1700 3740 50  0000 C CNN
F 2 "" H 1700 3600 50  0000 C CNN
F 3 "" H 1700 3600 50  0000 C CNN
	1    1700 3600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 59518B1B
P 1700 3900
F 0 "#PWR02" H 1700 3750 50  0001 C CNN
F 1 "+5V" H 1700 4040 50  0000 C CNN
F 2 "" H 1700 3900 50  0000 C CNN
F 3 "" H 1700 3900 50  0000 C CNN
	1    1700 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 59518B45
P 1700 4200
F 0 "#PWR03" H 1700 3950 50  0001 C CNN
F 1 "GND" H 1700 4050 50  0000 C CNN
F 2 "" H 1700 4200 50  0000 C CNN
F 3 "" H 1700 4200 50  0000 C CNN
	1    1700 4200
	1    0    0    -1  
$EndComp
$Comp
L PCF8574 U1
U 1 1 59518F2E
P 5550 5900
F 0 "U1" H 5200 6500 50  0000 L CNN
F 1 "PCF8574" H 5650 6500 50  0000 L CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 5550 5900 50  0001 C CNN
F 3 "" H 5550 5900 50  0000 C CNN
	1    5550 5900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 595192C3
P 5550 6600
F 0 "#PWR04" H 5550 6350 50  0001 C CNN
F 1 "GND" H 5550 6450 50  0000 C CNN
F 2 "" H 5550 6600 50  0000 C CNN
F 3 "" H 5550 6600 50  0000 C CNN
	1    5550 6600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR05
U 1 1 595192DD
P 5550 5200
F 0 "#PWR05" H 5550 5050 50  0001 C CNN
F 1 "+5V" H 5550 5340 50  0000 C CNN
F 2 "" H 5550 5200 50  0000 C CNN
F 3 "" H 5550 5200 50  0000 C CNN
	1    5550 5200
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG06
U 1 1 59519575
P 1400 3600
F 0 "#FLG06" H 1400 3695 50  0001 C CNN
F 1 "PWR_FLAG" H 1400 3780 50  0000 C CNN
F 2 "" H 1400 3600 50  0000 C CNN
F 3 "" H 1400 3600 50  0000 C CNN
	1    1400 3600
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG07
U 1 1 5951958F
P 1400 3900
F 0 "#FLG07" H 1400 3995 50  0001 C CNN
F 1 "PWR_FLAG" H 1400 4080 50  0000 C CNN
F 2 "" H 1400 3900 50  0000 C CNN
F 3 "" H 1400 3900 50  0000 C CNN
	1    1400 3900
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG08
U 1 1 595195A9
P 1400 4200
F 0 "#FLG08" H 1400 4295 50  0001 C CNN
F 1 "PWR_FLAG" H 1400 4380 50  0000 C CNN
F 2 "" H 1400 4200 50  0000 C CNN
F 3 "" H 1400 4200 50  0000 C CNN
	1    1400 4200
	1    0    0    -1  
$EndComp
NoConn ~ 6050 5800
NoConn ~ 6050 5900
NoConn ~ 6050 6000
NoConn ~ 6050 6100
NoConn ~ 6050 6200
NoConn ~ 5050 6300
NoConn ~ 3850 2400
NoConn ~ 3950 2400
$Comp
L R R1
U 1 1 595198B4
P 4850 2200
F 0 "R1" V 4930 2200 50  0000 C CNN
F 1 "680" V 4850 2200 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Box_L13.0mm_W4.0mm_P9.00mm" V 4780 2200 50  0001 C CNN
F 3 "" H 4850 2200 50  0000 C CNN
	1    4850 2200
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR09
U 1 1 5951A410
P 4550 2200
F 0 "#PWR09" H 4550 2050 50  0001 C CNN
F 1 "+5V" H 4550 2340 50  0000 C CNN
F 2 "" H 4550 2200 50  0000 C CNN
F 3 "" H 4550 2200 50  0000 C CNN
	1    4550 2200
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P1
U 1 1 5951A793
P 6850 3050
F 0 "P1" H 6850 3300 50  0000 C CNN
F 1 "Sensor" V 6950 3050 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_S04B-XH-A_04x2.50mm_Angled" H 6850 3050 50  0001 C CNN
F 3 "" H 6850 3050 50  0000 C CNN
	1    6850 3050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 5951ABC7
P 6550 2900
F 0 "#PWR010" H 6550 2750 50  0001 C CNN
F 1 "+5V" H 6550 3040 50  0000 C CNN
F 2 "" H 6550 2900 50  0000 C CNN
F 3 "" H 6550 2900 50  0000 C CNN
	1    6550 2900
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5951AE98
P 7600 4250
F 0 "R4" V 7680 4250 50  0000 C CNN
F 1 "100k" V 7600 4250 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Box_L13.0mm_W4.0mm_P9.00mm" V 7530 4250 50  0001 C CNN
F 3 "" H 7600 4250 50  0000 C CNN
	1    7600 4250
	1    0    0    -1  
$EndComp
$Comp
L BC237 Q2
U 1 1 5951B024
P 7900 3950
F 0 "Q2" H 8100 4025 50  0000 L CNN
F 1 "2N3904" H 8100 3950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 8100 3875 50  0000 L CIN
F 3 "" H 7900 3950 50  0000 L CNN
	1    7900 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5951B160
P 8000 4250
F 0 "#PWR011" H 8000 4000 50  0001 C CNN
F 1 "GND" H 8000 4100 50  0000 C CNN
F 2 "" H 8000 4250 50  0000 C CNN
F 3 "" H 8000 4250 50  0000 C CNN
	1    8000 4250
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5951B1C4
P 8500 3350
F 0 "R3" V 8580 3350 50  0000 C CNN
F 1 "680" V 8500 3350 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Box_L13.0mm_W4.0mm_P9.00mm" V 8430 3350 50  0001 C CNN
F 3 "" H 8500 3350 50  0000 C CNN
	1    8500 3350
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5951B3D8
P 8500 3800
F 0 "R2" V 8580 3800 50  0000 C CNN
F 1 "100k" V 8500 3800 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Box_L13.0mm_W4.0mm_P9.00mm" V 8430 3800 50  0001 C CNN
F 3 "" H 8500 3800 50  0000 C CNN
	1    8500 3800
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR012
U 1 1 5951B4D3
P 8650 3950
F 0 "#PWR012" H 8650 3800 50  0001 C CNN
F 1 "+5V" H 8650 4090 50  0000 C CNN
F 2 "" H 8650 3950 50  0000 C CNN
F 3 "" H 8650 3950 50  0000 C CNN
	1    8650 3950
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q1
U 1 1 5951B683
P 8700 3150
F 0 "Q1" H 9000 3200 50  0000 R CNN
F 1 "IRLZ44N" H 9350 3100 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 8900 3250 50  0001 C CNN
F 3 "" H 8700 3150 50  0000 C CNN
	1    8700 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5951B922
P 8800 3450
F 0 "#PWR013" H 8800 3200 50  0001 C CNN
F 1 "GND" H 8800 3300 50  0000 C CNN
F 2 "" H 8800 3450 50  0000 C CNN
F 3 "" H 8800 3450 50  0000 C CNN
	1    8800 3450
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR014
U 1 1 5951BC41
P 8500 2500
F 0 "#PWR014" H 8500 2350 50  0001 C CNN
F 1 "+12V" H 8500 2640 50  0000 C CNN
F 2 "" H 8500 2500 50  0000 C CNN
F 3 "" H 8500 2500 50  0000 C CNN
	1    8500 2500
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 5951BCB9
P 8400 2650
F 0 "D1" H 8400 2750 50  0000 C CNN
F 1 "1N4007" H 8400 2550 50  0000 C CNN
F 2 "Diodes_ThroughHole:D_A-405_P7.62mm_Horizontal" H 8400 2650 50  0001 C CNN
F 3 "" H 8400 2650 50  0000 C CNN
	1    8400 2650
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 5951C927
P 2450 4050
F 0 "C1" H 2475 4150 50  0000 L CNN
F 1 "100nF" H 2475 3950 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 2488 3900 50  0001 C CNN
F 3 "" H 2450 4050 50  0000 C CNN
	1    2450 4050
	1    0    0    -1  
$EndComp
$Comp
L JUMPER3 JP1
U 1 1 5952249E
P 4400 5550
F 0 "JP1" H 4450 5450 50  0000 L CNN
F 1 "A0" H 4400 5650 50  0000 C BNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4400 5550 50  0001 C CNN
F 3 "" H 4400 5550 50  0000 C CNN
	1    4400 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 59522647
P 4650 5550
F 0 "#PWR015" H 4650 5300 50  0001 C CNN
F 1 "GND" H 4650 5400 50  0000 C CNN
F 2 "" H 4650 5550 50  0000 C CNN
F 3 "" H 4650 5550 50  0000 C CNN
	1    4650 5550
	1    0    0    -1  
$EndComp
$Comp
L JUMPER3 JP2
U 1 1 59522EB2
P 4400 6050
F 0 "JP2" H 4450 5950 50  0000 L CNN
F 1 "A1" H 4400 6150 50  0000 C BNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4400 6050 50  0001 C CNN
F 3 "" H 4400 6050 50  0000 C CNN
	1    4400 6050
	1    0    0    -1  
$EndComp
$Comp
L JUMPER3 JP3
U 1 1 59522EF3
P 4400 6500
F 0 "JP3" H 4450 6400 50  0000 L CNN
F 1 "A2" H 4400 6600 50  0000 C BNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4400 6500 50  0001 C CNN
F 3 "" H 4400 6500 50  0000 C CNN
	1    4400 6500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 59523026
P 4650 6500
F 0 "#PWR016" H 4650 6250 50  0001 C CNN
F 1 "GND" H 4650 6350 50  0000 C CNN
F 2 "" H 4650 6500 50  0000 C CNN
F 3 "" H 4650 6500 50  0000 C CNN
	1    4650 6500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 5952305A
P 4650 6050
F 0 "#PWR017" H 4650 5800 50  0001 C CNN
F 1 "GND" H 4650 5900 50  0000 C CNN
F 2 "" H 4650 6050 50  0000 C CNN
F 3 "" H 4650 6050 50  0000 C CNN
	1    4650 6050
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 59523656
P 3800 5550
F 0 "R5" V 3880 5550 50  0000 C CNN
F 1 "100k" V 3800 5550 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Box_L13.0mm_W4.0mm_P9.00mm" V 3730 5550 50  0001 C CNN
F 3 "" H 3800 5550 50  0000 C CNN
	1    3800 5550
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR018
U 1 1 5952387D
P 3650 5550
F 0 "#PWR018" H 3650 5400 50  0001 C CNN
F 1 "+5V" H 3650 5690 50  0000 C CNN
F 2 "" H 3650 5550 50  0000 C CNN
F 3 "" H 3650 5550 50  0000 C CNN
	1    3650 5550
	1    0    0    -1  
$EndComp
$Comp
L BARREL_JACK CON1
U 1 1 59522F91
P 7850 2700
F 0 "CON1" H 7850 2950 50  0000 C CNN
F 1 "Valve" H 7850 2500 50  0000 C CNN
F 2 "Connect:BARREL_JACK" H 7850 2700 50  0001 C CNN
F 3 "" H 7850 2700 50  0000 C CNN
	1    7850 2700
	1    0    0    -1  
$EndComp
NoConn ~ 8150 2700
$Comp
L GND #PWR019
U 1 1 5952E752
P 6550 3100
F 0 "#PWR019" H 6550 2850 50  0001 C CNN
F 1 "GND" H 6550 2950 50  0000 C CNN
F 2 "" H 6550 3100 50  0000 C CNN
F 3 "" H 6550 3100 50  0000 C CNN
	1    6550 3100
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5952EC88
P 6250 3600
F 0 "R6" V 6330 3600 50  0000 C CNN
F 1 "100k" V 6250 3600 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Box_L13.0mm_W4.0mm_P9.00mm" V 6180 3600 50  0001 C CNN
F 3 "" H 6250 3600 50  0000 C CNN
	1    6250 3600
	1    0    0    -1  
$EndComp
$Comp
L JUMPER JP4
U 1 1 59530192
P 5000 2850
F 0 "JP4" H 5000 3000 50  0000 C CNN
F 1 "LED" H 5000 2770 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x01_Pitch2.54mm" H 5000 2850 50  0001 C CNN
F 3 "" H 5000 2850 50  0000 C CNN
	1    5000 2850
	0    1    1    0   
$EndComp
$Comp
L BC237 Q3
U 1 1 59535056
P 6250 3100
F 0 "Q3" H 6450 3175 50  0000 L CNN
F 1 "2N3904" H 6450 3100 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 6450 3025 50  0000 L CIN
F 3 "" H 6250 3100 50  0000 L CNN
	1    6250 3100
	0    -1   -1   0   
$EndComp
$Comp
L FUSE F1
U 1 1 59537D6E
P 2100 3600
F 0 "F1" H 2200 3650 50  0000 C CNN
F 1 "0.5A" H 2000 3550 50  0000 C CNN
F 2 "Fuse_Holders_and_Fuses:Fuse_TE5_Littlefuse-395Series" H 2100 3600 50  0001 C CNN
F 3 "" H 2100 3600 50  0000 C CNN
	1    2100 3600
	1    0    0    -1  
$EndComp
$Comp
L FUSE F2
U 1 1 59537F73
P 2100 3900
F 0 "F2" H 2200 3950 50  0000 C CNN
F 1 "50mA" H 2000 3850 50  0000 C CNN
F 2 "Fuse_Holders_and_Fuses:Fuse_TE5_Littlefuse-395Series" H 2100 3900 50  0001 C CNN
F 3 "" H 2100 3900 50  0000 C CNN
	1    2100 3900
	1    0    0    -1  
$EndComp
$Comp
L RJ45_LEDS-RESCUE-pot-RESCUE-pot J2
U 1 1 59541C7B
P 2900 2900
F 0 "J2" H 2900 2400 50  0000 C CNN
F 1 "Bus" H 2900 3300 50  0000 C CNN
F 2 "Connect:RJHSE538X" H 2900 2850 50  0001 C CNN
F 3 "" H 2900 2850 50  0000 C CNN
	1    2900 2900
	1    0    0    -1  
$EndComp
NoConn ~ 3200 3400
NoConn ~ 3300 2400
NoConn ~ 3200 2400
NoConn ~ 2600 2400
NoConn ~ 2500 2400
Wire Wire Line
	1400 3600 1850 3600
Wire Wire Line
	2350 3600 3950 3600
Wire Wire Line
	3850 3600 3850 3400
Wire Wire Line
	3950 3600 3950 3400
Connection ~ 3850 3600
Wire Wire Line
	4050 3900 4050 3400
Wire Wire Line
	1400 4200 4350 4200
Wire Wire Line
	4150 4200 4150 3400
Wire Wire Line
	4350 4200 4350 3400
Connection ~ 4150 4200
Wire Wire Line
	2500 3600 2500 3400
Wire Wire Line
	2600 3600 2600 3400
Connection ~ 2500 3600
Wire Wire Line
	2700 3900 2700 3400
Wire Wire Line
	1400 3900 1850 3900
Wire Wire Line
	2350 3900 4050 3900
Wire Wire Line
	2800 4200 2800 3400
Connection ~ 2800 4200
Connection ~ 1700 4200
Connection ~ 1700 3900
Connection ~ 1700 3600
Wire Wire Line
	4550 2200 4550 2400
Wire Wire Line
	4700 2200 4650 2200
Wire Wire Line
	4650 2200 4650 2400
Wire Wire Line
	6650 2900 6550 2900
Wire Wire Line
	6150 4650 5000 4650
Wire Wire Line
	6050 5500 6350 5500
Wire Wire Line
	6350 5500 6350 4650
Wire Wire Line
	4900 5500 5050 5500
Wire Wire Line
	4900 4400 4900 5500
Connection ~ 4900 4400
Wire Wire Line
	5050 5600 4800 5600
Wire Wire Line
	4800 5600 4800 4300
Connection ~ 4800 4300
Wire Wire Line
	4450 3400 4450 4400
Connection ~ 4450 4400
Wire Wire Line
	5050 5800 4400 5800
Wire Wire Line
	4400 5800 4400 5650
Wire Wire Line
	4400 6150 4400 6250
Wire Wire Line
	4400 6250 4800 6250
Wire Wire Line
	4800 6250 4800 5900
Wire Wire Line
	4800 5900 5050 5900
Wire Wire Line
	4400 6600 4400 6750
Wire Wire Line
	4400 6750 4900 6750
Wire Wire Line
	4900 6750 4900 6000
Wire Wire Line
	4900 6000 5050 6000
Wire Wire Line
	3950 5550 4150 5550
Wire Wire Line
	4150 6050 4050 6050
Wire Wire Line
	4050 5550 4050 6500
Connection ~ 4050 5550
Wire Wire Line
	4050 6500 4150 6500
Connection ~ 4050 6050
Wire Wire Line
	8000 4150 8000 4250
Wire Wire Line
	7600 4100 7600 3950
Wire Wire Line
	7600 3950 7700 3950
Wire Wire Line
	6350 4650 7600 4650
Wire Wire Line
	7600 4650 7600 4400
Wire Wire Line
	8500 3950 8650 3950
Wire Wire Line
	8500 3500 8500 3650
Wire Wire Line
	8000 3750 8000 3600
Connection ~ 8500 3600
Wire Wire Line
	8000 3600 8500 3600
Wire Wire Line
	8500 3150 8500 3200
Wire Wire Line
	8800 3350 8800 3450
Wire Wire Line
	8150 2600 8150 2500
Wire Wire Line
	8150 2800 8800 2800
Wire Wire Line
	8800 2800 8800 2950
Connection ~ 8400 2800
Wire Wire Line
	4650 3400 4650 4300
Connection ~ 4650 4300
Wire Wire Line
	6650 4400 6650 3200
Wire Wire Line
	6650 3100 6550 3100
Wire Wire Line
	6650 3000 6450 3000
Wire Wire Line
	6050 4300 6050 3000
Wire Wire Line
	6250 3300 6250 3450
Wire Wire Line
	6250 5600 6050 5600
Wire Wire Line
	6250 3750 6250 5600
Wire Wire Line
	5000 2200 5000 2550
Wire Wire Line
	5000 4650 5000 3150
Connection ~ 2600 3600
Connection ~ 2700 3900
Wire Wire Line
	8150 2500 8500 2500
Connection ~ 8400 2500
Connection ~ 2450 3900
Connection ~ 2450 4200
Wire Wire Line
	3000 3400 3000 4200
Connection ~ 3000 4200
Wire Wire Line
	3100 3400 3100 4400
Wire Wire Line
	3100 4400 6650 4400
Wire Wire Line
	3300 3400 3300 4300
Wire Wire Line
	3300 4300 6050 4300
Wire Wire Line
	3650 2700 3500 2700
NoConn ~ 4850 2700
NoConn ~ 2300 2700
NoConn ~ 6050 5700
Wire Wire Line
	6150 4650 6150 5600
Connection ~ 6150 5600
$EndSCHEMATC
