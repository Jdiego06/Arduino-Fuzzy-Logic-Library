/*---------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <jd99@outlook.com> written this file.
 * As long as you retain this notice you can do whatever you want with this
 * stuff. If we meet some day, and you think this stuff is worth it, you can
 * buy me a beer in return. Juan-Cardona
 * --------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
 * Ing: Juan Diego Cardona
 * Company: UCO
 * Date: 23-10-2019
 * Project: Fuzzy Control
 * Description:
 *              This class allows you to create an object of fuzzy logic type,
 *              supports the creation of multiple inputs, outputs, and sets for
 *              each of them, as well as the creation of multiple rules.
 *              allows defuzzification, and find the current value of the outputs,
 *              based on the current value of the inputs, and the defined rules.
 * --------------------------------------------------------------------------------------*/


#ifndef FUZZY_LOGIC_H
#define FUZZY_LOGIC_H

#include "sets.h"
#include "input.h"
#include "output.h"
#include "rule.h"

#define MAX_RULES 10
#define MAX_INPUTS 10
#define MAX_OUTPUTS 10

class Fuzzy_Logic
{
public:
    Fuzzy_Logic();
    Input * create_input();
    Output * create_output();
    void create_rule(Set * set_1, Set * output_set);
    void create_rule(Set * set_1, Set * set_2, Set * output_set);
    Set * create_input_set(Input * input, float p1,float p2,float p3, float p4);
    Set * create_input_set(Input * input, float p1,float p2, float p3);
    Set * create_output_set(Output * output, float p1);
    void set_input_value(Input * input, float value);
    void deffuzy();
    float get_output_result(Output * output);
private:
    Rule * rules[MAX_RULES];
    Input * inputs[MAX_INPUTS];
    Output * outputs[MAX_OUTPUTS];
    int input_number=0;
    int rules_number=0;
    int output_number=0;
};

#endif // FUZZY_LOGIC_H
