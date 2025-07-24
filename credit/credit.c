#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int longitud(long numero);
void algoritmo_comprobacion(long numero);

int main(void)
{

    long numero = 0;
    int contador = 0;
    /* do
     {
         numero = get_long("Number: ");
         int contador = longitud(numero);

         if (contador != 13 && contador != 15 && contador != 16)
         {
             printf("INVALID\n");
         }
     } while (numero <= 0 || (longitud(numero) != 13 && longitud(numero) != 15 && longitud(numero) != 16));
 */
    numero = get_long("Numero de Tarjeta: ");
    contador = longitud(numero);

    if (contador != 13 && contador != 15 && contador != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        algoritmo_comprobacion(numero);
    }
}

int longitud(long numero)
{
    int contador = 0;

    while (numero != 0)
    {
        numero /= 10;
        contador++;
    }
    return contador;
}

void algoritmo_comprobacion(long numero)
{

    int tamaño = longitud(numero);

    int temp = 0;
    int suma = 0, sum2 = 0;

    char n_numero[tamaño];
    sprintf(n_numero, "%ld", numero);

    int pen_u_d = tamaño - 2;

    while (pen_u_d >= 0)
    {

        temp = (n_numero[pen_u_d] - '0') * 2;

        if (temp >= 10)
        {
            suma += (temp % 10) + (temp / 10);
        }
        else
        {
            suma += temp;
        }

        pen_u_d -= 2;
    }

    int ultimo_num = tamaño - 1;

    while (ultimo_num >= 0)
    {
        sum2 += n_numero[ultimo_num] - '0';
        ultimo_num -= 2;
    }
    int suma_total = suma + sum2;

    if ((suma_total % 10) == 0)
    {
        if (tamaño == 15 && (n_numero[1] - '0' == 4 || n_numero[1] - '0' == 7))
        {
            printf("AMEX\n");
        }
        else if (n_numero[0] - '0' == 5 && (n_numero[1] - '0' <= 5))
        {
            printf("MASTERCARD\n");
        }
        else if (n_numero[0] - '0' == 4 && (tamaño == 13 || tamaño == 16))
        {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
