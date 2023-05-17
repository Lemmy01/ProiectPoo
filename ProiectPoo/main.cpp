#include <iostream>
#include "PachetTuristic.h"
#include "AdministrarePachete.h"
using namespace std;

void afisareOptiuni()
{

    cout << "A: Afisare Pachete"<<endl;
    cout << "I: Introdu Pachete" << endl;
    cout << "S: Salvare in fisier" << endl;
    cout << "D: Sterge Pachet" << endl;
    cout << "X: Inchide Program" << endl;
}


int main()
{
    const std::string numeFisier = "pachete.txt";

    AdministrarePachete adminPachete = AdministrarePachete(numeFisier);

    adminPachete.citestePachete();

    char op;
    int idPachet;
    do
    {
        afisareOptiuni();
        cin >> op;
        switch (toupper(op))
        {
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
            cout << endl << "Introdu id pachet:";
            cin >> idPachet;
            adminPachete.stergePachet(idPachet);
            break;
        case 'X':
            exit(0);
            break;
        }
    }
    while (1);
    return 0;
}
