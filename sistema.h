#ifndef SISTEMA_H
#define SISTEMA_H


#include <vector>
#include <planeta.h>
#include <iostream>
using namespace std;

class sistema
{
    double axtotal=0;
    double aytotal=0;
    double dist=0;
    vector<planeta> misistema;
public:
    sistema();
    string sincronizar();
};

#endif // SISTEMA_H
