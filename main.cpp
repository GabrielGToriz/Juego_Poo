#include <iostream>
#include <conio.h>

using namespace std;

char Tablero[3][3]; // CREAMOS NUESTRA MATRIZ DE 3 X 3 COMO EL TRADICIONAL GATO

class Gato
{
private:             // Atributos de nuestroa clase
    int turno = 0;   // INICIALISAMOS LOS TURNOS
    string jugador1; // INICIALISAMOS EN VACIO EL ARREGLO DEL NOMBRE DE NUESTRO PRIMER JUGADOR
    string jugador2; // INICIALISAMOS EN VACIO EL ARREGLO DEL NOMBRE DE NUESTRO SEGUNDO JUGADOR
public:              // TODOS LOS METODOS DE NUESTRO
    void construirTablero();

    void actualizarTurno(int, int);

    char posibleJugada();

    int verificarJugada(char);

    int verificarGanador();

    void identificarGanador(int);

    void setJugador1(string _jugador1);

    string getJugador1();

    void setJugador2(string _jugador2);

    string getJugador2();
};

void Gato::setJugador1(string _jugador1)
{
    jugador1 = _jugador1;
}

string Gato::getJugador1()
{
    return jugador1;
}

void Gato::setJugador2(string _jugador2)
{
    jugador2 = _jugador2;
}

string Gato::getJugador2()
{
    return jugador2;
}

void Gato::construirTablero()
{ // AQUI SE CREA EL TABLERO, LAS CONDICIONALES SON PARA QUE NO SE MUETREN LOS | AL FINAL DE CADA UNO DE LOS LADOS Y PARA QUE NO SALGAN LOS _ ABAJO DEL TABLERO
    int x = 0, y = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < 5 && i % 2 == 1)
            {
                cout << "___";
            }
            else
            {
                if (i < 5)
                {
                    cout << "  " << Tablero[x][y] << " ";
                    y++;
                }
                else
                {
                    cout << "   ";
                }
            }
            if (j < 2)
            {
                cout << "|";
            }
        }
        y = 0;
        if (i % 2 == 0)
        {
            x++;
        }
        cout << endl;
    }
}

char Gato::posibleJugada()
{ // SE SELECCIONA UNA DE LAS NUEVE POSIBILIDADES EN DONDE EL JUGADOR QUIERA PONER SU MARCA
    cout << "Opciones de juego" << endl;
    int contador = 0;
    string opciones = "abcdefghi";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << opciones[contador] << ") [" << i << "]"
                 << ","
                 << "[" << j << "]" << endl;
            if (Tablero[i][j] !=
                NULL)
            { // SI EL TABLERO ES DIFERENTE DE VACIO QUIERE DECIR QUE ESTA YA HA SIDO OCPADA Y NO SE PUEDE JUGAR EN ESA CASILLA
                cout << "Ocupado" << endl;
            }
            cout << endl;
            contador++;
        }
    }
    cout << endl;
    if (turno % 2 == 0)
    {
        cout << jugador1;
    }
    else
    {
        cout << jugador2;
    }
    cout << ", elige una jugada" << endl;
    return getch(); // PARA OMITIR USAR EL ENTER Y QUE AL DIGITAR LA JUGADA SE SELECCIONE AUTOMATICAMENTE
}

void Gato::actualizarTurno(int x, int y)
{ // EL PRIMER JUGADOR SERA LA " X " Y EL SEGUNDO JUGADOR SERÁ LA " O "
    if (turno % 2 == 0)
    {
        Tablero[x][y] = 'X';
    }
    else
    {
        Tablero[x][y] = 'O';
    }
    turno++;
}

int Gato::verificarJugada(char jugada)
{ // VERIFICAMOS QUE LA JUGADA QUE VAYAMOS A UTILIXAR SE ENCUENTRE DISPONIBLE
    if (jugada >= 'a' && jugada <= 'i')
    {
        switch (jugada)
        {
        case 'a':
            if (Tablero[0][0] == NULL)
            {
                actualizarTurno(0, 0);
                return 1;
            }
            break;
        case 'b':
            if (Tablero[0][1] == NULL)
            {
                actualizarTurno(0, 1);
                return 1;
            }
            break;
        case 'c':
            if (Tablero[0][2] == NULL)
            {
                actualizarTurno(0, 2);
                return 1;
            }
            break;
        case 'd':
            if (Tablero[1][0] == NULL)
            {
                actualizarTurno(1, 0);
                return 1;
            }
            break;
        case 'e':
            if (Tablero[1][1] == NULL)
            {
                actualizarTurno(1, 1);
                return 1;
            }
            break;
        case 'f':
            if (Tablero[1][2] == NULL)
            {
                actualizarTurno(1, 2);
                return 1;
            }
            break;
        case 'g':
            if (Tablero[2][0] == NULL)
            {
                actualizarTurno(2, 0);
                return 1;
            }
            break;
        case 'h':
            if (Tablero[2][1] == NULL)
            {
                actualizarTurno(2, 1);
                return 1;
            }
            break;
        case 'i':
            if (Tablero[2][2] == NULL)
            {
                actualizarTurno(2, 2);
                return 1;
            }
            break;
        }
    }
    return 0;
}

