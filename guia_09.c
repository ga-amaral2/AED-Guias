#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PI 3,14
#define MAX 10

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

void readPositiveDoubleMatrix(int *rows, int *cols, double matrix[MAX][MAX]) {
	do {
		printf("Digite o número de linhas (1 a %d): ", MAX);
		scanf("%d", rows);
	} while (*rows <= 0 || *rows > MAX);
	
	do {
		printf("Digite o número de colunas (1 a %d): ", MAX);
		scanf("%d", cols);
	} while (*cols <= 0 || *cols > MAX);
	
	for (int i = 0; i < *rows; i++) {
		for (int j = 0; j < *cols; j++) {
			do {
				printf("Digite o elemento [%d][%d] (>= 0): ", i, j);
				scanf("%lf", &matrix[i][j]);
				if (matrix[i][j] < 0) {
					printf("Erro: valor negativo não permitido.\n");
				}
			} while (matrix[i][j] < 0);
		}
	}
}

void printDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	printf("\nMatriz:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%6.2lf ", matrix[i][j]);
		}
		printf("\n");
	}
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

void fprintDoubleMatrix(const char *filename, int rows, int cols, double matrix[MAX][MAX]) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
	}
	fprintf(file, "%d %d\n", rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(file, "%.2lf ", matrix[i][j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}
void freadDoubleMatrix(const char *filename, int *rows, int *cols, double matrix[MAX][MAX]) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Erro ao abrir o arquivo para leitura.\n");
		return;
	}
	
	fscanf(file, "%d %d", rows, cols);
	for (int i = 0; i < *rows; i++) {
		for (int j = 0; j < *cols; j++) {
			fscanf(file, "%lf", &matrix[i][j]);
		}
	}
	
	fclose(file);
}

void printDiagonalDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Não há diagonal principal.\n");
		return;
	}
	
	printf("Diagonal principal:\n");
	for (int i = 0; i < rows; i++) {
		printf("Elemento [%d][%d] = %.2lf\n", i, i, matrix[i][i]);
	}
}

void printSDiagonalDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Não há diagonal secundária.\n");
		return;
	}
	
	printf("Diagonal secundária:\n");
	for (int i = 0; i < rows; i++) {
		int j = cols - 1 - i;
		printf("Elemento [%d][%d] = %.2lf\n", i, j, matrix[i][j]);
	}
}

void printLDTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Não há triângulo inferior definido.\n");
		return;
	}
	
	printf("Valores abaixo da diagonal principal:\n");
	for (int i = 1; i < rows; i++) {   
		for (int j = 0; j < i; j++) {  
			printf("Elemento [%d][%d] = %.2lf\n", i, j, matrix[i][j]);
		}
	}
}

void printLUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Não há triângulo superior definido.\n");
		return;
	}
	
	printf("Valores acima da diagonal principal:\n");
	for (int i = 0; i < rows - 1; i++) {
		for (int j = i + 1; j < cols; j++) {
			printf("Elemento [%d][%d] = %.2lf\n", i, j, matrix[i][j]);
		}
	}
}

void printSLDTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Não há triângulo inferior da diagonal secundária definido.\n");
		return;
	}
	
	int n = rows;
	printf("Valores abaixo e na diagonal secundária:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j >= n - 1) {
				printf("Elemento [%d][%d] = %.2lf\n", i, j, matrix[i][j]);
			}
		}
	}
}

void printSLUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Não há triângulo superior da diagonal secundária definido.\n");
		return;
	}
	
	int n = rows;
	printf("Valores acima e na diagonal secundária:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j <= n - 1) {
				printf("Elemento [%d][%d] = %.2lf\n", i, j, matrix[i][j]);
			}
		}
	}
}

bool allZerosLTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Teste inválido.\n");
		return false;
	}
	
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j < i; j++) {
			if (matrix[i][j] != 0.0) {
				return false; 
			}
		}
	}
	
	return true; 
}

