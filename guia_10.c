#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

/*

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

int randValue (int a, int b){
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	return rand() % (b-a+1)+ a;
}

void arraySearch (int array[], int valor, int n, char *fileName){
	FILE *arquivo = fopen(fileName,"w");
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
		return;
	}
	int encontrado = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] == valor) {
			fprintf(arquivo, "O valor %d foi encontrado na posição %d do array.\n", valor, i);
			encontrado = 1;
		}
	}
	
	if (!encontrado) {
		fprintf(arquivo, "O valor %d NAO foi encontrado no array.\n", valor);
	}
	fclose(arquivo);
}

int *readArquivoToArray(const char *fileName, int *n) {
	FILE *arquivo = fopen(fileName, "r");
	if (arquivo == NULL) {
		perror("ERRO ao abrir o arquivo");
		return NULL;
	}
	
	if (fscanf(arquivo, "%d", n) != 1) {
		fprintf(stderr, "ERRO ao ler o tamanho do array\n");
		fclose(arquivo);
		return NULL;
	}
	
	int *array = (int *) malloc(*n * sizeof(int));
	if (array == NULL) {
		perror("Erro ao alocar memória");
		fclose(arquivo);
		return NULL;
	}
	
	for (int i = 0; i < *n; i++) {
		if (fscanf(arquivo, "%d", &array[i]) != 1) {
			fprintf(stderr, "Erro ao ler valor %d\n", i);
			free(array);
			fclose(arquivo);
			return NULL;
		}
	}
	
	fclose(arquivo);
	return array;
}

int *arrayAdd(const int *arr1, int n1, const int *arr2, int n2, int constante) {
	if (n1 != n2) {
		fprintf(stderr, "Erro: os tamanhos dos arranjos sao incompativeis.\n");
		return NULL;
	}
	
	int *resultado = (int *) malloc(n1 * sizeof(int));
	if (resultado == NULL) {
		perror("Erro ao alocar memoria para resultado");
		return NULL;
	}
	
	for (int i = 0; i < n1; i++) {
		resultado[i] = arr1[i] + constante * arr2[i];
	}
	
	return resultado;
}

int isArrayDecrescent(const int *array, int n) {
	int decrescente = 1;
	
	for (int i = 1; i < n; i++) {
		if (array[i - 1] < array[i]) {
			decrescente = 0;
		}
	}
	
	return decrescente;
}

int **readMatrixFromFile(const char *fileName, int *rows, int *cols) {
	FILE *arquivo = fopen(fileName, "r");
	if (!arquivo) {
		perror("Erro ao abrir o arquivo");
		return NULL;
	}
	
	if (fscanf(arquivo, "%d %d", rows, cols) != 2) {
		fprintf(stderr, "Erro ao ler dimensões da matriz\n");
		fclose(arquivo);
		return NULL;
	}
	
	int **matriz = (int **) malloc(*rows * sizeof(int *));
	if (!matriz) {
		perror("Erro ao alocar linhas");
		fclose(arquivo);
		return NULL;
	}
	
	for (int i = 0; i < *rows; i++) {
		matriz[i] = (int *) malloc(*cols * sizeof(int));
		if (!matriz[i]) {
			perror("Erro ao alocar colunas");
			for (int k = 0; k < i; k++) free(matriz[k]);
			free(matriz);
			fclose(arquivo);
			return NULL;
		}
		
		for (int j = 0; j < *cols; j++) {
			if (fscanf(arquivo, "%d", &matriz[i][j]) != 1) {
				fprintf(stderr, "Erro ao ler valor [%d][%d]\n", i, j);
				for (int k = 0; k <= i; k++) free(matriz[k]);
				free(matriz);
				fclose(arquivo);
				return NULL;
			}
		}
	}
	
	fclose(arquivo);
	return matriz;
}

int **matrixTranspose(int **matriz, int rows, int cols) {
	int **transposta = (int **) malloc(cols * sizeof(int *));
	if (!transposta) return NULL;
	
	for (int i = 0; i < cols; i++) {
		transposta[i] = (int *) malloc(rows * sizeof(int));
		if (!transposta[i]) {
			for (int k = 0; k < i; k++) free(transposta[k]);
			free(transposta);
			return NULL;
		}
		
		for (int j = 0; j < rows; j++) {
			transposta[i][j] = matriz[j][i];
		}
	}
	
	return transposta;
}

int matrixZero(int **matriz, int rows, int cols) {
	int Zero = 1;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matriz[i][j] != 0) {
				Zero = 0;
			}
		}
	}
	
	return Zero;
}

int matrixCompare(int **mat1, int rows1, int cols1,
	int **mat2, int rows2, int cols2) {
		if (rows1 != rows2 || cols1 != cols2) {
			return 0;
		}
		
		int iguais = 1;
		
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols1; j++) {
				if (mat1[i][j] != mat2[i][j]) {
					iguais = 0;
				}
			}
		}
		
		return iguais;
	}

int **matrixAdd(int **mat1, int rows1, int cols1, 
	int constant, int **mat2, int rows2, int cols2) {
		if (rows1 != rows2 || cols1 != cols2) {
			printf("As dimensões das matrizes não são compativeis.\n");
			return NULL;
		}
		
		int **result = (int **) malloc(rows1 * sizeof(int *));
		if (!result) return NULL;
		
		for (int i = 0; i < rows1; i++) {
			result[i] = (int *) malloc(cols1 * sizeof(int));
			if (!result[i]) {
				for (int j = 0; j < i; j++) free(result[j]);
				free(result);
				return NULL;
			}
			
			for (int j = 0; j < cols1; j++) {

				result[i][j] = mat1[i][j] + constant * mat2[i][j];
			}
		}
		
		return result;
	}

int **matrixProduct(int **mat1, int rows1, int cols1, 
	int **mat2, int rows2, int cols2) {
		if (cols1 != rows2) {
			printf("As dimensões das matrizes não são compatíveis para multiplicação.\n");
			return NULL; 
		}
		int **result = (int **) malloc(rows1 * sizeof(int *));
		if (!result) return NULL;
		
		for (int i = 0; i < rows1; i++) {
			result[i] = (int *) malloc(cols2 * sizeof(int));
			if (!result[i]) {
				for (int j = 0; j < i; j++) free(result[j]);
				free(result);
				return NULL;
			}
			
			for (int j = 0; j < cols2; j++) {
				result[i][j] = 0;
				for (int k = 0; k < cols1; k++) {
					result[i][j] += mat1[i][k] * mat2[k][j];
				}
			}
		}
		
		return result;
	}

void arraySortDescending(int *array, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (array[j] < array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int identityMatrix(int **matrix, int rows, int cols) {
	if (rows != cols) return 0;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
				return 0;
			}
		}
	}
	return 1;
}

void printMatrix(int **matriz, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void ex_1 (void){
	int n, a, b;
	lerInteiro(&n);
	lerInteiro(&a);
	lerInteiro(&b);
	srand(time(NULL));
	if(a<b){
		int aux;
		aux = a;
		a = b;
		b = aux;
	}
	int *array;
	array = (int *) malloc(n*sizeof(int));
	if (array == NULL) {
		perror("Erro ao alocar memória");
		return;
	}
	for(int i=0;i<n;i++){
		array[i] = randValue(a,b);
	}
	FILE *arquivo = fopen("EXERCICIO01.TXT","w");
	if(arquivo == NULL){
		perror("ERRO ao abrir o arquivo");
		return;
	}
	fprintf(arquivo,"%d\n",n);
	for(int i=0;i<n;i++){
		fprintf(arquivo,"%d\n", array[i]);
	}
	free(array);
	fclose(arquivo);
	getchar();
	return;
}
void ex_2 (void){
	int n, valor;
	lerInteiro(&n);
	int *array;
	array = (int *) malloc(n*sizeof(int));
	if(array == NULL){
		perror("ERRO de alocação");
		return;
	}
	for(int i=0;i<n;i++){
		lerInteiro(&array[i]);
	}
	printf("\n digite o valor a ser procurado");
	scanf("%d", &valor);
	arraySearch(array,valor,n,"EXERCICIO02.TXT");
	free(array);
	getchar();
	return;
}
void ex_3 (void){
	int *array1;
	int *array2;
	int n1, n2;
	
	array1 = readArquivoToArray("ARRAY01.TXT", &n1);
	if (array1 == NULL) {
		printf("Erro ao ler ARRAY01.TXT\n");
		return;
	}
	
	array2 = readArquivoToArray("ARRAY02.TXT", &n2);
	if (array2 == NULL) {
		printf("Erro ao ler ARRAY02.TXT\n");
		free(array1);
		return;
	}
	
	if (n1 == n2) {
		printf("\nValores que pertencem aos dois arrays:\n");
		
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				if (array1[i] == array2[j]) {
					printf("O valor %d pertence aos dois arrays\n", array1[i]);
					break;
				}
			}
		}
		
	} else {
		printf("Os arrays têm tamanhos diferentes.\n");
	}
	
	free(array1);
	free(array2);
	getchar();
	return;
}
void ex_4 (void){
	int n1, n2;
	int *array1 = readArquivoToArray("ARRAY01.TXT", &n1);
	int *array2 = readArquivoToArray("ARRAY02.TXT", &n2);
	
	if (!array1 || !array1) return;
	
	int constante = 2; // Exemplo
	int *soma = arrayAdd(array1, n1, array1, n2, constante);
	
	if (soma) {
		printf("Resultado da soma com multiplicação por %d:\n", constante);
		for (int i = 0; i < n1; i++) {
			printf("%d ", soma[i]);
		}
		printf("\n");
		free(soma);
	}
	free(array1);
	free(array2);
	getchar();
	return;
}
void ex_5 (void){
	int *array;
	int n;

	
	array = readArquivoToArray("ARRAY01.TXT", &n);
	if (array == NULL) return;
	
	int resposta = isArrayDecrescent(array, n);
	
	if (resposta) {
		printf("O arranjo esta em ordem decrescente.\n");
	} else {
		printf("O arranjo NAO esta em ordem decrescente.\n");
	}
	
	free(array);
	getchar();
	return;
}
void ex_6 (void){
	int rows, cols;
	int **matriz = readMatrixFromFile("DADOS1.TXT", &rows, &cols);
	if (!matriz) return;
	
	int **transposta = matrixTranspose(matriz, rows, cols);
	if (!transposta) return;
	
	printf("Matriz original:\n");
	printMatrix(matriz, rows, cols);
	
	printf("\nMatriz transposta:\n");
	printMatrix(transposta, cols, rows);
	
	free(matriz);
	free(transposta);
	getchar();
	return;
}
void ex_7 (void){
	int rows, cols;
	int **matriz = readMatrixFromFile("DADOS1.TXT", &rows, &cols);
	if (!matriz) return;
	
	int resposta = matrixZero(matriz, rows, cols);
	if (resposta) {
		printf("A matriz contem apenas zeros.\n");
	} else {
		printf("A matriz contem pelo menos um valor diferente de zero.\n");
	}
	
	free(matriz);
	getchar();
	return;
}
void ex_8 (void){
	int rows1, cols1, rows2, cols2;
	int **matriz1 = readMatrixFromFile("DADOS1.TXT", &rows1, &cols1);
	int **matriz2 = readMatrixFromFile("DADOS2.TXT", &rows2, &cols2);
	
	if (!matriz1 || !matriz2) {
		printf("Erro ao ler matrizes.\n");
		return;
	}
	
	int iguais = matrixCompare(matriz1, rows1, cols1, matriz2, rows2, cols2);
	
	if (iguais) {
		printf("As matrizes sao iguais.\n");
	} else {
		printf("As matrizes sao diferentes.\n");
	}
	free(matriz1);
	free(matriz2);
	
	getchar();
	return;
}
void ex_9 (void){
	int rows1, cols1, rows2, cols2;
		int **matriz1 = readMatrixFromFile("DADOS1.TXT", &rows1, &cols1);
		int **matriz2 = readMatrixFromFile("DADOS2.TXT", &rows2, &cols2);
		
		if (!matriz1 || !matriz2) {
			printf("Erro ao ler matrizes.\n");
			return;
		}

		int constante = -1;
		int **soma = matrixAdd(matriz1, rows1, cols1, constante, matriz2, rows2, cols2);
		if (!soma) {
			printf("Erro ao realizar a soma das matrizes.\n");
			return;
		}
	printMatrix(soma,rows1,cols1);
	
	free(matriz2);
	free(matriz1);
	free(soma);
	
	getchar();
	return;
}
void ex_10 (void){
	int rows1, cols1, rows2, cols2;

	int **matriz1 = readMatrixFromFile("DADOS1.TXT", &rows1, &cols1);
	int **matriz2 = readMatrixFromFile("DADOS2.TXT", &rows2, &cols2);
	
	if (!matriz1 || !matriz2) {
		printf("Erro ao ler matrizes.\n");
		return;
	}
	int **produto = matrixProduct(matriz1, rows1, cols1, matriz2, rows2, cols2);
	if (!produto) {
		printf("Erro ao realizar o produto das matrizes.\n");
		return;
	}
	printf("Matriz resultante do produto:\n");
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			printf("%d ", produto[i][j]);
		}
		printf("\n");
	}
	free(matriz1);
	free(matriz2);
	free(produto);
	getchar();
	return;
}
void extra_01 (void) {
	int* readArquivoToArray(const char *fileName, int *n);
	void arraySortDescending(int *array, int n);
	
		int n;
		int *array = readArquivoToArray("ARRAY01.TXT", &n);
		
		if (!array) {
			printf("Erro ao ler arquivo.\n");
			return;
		}
		
		arraySortDescending(array, n);
		
		printf("\nArranjo ordenado em ordem decrescente:\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");
		
		free(array);
	getchar();
	return;
}
void extra_02 (void){
	int r1, c1, r2, c2;
	int **matriz1 = readMatrixFromFile("DADOS1.TXT", &r1, &c1);
	int **matriz2 = readMatrixFromFile("DADOS2.TXT", &r2, &c2);
	
	if (!matriz1 || !matriz2) {
		printf("Erro ao ler arquivos.\n");
		return;
	}
	if (c1 != r2) {
		printf("Matrizes com dimensoes incompativeis para multiplicacao.\n");
		return;
	}
	
	int **produto = matrixProduct(matriz1, r1, c1, matriz2, r2, c2);
	
	if (!produto) {
		printf("Erro ao calcular produto.\n");
		return;
	}
	
	if (identityMatrix(produto, r1, c2)) {
		printf("\nO produto e a matriz identidade.\n");
	} else {
		printf("\nO produto NAO e a matriz identidade.\n");
	}
	
	free(matriz1);
	free(matriz2);
	free(produto);
	getchar();
	return;
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
