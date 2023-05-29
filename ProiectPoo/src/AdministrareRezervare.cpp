#include <iostream>
#include <vector>
#include <fstream>

#include "AdministrarePachete.h"
#include "AdministrareRezervare.h"
#include "Utils.h"

AdministrareRezervare::AdministrareRezervare(const std::string& _numeFisier) : numeFisier(_numeFisier)
{
}

AdministrareRezervare::~AdministrareRezervare() {}



void AdministrareRezervare::afiseazaRezervari(AdministrarePachete& adminPachete) const
{
    for (const auto& rezervare : rezervari)
    {
        PachetTuristic* pachet= adminPachete.getPachetDupaId(rezervare.getIdPachet());

        cout<<rezervare<<"\t";
        cout << "Pachet turistic: " << pachet->getNume();
        cout << std::endl;
    }
}


void AdministrareRezervare::citesteRezervariFisier()
{
    ifstream file(numeFisier);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {

            vector<string> listaAtribute = split(line, ',');


            // Extrage valorile din linia citită
            if (!listaAtribute.empty())
            {

                try
                {
                    Rezervare rezervare=Rezervare(stoi(listaAtribute[0]),stoi(listaAtribute[1]),listaAtribute[2],stoi(listaAtribute[3]),stof(listaAtribute[4]));
                    rezervari.push_back(rezervare);
                }
                catch (const std::invalid_argument& e)
                {
                    cout << "Eroare: Argument invalid\n";
                }
                catch (const std::out_of_range& e)
                {
                    cout << "Eroare: Depasire de rang\n";
                }


            }
            else
            {
                std::cout << "Eroare la citirea datelor din fișier." << std::endl;
            }
        }
        nextId = rezervari.size() + 1;
        file.close();
        std::cout << "Pachetele au fost incarcate cu succes din fisierul " << numeFisier << std::endl;
    }
    else
    {
        std::cout << "Nu s-a putut deschide fiaierul pentru citire." << std::endl;
    }
}

void AdministrareRezervare::salveazaRezervariFisier() const
{
    std::ofstream fisier(numeFisier);

    if (!fisier)
    {
        std::cerr << "Eroare la deschiderea fisierului." << std::endl;
        return;
    }

    for (const auto& rezervare : rezervari)
    {
        fisier << rezervare.getId() << ","
               << rezervare.getIdPachet() << ","
               << rezervare.getNumeClient() << ","
               << rezervare.getNumarPersoane()<<","
               << rezervare.getPretTotal()<<","
               << std::endl;
    }
    fisier.close();
    cout << "Pachetele au fost salvate cu succes in fisierul " << numeFisier << std::endl;


}

void AdministrareRezervare::adaugaRezervare(AdministrarePachete& adminPachet)
{Rezervare rezervare=Rezervare();
  cin>>rezervare;

    PachetTuristic* pachet = adminPachet.getPachetDupaId(rezervare.getIdPachet());
    if(adminPachet.inchiriereLocuri(rezervare.getNumarPersoane(), rezervare.getIdPachet()))
    {

       rezervare.setId(nextId++);
       rezervare.setpretTotal(pachet->calculeazaPretTotal());

        rezervari.push_back(rezervare);
    }
    else
    {
        cout << "Nu sunt locuri suficiente";
    }
}

std::vector<Rezervare> AdministrareRezervare::getRezervariByPachetId(int id) const
{
    std::vector<Rezervare> rezervariPachet;

    for (const auto& rezervare : rezervari)
    {
        if (rezervare.getIdPachet() == id)
        {
            rezervariPachet.push_back(rezervare);
        }
    }

    return rezervariPachet;
}

void AdministrareRezervare::updatepachetIdRezervari(int oldId, int newId)
{


    for (auto& rezervare : rezervari)
    {
        if (rezervare.getIdPachet() == oldId)
        {
            rezervare.setPachetId(newId);
        }

    }

}

void AdministrareRezervare::deleteRezervariCuPachetId(int idPachet,AdministrarePachete& adminPachete)
{
    for (auto it = rezervari.begin(); it != rezervari.end(); ++it)
    {
        if (it->getIdPachet() == idPachet)
        {
            stergeRezervare(it->getId(),adminPachete);
            break;
        }
    }
}

void AdministrareRezervare::stergeRezervare(int id,AdministrarePachete& adminPachete)
{
    bool rezervareGasita = false;
    for (auto it = rezervari.begin(); it != rezervari.end(); ++it)
    {
        if (it->getId() == id)
        {
            adminPachete.completeazaLocuri(it->getNumarPersoane(),it->getIdPachet());
            rezervari.erase(it);
            std::cout << "Rezervarea cu ID-ul " << id << " a fost stearsa." << std::endl;
            rezervareGasita = true;
         break;
        }

    }
    for (auto it = rezervari.begin(); it != rezervari.end(); ++it)
    {
        if(it->getId() > id)
        {
            it->setId(it->getId() - 1);
        }
    }
    if (!rezervareGasita)
    {
        std::cout << "Rezervarea cu ID-ul " << id << " nu a fost gasita." << std::endl;
    }
}


int AdministrareRezervare::nextId = 1;
