#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define PI 3,14

/*
somatorio sequencial = n*(n+1)/2
somatorio par = n*(n+1)
somatorio pares = n²
somatorio elevado ao quadrado = (n*(n+1)/2)²

FORMA RECURSIVA
int f1 ( int n ) {
int y1 = 0;
if ( n > 0);
{
y1 = n + f1( n - 1 );
}else {
y1 = 0;
}
return (y1);

int f2 ( int n ){
int y1 = 0;
if ( k <= n ){
y1 = n + f1 ( k+1 );
}else {
y1 = 0;
}
return ( y1 );
}

int f2_b ( int k , int n ){
int y1 = 0;
if ( k <= n ){
y1 = k + f1 ( k+1, n );
}else {
y1 = 0;
}
return ( y1 );
}

int f2 ( int n ) {
int y1 = 0;
y1 = f2_b ( 1, n);
return ( y1 );
*/
void lerString (char *palavra){
	printf("\nDigite uma sequencia de caracteres:  ");
	scanf("%s",palavra);
	getchar();
}

void lerInteiro (int *numero){
	printf("\n Digite um numero inteiro:  ");
	scanf("%d",numero);
	getchar();
}

void lerReal (double *numero) {
	printf("\nDigite um valor real:  ");
	scanf("%lf",numero);
	getchar();
}

void f_01 (int n){
	if(n==0){
		return;
	}
	f_01(n-1);
	printf("%d ",n*3);
}

void f_02 (int n){
	if(n==0){
		return;
	}
	printf("%d ",n*3);
	f_02(n-1);
}

void f_03 (int n){
	if(n==0){
		return;
	}
	f_03(n-1);
	printf("1/%d ",n*3);
}

void f_04 (int n){
	if(n==0){
		return;
	}
	printf("1/%d ",n*3);
	f_04(n-1);
}

int f_05 (int n,int incremento,int soma){
	if(n==0){
		return soma;
	}
	soma += 3 + incremento;
	return f_05(n-1,incremento+2,soma);
}

int f_06 (int n,int incremento, int soma,int atual){
	if(n==0){
		return soma;
	}
	if((atual + incremento) % 3 == 0){
		soma += atual + incremento;
	}else{
		n++;
	}
	return f_06(n-1,incremento + 2,soma, atual);
}

void f_07(char *palavra){
	if(*palavra == '\0'){
		return;
	}
	f_07(palavra + 1);
	printf("%c\n",*palavra);
	
}

int f_08 (char *palavra, int count){
	if(*palavra == '\0'){
		return count;
	}
	if(isdigit(*palavra)){
		int num = *palavra - '0';
		if(num % 2 == 0){
			count++;
		}
	}
	return f_08(palavra+1,count);
}

int f_09 (char *palavra,int count){
	if(*palavra == '\0'){
		return count;
	}
	if(isupper(*palavra)){
		if(*palavra >= 'C' && *palavra <= 'P'){
			count++;
		}
	}
	return f_09(palavra + 1,count);
}

int f_10(int n,int atual,int anterior, int count,int soma){
	if(count == n){
		return soma;
	}
	int fibonacci = atual + anterior;
	if(fibonacci % 2 == 0){
		count++;
		soma += fibonacci;
	}
	return f_10(n,fibonacci,atual,count,soma);
}

int f_extra01 (int n,int x){
	if(n==0){
		return 1 + pow(x,3);
	}
	return pow(x,2 * n + 1) + f_extra01(x,n - 1);
}

void ex_1 (void){
int n;
lerInteiro(&n);
	f_01(n);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_2 (void){
int n;
lerInteiro(&n);
	f_02(n);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_3 (void){
int n;
lerInteiro(&n);
	if(n >= 1){
		printf("1/1 ");
		f_03(n-1);
	}
	getchar();
	return (EXIT_SUCCESS);
}
void ex_4 (void){
int n;
lerInteiro(&n);
	if(n >= 1){
		f_04(n-1);
		printf("1/1 ");
	}
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_5 (void){
int n;
lerInteiro(&n);
	int soma = f_05(n,0,0);
	printf("%d",soma);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_6 (void){
int n;
lerInteiro(&n);
	int soma = f_06(n,0,0,3);
	printf("1/%d ",soma);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_7 (void){
char palavra[100];
lerString(&palavra);
	f_07(palavra);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_8 (void){
char palavra[100];
	lerString(&palavra);
	int count = f_08(palavra,0);
	printf("%d ",count);
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_9 (void){
char palavra[100];
lerString(&palavra);
	int count = f_09(palavra,0);
	printf("%d ",count);
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_10 (void){
int n;
lerInteiro(&n);
	int soma = f_10(n,1,1,0,0);
	printf("%d ",soma);
	getchar();
	return (EXIT_SUCCESS);
}
void extra_01 (void) {
int n, x;
lerInteiro(&n);
lerInteiro(&x);
	int soma = f_extra01(n,x);
	printf("%d",soma+1);
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