bool allZerosUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) {
	if (rows != cols) {
		printf("A matriz não é quadrada. Teste inválido.\n");
		return false;
	}
	
	for (int i = 0; i < rows - 1; i++) {
		for (int j = i + 1; j < cols; j++) {
			if (matrix[i][j] != 0.0) {
				return false;
			}
		}
	}
	
	return true; 
}

void generateMatrixAndSaveToFile(int rows, int cols, int matrix[MAX][MAX], const char* filename) {
	int counter = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = i; j < cols; j++) {
			matrix[i][j] = counter;
			counter += 4;
		}
		counter = i + 2;
	}
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Erro ao abrir o arquivo para gravação.\n");
		return;
	}
	fprintf(file, "%d %d\n", rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(file, "%d ", matrix[i][j]);
		}
		fprintf(file, "\n");
	}
	
	fclose(file);
	printf("Matriz gravada no arquivo %s\n", filename);
}

void ex_1 (void){
	int linhas, colunas;
	double positiveMatrix[MAX][MAX];	
	readPositiveDoubleMatrix(&linhas, &colunas, positiveMatrix);
	printDoubleMatrix(linhas, colunas, positiveMatrix);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_2 (void){
	int rows, cols;
	double matrix[MAX][MAX];
	double matrixFromFile[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, matrix);
	fprintDoubleMatrix("MATRIX_01.TXT", rows, cols, matrix);
	printf("\nMatriz gravada em 'MATRIX_01.TXT'.\n");
	freadDoubleMatrix("MATRIX_01.TXT", &rows, &cols, matrixFromFile);
	printf("\nMatriz lida do arquivo:\n");
	printDoubleMatrix(rows, cols, matrixFromFile);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_3 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix);
	printDiagonalDoubleMatrix(rows, cols, positiveMatrix);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_4 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix);
	printSDiagonalDoubleMatrix(rows, cols, positiveMatrix);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_5 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix); 
	printLDTriangleDoubleMatrix(rows, cols, positiveMatrix);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_6 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix); 
	printLUTriangleDoubleMatrix(rows, cols, positiveMatrix);
	return;
}
void ex_7 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix); 
	printSLDTriangleDoubleMatrix(rows, cols, positiveMatrix);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_8 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix); 
	printSLUTriangleDoubleMatrix(rows, cols, positiveMatrix);
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_9 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix); 
	bool result = allZerosLTriangleDoubleMatrix(rows, cols, positiveMatrix);
	if (result) {
		printf("Todos os valores abaixo da diagonal principal sao zeros.\n");
	} else {
		printf("Ha valores diferentes de zero abaixo da diagonal principal.\n");
	}
	
	return 0;
	getchar();
	return; //(EXIT_SUCCESS);
}
void ex_10 (void){
	int rows, cols;
	double positiveMatrix[MAX][MAX];
	readPositiveDoubleMatrix(&rows, &cols, positiveMatrix);
	bool result = allZerosUTriangleDoubleMatrix(rows, cols, positiveMatrix);	
	if (result) {
		printf("Todos os valores acima da diagonal principal são zeros.\n");
	} else {
		printf("Há valores diferentes de zero acima da diagonal principal.\n");
	}
	
	return 0;
	getchar();
	return; //(EXIT_SUCCESS);
}
void extra_01 (void) {
	int rows, cols;
		int matrix[MAX][MAX];
		char filename[] = "matrix_output.txt";
		lerInteiro(&rows);
		lerInteiro(&cols);
		
		generateMatrixAndSaveToFile(rows, cols, matrix, filename);
		
		return 0;
	getchar();
	return; //(EXIT_SUCCESS);
}
void extra_02 (void){
	int rows, cols;
	int matrix[MAX][MAX];
	char filename[] = "matrix_output_09E2.txt"; 
	lerInteiro(&rows);
	lerInteiro(&cols);
	generateMatrixAndSaveToFile(rows, cols, matrix, filename);
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
