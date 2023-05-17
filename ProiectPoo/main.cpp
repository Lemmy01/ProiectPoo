#include <iostream>
#include "PachetTuristic.h"
#include "AdministrarePachete.h"
#include "AdministrareRezervare.h"

using namespace std;

void afisareOptiuni() {

    cout << "A: Afisare Pachete"<<endl;
    cout << "I: Introdu Pachete" << endl;
    cout << "S: Salvare in fisier" << endl;
    cout << "D: Sterge Pachet" << endl;
    cout << "R: Creaza rezervare" << endl;
    cout << "V: Vizoneaza rezervari" << endl;
    cout << "F: Sterge rezervare" << endl;
    cout << "X: Inchide Program" << endl;
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
    int idPachet,idRezervare;
    do
    {
        afisareOptiuni();
        cin >> op;
        switch (toupper(op)) {
        case 'A':
            adminPachete.afiseazaPachete();
            break;
        case 'I':
            adminPachete.adaugaPachet();
            break;
        case 'S':
            adminPachete.salveazaPachete();
            break;
        case 'D':
            cout << endl << "Introdu id pachet";
            cin >> idPachet;
            //adminPachete.stergePachet(idPachet,adminRezervari);
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
            adminRezervari.stergeRezervare(idRezervare);
            break;
        case 'X':
            exit(0);
            break;
        }

    }
        while (1);
    return 0;
}
