#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3,14


void lerString (char *palavra){
    printf("\nDigite uma sequencia de caracteres");
    scanf("%s",palavra);

}

void lerInteiro (int *numero){
    printf("\n Digite um numero inteiro");
    scanf("%d",numero);
}

void lerReal (double *numero) {
    printf("\nDigite um valor real: ");
    scanf("%lf",numero);
}

void ex_1 (void){

getchar();
return (EXIT_SUCCESS);
}
void ex_2 (void){

    getchar();
    return (EXIT_SUCCESS);
}
void ex_3 (void){


    getchar();
    return (EXIT_SUCCESS);
}
void ex_4 (void){


    getchar();
    return (EXIT_SUCCESS);
}
void ex_5 (void){

   getchar();
    return (EXIT_SUCCESS);
}
void ex_6 (void){

    getchar();
    return (EXIT_SUCCESS);
}
void ex_7 (void){

 getchar();
return (EXIT_SUCCESS);
}
void ex_8 (void){


getchar();
return (EXIT_SUCCESS);
}
void ex_9 (void){


getchar();
return (EXIT_SUCCESS);
}
void ex_10 (void){

getchar();
return (EXIT_SUCCESS);
}
void extra_01 (void) {

getchar();
return (EXIT_SUCCESS);
}
void extra_02 (void){

getchar();
return (EXIT_SUCCESS);
}
int main (int argc,char*argv []){
    int opcao = 0;
    printf ( "%s\n", "Guia02 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Gabriel da Silva Amaral" );
    printf ( "\n" );
  do
{
    printf ( "\n%s\n", "Opcoes:"         );
    printf ( "\n%s"   , "0 -  Terminar"   );
    printf ( "\n%s"   , "1 -  exercicio 01" );
    printf ( "\n%s"   , "2 -  exercicio 02" );
    printf ( "\n%s"   , "3 -  exercicio 03" );
    printf ( "\n%s"   , "4 -  exercicio 04" );
    printf ( "\n%s"   , "5 -  exercicio 05" );
    printf ( "\n%s"   , "6 -  exercicio 06" );
    printf ( "\n%s"   , "7 -  exercicio 07" );
    printf ( "\n%s"   , "8 -  exercicio 08" );
    printf ( "\n%s"   , "9 -  exercicio 09" );
    printf ( "\n%s"   , "10 - exercicio 10" );
    printf ( "\n%s"   , "11 - extra 01" );
    printf ( "\n%s"   , "12 - extra 02" );
    printf ( "\n " );

    printf  ( "\n%s", "Opcao = " );
    scanf  ( "%d", &opcao );
    getchar( );
    printf  ( "\n%s%d", "Opcao = ", opcao );

    switch ( opcao )
    {
        case 0:
            break;
        case 1:
            ex_1 ();
            break;
        case 2:
            ex_2 ();
            break;
        case 3:
            ex_3 ();
            break;
        case 4:
            ex_4 ();
            break;
        case 5:
            ex_5 ();
            break;
        case 6:
            ex_6 ();
            break;
        case 7:
            ex_7 ();
            break;
        case 8:
            ex_8 ();
            break;
        case 9:
            ex_9 ();
            break;
        case 10:
            ex_10 ();
            break;
        case 11:
            extra_01 ();
            break;
        case 12:
            extra_02 ();
            break;
        default:
            printf ( "\nERRO: Opcao invalida.\n" );
            break;
    }
}
while ( opcao != 0 );
    printf    ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return   ( 0 );
}
