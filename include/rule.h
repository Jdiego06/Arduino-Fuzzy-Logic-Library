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
 *              This class defines the behavior of system rules
 * --------------------------------------------------------------------------------------*/

#ifndef RULE_H
#define RULE_H

#include "Set.h"

class Rule
{
public:
    Rule(Set * set_1, Set * output_set);
    Rule(Set * set_1, Set * set_2, Set * output_set);
    float calculate_rule_result();
    Set * get_output_set();
private:
    Set * set_1;
    Set * set_2;
    Set * output_set;
    int input_sets_number;
};

#endif // RULE_H

