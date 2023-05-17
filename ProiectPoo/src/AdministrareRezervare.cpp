#include "AdministrareRezervare.h"
#include "AdministrarePachete.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <fstream>




AdministrareRezervare::AdministrareRezervare(const std::string& numeFisier) : numeFisier_(numeFisier)
{
}

AdministrareRezervare::~AdministrareRezervare() {}



void AdministrareRezervare::afiseazaRezervari(AdministrarePachete& adminPachete) const
{
    for (const auto& rezervare : rezervari)
    {
        PachetTuristic* pachet= adminPachete.getPachetDupaId(rezervare.getIdPachet());
        std::cout << "ID rezervare: " << rezervare.getId() << std::endl;
        std::cout << "Pachet turistic: " << pachet->getNume() << std::endl;
        std::cout << "Client: " << rezervare.getNumeClient() << std::endl;
        std::cout << "Numar persoane: " << rezervare.getNumarPersoane() << std::endl;
        std::cout << "Pret total: " << rezervare.getPretTotal() << std::endl;
        std::cout << std::endl;
    }
}


void AdministrareRezervare::citesteRezervariFisier()
{
    ifstream file(numeFisier_);

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
        std::cout << "Pachetele au fost incarcate cu succes din fiaierul " << numeFisier_ << std::endl;
    }
    else
    {
        std::cout << "Nu s-a putut deschide fiaierul pentru citire." << std::endl;
    }
}

void AdministrareRezervare::salveazaRezervariFisier() const
{
    std::ofstream fisier(numeFisier_);

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
}

void AdministrareRezervare::adaugaRezervare(AdministrarePachete& adminPachet)
{
    int id = nextId++;
    std::string numeClient;
    int idPachet,numarPersoane;



    // Citirea numelui clientului
    std::cout << "Nume client: ";

    cin >> numeClient;


    std::cout << "Id Pachet: ";
    cin >> idPachet;

    std::cout << "Numar de persoane ";
    cin >> numarPersoane;


    PachetTuristic* pachet = adminPachet.getPachetDupaId(idPachet);
    if(adminPachet.inchiriereLocuri(numarPersoane, idPachet))
    {
        Rezervare rezervare = Rezervare(id, idPachet, numeClient, numarPersoane,pachet->getPret());
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

void AdministrareRezervare::deleteRezervariCuPachetId(int idPachet)
{
    for (int i = 0; i < rezervari.size(); i++)
    {
        if (rezervari[i].getIdPachet() == idPachet)
        {
            rezervari.erase(rezervari.begin() + i);
        }
    }
}

void AdministrareRezervare::stergeRezervare(int id)
{
    bool rezervareGasita = false;
    for (auto it = rezervari.begin(); it != rezervari.end(); ++it)
    {
        if (it->getId() == id)
        {
            rezervari.erase(it);
            std::cout << "Rezervarea cu ID-ul " << id << " a fost stearsa." << std::endl;
            rezervareGasita = true;
            break;
        }
    }

    if (!rezervareGasita)
    {
        std::cout << "Rezervarea cu ID-ul " << id << " nu a fost gasita." << std::endl;
    }
}


int AdministrareRezervare::nextId = 1;
