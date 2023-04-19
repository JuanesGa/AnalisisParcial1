#include <iostream>
#include <fstream>
using namespace std;

void leerPensum();
void menu();

char pensum;
int smenu;

int main()
{

menu();


    return 0;
}

void leerPensum()
{
    ifstream leerPensum;
    leerPensum.open("pensum.txt");

    if(!leerPensum.is_open())
    {
        cout<<"Error";
    }

    while(leerPensum.get(pensum))
    {
      cout<<pensum;
    }

    leerPensum.close();
}

void menu()
{
    cout<<"Bienvenido al sistema de matricula \n \n";
    cout<<"1.Oferta y matricula \n";
    cout<<"2.Ver horario \n";
    cout<<"3.Salir \n \n";
    cout<<"Seleccione una opcion: ";
    cin>>smenu;
    system("cls");
    switch (smenu)
    {
        case 1:
        leerPensum();
            break;

        case 2:
            break;

        case 3:
            break;

    }
}
