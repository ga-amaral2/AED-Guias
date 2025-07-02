#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

const double PI = 3.14;

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

// Exercícios
void ex_1() { 
	std::cin.get(); 
}
void ex_2() { 
	std::cin.get();
}
void ex_3() { 
	std::cin.get(); 
}
void ex_4() {
	std::cin.get();
}
void ex_5() { 
	std::cin.get();
}
void ex_6() {
	std::cin.get();
}
void ex_7() { 
	std::cin.get(); 
}
void ex_8() { 
	std::cin.get();
}
void ex_9() { 
	std::cin.get();
}
void ex_10() { 
	std::cin.get();
}
void extra_01() { 
	std::cin.get();
}
void extra_02() { 
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

