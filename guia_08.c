#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define PI 3,14

/*
definir numero aleatorio de 1 a 100
	srand(time(NULL));
	int n = (rand()%100)+1;
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

void lerPares(int *n, int array[]){
int i = 0;
int valor;
	while(i < *n){
		lerInteiro(&valor);
		if(valor > 0 && valor % 2 == 0){
			array[i] = valor;
			i++;
		}else{
			printf("Digite um valor Par e Positivo");
		}
	}
}

void gravarParesPositivos (int *n, int array[], char *FileName){
	FILE* arquivo = fopen( FileName, "wt");
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
		return;
	}
	int i = 0;
	int valor;
	fprintf(arquivo, "%d \n", *n);
	while(i < *n){
		lerInteiro(&valor);
		if(valor % 2 == 0 && valor >= 0){
			array[i] = valor;
			fprintf(arquivo, "%d \n", array[i]);
			i++;
		}
	}
	fclose(arquivo);
}

void gerarInt (int num1, int num2, int *n, int array[]){
	FILE *arquivo = fopen("DADOS.TXT", "wt");
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
		return;
	}
	fprintf(arquivo, "%d \n", *n);
	int i = 0;
	int valor;
	while(i < *n){
		valor = rand();
		if(valor >= num1 && valor <= num2){
			array[i] = valor;
			fprintf(arquivo, "%d \n", array[i]);
			i++;
		}
	}
	fclose(arquivo);
}

int* lerArquivo(int *n, const char *nomeArquivo) {
	FILE *arquivo = fopen(nomeArquivo, "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
	}
	fscanf(arquivo, "%d", n);
	int *arranjo = malloc(*n * sizeof(int));
	if (!arranjo) {
		printf("Erro de alocação de memória.\n");
		exit(1);
	}
	for (int i = 0; i < *n; i++) {
		fscanf(arquivo, "%d", &arranjo[i]);
	}
	fclose(arquivo);
	return arranjo;
}

int acharMenorPar(int n, int arranjo[]) {
	int menorPar = -1;
	for (int i = 0; i < n; i++) {
		if (arranjo[i] % 2 == 0) {
			menorPar = arranjo[i];
		}
	}
	if (menorPar == -1) {
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (arranjo[i] % 2 == 0 && arranjo[i] < menorPar) {
			menorPar = arranjo[i];
		}
	}	
	return menorPar;
}

int acharMaiorImparMulti3(int n, int array[]) {
	int maiorImparMulti3 = -1;
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 != 0 && array[i] % 3 == 0) {
			maiorImparMulti3 = array[i];
			break;
		}
	}
	if (maiorImparMulti3 == -1) {
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 != 0 && array[i] % 3 == 0 && array[i] > maiorImparMulti3) {
			maiorImparMulti3 = array[i];
		}
	}
	return maiorImparMulti3;
}

void gravarMenorMedia (int n ,int array[]){
int media = 0;
	for(int i=0;i<n;i++){
		media += array[i];
	}
	media = media / n;
FILE *arquivo = fopen("MENORQMEDIA.TXT", "wt");
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
	}
	for(int i=0;i<n;i++){
		if(array[i] <= media){
			fprintf(arquivo, "%d " , array[i]);
		}
	}
	fclose(arquivo);
	
}

void gravarMaiorMedia (int n, int array[]){
	int media = 0;
	for(int i=0;i<n;i++){
		media += array[i];
	}
	media = media / n;
	FILE *arquivo = fopen("MAIORQMEDIA.TXT", "wt");
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
	}
	for(int i=0;i<n;i++){
		if(array[i] > media){
			fprintf(arquivo, "%d " , array[i]);
		}
	}
	fclose(arquivo);
	
}

int estaOrdenadoDecrescente(int n, int arranjo[]) {
	int ordenado = 1;
	for (int i = 0; i < n - 1; i++) {
		if (arranjo[i] < arranjo[i + 1]) {
			ordenado = 0;
		}
	}
	return ordenado;
}

int acharValor(int valor, int inicio, int n, int array[]) {
	int achou = 0;
	for (int i = inicio; i < n; i++) {
		if (array[i] == valor) {
			achou = 1;
		}
	}
	return achou;
}

int acharPosicao(int valor, int inicio, int n, int array[]) {
	int posicao = -1;
	
	for (int i = inicio; i < n; i++) {
		if (array[i] == valor && posicao == -1) {
			posicao = i;
		}
	}
	
	return posicao; 
}

int acharQuantos(int valor, int inicio, int n, int array[]) {
	int contador = 0;
	for (int i = inicio; i < n; i++) {
		if (array[i] == valor) {
			contador++;
		}
	}	
	return contador;
}

int calcularDivisoresPares(int valor, int divisores[]) {
	int quantidade = 0;
	
	for (int i = 1; i <= valor; i++) {
		if (valor % i == 0 && i % 2 == 0) {
			divisores[quantidade] = i;
			quantidade++;
		}
	}
	
	return quantidade;
}

int filtrarPalavras(char resultado[10][50]) {
	FILE *arquivo = fopen("PALAVRAS.TXT", "rt");
	if (arquivo == NULL) {
		perror("Erro ao abrir o arquivo");
		return 0;
	}
	char palavra[50];
	int contador = 0;
	while (fscanf(arquivo, "%49s", palavra) == 1 && contador < 10) {
		int len = strlen(palavra);
		if (len > 0) {
			char primeira = tolower(palavra[0]);
			char ultima = tolower(palavra[len - 1]);
			
			if (primeira != 'e' && ultima != 'e') {
				strcpy(resultado[contador], palavra);
				contador++;
			}
		}
	}
	fclose(arquivo);
	return contador;
}

void ex_1 (void){
int n;
	do{
		lerInteiro(&n);
	}while(n<=0);
	int array[n];
	lerPares(&n, array);
	for(int i=0;i<=n-1;i++){
		printf("%d ,",array[i]);
	}
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_2 (void){
int n;
	do{
	lerInteiro(&n);
	}while(n<=0);
char name[100];
	lerString(&name);
	int array[n];
	gravarParesPositivos(&n, array, name);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_3 (void){
int n;
	do{
		lerInteiro(&n);
	}while(n<= 0);
	int array[n];
	int num1 = 0,num2 = 0;
	lerInteiro(&num1);
	lerInteiro(&num2);
	if(num1 > num2){
		int aux = num1;
		num1 = num2;
		num2 = aux;
	}
	gerarInt(num1, num2, &n, array);
	

	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_4 (void){
	int n;
	int *arranjo = lerArquivo(&n, "EXEMPLO.TXT");
	int menor = acharMenorPar(n, arranjo);
	
	if (menor == -1) {
		printf("Nenhum valor par encontrado.\n");
	} else {
		printf("O menor valor par é: %d\n", menor);
	}
	
	free(arranjo);
	return 0;;
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_5 (void){
	int n;
	int *array = lerArquivo(&n, "EXEMPLO.TXT");
	int maior = acharMaiorImparMulti3(n, array);
	if(maior == -1) {
		printf("Nenhum valor IMPAR encontrado.\n");
	} else {
		printf("O menor valor IMPAR MULTIPLO DE 3 é: %d\n", maior);
	}
		free(array);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_6 (void){
	int n;
	int *array = lerArquivo(&n, "DADOS.TXT");
	gravarMenorMedia(n, array);
	gravarMaiorMedia(n, array);
	free(array);
	return;
}
void ex_7 (void){
	int n;
	int *array = lerArquivo(&n, "DADOS.TXT");
		
		if (estaOrdenadoDecrescente(n, array)) {
			printf("\nO arranjo está em ordem decrescente.\n");
		} else {
			printf("\nO arranjo NÃO está em ordem decrescente.\n");
		}
		
		free(array);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_8 (void){
	int n, valor, posicaoInicial;
	int *array = lerArquivo(&n, "DADOS.TXT");
	lerInteiro(&valor);
	lerInteiro(&posicaoInicial);
	if (posicaoInicial < 0 || posicaoInicial >= n) {
		printf("Posição inicial inválida!\n");
	} else {
		int existe = acharValor(valor, posicaoInicial, n, array);
		if (existe) {
			printf("O valor %d foi encontrado a partir da posição %d.\n", valor, posicaoInicial);
		} else {
			printf("O valor %d NAO foi encontrado a partir da posição %d.\n", valor, posicaoInicial);
		}
	}
	free(array);
	
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_9 (void){
	int n, valor, posicaoInicial;
	int *array = lerArquivo(&n, "DADOS.TXT");
	lerInteiro(&valor);
	lerInteiro(&posicaoInicial);
	
	if (posicaoInicial < 0 || posicaoInicial >= n) {
		printf("Posição inicial inválida!\n");
	} else {
		int onde = acharPosicao(valor, posicaoInicial, n, array);
		if (onde == -1) {
			printf("O valor %d NAO foi encontrado a partir da posição %d.\n", valor, posicaoInicial);
		} else {
			printf("O valor %d foi encontrado na posição %d.\n", valor, onde);
		}
	}
	
	free(array);
	
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_10 (void){
	int n, valor, posicaoInicial;
	
	int *array = lerArquivo(&n, "DADOS.TXT");
	
	lerInteiro(&valor);
	lerInteiro(&posicaoInicial);
	if (posicaoInicial < 0 || posicaoInicial >= n) {
		printf("Posição inicial inválida!\n");
	} else {
		int vezes = acharQuantos(valor, posicaoInicial, n, array);
		if (vezes == 0) {
			printf("O valor %d NÃO foi encontrado a partir da posição %d.\n", valor, posicaoInicial);
		} else {
			printf("O valor %d foi encontrado %d vez(es) a partir da posição %d.\n", valor, vezes, posicaoInicial);
		}
	}
	free(array);
	getchar();
	return; //(EXIT_SUCCESS);
}
void extra_01 (void) {
	int n;
	lerInteiro(&n);
	int divisores[n];
	int qtd = calcularDivisoresPares(n, divisores);
	printf("Divisores pares de %d:\n", n);
	for (int i = 0; i < qtd; i++) {
		printf("%d ", divisores[i]);
	}
	printf("\n");
	
	FILE *arquivo = fopen("DIVISORES.TXT", "wt");
	if (arquivo == NULL) {
		perror("Erro ao abrir o arquivo");
		return;
	}
	
	for (int i = 0; i < qtd; i++) {
		fprintf(arquivo, "%d\n", divisores[i]);
	}
	
	fclose(arquivo);
	getchar();
	return; //(EXIT_SUCCESS);
}
void extra_02 (void){
	char palavras[10][50];
	int quantidade = filtrarPalavras(palavras);
		if (quantidade == 0) {
			printf("Nenhuma palavra válida foi encontrada.\n");
		} else {
			printf("Palavras que não começam nem terminam com 'e' ou 'E':\n");
			for (int i = 0; i < quantidade; i++) {
				printf("%s\n", palavras[i]);
			}
		}
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
