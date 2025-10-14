#include "NodoBitacorasEstadoDelCarro.h"


NodoBitacorasEstadoDelCarro::NodoBitacorasEstadoDelCarro(BitacoraEstadosDelCarro* bitacora, NodoBitacorasEstadoDelCarro* siguiente)
{
	this->bitacora = bitacora;
	this->siguiente = siguiente;	
}

NodoBitacorasEstadoDelCarro::~NodoBitacorasEstadoDelCarro()
{
	delete bitacora;
}
BitacoraEstadosDelCarro* NodoBitacorasEstadoDelCarro::getBitacora()
{
	return bitacora;
}
NodoBitacorasEstadoDelCarro* NodoBitacorasEstadoDelCarro::getSiguiente()
{
	return siguiente;
}
NodoBitacorasEstadoDelCarro* NodoBitacorasEstadoDelCarro::setSiguiente(NodoBitacorasEstadoDelCarro* siguiente)
{
	return this->siguiente = siguiente;
}
