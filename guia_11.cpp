#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

const double PI = 3.14;
const int MAX = 10;

void lerString(std::string &palavra) {
	std::cout << "\nDigite uma sequencia de caracteres: ";
	std::cin >> palavra;
	std::cin.ignore();
}

void lerInteiro(int &numero) {
	std::cout << "\nDigite um numero inteiro: ";
	std::cin >> numero;
	std::cin.ignore();
}

void lerReal(double &numero) {
	std::cout << "\nDigite um valor real: ";
	std::cin >> numero;
	std::cin.ignore();
}

std::vector<int> lerArquivo(int &n, const std::string &nomeArquivo) {
	std::ifstream arquivo(nomeArquivo);
	if (!arquivo.is_open()) {
		std::cerr << "Erro ao abrir o arquivo.\n";
		exit(1);
	}
	
	arquivo >> n;
	std::vector<int> arranjo(n);
	for (int i = 0; i < n; ++i) {
		arquivo >> arranjo[i];
	}
	return arranjo;
}

std::vector<int> readArrayFile(const std::string& fileName){
	std::ifstream arquivo(fileName);
	if(!arquivo){
		std::cerr << "ERRO";
		return {};
	}
	int n;
	arquivo >> n;
	std::vector<int> array(n);
	for(int i=0;i<n;i++){
		arquivo >> array[i];
	}
	arquivo.close();
	return array;
}

int maiorImpar (const std::vector<int>& array){
	bool encontrou = false;
	int maior = 0;
	
	for (int valor : array) {
		if (valor % 2 != 0) {
			if (!encontrou || valor > maior) {
				maior = valor;
				encontrou = true;
			}
		}
	}
	
	if (!encontrou) {
		throw std::runtime_error("Nenhum valor ímpar encontrado.");
	}
	
	return maior;
}

int maiorImparMulti3 (const std::vector<int>& array){
	bool encontrou = false;
	int maior = 0;
	
	for (int valor : array) {
		if (valor % 2 != 0 && valor % 3 == 0) {
			if (!encontrou || valor > maior) {
				maior = valor;
				encontrou = true;
			}
		}
	}
	
	if (!encontrou) {
		throw std::runtime_error("Nenhum valor ímpar encontrado.");
	}
	
	return maior;
}

int arrayAddInterval ( const std::vector<int>&  array, int a, int b){
	int soma = 0;
		for(int i=a;i<b;i++){
			soma += array[i];
	}
	return soma;
}

int arrayMediaInterval (const std::vector<int>& array, int a, int b){
	int media = 0;
	int soma = 0, count = 0;
		for(int i=a;i<b;i++){
			soma += array[i];
			count++;
		}
	media = soma / count;
	return media;
}

int arrayTestPositive100 ( const std::vector<int>& array){
	int result = 1;
	for(int valor : array){
		if(!(valor >= 100)){
			result = 0;
		}
	}
	return result;
}

void arrayIsDecrescente (const std::vector<int>& array){
	int maior = array[0];
	int aux = 0;
	for(int valor : array){
		if(valor <= maior){
			maior = valor;
			aux = 0;
		}else{
			aux = 1;
		}
	}
	if(aux == 0){
		std::cout << "O array esta em ordem decrescente" << std::endl;
	}else{
		std::cout << "O array nao esta em ordem decrescente" << std::endl;
	}

}

void arraySearchInterval (const std::vector<int>& array, int inicial, int fim, int valor ){
	int aux = 0;
	for(int i=inicial-1;i<fim-1;i++){
		if(array[i] == valor){
			aux = 1;
		}
	}
	if(aux == 1){
		printf("\nValor encontrado");
	}else{
		printf("\nValor NAO encontrado");
	}
}

void arrayScalar (const std::vector<int>& array, int constante ){
	for(int valor : array){
		valor = valor * constante;
		std::cout << valor << std::endl;
	}
}

void sortDown(std::vector<int>& data) {
	int n = data.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (data[j] < data[j + 1]) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}

void printArray(const std::vector<int>& data) {
	for (int val : data) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

bool saoDiferentes(const std::vector<int>& a, const std::vector<int>& b) {
	if (a.size() != b.size()) {
		return true;
	}
	
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			return true;
		}
	}
	
	return false;
}

std::vector<int> calcularDiferencas(const std::vector<int>& a, const std::vector<int>& b) {
	std::vector<int> diferencas;
	
	if (a.size() != b.size()) {
		std::cerr << "Erro: Vetores de tamanhos diferentes!" << std::endl;
		return diferencas;
	}
	
	for (size_t i = 0; i < a.size(); ++i) {
		diferencas.push_back(a[i] - b[i]);
	}
	
	return diferencas;
}

