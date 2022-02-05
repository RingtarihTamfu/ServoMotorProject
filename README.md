# ServoMotorProject
This project interfaced a Raspberry Pi 4 and an Arduino Mega to control a Servo Motor, Character LCD and a 4x4 Keypad. using UART.

Summary: 
The Raspberry Pi 4 continuously requests what key is being pressed on the 4x4 Keypad on the Arduino Mega. WHen a key is pressed, the Arduino sends the character of the key that was pressed to the Raspberry Pi 4. The Raspberry Pi then takes this key and requests to set the PWM value of the servo motors, increment or decrement the values of the PWM values. The instructions goes as follows.
               - If 1 is pressed, the PWM signal for the servo motor is increased by +1
               - If 2 is pressed, the PWM signal for the servo motor is increased by +10
               - If 3 is pressed, the PWM signal for the servo motor is increased by +100 
               - If A is pressed, the PWM signal for the servo motor is set to 2000
               - If 4 is pressed, the PWM signal for the servo motor is decreased by -1
               - If 5 is pressed, the PWM signal for the servo motor is decreased by -10
               - If 6 is pressed, the PWM signal for the servo motor is decreased by -100
               - If B is pressed, the PWM signal for the servo motor is set to 1000
               - If 0 is pressed, the PWM signal for the servo motor is set to 1500
