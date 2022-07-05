# copilot-arduino

###Use plans.md to document ideas / what's been ordered / who doing what

## Overall goals for drone:

- Lift off
- Stabilisation
- Movement

  1. Pre-programmed
  2. Radio control
  3. Autonomous

- Landing

Other considerations:

- Safety

  1.Prevent crashing
  2.Manual shut down button
  3.Prevent battery dying
  4.Auto return to home

Hardware:

- Flight controller - STM32F103C8T6
- IMU - MPU6050
- Radio - nrf24l01
- GPS - No clue
- Camera:

  - Microcomputer (i.e rPi) - image detection
  - Radio FPV - live feed
  - Cinematic - high res video recording

- Surroundings sensor:

  -Lidar / Sonar
  -Ultrasonic
  -Infrared
  -Visible (rpi?)

- Wires

  - Soldering
  - Breadboard testing

- PCB

- Motors
- ESCs
- Battery

- Frame

Cost: (Assume bought from aliexpress, else state)

FC ~ 5
IMU ~ 6
Radio ~ 5 (pair)
GPS ~

Camera ~ 4
Rpi ~ 20 (Amazon)
Surroundings sensor ~

Wires ~
PCB ~ 3.5

Motors, ESC's combo ~ 44
Propellors ~ 2.50
Frame ~ 18

Lipo Battery ~ 22 (2 pack) (Amazon)
Battery charger ~ 17 (Amazon)
Power Distribution board (PDB) ~ 4.50

##TODO:

1. Choose & order GPS
2. Control motors using uno
3. Calibrate IMU
4. Bidirectional radio communication test
5. PID algo for stabilisation using IMU
6. PID for movement
7.
8.
9.
10.
11.
12.
13.
14.
15.
16.
17.
18.
19.
20.
21.
22.
23.
24.
25.
