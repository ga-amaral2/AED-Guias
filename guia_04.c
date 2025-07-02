#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define PI 3. 14
#define MAX_PALAVRA 100
#define MAX_PALAVRAS 10

void lerString (char *palavra){
	printf("\nDigite uma sequencia de caracteres\n");
	scanf("%s",palavra);
	
}

void lerInteiro (int *numero){
	printf("\n Digite um numero inteiro\n");
	scanf("%d",numero);
}

void lerReal (double *numero) {
	printf("\nDigite um valor real:\n ");
	scanf("%lf",numero);
}
int functionContCeP (char *palavra){
int cont = 0;
	for(int i=0;palavra[i] != '\0';i++){
		if(islower(palavra[i])){
			if(palavra[i]>'c'&& palavra[i]<'p'){
				cont++;
			}
		}
	}
	return cont;
}

char functionPartCeP (char *palavra, char *palavraNew){
int j = 0;
	for (int i = 0; palavra[i] != '\0'; i++) {
		if (islower(palavra[i]) && palavra[i] > 'c' && palavra[i] < 'p') {
			palavraNew[j++] = palavra[i];
		}
	}
	return palavraNew[j];
}

int functionContCcePp (char *palavra){
int cont = 0;
	for(int i=0;palavra[i] != '\0';i++){
		if((islower(palavra[i]) || isupper(palavra[i])) && (palavra[i] > 'c' && palavra[i] < 'p') || (palavra[i] > 'C' && palavra[i] < 'P') ){
			cont++;
		}
	}
	return cont;
}
void functionShowCcePp (char *palavra){
	for(int i=0;palavra[i] != '\0';i++){
		if((islower(palavra[i]) || isupper(palavra[i])) && (palavra[i] > 'c' && palavra[i] < 'p') || (palavra[i] > 'C' && palavra[i] < 'P') ){
			printf("%c",palavra[i]);
		}
	}
}

int functionPares (char *palavra){
int cont = 0,num[100],j = 0, cont2 = 0;
	for(int i=0;palavra[i];i++){
		if(isdigit(palavra[i])){
			num[j++] = (int) palavra[i];
			cont2++;
		}
	}
	for(int j=0;j<=cont2;j++){
		if(num[j] % 2 == 0){
			cont++;
		}
	}
	return cont;
}

char functionShowNotAllNum (char *palavra, char *palavraNew){
int j = 0;
	for(int i=0;palavra[i] != '\0';i++){
		if(isalnum(palavra[i]) == 0){
			palavraNew[j++] = palavra[i]; 
		}
	}
	return palavraNew;
}

char functionShowAllNum (char *palavra, char *palavraNew){
	int j = 0;
	for(int i=0;palavra[i] != '\0';i++){
		if(isalnum(palavra[i])){
			palavraNew[j++] = palavra[i]; 
		}
	}
	return palavraNew;
}

int comparaçãoCadeias (char *palavra, char *palavra2){
int cont1 = 0,cont2 = 0;
	for(int i=0;palavra[i] != '\0';i++){
		if(isdigit(palavra[i])){
			cont1++;
		}
	}
	for(int i=0;palavra2[i] != '\0';i++){
		if(isdigit(palavra2[i])){
			cont2++;
		}
	}
	if(cont1 > cont2){
		return cont1;
	}else if(cont1 < cont2){
		return cont2;
	}else if(cont1 == cont2){
		return cont1;
	}
}

int contarAlfanumericos(const char *palavra) {
	int count = 0;
	for (int i = 0; palavra[i] != '\0'; i++) {
		if (isalnum((unsigned char)palavra[i])) {
			count++;
		}
	}
	return count;
}

int contarSimbolos(const char *frase) {
	int count = 0;
	for (int i = 0; frase[i] != '\0'; i++) {
		if (isalnum((unsigned char)frase[i]) || frase[i] == ' ') {
			count++;
		}
	}
	return count;
}

