#include "Rezervare.h"





Rezervare::Rezervare(): id(0), idPachet(0), numeClient("Necunoscut"), numarPersoane(0),pretTotal(0) {}

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

void Rezervare::setpretTotal(float pret)
{
   pretTotal=pret;
}


istream& operator>>(istream& is, Rezervare& rezervare)
{


    std::cout << "Nume client: ";
    cin >> rezervare.numeClient;

    std::cout << "Id Pachet: ";
    cin >>rezervare. idPachet;

    std::cout << "Numar de persoane ";
    cin >> rezervare.numarPersoane;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Rezervare& rezervare) {

        std::cout << "ID rezervare: " << rezervare.getId() <<"\t";
        std::cout << "Client: " << rezervare.getNumeClient() << "\t";
        std::cout << "Numar persoane: " << rezervare.getNumarPersoane() << "\t";
        std::cout << "Pret total: " << rezervare.getPretTotal() << "\t";

    return os;
}
