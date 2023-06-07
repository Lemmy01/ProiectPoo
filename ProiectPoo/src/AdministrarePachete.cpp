#include <iostream>
#include "AdministrarePachete.h"
#include "AdministrareRezervare.h"
#include "Utils.h"


using namespace std;



AdministrarePachete:: AdministrarePachete(const std::string& _numeFisier) : numeFisier(_numeFisier)
{
}

void AdministrarePachete::adaugaPachet()
{
    PachetTuristic pachet=PachetTuristic();
    cin>>pachet;
    int id=nextId++;
    pachet.setId(id);
    pachete.push_back(pachet);
}

void AdministrarePachete::afiseazaPachete()
{
    int pachetePePagina = 100;
    int totalPachete = pachete.size();
    int pagini = (totalPachete + pachetePePagina - 1) / pachetePePagina;

    if (totalPachete == 0)
    {
        cout << "Nu exista pachete de afisat." << endl;
        return;
    }

    for (int pagina = 1; pagina <= pagini; ++pagina)
    {
        cout << "----- Pagina " << pagina << " -----" << endl;

        int start = (pagina - 1) * pachetePePagina;
        int end = min(start + pachetePePagina, totalPachete);

        for (int i = start; i < end; ++i)
        {
            cout << pachete[i] << endl;
        }

        cout << endl;

        // Pauză pentru a permite utilizatorului să citească pagina curentă
        if (pagina < pagini)
        {
            cout << "Apasati ENTER pentru a continua sau 'q' pentru a iesi din afisare..." << endl;

            fflush(stdin);
            string input;

            getline(cin, input);

            if (input == "q")
            {
                cout << "Iesire din afisare." << endl;
                return;
            }
        }
    }
}

void AdministrarePachete:: salveazaPachete()
{
    std::ofstream file(numeFisier);

    if (file.is_open())
    {
        for (const auto& pachet : pachete)
        {
            // Scrie informațiile despre pachet în fișier
            file <<pachet.getId() << "," << pachet.getNume() << "," << pachet.getDescriere() << "," << pachet.getDestinatie() << "," << pachet.getPret() << "," << pachet.getDurata() << "," << pachet.getLocuriDisponibile() << "," << "\n";
        }

        file.close();
        cout << "Pachetele au fost salvate cu succes in fisierul " << numeFisier << std::endl;
    }
    else
    {
        std::cout << "Nu s-a putut deschide fisierul pentru salvare." << std::endl;
    }
}

void AdministrarePachete:: citestePachete()
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
        std::cout << "Pachetele au fost incarcate cu succes din fisierul " << numeFisier << std::endl;
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

void AdministrarePachete::stergePachet(int id,AdministrareRezervare& adminRezervari)
{
    bool wasDeleted=false;
    for (auto it = pachete.begin(); it != pachete.end(); ++it)
    {
        if (it->getId() == id)
        {

            adminRezervari.deleteRezervariCuPachetId(it->getId(),*this);
            nextId--;
            wasDeleted=true;
            pachete.erase(it);
            break;
        }
    }
    for (auto it = pachete.begin(); it != pachete.end(); ++it)
    {
        if(it->getId() > id)
        {

            adminRezervari.updatepachetIdRezervari(it->getId(), it->getId()-1);
            it->setId(it->getId() - 1);
        }
    }


    if(!wasDeleted)
    {
        cout<<"Pachetul cu id "<<id<<" nu a fost gasit";
    }
}

void AdministrarePachete::completeazaLocuri(int locuriDeAdaugat,int idPachet)
{
    auto pachet = getPachetDupaId(idPachet);
    pachet->setLocuriDisponibile(pachet->getLocuriDisponibile()+locuriDeAdaugat);
}

std::vector<PachetTuristic*> AdministrarePachete::cautaPachetDupaNume(const std::string& numePachet) {
    std::vector<PachetTuristic*> pacheteGasite;

    for (auto& pachet : pachete) {
        if (pachet.getNume() == numePachet) {
            pacheteGasite.push_back(&pachet);
        }
    }

    return pacheteGasite;
}


int AdministrarePachete::nextId = 1;
