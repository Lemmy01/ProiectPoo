#include "Rezervare.h"

Rezervare::Rezervare(const int id, const int idPachet, const string& numeClient,  int numarPersoane,float pret)
    : id(id), idPachet(idPachet), numeClient(numeClient), numarPersoane(numarPersoane)
{

    pretTotal = pret * numarPersoane;
}
Rezervare::~Rezervare() {}


int  Rezervare::getId() const
{
    return id;
}

int  Rezervare::getIdPachet() const
{
    return idPachet;
}

string  Rezervare::getNumeClient() const
{
    return numeClient;
}


int  Rezervare::getNumarPersoane() const
{
    return numarPersoane;
}

float  Rezervare::getPretTotal() const
{
    return pretTotal;
}


void  Rezervare::setId(int newId)
{
    id = newId;
}

void  Rezervare::setPachetId(int newId)
{
    idPachet = newId;
}