void ex_1 (void){
int n,cont1 = 0, cont2 = 0;
lerInteiro(&n);
double a, b, valores[n];
lerReal(&a);
lerReal(&b);
// garantir A < B
	if(a>b){
		double c = a;
		b = a;
		a = c;
	}
// ler valores reais
	for(int i=0;i<=n;i++){
		lerReal(&valores[i]);
	}
// testar valores
	for(int i=0;i<=n;i++){
		if(valores[i]>=a && valores[i]<=b){
			cont1++;
		}else{
			cont2++;
		}
	}
	printf("\n dentro do intervalo %d, fora %d",cont1,cont2);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_2 (void){
char palavra[100];
int cont = 0;
lerString(palavra);
	for(int i=0;palavra[i] != '\0';i++){
		if(islower(palavra[i])){
			if(palavra[i]>'c'&& palavra[i]<'p'){
				cont++;
				printf("%c",palavra[i]);
			}
		}
	}
	printf("contagem de: %d\n",cont);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_3 (void){
char palavra[100];
lerString(palavra);
int cont = 0;
	cont = functionContCeP(palavra);
	printf("%d",cont);
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_4 (void){
char palavra[100],palavraNew[100];
lerString(palavra);
	functionPartCeP(palavra,palavraNew);
	printf("%s",palavraNew);
	
	getchar();
	return (EXIT_SUCCESS);
}
void ex_5 (void){
char palavra[100];
lerString(palavra);
	int cont = functionContCcePp(palavra);
	printf("%d",cont);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_6 (void){
char palavra[100];
lerString(palavra);
	functionShowCcePp(palavra);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_7 (void){
char palavra[100];
lerString(palavra);
int cont = 0;
	cont = functionPares(palavra);
	printf("%d",cont);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_8 (void){
char palavra[100], palavraNew[100];
lerString(palavra);
	functionShowNotAllNum(palavra,palavraNew);
	printf("%s\n",palavraNew);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_9 (void){
char palavra[100],palavraNew[100];
lerString(palavra);
	functionShowAllNum(palavra,palavraNew);
	printf("%s\n",palavraNew);
	getchar();
	return (EXIT_SUCCESS);
}
void ex_10 (void){
char palavras[MAX_PALAVRAS][MAX_PALAVRA];
int totalAlfanumericos = 0;
int n;
lerInteiro(n);
	if (n > MAX_PALAVRAS) {
		printf("Número excede o limite permitido.\n");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		printf("Digite a palavra %d: ", i + 1);
		fgets(palavras[i], MAX_PALAVRA, stdin);
		palavras[i][strcspn(palavras[i], "\n")] = '\0';
	}
	for (int i = 0; i < n; i++) {
		int count = contarAlfanumericos(palavras[i]);
		printf("Palavra: %s | Alfanuméricos: %d\n", palavras[i], count);
		totalAlfanumericos += count;
	}
	
	printf("Total acumulado de caracteres alfanuméricos: %d\n", totalAlfanumericos);
	getchar();
	return (EXIT_SUCCESS);
}
void extra_01 (void) {
	char palavras[MAX_PALAVRAS][MAX_PALAVRA];
	int totalSimbolos = 0;
	int n;
lerInteiro(n);
	if (n > MAX_PALAVRAS) {
		printf("Número excede o limite permitido.\n");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		printf("Digite a frase %d: ", i + 1);
		fgets(palavras[i], MAX_PALAVRA, stdin);
		palavras[i][strcspn(palavras[i], "\n")] = '\0'; 
	}
	for (int i = 0; i < n; i++) {
		int count = contarSimbolos(palavras[i]);
		printf("Frase: \"%s\" | Símbolos alfanuméricos e espaços: %d\n", palavras[i], count);
		
		if (count > 3) {
			totalSimbolos += count;
		}
	}
	
	printf("Total acumulado de frases com mais de 3 símbolos: %d\n", totalSimbolos);
	
	getchar();
	return (EXIT_SUCCESS);
}
void extra_02 (void){
char palavra[100],palavra2[100];
lerString(palavra);
lerString(palavra2);
int cont = 0;
	cont = comparaçãoCadeias(palavra,palavra2);
	printf("%d\n",cont);
	
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
		
		printf  ( "\n%s", "Opcao = \n" );
		scanf  ( "%d", &opcao );
		getchar( );
		printf  ( "\n%s%d", "Opcao = \n", opcao );
		
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
