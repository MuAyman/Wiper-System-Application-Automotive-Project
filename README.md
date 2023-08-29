# Wiper System Application Automotive Project

The system is composed of 3 inputs (wiper mode, rain sensor error, and wiper speed required) and two outputs (wiper motor PWM duty cycle, and wiper active flag)
   1. Wiper Mode has three modes which are off, auto, low speed, and high-speed mode
   2. Rain Sensor Error is a boolean
   3. Wiper Speed Required is 7 levels of speed follows that [0 0.40 0.45 0.50 0.55 0.60 0.65 0.70]

The system should be in off mode if the Rain Sensor Error is true. If not, it should follow the input signal in Wiper Mode. Low-Speed Mode is fixed at a speed of 0.4 and High-Speed Mode is fixed at a speed of 0.7. Auto Mode speed should follow the input signal Wiper Speed Required with smoothing the speed change.
