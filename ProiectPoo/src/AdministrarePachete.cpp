#include "AdministrarePachete.h"
#include <iostream>
#include "Utils.h"
using namespace std;






AdministrarePachete:: AdministrarePachete(const std::string& numeFisier) : numeFisier_(numeFisier)
{
}
PachetTuristic AdministrarePachete::  citestePachet()
{
    string nume, destinatie, descriere;
    int locuriDisponibile, durata;
    float pret;

    std::cout << "Introduceti numele pachetului: ";
    std::cin >> nume;

    std::cout << "Introduceti destinatia: ";
    std::cin >> destinatie;

    std::cout << "Introduceti descrierea: ";
    std::cin >> descriere;

    std::cout << "Introduceti durata sejurului (in zile): ";
    std::cin >> durata;

    std::cout << "Introduceti pretul: ";
    std::cin >> pret;

    std::cout << "Introduceti numarul total de locuri: ";
    std::cin >> locuriDisponibile;
    int id = nextId++;

    return PachetTuristic(id,nume,descriere,destinatie,pret,durata,locuriDisponibile);
}

void AdministrarePachete::adaugaPachet()
{
    pachete.push_back(citestePachet());
}

void AdministrarePachete:: afiseazaPachete()
{
    for (const auto& pachet : pachete)
    {
        cout << "Id: " << pachet.getId() << "\t";
        cout << "Nume: " << pachet.getNume() << "\t";
        cout << "Descriere: " << pachet.getDescriere() << "\t";
        cout << "Destinatie: " << pachet.getDestinatie() << "\t";
        cout << "Pret: " << pachet.getPret() << "\t";
        cout << "Durata: " << pachet.getDurata() << "\t";
        cout << "Locuri disponibile: " << pachet.getLocuriDisponibile() << "\t";
        cout << endl;
    }
}

void AdministrarePachete:: salveazaPachete()
{
    std::ofstream file(numeFisier_);

    if (file.is_open())
    {
        for (const auto& pachet : pachete)
        {
            // Scrie informațiile despre pachet în fișier
            file <<pachet.getId() << "," << pachet.getNume() << "," << pachet.getDescriere() << "," << pachet.getDestinatie() << "," << pachet.getPret() << "," << pachet.getDurata() << "," << pachet.getLocuriDisponibile() << "," << "\n";
        }

        file.close();
        cout << "Pachetele au fost salvate cu succes in fisierul " << numeFisier_ << std::endl;
    }
    else
    {
        std::cout << "Nu s-a putut deschide fisierul pentru salvare." << std::endl;
    }
}

void AdministrarePachete:: citestePachete()
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
                // Crează obiectul PachetTuristic și adaugă-l în vectorul de pachete
                try
                {
                    PachetTuristic pachet(stoi(listaAtribute[0]), listaAtribute[1],  listaAtribute[2], listaAtribute[3], stof(listaAtribute[4]), stoi(listaAtribute[5]), stoi(listaAtribute[6]));
                    pachete.push_back(pachet);
                }
                catch (const std::invalid_argument& e)
                {
                    cout << "Eroare: Argument invalid\n";
                }
                catch (const std::out_of_range& e)
                {
                    cout << "Eroare: Depășire de rang\n";
                }


            }
            else
            {
                std::cout << "Eroare la citirea datelor din fișier." << std::endl;
            }
        }
        nextId = pachete.size() + 1;
        file.close();
        std::cout << "Pachetele au fost incarcate cu succes din fiaierul " << numeFisier_ << std::endl;
    }
    else
    {
        std::cout << "Nu s-a putut deschide fiaierul pentru citire." << std::endl;
    }
}

PachetTuristic* AdministrarePachete:: getPachetDupaId(int id)
{
    for (auto& pachet : pachete)
    {
        if (pachet.getId() == id)
        {
            return &pachet;
        }
    }
    return nullptr;
}

bool AdministrarePachete::inchiriereLocuri(int locuriOcupate,int idPachet)
{
    auto pachet = getPachetDupaId(idPachet);
    if (pachet->getLocuriDisponibile() - locuriOcupate >= 0)
    {
        pachet->setLocuriDisponibile(pachet->getLocuriDisponibile() - locuriOcupate);
        return true;
    }
    else
    {
        return false;
    }
}


void AdministrarePachete::stergePachet(int idPachet)
{
    bool wasDeleted=false;
    for (auto it = pachete.begin(); it != pachete.end(); ++it)
    {
        if (it->getId() == idPachet)
        {
            pachete.erase(it);
            nextId--;
            wasDeleted=true;
        }
        if(it->getId() > idPachet)
        {
            it->setId(it->getId() - 1);
        }
    }
    if(!wasDeleted)
        cout << "Pachetul " << idPachet << " nu a fost gasit.\n";
}

int AdministrarePachete::nextId = 1;
