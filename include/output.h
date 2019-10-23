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
 *              This class defines the behavior of the system outputs
 * --------------------------------------------------------------------------------------*/

#ifndef OUTPUT_H
#define OUTPUT_H
#include "singleton.h"

#define MAX_OUTPUT_SETS 10

class Output
{
public:
    Output();
    Set * create_output_set(float p1);
    void calculate_output();
    float get_output();
    void clear_phi_x();
private:
    float actual_output=0;
    int sets_number=0;
    Set * sets[MAX_OUTPUT_SETS];

};

#endif // OUTPUT_H

