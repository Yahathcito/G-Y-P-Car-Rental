#pragma once
#include "Cliente.h"
#include <string>
#include <sstream>
using namespace std;

class ClienteJuridico : public Cliente {
private:
    string actividadEconomica;
public:
    ClienteJuridico(string nombre, string id, string paisResidencia, string actividadEconomica);

    void setActividadEconomica(string);
    string getActividadEconomica();
    virtual string getTipo(); 
    virtual string toString();
};

