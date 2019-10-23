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
 *              This class defines the behavior of the triangle set
 * --------------------------------------------------------------------------------------*/
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Set.h"

class Triangle: public Set
{
public:
    Triangle(float p1, float p2, float p3);
    void find_phi_x(float x) override;
    float get_phi_x() override;
};

#endif // TRIANGLE_H
