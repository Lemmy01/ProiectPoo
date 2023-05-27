#ifndef ADMINISTRAREREZERVARE_H
#define ADMINISTRAREREZERVARE_H


#include <iostream>
#include <vector>
#include <fstream>
#include "Rezervare.h"



using namespace std;

class AdministrarePachete;

class AdministrareRezervare {
    static int nextId;
private:
    std::vector<Rezervare> rezervari;

    string numeFisier;
public:
AdministrareRezervare(const std::string& ) ;

~AdministrareRezervare();

void afiseazaRezervari(AdministrarePachete&) const ;

void citesteRezervariFisier() ;

void salveazaRezervariFisier() const ;

void adaugaRezervare(AdministrarePachete&) ;

std::vector<Rezervare> getRezervariByPachetId(int ) const ;

void updatepachetIdRezervari(int, int );

void deleteRezervariCuPachetId(int ,AdministrarePachete&) ;

void stergeRezervare(int ,AdministrarePachete&) ;

};


#endif // ADMINISTRAREREZERVARE_H
