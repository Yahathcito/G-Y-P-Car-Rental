#pragma once
#include "NodoColaborador.h"
class ContenedorColaboradores
{
private:
    NodoColaborador* cabeza;

public:
    ContenedorColaboradores();
    ~ContenedorColaboradores();

    void agregarColaborador(Colaborador* colaborador);
    void eliminarColaborador(const string& id);
    Colaborador* buscarColaborador(const string& id);
    bool estaVacio() const;
	string toString();
};

