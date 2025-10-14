#include "NodoPlantel.h"

NodoPlantel::NodoPlantel(Plantel* plantel, NodoPlantel* siguiente) {
    this->plantel = plantel;
    this->siguiente = siguiente;
}

NodoPlantel::~NodoPlantel() {
     delete plantel;
}

Plantel* NodoPlantel::getPlantel() {
    return plantel;
}

NodoPlantel* NodoPlantel::getSiguiente() {
    return siguiente;
}

void NodoPlantel::setPlantel(Plantel* plantel) {
    this->plantel = plantel;
}

void NodoPlantel::setSiguiente(NodoPlantel* siguiente) {
    this->siguiente = siguiente;
}
