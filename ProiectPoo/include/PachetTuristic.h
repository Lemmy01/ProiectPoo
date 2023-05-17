#ifndef PACHETTURISTIC_H
#define PACHETTURISTIC_H

#include <iostream>

using namespace std;

class PachetTuristic
{
private:
    int id;
    string nume;
    string descriere;
    string destinatie;
    float pret;
    int durata;
    int locuriDisponibile;

public:

    PachetTuristic();

    PachetTuristic(int,string, string, string, float, int, int ) ;

    string getNume()const;

    string getDescriere()const;

    string getDestinatie()const;

    float getPret() const;

    int getDurata()const;

    int getLocuriDisponibile()const;

    void setNume(string ) ;

    void setDescriere(string );

    void setDestinatie(string );

    void setPret(float ) ;

    void setDurata(int );

    void setLocuriDisponibile(int ) ;

    float calculeazaPretTotal() const;

    void setId(int ) ;

    int getId() const;
};

#endif // PACHETTURISTIC_H
