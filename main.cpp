#include <iostream>
#include "RegularLine.h"

using namespace std;

int main()
{
    std::vector<int> vect1 = {1, 3, 1, 2};
    RegularLine regline1(vect1);
    Line line = regline1.getLine();
    std::cout << line.a << " " << line.b << " " << line.c <<std::endl;
    std::vector<int> vect2 = {1, 3453, 2 , 123};
    RegularLine regline2(vect2,regline1);
    line = regline2.getLine();
    std::cout << line.a << " " << line.b << " " << line.c <<std::endl;
    return 0;
}
