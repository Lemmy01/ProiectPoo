#include <iostream>
#include "PachetTuristic.h"
#include "AdministrarePachete.h"
#include "AdministrareRezervare.h"

using namespace std;

void afisareOptiuni()
{
    cout<<endl;
    cout << "A: Afisare Pachete"<<endl;
    cout << "L: Cauta pachet dupa Id"<<endl;
    cout << "N: Cauta pachet dupa nume"<<endl;
    cout << "I: Introdu Pachete" << endl;
    cout << "D: Sterge Pachet" << endl;
    cout << "R: Creaza rezervare" << endl;
    cout << "V: Vizoneaza rezervari" << endl;
    cout << "K: Cauta rezervare dupa Id" << endl;
    cout << "F: Sterge rezervare" << endl;
    cout << "S: Salvare in fisier" << endl;
    cout << "C: Curata consola" << endl;
    cout << "X: Inchide Program" << endl;
}

void gen()
{
    std::ofstream file("pachete.txt");

    if (!file)
    {
        std::cout << "Eroare la deschiderea fisierului.";

    }


    for (int i = 1; i <= 1000; ++i)
    {

        file << i << ",a"<<i<<",b"<<i<<",c"<<i<<",1,1,100,";

        file  << std::endl;
    }

    file.close();

    std::cout << "Fisierul 'date_intrare.txt' a fost generat cu succes.";


}

int main()
{
    const std::string numeFisier = "pachete.txt";
    const std::string numeFisierRezervari = "rezervari.txt";
    AdministrarePachete adminPachete = AdministrarePachete(numeFisier);
    AdministrareRezervare adminRezervari = AdministrareRezervare(numeFisierRezervari);
    adminPachete.citestePachete();
    adminRezervari.citesteRezervariFisier();
    char op;
    vector<PachetTuristic*> pachete;
    int idPachet,idRezervare,id;
    PachetTuristic* pachet;
    Rezervare* rezervare;
    string nume;

    do
    {
        afisareOptiuni();
        cin >> op;
        switch (toupper(op))
        {

        case 'C':
            cout<<endl<<"Apasa enter pentru a continua";
            fflush(stdin);
            getchar();
            fflush(stdin);
            system("cls");
            break;
        case 'A':
            adminPachete.afiseazaPachete();
            break;
        case 'I':
            adminPachete.adaugaPachet();
            break;
        case 'S':
            adminPachete.salveazaPachete();
            adminRezervari.salveazaRezervariFisier();
            break;
        case 'D':
            cout << endl << "Introdu id pachet:";
            cin >> idPachet;
            adminPachete.stergePachet(idPachet,adminRezervari);
            break;
        case 'R':
            adminRezervari.adaugaRezervare(adminPachete);
            break;
        case 'V':
            adminRezervari.afiseazaRezervari(adminPachete);
            break;
        case 'F':
            cout << "Introdu id Rezervare";
            cin >> idRezervare;
            adminRezervari.stergeRezervare(idRezervare,adminPachete);
            break;
        case 'N':

            cout<<"Introdu Nume:";
            fflush(stdin);
            getline(cin,nume);
            pachete= adminPachete.cautaPachetDupaNume(nume);
            if(pachete.size()!= 0)
            {
                for (auto& pachet : pachete)
                    cout<<*pachet;

            }
            else
            {
                cout<<"Pachetul cautat nu exista";
            }
            cout<<endl;
            break;
        case 'L':

            cout<<"Introdu ID:";
            cin>>id;
            pachet= adminPachete.getPachetDupaId(id);
            if(pachet!=NULL)
            {
                cout<<*pachet;

            }
            else
            {
                cout<<"Pachetul cautat nu exista";
            }
            cout<<endl;
            break;
        case 'K':

            cout<<"Introdu ID:";
            cin>>id;
            rezervare= adminRezervari.cautaPachetDupaId(id);
            if(rezervare!=NULL)
            {
                pachet= adminPachete.getPachetDupaId(rezervare->getIdPachet());
                cout<<*rezervare<<"\t";
                cout << "Pachet turistic: " << pachet->getNume();
            }
            else
            {
                cout<<"Rezervarea cautat nu exista";
            }
            cout<<endl;
            break;
        case 'X':
            exit(0);
            break;
        }
    }
    while (1);


    return 0;
}
