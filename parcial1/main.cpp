#include <iostream>
#include <fstream>
using namespace std;


void leerPensum();
void mostrarPensum();
void sacarCodigo();
void menu();
void asignarHorario();

bool compararHorario();

ofstream Horario;

const int linea=100;
const int mcodigos=100;
const int mlcodigo=12;
char pensum, fila[linea], codigos[mcodigos][mlcodigo], codigo[mlcodigo], horariocom;
int i, j, longil=0,s1=-1,s2=-1,smenu, mmatricula, contarc, contarm;

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
void abrirHorario()
{
    Horario.open("horario.txt",ios::app);
    if(!Horario.is_open())
    {
        cout<<"Error al Abrir el Archivo\n";
        system("PAUSE");
    }
}
bool compararHorario(char dia[], char dia2[], char hi[], char hf[])
{
    ifstream horario("horario.txt");
    if(!horario.is_open())
    {
        cout << "Error al abrir el archivo\n";
        system("PAUSE");
    }
    char diaComparar[10];
    char dia2Comparar[10];
    char hiComparar[10];
    char hfComparar[10];

    while(horario>>codigo>>diaComparar>>dia2Comparar>>hiComparar>>hfComparar)
    {
        bool higual=true;
        for(i=0;dia[i]!='\0' && higual;i++)
        {
            if(dia[i]!=diaComparar[i])
            {
                higual=false;
            }
        }
        for(i=0;dia2[i]!='\0' && higual;i++)
        {
            if(dia2[i]!=dia2Comparar[i])
            {
                higual=false;
            }
        }
        for(i=0;hi[i]!='\0' && higual;i++)
        {
            if (hi[i]!=hiComparar[i] || hf[i]!=hfComparar[i])
            {
                higual=false;
            }
        }
        if(higual)
        {
            cout<<"El horario ya está en uso\n";
            return true;
        }
    }
    return false;
}
void asignarHorario(char codigo[])
{
        char d[10];
        char d2[10];
        char hi[10];
        char hf[10];
        cout<<"Ingrese el Dia en que Ve la Materia: ";
        cin>>d;
        cout<<"Ingrese el Dia2 en que Ve la Materia: ";
        cin>>d2;
        cout<<"Ingrese la Hora Inicio de la Clase: ";
        cin>>hi;
        cout<<"Ingrese la Hora Fin de la Clase: ";
        cin>>hf;
        if(compararHorario(d, d2, hi, hf))
        {
            cout<<"Este Horario ya Esta en Uso\n";
            return;
        }
        Horario<<"["<<codigo<<","<<d<<"/"<<d2<<","<<hi<<"-"<<hf<<"]"<<"\n";
        cout<<"Horario Asignado Exitosamente";

}
void cerrarHorario()
{
    Horario.close();
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
            comparar=true;
        }
    }

    if(comparar)
    {

        abrirHorario();
        asignarHorario(codigo);

        cerrarHorario();
        cout<<"\nMatricula Exitosa\n";
        system("PAUSE");
    }
    else
    {
        cout<<"\nCurso no Encontrado\n";
        system("PAUSE");
    }
}
void horarioCompleto()
{
    ifstream verHorario;
    verHorario.open("horario.txt");
    if(!verHorario.is_open())
    {
        cout<<"Error";
    }
    while(verHorario.get(horariocom))
    {
      cout<<horariocom;
    }

    verHorario.close();
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
                do{
                    system("cls");
                    cout<<"1.Matricular\n";
                    cout<<"2.Regresar\n\n";
                    cout<<"Digite la opcion: ";
                    cin>>mmatricula;

                    if(mmatricula==1)
                    {
                        system("cls");
                        cout<<"Malla Curricular\n\n";
                        contarm++;
                        leerPensum();
                        mostrarPensum();
                        sacarCodigo();
                        compararCodigo(codigos,contarc);
                    }

                }while(mmatricula!=2);
            break;

            case 2:
                horarioCompleto();
                system("PAUSE");
            break;
        }
    }
    if(smenu==3)
    {
        Horario.open("horario.txt",ios::out | ios::trunc);
    }
}
