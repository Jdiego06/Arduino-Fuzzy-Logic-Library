# Fuzzy logic C++ library

This class allows you to create an object of fuzzy logic type,
supports the creation of multiple inputs, outputs, and sets for
each of them, as well as the creation of multiple rules.
allows defuzzification, and find the current value of the outputs,
based on the current value of the inputs, and the defined rules.

# Example

	#include "Fuzzy_logic.h"

	  // Create fuzzy logic object
	  Fuzzy_Logic Fuzzy_Machine;

	  // Create inputs set objects
	  Input *Error = Fuzzy_Machine.create_input();
	  Input *Derivate = Fuzzy_Machine.create_input();

	  // Create outputs set objects
	  Output *Pwm = Fuzzy_Machine.create_output();

	  //Set sets to input objects
	  Set *Low_Error = Fuzzy_Machine.create_input_set(Error, -1, 0, 1);
	  Set *High_Error = Fuzzy_Machine.create_input_set(Error, 2, 10, 20, 100);
	  Set *Low_Derivate = Fuzzy_Machine.create_input_set(Derivate, -0.1, 0, 0.1);

	  //Set sets to output objects
	  Set *High_Pwm = Fuzzy_Machine.create_output_set(Pwm, 100);
	  Set *Medium_Pwm = Fuzzy_Machine.create_output_set(Pwm, 50);
	  Set *Low_Pwm = Fuzzy_Machine.create_output_set(Pwm, 10);


	void setup()
	{
	  Serial.begin(9600);

	  //Create rules
	  Fuzzy_Machine.create_rule(High_Error, High_Pwm);
	  Fuzzy_Machine.create_rule(Low_Error, Low_Derivate, Medium_Pwm);
	}


	void loop()
	{
	  //Set actual values to inputs
	  float actual_error = 0.1;
	  float actual_derivate = 0;

	  Serial.println(actual_error);
	  Serial.println(actual_derivate);


	  Fuzzy_Machine.set_input_value(Error, actual_error);
	  Fuzzy_Machine.set_input_value(Derivate, actual_derivate);

	  //Defuzzificación
	  Fuzzy_Machine.deffuzy();

	  //Get Output
	  float Control = Fuzzy_Machine.get_output_result(Pwm);
	  Serial.println(Control);
	  Serial.println("");
	  delay(10000);
	}


# BEER WARE
jd99@outlook.com> written this file. As long as you retain this notice you can do whatever you want with this  stuff. If we meet some day, and you think this stuff is worth it, you can  buy me a beer in return. Juan-Cardona