void ex_1() { 
	int n;
	lerInteiro(n);
	std::srand(std::time(nullptr));
	std::vector<int> array(n);
	for(int i=0;i<n;i++){
		array[i] = std::rand()%1000;
	}
	std::ofstream arquivo("DADOS.TXT");
	if(!arquivo){
		std::cerr << "ERRO";
		return;
	}
	arquivo << n << "\n";
	for(int i=0;i<n;i++){
		arquivo << array[i] << "\n";
	}
	arquivo.close();
	std::cin.get(); 
}
void ex_2() { 
		std::vector<int> array = readArrayFile("DADOS.TXT");
		int maior = maiorImpar(array);
		std::cout << "Maior valor impar" << maior << std::endl;
	std::cin.get();
}
void ex_3() { 
		std::vector<int> array = readArrayFile("DADOS.TXT");
		int maior = maiorImparMulti3(array);
		std::cout << "Maior valor impar multiplo de 3 e" << maior << std::endl;
	
	std::cin.get(); 
}
void ex_4() {
		std::vector<int> array = readArrayFile("DADOS.TXT");
		int inicio, fim;
		std::cin >> inicio;
		std::cin >> fim;
	int soma = arrayAddInterval(array,inicio,fim);
	std::cout << "\n";
	std::cout << "Valor da soma e " << soma << std::endl;
	
	std::cin.get();
}
void ex_5() { 
		std::vector<int> array = readArrayFile("DADOS.TXT");
		int inicio, fim;
		std::cin >> inicio;
		std::cin >> fim;
	int media = arrayMediaInterval(array, inicio, fim);
	std::cout << "\n";
	std::cout << "A media e igual a " << media << std::endl;
	
	std::cin.get();
}
void ex_6() {
	std::vector<int> array = readArrayFile("DADOS.TXT");
	int result = arrayTestPositive100(array);
	std::cout << "\n";
	if(result == 1){
		std::cout << "Todos os valores sao positivos e maiores que 100" << std::endl;
	}else{
		std::cout << "Nem todos os valores sao positivos e maiores que 100" << std::endl;
	}
	std::cin.get();
}
void ex_7() { 
	std::vector<int> array = readArrayFile("DADOS.TXT");
	arrayIsDecrescente(array);
	std::cin.get(); 
}
void ex_8() { 
	std::vector<int> array = readArrayFile("DADOS.TXT");
	int inicio, fim, valor;
	std::cin >> inicio;
	do {
		std::cin >> fim;
	} while(fim <= inicio);
	std::cin >> valor;
	arraySearchInterval(array, inicio, fim, valor);
	std::cin.get();
}
void ex_9() { 
	std::vector<int> array = readArrayFile("DADOS.TXT");
	int constante;
	std::cin >> constante;
	arrayScalar(array, constante);
	std::cin.get();
}
void ex_10() { 
	std::vector<int> array = readArrayFile("DADOS.TXT");
	sortDown(array);
	printArray(array);
	std::cin.get();
}
void extra_01() { 
	std::vector<int> array1 = readArrayFile("DADOS.TXT");
	std::vector<int> array2 = array1;
	
	sortDown(array2);
	
	if (saoDiferentes(array1, array2)) {
		std::cout << "Os arranjos sao diferentes em pelo menos uma posicao." << std::endl;
	} else {
		std::cout << "Os arranjos são iguais em todas as posicoes." << std::endl;
	}
	std::cin.get();
}
void extra_02() { 
	std::vector<int> array1 = readArrayFile("DADOS.TXT");
	std::vector<int> array2 = array1;
	
	sortDown(array2);

	std::vector<int> diferencas = calcularDiferencas(array1, array2);
	
	std::cout << "Diferencas posicao a posição (original - ordenado):" << std::endl;
	printArray(diferencas);
	std::cin.get();
}

int main(int argc, char* argv[]) {
	int opcao = 0;
	std::cout << "Guia02 - Programa = v0.0\n";
	std::cout << "Autor: Gabriel da Silva Amaral\n\n";
	
	do {
		std::cout << "\nOpcoes:\n";
		std::cout << "0 - Terminar\n";
		std::cout << "1 - exercicio 01\n";
		std::cout << "2 - exercicio 02\n";
		std::cout << "3 - exercicio 03\n";
		std::cout << "4 - exercicio 04\n";
		std::cout << "5 - exercicio 05\n";
		std::cout << "6 - exercicio 06\n";
		std::cout << "7 - exercicio 07\n";
		std::cout << "8 - exercicio 08\n";
		std::cout << "9 - exercicio 09\n";
		std::cout << "10 - exercicio 10\n";
		std::cout << "11 - extra 01\n";
		std::cout << "12 - extra 02\n";
		std::cout << "\nOpcao = ";
		std::cin >> opcao;
		std::cin.ignore();
		
		std::cout << "\nOpcao = " << opcao << "\n";
		
		switch (opcao) {
			case 0: break;
			case 1: ex_1(); break;
			case 2: ex_2(); break;
			case 3: ex_3(); break;
			case 4: ex_4(); break;
			case 5: ex_5(); break;
			case 6: ex_6(); break;
			case 7: ex_7(); break;
			case 8: ex_8(); break;
			case 9: ex_9(); break;
			case 10: ex_10(); break;
			case 11: extra_01(); break;
			case 12: extra_02(); break;
		default:
			std::cerr << "\nERRO: Opcao invalida.\n";
			break;
		}
	} while (opcao != 0);
	
	std::cout << "\n\nApertar ENTER para terminar.";
	std::cin.get();
	
	return 0;
}

