/*---------------------------------------------------------------------------------------
 *                     This is an example of the use of fuzzy control library
 * --------------------------------------------------------------------------------------*/

#include <iostream>
#include "fuzzy_logic.h"

using namespace std;

int main()
{
    // Create fuzzy logic object
    Fuzzy_Logic Fuzzy_Machine;

    // Create inputs set objects
    Input * Error = Fuzzy_Machine.create_input();
    Input * Derivate = Fuzzy_Machine.create_input();

    // Create outputs set objects
    Output * Pwm = Fuzzy_Machine.create_output();


    //Set sets to input objects
    Set * Low_Error = Fuzzy_Machine.create_input_set(Error, -1, 0, 1);
    Set * High_Error = Fuzzy_Machine.create_input_set(Error, 2, 10, 20,100);
    Set* Low_Derivate = Fuzzy_Machine.create_input_set(Derivate, -0.1, 0, 0.1);


    //Set sets to output objects
    Set * High_Pwm = Fuzzy_Machine.create_output_set(Pwm,100);
    Set * Medium_Pwm = Fuzzy_Machine.create_output_set(Pwm,50);
    Set * Low_Pwm = Fuzzy_Machine.create_output_set(Pwm,10);


    //Create rules
    Fuzzy_Machine.create_rule(High_Error,High_Pwm);
    Fuzzy_Machine.create_rule(Low_Error,Low_Derivate,Medium_Pwm);


    //Set actual values to inputs
    float actual_error = 0.1 ;
    float actual_derivate = 0;

    Fuzzy_Machine.set_input_value(Error,actual_error);
    Fuzzy_Machine.set_input_value(Derivate,actual_derivate);


    //Defuzzificación
    Fuzzy_Machine.deffuzy();


    //Get Output
    float Control=Fuzzy_Machine.get_output_result(Pwm);

    cout << "Run Success, result: ";
    cout << Control << endl;

    return 0;
}
