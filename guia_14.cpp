#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <algorithm>

const double PI = 3.14;
const int MAX = 10;

class MyString {
private:
	std::string texto;
	
public:
	MyString(std::string valor = "") : texto(valor) {}
	
	void setTexto(std::string valor) {
		texto = valor;
	}
	
	std::string getTexto() const {
		return texto;
	}
	
	int getInt() {
		for (char c : texto)
			if (!isdigit(c) && c != '-') return -1;
		return std::stoi(texto);
	}
	
	double getDouble() {
		bool ponto = false;
		for (char c : texto)
			if (!isdigit(c) && c != '-' && c != '.') return 0.0;
		return std::stod(texto);
	}
	
	bool getBoolean() {
		std::string temp = texto;
		for (char &c : temp) c = std::tolower(c);
		return (temp == "true" || temp == "t" || temp == "1");
	}
	
	bool contains(std::string subtexto) {
		return texto.find(subtexto) != std::string::npos;
	}
	
	std::string toUpperCase() {
		std::string resultado = texto;
		for (char &c : resultado) c = std::toupper(c);
		return resultado;
	}
	
	std::string toLowerCase() {
		std::string resultado = texto;
		for (char &c : resultado) c = std::tolower(c);
		return resultado;
	}
	
	std::string replace(char original, char novo) {
		std::string resultado = texto;
		for (char &c : resultado)
			if (c == original) c = novo;
		return resultado;
	}
	
	std::string encrypt() {
		std::string resultado = texto;
		for (char &c : resultado)
			if (isalpha(c)) c = (c - 'a' + 3) % 26 + 'a';
		return resultado;
	}
	
	std::string decrypt() {
		std::string resultado = texto;
		for (char &c : resultado)
			if (isalpha(c)) c = (c - 'a' - 3 + 26) % 26 + 'a';
		return resultado;
	}
	
	int split(std::string sequencia[]) {
		int count = 0;
		std::string palavra = "";
		for (char c : texto) {
			if (c == ' ') {
				if (!palavra.empty()) {
					sequencia[count++] = palavra;
					palavra = "";
				}
			} else {
				palavra += c;
			}
		}
		if (!palavra.empty()) sequencia[count++] = palavra;
		return count;
	}
	
	int split(std::string sequencia[], char delimitador) {
		int count = 0;
		std::string palavra = "";
		for (char c : texto) {
			if (c == delimitador) {
				if (!palavra.empty()) {
					sequencia[count++] = palavra;
					palavra = "";
				}
			} else {
				palavra += c;
			}
		}
		if (!palavra.empty()) sequencia[count++] = palavra;
		return count;
	}
	
	std::string reverse() {
		std::string resultado = texto;
		std::reverse(resultado.begin(), resultado.end());
		return resultado;
	}
};

void ex_1() {
	MyString s("-123");
	std::cout << "Inteiro: " << s.getInt() << "\n";
	std::cin.get();
}

void ex_2() {
	MyString s("3.14");
	std::cout << "Double: " << s.getDouble() << "\n";
	std::cin.get();
}

void ex_3() {
	MyString s("true");
	std::cout << "Boolean: " << s.getBoolean() << "\n";
	std::cin.get();
}

void ex_4() {
	MyString s("exemplo de texto");
	std::cout << "Contem 'de'? " << s.contains("de") << "\n";
	std::cin.get();
}

void ex_5() {
	MyString s("texto");
	std::cout << "Maiusculas: " << s.toUpperCase() << "\n";
	std::cin.get();
}

void ex_6() {
	MyString s("TEXTO");
	std::cout << "Minusculas: " << s.toLowerCase() << "\n";
	std::cin.get();
}

void ex_7() {
	MyString s("banana");
	std::cout << "Substituicao: " << s.replace('a', 'o') << "\n";
	std::cin.get();
}

void ex_8() {
	MyString s("abc");
	std::cout << "Criptografado: " << s.encrypt() << "\n";
	std::cin.get();
}

void ex_9() {
	MyString s("def");
	std::cout << "Descriptografado: " << s.decrypt() << "\n";
	std::cin.get();
}

void ex_10() {
	MyString s("a b c d");
	std::string partes[10];
	int qtd = s.split(partes);
	for (int i = 0; i < qtd; ++i) std::cout << partes[i] << "\n";
	std::cin.get();
}

void extra_01() {
	MyString s("um-dois-tres");
	std::string partes[10];
	int qtd = s.split(partes, '-');
	for (int i = 0; i < qtd; ++i) std::cout << partes[i] << "\n";
	std::cin.get();
}

void extra_02() {
	MyString s("invertido");
	std::cout << "Invertido: " << s.reverse() << "\n";
	std::cin.get();
}

int main() {
	int opcao;
	std::cout << "Guia14 - Programa = v0.0\n";
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
			default: std::cout << "Opcao invalida.\n"; break;
		}
	} while (opcao != 0);
	return 0;
}

