#ifndef REZERVARE_H
#define REZERVARE_H


#include <string>
#include <iostream>

using namespace std;

class Rezervare
{
private:
    int id;
    int idPachet;
    string numeClient;
    int numarPersoane;
    float pretTotal;
public:
    Rezervare(const int,const int,const string&,int,float);
    ~Rezervare();
    // metode de acces
    int getId() const ;

    int getIdPachet() const;

    string getNumeClient() const ;

    int getNumarPersoane() const ;

    float getPretTotal() const ;

    void setId(int ) ;

    void setPachetId(int ) ;

};


#endif // REZERVARE_H
