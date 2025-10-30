#include "Carro.h"

Carro::Carro(string placa, int modelo, string marca, string categoria,string tipoLicencia) {
    this->placa = placa;
    this->modelo = modelo;
    this->marca = marca;
    this->categoria = categoria;
    this->tipoLicencia = tipoLicencia; 
    this->estado = "Disponible";
    bitacorasDelCarro = new ContenedorBitacoras(); 
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

void Carro::mostrarEstadosParaPlantel(){
    string estados[3] = { "Disponible","Revision", "Lavado" }; 
    for (int i = 0; i < 3; i++) {
        cout << i+1 <<"- " << estados[i] << "." << endl;
    }
}

ContenedorBitacoras* Carro::getBitacora(){
    return bitacorasDelCarro;
}

void Carro::cambiarEstado(string estadoAnterior, string estadoNuevo,string IdColaborador,string fecha){
    BitacoraEstadosDelCarro* bitacora = new BitacoraEstadosDelCarro(estadoAnterior, estadoNuevo, IdColaborador, fecha); 
    bitacorasDelCarro->registrarBitacora(bitacora); 
    estado = estadoNuevo; 
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

