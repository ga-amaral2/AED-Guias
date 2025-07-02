#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3,14


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
		f_02(n-1);
	printf("%d ",n*15);

}

void f_03 (int n){
	if(n==0){
		return;
	}

	printf("%d ", (int)pow(4,n));
	f_03(n-1);
}

void f_04 (int n){
	if(n==0){
		return;
	}
	f_04(n-1);
	printf("1/%d ", n*3);
	//printf("%d ", 1/ (n*3));
}

void f_05 (int n, double x){
	if(n==0){
		return;
	}

	f_05(n-1,x);
	printf("1/%1.f  ",pow(x,(double)n+2));
}

int f_06 (int n){
	if(n==0){
		return 0;
	}
	int valor = f_06(n-1);
	int num = 3;
	while(n > 1){
		num += 3;
		if(num %4 != 0){
			n--;
		}
	}
	return valor + num;
}

void testar_f_06() {
	int valores[] = {3, 5, 7};
	int tamanho = sizeof(valores) / sizeof(valores[0]);
	
	for (int i = 0; i < tamanho; i++) {
		int n = valores[i];
		int resultado = f_06(n);
		printf("\nPara n = %d, e: %d\n\n", n, resultado);
	}
}

int f_07 (int n){
	if(n==0){
		return 0;
	}
	int valor = f_07(n-1);
	int num = 4;
	while(n > 1){
		num += 4;
		if(num %5 != 0){
			n--;
		}
	}
	return valor + num;
}

void testar_f_07() {
	int valores[] = {3, 5, 7};
	int tamanho = sizeof(valores) / sizeof(valores[0]);
	
	for (int i = 0; i < tamanho; i++) {
		int n = valores[i];
		int resultado = f_07(n);
		printf("\nPara n = %d,  e: %d\n\n", n, resultado);
	}
}

int f_08(int n, int a, int incremento) {
	if (n == 0) {
		return 0; 
	}
	return a + f_08(n - 1, a + incremento, incremento + 1);
}

void testar_f_08() {
	int valores[] = {3, 5, 7};
	int tamanho = sizeof(valores) / sizeof(valores[0]);
	
	for (int i = 0; i < tamanho; i++) {
		int n = valores[i];
		int resultado = f_08(n, 5,1);
		printf("\nPara n = %d, e: %d\n\n", n, resultado);
	}
}

int f_09(int n, int a) {
	if (n <= 0) {
		return 0;  
	}
		
	return pow(a,2) + f_09(n - 1, a + 1);

} 

void testar_f_09() {
	int valores[] = {3, 5, 7}; 
	int tamanho = sizeof(valores) / sizeof(valores[0]);
	
	for (int i = 0; i < tamanho; i++) {
		int n = valores[i];
		int resultado = f_09(n, 5);
		printf("\nPara n = %d, a soma dos quadrados e: %d\n\n", n, resultado);
	}
}

int f_10 (int n, int a){
	if (n == 0) {
		return 0.0;
	}
	return 1.0 / a + f_10(n - 1, a - (a % 10 == 3 ? 4 : 1));
}

void testarSomaInversos(int n) {
	int ultimoValor = 3;
	for (int i = 1; i < n; i++) {
		ultimoValor += (ultimoValor % 10 == 3) ? 4 : 1;
	}
	
	printf("Soma dos inversos para n = %d: %lf\n", n, f_10(n, ultimoValor));
}

int f_extra01(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * f_extra01(n - 1);
}

double f_extra02(int n) {
	if (n <= 0) {
		return 1;
	} else {
		return (1 + ((2.0 * n) / f_extra01((2 * n) + 1))) * f_extra02(n - 1);
	}
}

void ex_1 (void){
int n;
lerInteiro(&n);
	if (n > 0) {
		f_01(n);
	} else {
		printf("O valor deve ser maior que 0.\n");
	}
	getchar();
	return (EXIT_SUCCESS);
}
void ex_2 (void){
int n;
lerInteiro(&n);
	if (n > 0) {
		f_02(n);
	} else {
		printf("O valor deve ser maior que 0.\n");
	}

	getchar();
	return (EXIT_SUCCESS);
}
void ex_3 (void){
int n;
lerInteiro(&n);
	if (n > 0) {
		f_03(n);
	} else {
		printf("O valor deve ser maior que 0.\n");
	}
	getchar();
	return (EXIT_SUCCESS);
}
void ex_4 (void){
int n;
lerInteiro(&n);
	if (n > 0) {
		f_04(n);
	} else {
		printf("O valor deve ser maior que 0.\n");
	}
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_5 (void){
int n;
lerInteiro(&n);
double x;
lerReal(&x);	
	if (n > 0) {
		f_05(n,x);
	} else {
		printf("O valor deve ser maior que 0.\n");
	}
	getchar();
	return (EXIT_SUCCESS);
}
void ex_6 (void){
	testar_f_06();
	getchar();
	return (EXIT_SUCCESS);
}
void ex_7 (void){
	testar_f_07();
	getchar();
	return (EXIT_SUCCESS);
}
void ex_8 (void){
	testar_f_08();
	getchar();
	return (EXIT_SUCCESS);
}
void ex_9 (void){
	testar_f_09();
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_10 (void){
	// DUVIDA!!!
int n;
lerInteiro(&n);
	testarSomaInversos(5);
	testarSomaInversos(7);
	testarSomaInversos(10);
	testarSomaInversos(n);
	getchar();
	return (EXIT_SUCCESS);
}
void extra_01 (void) {
int n;
lerInteiro(&n);
	int resultado = f_extra01(n);
	printf("%d ",resultado);
	getchar();
	return (EXIT_SUCCESS);
}
void extra_02 (void){
	// DUVIDA!!!
int n;
lerInteiro(&n);
	double resultado =	f_extra02(n);
	printf("%.6f ",resultado);
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
