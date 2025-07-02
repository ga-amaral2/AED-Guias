#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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

void f_01arq(const char* fileName,int n) {
	FILE* arquivo = fopen(fileName, "wt");
	if (arquivo == NULL) {
		perror("Erro ao abrir o arquivo");
		return;
	}
	int i = 1;
	while(i<=n){
		fprintf(arquivo,"%d ",4*i);
		i++;
	}
	
	fclose(arquivo);
}

void f_02arq(char* fileName,int n){
	FILE* arquivo = fopen(fileName, "wt");
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
		return;
	}
	int count = 0, valor = 0;
	for (valor = 150; valor >= 30 && count < n; valor -= 15) {
		if (valor % 2 == 0) {
			fprintf(arquivo, "%d\n", valor);
			count++;
		}
	}
	
	fclose(arquivo);
}


void f_03arq(char* fileName, int n) {
	FILE* arquivo = fopen(fileName, "wt");
	
	if (arquivo == NULL) {
		perror("ERRO ao abrir o arquivo");
		return;
	}
	
	for (int i = 0; i <= n; i++) {
		int valor = (int)pow(3, i);
		fprintf(arquivo, "%d\n", valor);
	}
	
	fclose(arquivo);
}

void f_04arq (char* fileName, int n){
	FILE* arquivo = fopen(fileName, "wt");
	
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
		return;
	}
	for(int i=n;i>=0;i--){
		int valor = (int) pow(3,i);
		fprintf(arquivo, "1/%d ",valor);
	}
	fclose(arquivo);
}

void f_05arq (char* fileName, int n, double x){
	FILE* arquivo = fopen(fileName, "wt");
	
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
		return;
	}
	int y = 1;
	for(int i=0;i<=n;i++){
		double sequencia = pow(x,y);
		y += 2;
		fprintf(arquivo, "1/%lf ", sequencia);
	}
	
	
	fclose(arquivo);
}

void somaValores(char* inputFile, char* outputFile, int qtd){
	FILE* arquivo = fopen(inputFile, "rt");
	FILE* resultado = fopen(outputFile, "at"); 
	if (arquivo == NULL || resultado == NULL){
		perror("Erro ao abrir arquivos");
		return;
	}
	
	double soma = 0.0;
	char buffer[100];
	int contador = 0;
	
	while (fscanf(arquivo, "1/%s", buffer) == 1 && contador < qtd){
		double valor = atof(buffer);
		soma += 1.0 / valor;
		contador++;
	}
	
	fprintf(resultado, "Quantidade: %d | Soma: %.10lf\n", qtd, soma);
	
	fclose(arquivo);
	fclose(resultado);
}

void f_07arq (char* inputFile, char* outputFile, int n){
	FILE* arquivo = fopen(inputFile, "rt");
	FILE* resultado = fopen(outputFile, "at");
	if(arquivo == NULL || resultado == NULL){
		perror("ERRO ao abrir arquivos");
		return;
	}
	double termos[1000];
	int totalLido = 0;
	while (totalLido < n && fscanf(arquivo, "%lf", &termos[totalLido]) == 1) {
		totalLido++;
	}
	for (int i = 1; i <= totalLido; i++) {
		double soma = 0.0;
		for (int j = 0; j < i; j++) {
			soma += termos[j];
		}
		fprintf(resultado, "n = %d => %.10f\n", i, soma);
	}
	
	fclose(arquivo);
	fclose(resultado);
	printf("Resultados gravados em RESULTADO07.TXT com sucesso.\n");
}

int Par(int numero) {
	return numero % 2 == 0;
}

void f_08arq(char* fileName,int n) {
	FILE *arquivo = fopen(fileName, "w");
	
	if (arquivo == NULL) {
		perror("Erro ao abrir o arquivo\n");
		return;
	}
	
	int a = 0, b = 1, contador = 0;
	
	while (contador < n) {
		int proximo = a + b;
		a = b;
		b = proximo;
		
		if (Par(proximo)) {
			fprintf(arquivo, "%d\n", proximo);
			contador++;
		}
	}
	
	fclose(arquivo);
	printf("Os %d primeiros pares da série de Fibonacci foram gravados em RESULTADO08.TXT com sucesso.\n", n);
}

int contarMaiusculas(const char* texto) {
	int contador = 0;
	for (int i = 0; texto[i] != '\0'; i++) {
		if (isupper(texto[i])) {
			contador++;
		}
	}
	return contador;
}

