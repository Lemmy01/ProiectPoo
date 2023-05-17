#ifndef PACHETTURISTIC_H
#define PACHETTURISTIC_H

#include <iostream>

using namespace std;

class PachetTuristic {
private:
    int id;
    string nume;
    string descriere;
    string destinatie;
    float pret;
    int durata;
    int locuriDisponibile;

public:

    PachetTuristic() : id(0), nume("") ,descriere(""),pret(0),durata(0),locuriDisponibile(0),destinatie(""){}

    PachetTuristic(int _id,string n, string d, string dest, float p, int dur, int loc) {
        id = _id;
        nume = n;
        descriere = d;
        destinatie = dest;
        pret = p;
        durata = dur;
        locuriDisponibile = loc;
    }


    string getNume() const{
        return nume;
    }

    string getDescriere() const {
        return descriere;
    }

    string getDestinatie() const {
        return destinatie;
    }

    float getPret() const {
        return pret;
    }

    int getDurata()const {
        return durata;
    }

    int getLocuriDisponibile() const {
        return locuriDisponibile;
    }


    void setNume(string n) {
        nume = n;
    }

    void setDescriere(string d) {
        descriere = d;
    }

    void setDestinatie(string dest) {
        destinatie = dest;
    }

    void setPret(float p) {
        pret = p;
    }

    void setDurata(int dur) {
        durata = dur;
    }

    void setLocuriDisponibile(int loc) {
        locuriDisponibile = loc;
    }

    float calculeazaPretTotal() const {

        float pretBaza = getPret();
        int durataSejur = getDurata();
        float pretTotal = pretBaza;


        if (durataSejur > 7) {
            pretTotal = pretBaza* durataSejur * 0.9;  // Reducere de 10% pentru sejururi mai lungi de 7 zile
        }

        return pretTotal;
    }



    void setId(int newId) {
        id = newId;
    }

    // Metoda de obținere a ID-ului
    int getId() const {
        return id;
    }
};

#endif // PACHETTURISTIC_H
