#include "input.h"

/*---------------------------------------------------------------------------------------
 *			                        Constructor
 * --------------------------------------------------------------------------------------*/
Input::Input()
{
}

/*---------------------------------------------------------------------------------------
 *     	                        Create input sets
 * --------------------------------------------------------------------------------------*/
Set *  Input::create_input_set(float p1, float p2, float p3, float p4)
{
    Set * new_set = new Polygon(p1,p2,p3,p4);
    this->sets[this->sets_number]=new_set;
    this->sets_number++;
    return new_set;
}

Set * Input::create_input_set(float p1, float p2, float p3)
{
    Set * new_set = new Triangle(p1,p2,p3);
    this->sets[this->sets_number]=new_set;
    this->sets_number++;
    return new_set;
}

/*---------------------------------------------------------------------------------------
 *                Find phi of each set based on current_input_value
 * --------------------------------------------------------------------------------------*/
void Input::find_sets_phi()
{
    for(int i=0; i< this->sets_number; i++)
    {
        this->sets[i]->find_phi_x(this->current_input_value);
    }
}


/*---------------------------------------------------------------------------------------
 *                                 Change input value
 * --------------------------------------------------------------------------------------*/
void Input::set_current_input_value(float value)
{
    this->current_input_value=value;
}

