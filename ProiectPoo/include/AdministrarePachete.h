#ifndef ADMINISTRAREPACHETE_H
#define ADMINISTRAREPACHETE_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "PachetTuristic.h"


using namespace std;

class AdministrareRezervare;

class AdministrarePachete
{
    static int nextId;
private:
    vector<PachetTuristic> pachete;
    string numeFisier;

public:
    AdministrarePachete(const std::string&);

    PachetTuristic citestePachet();

    void adaugaPachet();

    void stergePachet(int,AdministrareRezervare&);

    void afiseazaPachete();

    void salveazaPachete() ;

    void citestePachete() ;

    PachetTuristic* getPachetDupaId(int);

    bool inchiriereLocuri(int,int);

    void completeazaLocuri(int,int);
};





#endif // ADMINISTRAREPACHETE_H
