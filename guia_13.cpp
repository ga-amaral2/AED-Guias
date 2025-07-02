
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

class Contato {
private:
	std::string enderecoResidencial;
	std::string enderecoProfissional;
	std::string nome;
	std::vector<std::string> telefones;
	int qtdTelefones = 0;
	
	bool isValidPhone(const std::string& tel) {
		for (char c : tel) {
			if (!isdigit(c) && c != '-') return false;
		}
		return true;
	}
	
public:
	Contato() {
		nome = "";
		qtdTelefones = 0;
	}
	
	Contato(std::string n, std::string t1, std::string t2 = "") {
		nome = n;
		if (!t1.empty()) {
			telefones.push_back(t1);
			qtdTelefones++;
		}
		if (!t2.empty()) {
			telefones.push_back(t2);
			qtdTelefones++;
		}
	}
	
	void readName() {
		std::cout << "Nome: ";
		std::getline(std::cin, nome);
	}
	
	void readPhone() {
		std::string tel;
		std::cout << "Fone: ";
		std::getline(std::cin, tel);
		if (!tel.empty()) {
			telefones.push_back(tel);
			qtdTelefones++;
		}
	}
	
	void show() {
		std::cout << "Nome: " << nome << "\n";
		for (int i = 0; i < qtdTelefones; i++) {
			std::cout << "Fone[" << i+1 << "]: " << telefones[i] << "\n";
		}
	}
	
	bool validarUltimoTelefone() {
		if (telefones.empty()) return false;
		return isValidPhone(telefones.back());
	}
	
	void readFromFile(const std::string& nomeArquivo) {
		std::ifstream arq(nomeArquivo);
		if (arq.is_open()) {
			std::getline(arq, nome);
			std::string tel;
			telefones.clear();
			qtdTelefones = 0;
			while (std::getline(arq, tel)) {
				telefones.push_back(tel);
				qtdTelefones++;
			}
			arq.close();
		} else {
			std::cerr << "Erro ao abrir arquivo.\n";
		}
	}
	
	void writeToFile(const std::string& nomeArquivo) {
		std::ofstream arq(nomeArquivo);
		if (arq.is_open()) {
			arq << nome << "\n";
			for (const auto& t : telefones) {
				arq << t << "\n";
			}
			arq.close();
			std::cout << "Dados gravados com sucesso.\n";
		} else {
			std::cerr << "Erro ao criar arquivo.\n";
		}
	}
	
	int getQtdTelefones() {
		return qtdTelefones;
	}
	
	void setPhone2a(const std::string& novo) {
		if (qtdTelefones == 1) {
			telefones.push_back(novo);
			qtdTelefones++;
		}
	}
	
	void setPhone2b(const std::string& novo) {
		if (qtdTelefones >= 2) {
			telefones[1] = novo;
		} else {
			std::cerr << "Erro: segundo telefone não existe.\n";
		}
	}
	void addPhone(const std::string& tel) {
		if (qtdTelefones < 10 && !tel.empty()) {
			telefones.push_back(tel);
			qtdTelefones++;
		}
	}
	
	void setPhone2c() {
		if (qtdTelefones >= 2) {
			telefones.erase(telefones.begin() + 1);
			qtdTelefones--;
		} else {
			std::cerr << "Erro: nenhum segundo telefone para remover.\n";
		}
	}
	void setEnderecoResidencial(const std::string& endereco) {
		enderecoResidencial = endereco;
	}
	
	void setEnderecoProfissional(const std::string& endereco) {
		enderecoProfissional = endereco;
	}
};



void ex_1() {
	Contato c;
	c.readName();
	c.show();
	std::cin.get();
}

void ex_2() {
	Contato c;
	c.readPhone();
	c.show();
	std::cin.get();
}

void ex_3() {
	Contato c;
	c.readPhone();
	if (c.validarUltimoTelefone()) std::cout << "Telefone válido!\n";
	else std::cout << "Telefone inválido!\n";
	std::cin.get();
}

void ex_4() {
	Contato c;
	c.readFromFile("Pessoa1.txt");
	c.show();
	std::cin.get();
}

void ex_5() {
	Contato c;
	c.readName();
	c.readPhone();
	c.writeToFile("Pessoa1.txt");
	std::cin.get();
}

void ex_6() {
	Contato c("Joao", "99999-1111", "98888-2222");
	c.show();
	std::cin.get();
}

void ex_7() {
	Contato c("Maria", "8888-1111", "87777-3333");
	std::cout << "Qtd Telefones: " << c.getQtdTelefones() << "\n";
	std::cin.get();
}

void ex_8() {
	Contato c("Luis", "1234-5678");
	c.setPhone2a("9999-9999");
	c.show();
	std::cin.get();
}

void ex_9() {
	Contato c("Pedro", "1234-5678", "1111-2222");
	c.setPhone2b("2222-3333");
	c.show();
	std::cin.get();
}

void ex_10() {
	Contato c("Ana", "9999-1111", "4444-5555");
	c.setPhone2c();
	c.show();
	std::cin.get();
}

void extra_01() { 
	Contato c;
	c.readName();
	for (int i = 0; i < 10; ++i) {
		std::cout << "Digite telefone [" << i+1 << "] (vazio para parar): ";
		std::string tel;
		std::getline(std::cin, tel);
		if (tel.empty()) break;
		c.addPhone(tel);
	}
	c.show();
	std::cin.get();
}
void extra_02() { 
	Contato c;
	c.readName();
	c.readPhone();
	std::string end1, end2;
	std::cout << "Endereco Residencial: ";
	std::getline(std::cin, end1);
	c.setEnderecoResidencial(end1);
	
	std::cout << "Endereco Profissional: ";
	std::getline(std::cin, end2);
	c.setEnderecoProfissional(end2);
	
	c.show();
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

