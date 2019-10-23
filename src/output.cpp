#include "output.h"

/*---------------------------------------------------------------------------------------
 *                                Constructor
 * --------------------------------------------------------------------------------------*/
Output::Output()
{
    //ctor
}


/*---------------------------------------------------------------------------------------
 *     	                        Create output sets
 * --------------------------------------------------------------------------------------*/
Set * Output::create_output_set(float p1)
{
    Set * new_set = new Singleton(p1);
    this->sets[this->sets_number]= new_set;
    sets_number++;
    return new_set;
}

/*---------------------------------------------------------------------------------------
 *           Calculate new output value based on phi_x of each output sets
 * --------------------------------------------------------------------------------------*/
void Output::calculate_output()
{
    float numerator = 0;
    float denominator=0;

    for(int i=0; i<this->sets_number; i++)
    {
        numerator+=(this->sets[i]->get_phi_x()*this->sets[i]->get_p1());
        denominator+=this->sets[i]->get_phi_x();
    }

    if(denominator==0)
    {
        this->actual_output=0;
    }
    else
    {
        this->actual_output=numerator/denominator;
    }
}


/*---------------------------------------------------------------------------------------
 *                        Set to 0 phi_x of each set output sets
 * --------------------------------------------------------------------------------------*/
void Output::clear_phi_x()
{
    for(int i=0; i<this->sets_number; i++)
    {
        this->sets[i]->find_phi_x(0);
    }
}


/*---------------------------------------------------------------------------------------
 *                                Return actual output
 * --------------------------------------------------------------------------------------*/
float Output::get_output()
{
    return this->actual_output;
}

