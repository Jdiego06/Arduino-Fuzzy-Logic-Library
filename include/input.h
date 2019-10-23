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
 *              This class defines the behavior of the system inputs
 * --------------------------------------------------------------------------------------*/

#ifndef INPUT_H
#define INPUT_H
#include "Sets.h"

#define MAX_INPUT_SETS 10

class Input
{
public:
    Input();
    Set * create_input_set(float p1, float p2, float p3, float p4);
    Set * create_input_set(float p1, float p2, float p3);
    void set_current_input_value(float value);
    void find_sets_phi();
private:
    int sets_number=0;
    Set * sets[MAX_INPUT_SETS];
    float current_input_value;
};

#endif // INPUT_H
