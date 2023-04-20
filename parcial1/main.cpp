#include <iostream>
#include <fstream>
using namespace std;


void leerPensum();
void mostrarPensum();
void sacarCodigo();
void menu();

const int linea=100,linea2=100;
const int mcodigos=100;
const int mlcodigo=12;
char pensum, fila[linea],fila2[linea2], codigos[mcodigos][mlcodigo], codigo[mlcodigo];
int i, j, longil=0,s1=-1,s2=-1,smenu, mmatricula, contarc;

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

    leerPensum.close();
}

void mostrarPensum()
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

void sacarCodigo()
{
    ifstream leerPensum;
    leerPensum.open("pensum.txt");

    if(!leerPensum.is_open())
    {
        cout<<"Error";
    }
    while(leerPensum.get(pensum))
    {
        if(pensum=='\n')
        {
            for(i=0;i<longil;i++)
            {
                if(fila[i]=='[')
                {
                    s1=i;
                }else if (fila[i]==',')
                {
                    s2=i;
                    break;
                }
            }
            if(s1!=-1 && s2!=-1)
            {

                int pos = 0;
                for(i=s1+1;i<s2;i++)
                {
                    codigos[contarc][pos] = fila[i];
                    pos++;
                }
                codigos[contarc][pos] = '\0';
                contarc++;
            }
            longil=0;
        }else
        {
            fila[longil++]= pensum;
        }
    }
    cout<<"\n";
    leerPensum.close();
}
void compararCodigo(char codigos[][mlcodigo], int contarc)
{
    cout<<"Ingrese el Codigo: ";
    cin>>codigo;

    bool comparar=false;
    for(i=0; i<contarc && !comparar; i++)
    {
        j=0;
        while(codigo[j]!='\0' && codigos[i][j]!='\0' && codigo[j]==codigos[i][j])
        {
            j++;
        }
        if(codigo[j]=='\0' && codigos[i][j]=='\0')
        {
            comparar = true;
        }
    }

    if(comparar)
    {
        cout<<"Matricula Exitosa\n";
        system("PAUSE");
    }
    else
    {
        cout<<"Curso no Encontrado\n";
        system("PAUSE");
    }
}

void menu()
{
    smenu=0;
    while(smenu!=3)
    {
        system("cls");
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
            while(mmatricula!=2)
            {
                system("cls");
                cout<<"1.Matricular\n";
                cout<<"2.Regresar\n\n";
                cout<<"Digite la opcion: ";
                cin>>mmatricula;
                leerPensum();
                switch(mmatricula)
                {

                case 1:
                    system("cls");
                    cout<<"Malla Curricular\n\n";
                    mostrarPensum();
                    sacarCodigo();
                    compararCodigo(codigos,contarc);
                    break;
                }
                break;
            }
            case 2:
            break;
        }
    }
}
