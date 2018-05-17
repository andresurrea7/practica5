#include <iostream>
#include <fstream>
#include "sistema.h"
#include <math.h>
using namespace std;

int main()
{
    sistema lactea;
    ofstream a;
//    cout<<cos(1.57065347*3.1416/180.0)<<endl;

    a.open("calculos1.txt");
    for(int i=0;i<10000;i++){
        a<<lactea.sincronizar()<<endl;
    }
    a.close();
    return 0;
}
