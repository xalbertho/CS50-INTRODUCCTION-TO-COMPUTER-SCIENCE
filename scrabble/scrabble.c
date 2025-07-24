#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int puntos[27] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

string mayusculas(string palabra);
int suma(string palabra);

int main(void)
{
    int suma1, suma2;
    suma1 = suma2 = 0;

    string palabra1 = get_string("Jugador1: ");
    string palabra2 = get_string("Jugador2: ");
    palabra1 = mayusculas(palabra1);
    palabra2 = mayusculas(palabra2);
    suma1 = suma(palabra1);
    suma2 = suma(palabra2);

    suma1 == suma2 ? printf("Tie!") : (suma1 < suma2 ? printf("Player 2 wins!") : printf("Player 1 wins!"));
}

string mayusculas(string palabra)
{
    int longitud = strlen(palabra);
    for (int i = 0; i < longitud; i++)
    {

        if (islower(palabra[i]))
        {
            palabra[i] = toupper(palabra[i]);
        }
        else
        {
            palabra[i] = (palabra[i]);
        }
    }
    return palabra;
}

int suma(string palabra)
{
    int suma = 0;

    for (int i = 0; i < strlen(palabra); i++)
    {
        if (palabra[i] >= 65 && palabra[i] <= 90)
        {
            int aux = palabra[i] - 65;
            suma += puntos[aux];
        }
        else
        {
            continue;
        }
    }
    return suma;
}
