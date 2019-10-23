#include "fuzzy_logic.h"

/*---------------------------------------------------------------------------------------
 *			                        Constructor
 * --------------------------------------------------------------------------------------*/
Fuzzy_Logic::Fuzzy_Logic()
{

}

/*---------------------------------------------------------------------------------------
 *			                Create input type object
 * --------------------------------------------------------------------------------------*/
Input *  Fuzzy_Logic::create_input()
{
    Input * new_input = new Input();
    this->inputs[this->input_number]=new_input;
    this->input_number++;
    return new_input;
}

/*---------------------------------------------------------------------------------------
 *			                Create output type object
 * --------------------------------------------------------------------------------------*/
Output * Fuzzy_Logic::create_output()
{
    Output * new_output = new Output();
    this->outputs[this->output_number]=new_output;
    this->output_number++;
    return new_output;
}


/*---------------------------------------------------------------------------------------
 *			                Create rule type object(s)
 * --------------------------------------------------------------------------------------*/
void Fuzzy_Logic::create_rule(Set * set_1, Set * output_set)
{
    Rule *  new_rule = new Rule(set_1,output_set);
    this->rules[this->rules_number]=new_rule;
    this->rules_number++;
}


void Fuzzy_Logic::create_rule(Set * set_1, Set * set_2,Set * output_set)
{
    Rule *  new_rule = new Rule(set_1,set_2,output_set);
    this->rules[this->rules_number]=new_rule;
    this->rules_number++;
}


/*---------------------------------------------------------------------------------------
 *			           Create Set(s) type object for inputs and outputs
 * --------------------------------------------------------------------------------------*/
Set * Fuzzy_Logic::create_input_set(Input * input, float p1,float p2, float p3, float p4)
{
    Set * new_set  = input->create_input_set(p1,p2,p3,p4);
    return new_set;
}

Set * Fuzzy_Logic::create_input_set(Input * input, float p1,float p2, float p3)
{
    Set * new_set  = input->create_input_set(p1,p2,p3);
    return new_set;
}


Set * Fuzzy_Logic::create_output_set(Output * output, float p1)
{
    Set * new_set=output->create_output_set(p1);
    return new_set;
}


/*---------------------------------------------------------------------------------------
 *			                 Set current value of an input
 * --------------------------------------------------------------------------------------*/
void Fuzzy_Logic::set_input_value(Input * input, float value)
{
    input->set_current_input_value(value);
}

/*---------------------------------------------------------------------------------------
 *	                              Defuzzification process
 * --------------------------------------------------------------------------------------*/
void Fuzzy_Logic::deffuzy()
{

    // Find phi of each set of each input
    for (int i=0; i < this->input_number; i++)
    {
        this->inputs[i]->find_sets_phi();
    }

    // Reset to 0 phi of all sets of each output
    for (int i=0; i < this->output_number; i++)
    {
        this->outputs[i]->clear_phi_x();
    }


    //replace phi of sets outputs with max value of rules
    for(int i = 0 ; i < this->rules_number ; i++)
    {
        float rule_result = this->rules[i]->calculate_rule_result();
        float actual_phi_set=rules[i]->get_output_set()->get_phi_x();

        if(rule_result>actual_phi_set)
        {
            rules[i]->get_output_set()->find_phi_x(rule_result);
        }
    }

}


/*---------------------------------------------------------------------------------------
 *               Calculate and return the value of an output
 * --------------------------------------------------------------------------------------*/
float Fuzzy_Logic::get_output_result(Output * output)
{
    output->calculate_output();
    return output->get_output();
}
