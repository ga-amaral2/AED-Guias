#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define PI 3.14


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
char palavra[100];
lerString(palavra);
	for(int i= 0;palavra[i] != '\0';i++){
		if(palavra[i] >= 'K' && palavra[i] <= 'Z'){
			printf("\n %c",palavra[i]);
		}
	}
	getchar();
	return (EXIT_SUCCESS);
}
void ex_2 (void){
char palavra[100];
lerString(palavra);
	for(int i = 0;palavra[i] != '\0';i++){
		if(palavra[i] >= 'a' && palavra[i] <= 'k'){
			printf("\n %c", palavra[i]);
		}
	}
	return (EXIT_SUCCESS);
}
void ex_3 (void){
char palavra[100];
lerString(palavra);
int cont = 0;

	for(int i = 0;palavra[i] != '\0';i++){
		if(palavra[i] <= 'k'&& palavra[i] >= 'a'){
			cont++;
			printf("\n %c",palavra[i]);
		}
	}
	printf("\nForam digitadas %d letras dentro do intervalo",cont);
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_4 (void){
char palavra[100],palavraNew[100];
lerString(palavra);
	for(int i=0;palavra[i] != '\0';i++){
		if(isalnum(palavra[i])){
			palavraNew[i] = palavra[i];
		}
	}
	printf("\n %c", palavraNew);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_5 (void){
char palavra[100];
lerString(palavra);
int quant = strlen(palavra);
	for(int i=quant - 1;i >= 0;i--){
		if(isdigit(palavra[i])){
			int numero = palavra[i] - '0';
			if(numero % 2 == 0){
				printf("\n %c",palavra[i]);
			}
		}
	}
	getchar();
	return (EXIT_SUCCESS);
}
void ex_6 (void){
char palavra[100],palavraNew[100];
lerString(palavra);
	int j = 0;
// filtro de caracteres
	for(int i = 0;palavra[i] != '\0';i++){
		if(isalnum(palavra[i])){
			palavraNew[j++]= palavra[i];
		}
	}
// filtro de numeros impares
	for(int i = 0;palavra[i] != '0';i++){
		if(isdigit(palavra[i])){
			int numero = palavra[i] - '0';
			if(numero % 2 != 0){
				palavraNew[j++] = palavra[i];
			}
		}
	}
		printf("\nforam digitados %d elementos dentro do filtro que sao %c ",j,palavraNew);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_7 (void){
int a, b, n,cont = 0;
lerInteiro(a);
lerInteiro(b);
lerInteiro(n);
int valores[n];
// garantir A < B
	if(a>=b){
		int c;
		c = a;
		a = b;
		b = c;
	}
// leitura de valores para serem testados
	for(int i=0;i<=n;i++){
		lerInteiro(valores[i]);
	}
// teste de valores
	for(int i=0;i<=n;i++){
		if((valores[i]>= a && valores[i]<= b) && valores[i] % 3 == 0){
			cont++;
			printf("\n%d",valores[i]);
		}
	}
	printf("\n%d quantidade",cont);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_8 (void){
int a, b, n, cont = 0;
lerInteiro(a);
lerInteiro(b);
lerInteiro(n);
int valores[n];
// garantir a < b
	if(a>=b){
		int c;
		c = a;
		a = b;
		b = c;
	}
// leitura de valores
	for(int i=0;i<=n;i++){
		lerInteiro(valores[i]);
	}
// teste de valores
	for(int i=0;i<=n;i++){
		if( (valores[i]>= a && valores[i]<= b) && (valores[i] % 4 == 0 && !(valores[i] % 3 == 0))){
			cont++;
			printf("%d", valores[i]);
		}
	}
	printf("\n%d quantidade",cont);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_9 (void){
int n, cont = 0;
double a, b;
lerReal(&a);
lerReal(&b);
lerInteiro(n);
double valores[n];
int inteiro[n];

// garantir A < B
	if(a>=b){
		double c;
		c = a;
		a = b;
		b = c;
	}
// leitura de valores
	for(int i=0;i<=n;i++){
		lerReal(&valores[i]);
		inteiro[i] = (int)valores[i];
	}
// teste de valores
	for(int i=0;i<=n;i++){
		if((valores[i]> a && valores[i]< b) && (inteiro[i] % 2 == 0 && inteiro[i] < 5)){
		cont++;
		printf("%lf", valores[i]);
		}
	}
	printf("\n%d quantidade",cont);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_10 (void){
double a, b;
int n, cont = 0;
lerInteiro(n);
double valores[n],fracao[n];
int inteiro[n];
	printf("\nDigite um valor maior que 0");
	scanf("%lf",&a);
	if(a>=1 || a<=0){
		printf("\nDigite um valor maior que 0");
		scanf("%lf",&a);
	}
	printf("\Digite um valor menor que 1");
	scanf("%lf", &b);
	if(b>=1 || b<=0){
		printf("\nDigite um valor menor que 1");
		scanf("%lf",&b);
	}
// garantir A < B
	if(a>=b){
		double c;
		c = a;
		a = b;
		b = c;
	}
// leitura de valores
	for(int i=0;i<=n;i++){
		lerReal(&valores[i]);
		inteiro[i] = (int)valores[i];
		fracao[i] = valores[i] - inteiro[i];
	}
// teste de valores
	 for(int i=0;i<=n;i++){
		 if(fracao[i] > a && fracao[i] < b){
			 printf("\n%lf",valores[i]);
			 cont++;
		 }
	 }
	printf("\n%d quantidade",cont);
	getchar();
	return (EXIT_SUCCESS);
}
void extra_01 (void) {
char linha[1000]; 
	printf("Digite uma linha de texto: ");
	fgets(linha, sizeof(linha), stdin);
 	printf("Símbolos não alfanuméricos: ");
	for (int i = 0; linha[i] != '\0'; i++) {
		if (!isalnum(linha[i])) {
			printf("%c ", linha[i]);
		}
	}
	
	getchar();
	return (EXIT_SUCCESS);
}
void extra_02 (void){
char palavra[100];
bool possuiAlNum = false;
fgets(palavra,sizeof(palavra), stdin);
// teste a sequencia
	for(int i=0;palavra[i] != '\0';i++){
		if(isalnum(palavra[i])){
			possuiAlNum = true;
			break;
		}
	}
	if(possuiAlNum){
		printf("\n A sequencia contem letras ou numeros");
	}else {
		printf("\n A sequencia contem apenas simbolos");
	}
	
	getchar();
	return (EXIT_SUCCESS);
}
int main (int argc,char*argv []){
	int opcao = 0;
	printf ( "%s\n", "Guia03 - Programa = v0.0" );
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