int Gato::verificarGanador()
{ // verificamos las posiciones de nuestros posibles 3 en raya para que se valide la jugada ganadora
    if (Tablero[0][0] != NULL && Tablero[0][0] == Tablero[0][1] && Tablero[0][0] == Tablero[0][2])
    {
        return 1;
    }
    if (Tablero[1][0] != NULL && Tablero[1][0] == Tablero[1][1] && Tablero[1][0] == Tablero[1][2])
    {
        return 1;
    }
    if (Tablero[2][0] != NULL && Tablero[2][0] == Tablero[2][1] && Tablero[2][0] == Tablero[2][2])
    {
        return 1;
    }
    if (Tablero[0][0] != NULL && Tablero[0][0] == Tablero[1][0] && Tablero[0][0] == Tablero[2][0])
    {
        return 1;
    }
    if (Tablero[0][1] != NULL && Tablero[0][1] == Tablero[1][1] && Tablero[0][1] == Tablero[0][2])
    {
        return 1;
    }
    if (Tablero[0][2] != NULL && Tablero[0][2] == Tablero[1][2] && Tablero[0][2] == Tablero[2][2])
    {
        return 1;
    }
    if (Tablero[0][0] != NULL && Tablero[0][0] == Tablero[1][1] && Tablero[0][0] == Tablero[2][2])
    {
        return 1;
    }
    if (Tablero[0][2] != NULL && Tablero[0][2] == Tablero[1][1] && Tablero[0][2] == Tablero[2][0])
    {
        return 1;
    }
    return 0;
}

void Gato::identificarGanador(int turnoAnterior)
{
    if (turnoAnterior % 2 == 0)
    { // SI EL TURNO DEL JUGADOR ES PAR GANA EL JUGADOR UNO CASO CONTRARIO GANÓ EL JUGADOR 2
        cout << "El ganador es: " << getJugador1();
    }
    else
    {
        cout << "El ganador es: " << getJugador2();
    }
}

int main()
{
    string p1;
    string p2;
    int numeroDeTurno = 0;
    int banderaJugada = 0;
    int banderaGanador = 0;
    Gato gato;

    cout << "Ingrese el nombre del jugador 1 -> ";
    cin >> p1;
    gato.setJugador1(p1); // LE PASAMOS EL PARAMETRO DEL JUGADOR 1 A NUESTRA CLASE
    cout << "Ingrese el nombre del jugador 2 ->";
    cin >> p2;
    gato.setJugador2(p2); // LE PASAMOS EL PARAMETRO DEL JUGADOR 2 A NUESTRA CLASE
    while (numeroDeTurno < 9 && banderaGanador ==
                                    0)
    {                            // MIENTARS QUE NO SE HAGAN LAS 9 JUGADAS QUE SE PUEDEN HACER EN EL GATO Y NO HAYA UN GANADOR SE SEGUIRA EJECUTANDO EL PROGRAMA
        system("cls");           // BORRAMOS TODO LO QUE SEA ANTERIOR
        gato.construirTablero(); // VOLVEMOS A CONSTRUIR EL TABLERO
        banderaJugada = gato.verificarJugada(gato.posibleJugada());
        if (banderaJugada == 1)
        {
            banderaGanador = gato.verificarGanador(); // SE VERIFICA QUE HICIERA UNA BUENA JUGADA Y SI ES UNO SE SALE DEL CICLO WHILE PARA DECIR QUIEN ES EL GANADOR
            numeroDeTurno++;
        }
    }
    system("cls"); // LIMPIAMOS TODO Y MOSTRAMOS EL TABLERO CON LA JUGADA GANADORA
    gato.construirTablero();
    if (banderaGanador == 1)
    {
        gato.identificarGanador(numeroDeTurno -
                                1); // EL TURNO MENOS UNO ES PARA QUE NO DETECTE QUE EL JUGADOR SIGUIENTE ES EL GANADOR, SINO EL ANTEIROR
    }
    else
    {
        cout << "EL JUEGO ES UN EMPATE";
    }
    return 0;
}