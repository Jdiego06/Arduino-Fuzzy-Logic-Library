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
 *        This class defines the behavior and overall shape of all sets.
 * --------------------------------------------------------------------------------------*/

#ifndef SET_H
#define SET_H

using namespace std;

class Set
{
public:
    virtual void find_phi_x(float x)=0;
    virtual float get_phi_x()=0;
    float get_p1()
    {
        return p1;
    }
protected:
    float p1,p2,p3,p4=0;
    float phi_x=0;
};


#endif // SET_H
