#pragma once
#include "Cliente.h"
#include <string>
#include <sstream>
using namespace std;

class ClienteNormal : public Cliente {
public:
    ClienteNormal(string nombre, string id, string paisResidencia);
    virtual string toString();
    virtual string getTipo(); 
};
