#include <stdio.h>
#include <cs50.h>

int main(void){
    int a=1;
    int contador=0,num;
    do{
     num=get_int("Ingrese la altura de la piramide (entre 1 a 8): ");
    } while(num < 1 || num > 8);

   contador=num-1;

    for(int i=1; i<=num;i++){

            for(int k=1; k<=contador; k++){
                printf(" ");
                }

            for(int h=1; h<=a; h++ ){
                printf("#");
                }

            for(int k=1; k<=2; k++){
                printf(" ");
                }


            for(int h=1; h<=a; h++ ){
                printf("#");
                }



                printf("\n");
                a++;
                contador--;

        }


}
