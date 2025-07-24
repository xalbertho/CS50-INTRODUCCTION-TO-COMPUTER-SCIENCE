#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int contar_palabras(string texto);
int contar_letras(string texto);

int contar_oraciones(string texto);
string mayusculas(string texto);

int main(void)
{
    string texto = get_string("Escriba: ");
    texto = mayusculas(texto);

    int letras = contar_letras(texto);
    int palabras = contar_palabras(texto);
    int oraciones = contar_oraciones(texto);
    float L = ((float) letras / palabras) * 100;
    float S = (float) oraciones / palabras * 100;
    float indice = 0.0588 * L - 0.296 * S - 15.8;

    int indice_final = round(indice);

    indice_final < 1 ? printf("Before Grade 1\n")
                     : (indice_final > 16 ? printf("Grade 16+\n") : printf("Grade %d\n", indice_final));
}

int contar_letras(string texto)
{
    int total = 0;

    for (int i = 0; i < (strlen(texto)); i++)
    {
        if (texto[i] >= 65 && texto[i] <= 90)
        {
            total += 1;
        }
        else
        {
            continue;
        }
    }

    return total;
}

int contar_palabras(string text)
{
    int total = 1;
    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] == ' ')
        {
            total += 1;
        }
        else
            continue;
    }
    return total;
}

string mayusculas(string text)
{

    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]))
        {
            text[i] = toupper(text[i]);
        }
        else
        {
            continue;
        }
    }
    return text;
}

int contar_oraciones(string text)
{
    int total = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            total += 1;
        }
        else
        {
            continue;
        }
    }
    return total;
}
