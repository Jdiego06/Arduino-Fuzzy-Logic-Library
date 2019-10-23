#include "rule.h"

/*---------------------------------------------------------------------------------------
 *                             Constructor(s)
 * --------------------------------------------------------------------------------------*/
Rule::Rule(Set * set_1, Set * output_set)
{
    this->input_sets_number=1;

    this->set_1=set_1;
    this->output_set=output_set;
}

Rule::Rule(Set * set_1, Set * set_2, Set * output_set)
{
    this->input_sets_number=2;

    this->set_1=set_1;
    this->set_2=set_2;
    this->output_set=output_set;
}

/*---------------------------------------------------------------------------------------
 *                   Calculate rule result based on sets
 * --------------------------------------------------------------------------------------*/
float Rule::calculate_rule_result()
{

    float rule_result=0;
    switch (this->input_sets_number)
    {
    case 1:
        rule_result=this->set_1->get_phi_x();
        break;
    case 2:
        float result_1= this->set_1->get_phi_x();
        float result_2= this->set_2->get_phi_x();

        if(result_1<result_2)
        {
            rule_result=result_1;
        }
        else
        {
            rule_result=result_2;
        }
        break;
    }
    return rule_result;
}

/*---------------------------------------------------------------------------------------
 *                               Get output set of a rule
 * --------------------------------------------------------------------------------------*/
Set * Rule::get_output_set()
{
    return this->output_set;
}

