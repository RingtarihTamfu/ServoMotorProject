/* Author: Ringtarih Tamfu
 * 
 * Microprocessor Laboratory 6: Raspberry Pi 4 Code
 * 
 * Spring 2021 - EE 3420 - 001
 * 
 * Instructor: William Stapleton
 * 
 * Description: 
 */

//All Libraries used in this program
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pigpio.h>
#include "ee3420_pi.h"
#include "keypad4x4.h"
#include "character_lcd.h"

//State Functions
void PressedOne();
void PressedTwo();
void PressedThree();
void PressedA();
void PressedFour();
void PressedFive();
void PressedSix();
void PressedB();
void PressedZero();

//Varisables being used
time_t current_time;
time_t start_time;
time_t desired_duration;
char test_string[]="ONE:TWO:Three:Four:five:sIx:?\n";
char command_string[100];
char command_parameters[max_parameter_limit][max_parameter_length];

int main()
{
	//The ee3420_startup() function from ee3420_pi.h should be the first function called
	if(ee3420_startup() <0)
	{ return(ee3420_shutdown()); }	//if unable to intialize completely, end the program
	
	//demonstrating how a command string is parsed using a sample string
	printf("\nParsing test string into parameters ...\n");
	printf("%s",test_string);
	
	command_parameter_counter=parse_command_string(test_string,command_parameters, parameter_separators);
	
	for(int i=0; i<command_parameter_counter; i++)
	{
		if(command_parameters[i][0]=='\0') {break;}
		printf("%s\n",&command_parameters[i][0]);
	}
	printf("\n");
	
	printf("Standardizing parameters to uppercase\n");
	
	make_command_parameters_uppercase(command_parameters);
		
	for(int i=0; i<command_parameter_counter; i++)
	{
		if(command_parameters[i][0]=='\0') {break;}
		printf("%s\n",&command_parameters[i][0]);
	}
	
	
	/////////////////////////////////////////////////////////////////////////
	//MAIN DRIVER CODE	
	/////////////////////////////////////////////////////////////////////////
	
	int run = 1;
	
	while (run == 1)
	{
		sprintf(command_string, "KEYPAD:?\n");
		printf("Sending request ... %s",command_string);
		serial_send_request(serial_handle, command_string, serial_receive_buffer);
		printf("Response ...\n");
		printf("%s\n",serial_receive_buffer);
	
		//if(process_serial_response(serial_receive_buffer) < 0)
		//{
			//display_serial_device_error(serial_device.last_error_code);
		//}
		
		//This takes the char that was being returned by the command above and you can save it 
		//into a variable of your choice
		parse_command_string(serial_receive_buffer, serial_command_parameters, parameter_separators);
		make_command_parameters_uppercase(serial_command_parameters);
		
		char letter = serial_command_parameters[1][0];
		
		gpioDelay(250000);
		
		if (letter == '1')
		{
			PressedOne();
		}
		else if (letter == '2')
		{
			PressedTwo();
		}
		else if (letter == '3')
		{
			PressedThree();
		}
		else if (letter == 'A')
		{
			PressedA();
		}
		else if (letter == '4')
		{
			PressedFour();
		}
		else if (letter == '5')
		{
			PressedFive();
		}
		else if (letter == '6')
		{
			PressedSix();
		}
		else if (letter == 'B')
		{
			PressedB();
		}
		else if (letter == '0')
		{
			PressedZero();
		}
	}
	
	
	
	//Properly terminating everything
	gpioTerminate();
	return(ee3420_shutdown());
	
	return 0;
}

void PressedOne()
{
	sprintf(command_string, "SERVO:1\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedTwo()
{
	sprintf(command_string, "SERVO:10\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedThree()
{
	sprintf(command_string, "SERVO:100\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedA()
{
	sprintf(command_string, "SERVO:A\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedFour()
{
	sprintf(command_string, "SERVO:-1\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedFive()
{
	sprintf(command_string, "SERVO:-10\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedSix()
{
	sprintf(command_string, "SERVO:-100\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedB()
{
	sprintf(command_string, "SERVO:B\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

void PressedZero()
{
	sprintf(command_string, "SERVO:0\n");
	printf("Sending request ... %s",command_string);
	serial_send_request(serial_handle, command_string, serial_receive_buffer);
	printf("Response ...\n");
	printf("%s\n",serial_receive_buffer);
	
	if(process_serial_response(serial_receive_buffer) < 0)
	{
		display_serial_device_error(serial_device.last_error_code);
	}
}

