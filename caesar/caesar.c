

//GitHub profile------> @xalbertho

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])

{
    if (argc == 1) // verificamos si el usuario no digito ningu valor
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; argv[1][i] != '\0'; i++) // verificamos si es un numero valido y no de la forma 2x
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int llave = atoi(argv[1]); // uso de la funcion atoi= convierte el argumento
                               //  arv[1] en un numero entero

    if (argc != 2 || llave <= 0) // nuevamente verificamos que no sea diferente de 2 los argc (prgrama y llave) la llave no puede
                                 // ser menor o igual a 0
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string texto = get_string("plaintext: ");
    if (strlen(texto) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(texto);
         i++) // aqui hacemos el cifrado, aumentando el numero puesto, en caso de ser mayor a 26 se hace un ciclo con el uso de "%"
    {
        if (islower(texto[i]))
        {
            texto[i] = (texto[i] - 'a' + llave) % 26 + 'a';
        }
        else if (isupper(texto[i]))
        {
            texto[i] = (texto[i] - 'A' + llave) % 26 + 'A';
        }
    }
    printf("ciphertext: %s\n", texto);
}

