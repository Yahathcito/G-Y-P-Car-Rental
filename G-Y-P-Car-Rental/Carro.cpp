#include "Carro.h"

Carro::Carro(string placa, int modelo, string marca, string tipo) {
    this->placa = placa;
    this->modelo = modelo;
    this->marca = marca;
    this->tipo = tipo;
}

void Carro::setPlaca(string p) {
    placa = p;
}

void Carro::setModelo(int m) {
    modelo = m;
}

void Carro::setMarca(string m) {
    marca = m;
}

void Carro::setTipo(string t) {
    tipo = t;
}

string Carro::getPlaca() {
    return placa;
}

int Carro::getModelo() {
    return modelo;
}

string Carro::getMarca() {
    return marca;
}

string Carro::getTipo() {
    return tipo;
}

string Carro::toString() {
    stringstream s;
    s << "Placa: " << placa << endl;
    s << "Modelo: " << modelo << endl;
    s << "Marca: " << marca << endl;
    s << "Tipo: " << tipo << endl;
    return s.str();
}
