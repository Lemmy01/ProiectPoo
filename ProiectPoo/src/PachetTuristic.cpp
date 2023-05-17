#include "PachetTuristic.h"

#include <iostream>

using namespace std;


PachetTuristic:: PachetTuristic() : id(0), nume(""),descriere(""),pret(0),durata(0),locuriDisponibile(0),destinatie("") {}

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