void f_09arq(char* inputFile, char* outputFile) {
	FILE *arquivo = fopen(inputFile, "r");
	FILE *resultado = fopen(outputFile, "w");
	
	if (arquivo == NULL || resultado == NULL) {
		printf("Erro ao abrir arquivos.\n");
		return;
	}
	
	char linha[256];
	
	
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		linha[strcspn(linha, "\n")] = '\0';
		
		int qtdMaiusculas = contarMaiusculas(linha);
		fprintf(resultado, "%s => %d\n", linha, qtdMaiusculas);
	}
	
	fclose(arquivo);
	fclose(resultado);
	printf("Resultados gravados em RESULTADO09.TXT com sucesso.\n");
}

int contarDigitosMaioresIgual3(const char* texto) {
	int contador = 0;
	for (int i = 0; texto[i] != '\0'; i++) {
		if (isdigit((unsigned char)texto[i])) {
			if (texto[i] >= '3') {
				contador++;
			}
		}
	}
	return contador;
}

void f_10arq(char* inputFile, char* outputFile) {
	FILE* arquivo = fopen(inputFile, "r");
	FILE* resultado = fopen(outputFile, "w");
	
	if (arquivo == NULL || resultado == NULL) {
		printf("Erro ao abrir arquivos.\n");
		return;
	}
	
	char linha[512];
	
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		// Remove o \n, se presente
		linha[strcspn(linha, "\n")] = '\0';
		
		int digitos = contarDigitosMaioresIgual3(linha);
		fprintf(resultado, "%s => %d\n", linha, digitos);
	}
	
	fclose(arquivo);
	fclose(resultado);
	printf("Resultados gravados em RESULTADO10.TXT com sucesso.\n");
}

void f_extra01arq(char* fileName,int num) {
	FILE *arquivo = fopen(fileName, "w");
	
	if (arquivo == NULL) {
		printf("Erro ao abrir arquivo\n");
		return;
	}
	
	for (int i = num; i >= 1; i--) {
		if (num % i == 0 && i % 2 != 0) {
			fprintf(arquivo, "%d\n", i);
		}
	}
	
	fclose(arquivo);
	printf("Divisores ímpares gravados em %s com sucesso.\n",fileName);
}

int contarPalavrasValidasE2(const char* nomeArquivo) {
	FILE *arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
		return -1;
	}
	char linha[256];
	int contador = 0;
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		linha[strcspn(linha, "\n")] = '\0';
		size_t len = strlen(linha);
		if ((linha[0] == 'c' || linha[0] == 'C') && len <= 12) {
			contador++;
		}
	}
	
	fclose(arquivo);
	return contador;
}

void f_extra02arq() {
	const char *nomeArquivo = "ARQUIVOEXTRA02.TXT";
	
	int resultado = contarPalavrasValidasE2(nomeArquivo);
	
	if (resultado >= 0) {
		printf("Total de palavras que começam com 'c' ou 'C' e têm até 12 caracteres: %d\n", resultado);
	}
}

void ex_1 (void){
	int n;
	lerInteiro(&n);
	f_01arq("ARQUIVO01.TXT", n);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_2 (void){
	int n;
	lerInteiro(&n);
	f_02arq("ARQUIVO02.TXT", n);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_3 (void){
	int n;
	lerInteiro(&n);
	f_03arq("ARQUIVO03.TXT", n);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_4 (void){
	int n;
	lerInteiro(&n);
	f_04arq("ARQUIVO04.TXT", n);
	
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_5 (void){
	int n;
	lerInteiro(&n);
	double x;
	lerReal(&x);
	f_05arq("ARQUIVO05.TXT",n,x);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_6 (void){
	f_05arq("RESULTADO05.TXT", 10, 2.0);

	somaValores("RESULTADO05.TXT", "RESULTADO06.TXT", 3);
	somaValores("RESULTADO05.TXT", "RESULTADO06.TXT", 5);
	somaValores("RESULTADO05.TXT", "RESULTADO06.TXT", 7);
	
	return;
}
void ex_7 (void){
int n;
	lerInteiro(&n);
	f_04arq("RESULTADO04.TXT", n);
	
	f_07arq("RESULTADO04.TXT", "ARQUIVO07.TXT",n);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_8 (void){
int n;
lerInteiro(&n);
	f_08arq("ARQUIVO08.TXT",n);
	
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_9 (void){
	f_09arq("ARQUIVO09.TXT", "RESULTADO09.TXT");
	
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_10 (void){
	f_10arq("ARQUIVO10.TXT", "RESULTADO10.TXT");
	getchar();
	return; //(EXIT_SUCCESS);
}
void extra_01 (void) {
int n;
lerInteiro(&n);
	f_extra01arq("ARQUIVOEXTRA01.TXT",n);
	getchar();
	return; //(EXIT_SUCCESS);
}
void extra_02 (void){
	f_extra02arq();
	getchar();
	return; //(EXIT_SUCCESS);
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
