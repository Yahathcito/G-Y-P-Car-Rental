#include "Carro.h"

Carro::Carro(string placa, int modelo, string marca, string categoria,string tipoLicencia) {
    this->placa = placa;
    this->modelo = modelo;
    this->marca = marca;
    this->categoria = categoria;
    this->tipoLicencia = tipoLicencia; 
    this->estado = "Disponible";
}

void Carro::setPlaca(string p) { placa = p; }

void Carro::setModelo(int m) {modelo = m;}

void Carro::setMarca(string m) {
    marca = m;
}

void Carro::setCategoria(string c) {
    categoria = c; 
}

void Carro::setEstado(string e) { estado = e; }

void Carro::setTipoLicencia(string t) { tipoLicencia = t; }

string Carro::getPlaca() {
    return placa;
}

int Carro::getModelo() {
    return modelo;
}

string Carro::getMarca() {
    return marca;
}

string Carro::getCategoria() {
    return categoria;
}
string Carro::getEstado(){
    return estado;
}

string Carro::getTipoLicencia(){
    return tipoLicencia;
}

string Carro::toString() {
    stringstream s;
    s << "Placa: " << placa << endl;
    s << "Modelo: " << modelo << endl;
    s << "Marca: " << marca << endl;
    s << "Categoria: " << categoria << endl;
    s << "Tipo de licencia requerida: " << tipoLicencia << endl; 
    s << "Estado actual: " << estado << endl; 
    return s.str();
}


bool Carro::verificarDisponibilidad() {
    if( estado == "Disponible")
        return true;
    else
		return false;
}

