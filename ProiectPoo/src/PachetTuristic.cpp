#include "PachetTuristic.h"

#include <iostream>

using namespace std;


PachetTuristic:: PachetTuristic() : id(0), nume("Necunoscut"),descriere("Necunoscut"),pret(0),durata(0),locuriDisponibile(0),destinatie("Necunoscut") {}

PachetTuristic::  PachetTuristic(int _id,string n, string d, string dest, float p, int dur, int loc)
{
    id = _id;
    nume = n;
    descriere = d;
    destinatie = dest;
    pret = p;
    durata = dur;
    locuriDisponibile = loc;
}


string PachetTuristic:: getNume() const
{
    return nume;
}

string PachetTuristic:: getDescriere() const
{
    return descriere;
}

string PachetTuristic:: getDestinatie() const
{
    return destinatie;
}

float PachetTuristic:: getPret() const
{
    return pret;
}

int PachetTuristic:: getDurata()const
{
    return durata;
}

int PachetTuristic:: getLocuriDisponibile() const
{
    return locuriDisponibile;
}


void PachetTuristic:: setNume(string n)
{
    nume = n;
}

void PachetTuristic:: setDescriere(string d)
{
    descriere = d;
}

void PachetTuristic:: setDestinatie(string dest)
{
    destinatie = dest;
}

void PachetTuristic:: setPret(float p)
{
    pret = p;
}

void PachetTuristic:: setDurata(int dur)
{
    durata = dur;
}

void PachetTuristic:: setLocuriDisponibile(int loc)
{
    locuriDisponibile = loc;
}

float PachetTuristic:: calculeazaPretTotal() const
{

    float pretBaza = getPret();
    int durataSejur = getDurata();
    float pretTotal = pretBaza* durataSejur;

    return pretTotal;
}



void PachetTuristic:: setId(int newId)
{
    id = newId;
}


int PachetTuristic:: getId() const
{
    return id;
}

istream& operator>>(istream& is, PachetTuristic& pachet) {


    std::cout << "Introduceti numele pachetului: ";
    std::cin >> pachet.nume;

    std::cout << "Introduceti destinatia: ";
    std::cin >> pachet.destinatie;

    std::cout << "Introduceti descrierea: ";
    std::cin >> pachet.descriere;

    std::cout << "Introduceti durata sejurului (in zile): ";
    std::cin >>pachet. durata;

    std::cout << "Introduceti pretul(per zi): ";
    std::cin >> pachet.pret;

    std::cout << "Introduceti numarul total de locuri: ";
    std::cin >> pachet.locuriDisponibile;

        return is;
    }

std::ostream& operator<<(std::ostream& os, const PachetTuristic& pachet) {
        os << "Id: " << pachet.getId() << "\t";
        os << "Nume: " << pachet.getNume() << "\t";
        os << "Descriere: " << pachet.getDescriere() << "\t";
        os << "Destinatie: " << pachet.getDestinatie() << "\t";
        os << "Pret pe zi: " << pachet.getPret() << "\t";
        os << "Durata: " << pachet.getDurata() << "\t";
        os << "Pret total " << pachet.calculeazaPretTotal() << "\t";
        os << "Locuri disponibile: " << pachet.getLocuriDisponibile() << "\t";

    return os;
}
