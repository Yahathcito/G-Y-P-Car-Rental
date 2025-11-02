#pragma once
#include "NodoColaborador.h"
#include "Colaborador.h"
#include "ContenedorContratoAlquiler.h"
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
    void reporteAlquileresPorColaborador(ContenedorContratoAlquiler* contenedorContratos);

	string toString();
};

