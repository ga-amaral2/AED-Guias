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

class Matriz {
private:
	std::vector<std::vector<int>> data;
	int rows = 0;
	int cols = 0;
	
public:
	void readMatriz() {
		std::cout << "Digite a quantidade de linhas: ";
		std::cin >> rows;
		std::cout << "Digite a quantidade de colunas: ";
		std::cin >> cols;
		if (rows <= 0 || cols <= 0) {
			std::cerr << "Dimensoes invalidas.\n";
			rows = cols = 0;
			return;
		}
		data.resize(rows, std::vector<int>(cols));
	}
	
	void randomGenerator(int inferior, int superior) {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = inferior + std::rand() % (superior - inferior + 1);
			}
		}
	}
	
	void saveFile(const std::string& fileName) {
		std::ofstream arquivo(fileName);
		if (!arquivo) {
			std::cerr << "Erro ao abrir arquivo para escrita.\n";
			return;
		}
		arquivo << rows << ' ' << cols << '\n';
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				arquivo << data[i][j] << '\n';
			}
		}
		arquivo.close();
	}
	
	void print() const {
		for (const auto& row : data) {
			for (int num : row)
				std::cout << num << " ";
			std::cout << '\n';
		}
	}
	
	static Matriz readMatrizFile(const std::string& fileName) {
		std::ifstream arquivo(fileName);
		Matriz matriz;
		if (!arquivo) {
			std::cerr << "Erro ao abrir arquivo para leitura.\n";
			return matriz;
		}
		
		arquivo >> matriz.rows >> matriz.cols;
		
		std::vector<int> valores;
		int value;
		while (arquivo >> value) {
			valores.push_back(value);
		}
		arquivo.close();
		
		if (valores.size() != static_cast<size_t>(matriz.rows * matriz.cols)) {
			std::cerr << "Erro: quantidade de dados não compatível com as dimensões.\n";
			matriz.rows = matriz.cols = 0;
			matriz.data.clear();
			return matriz;
		}
		
		matriz.data.resize(matriz.rows, std::vector<int>(matriz.cols));
		int index = 0;
		for (int i = 0; i < matriz.rows; i++)
			for (int j = 0; j < matriz.cols; j++)
				matriz.data[i][j] = valores[index++];
		
		return matriz;
	}
	
	Matriz scalar(int constante) {
		Matriz result;
		result.rows = rows;
		result.cols = cols;
		result.data.resize(rows, std::vector<int>(cols));
		
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result.data[i][j] = data[i][j] * constante;
		return result;
	}
	
	bool identidade() const {
		if (rows != cols)
			return false;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i == j && data[i][j] != 1)
					return false;
				if (i != j && data[i][j] != 0)
					return false;
			}
		}
		return true;
	}
	
	bool operator==(const Matriz& other) const {
		if (rows != other.rows || cols != other.cols)
			return false;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				if (data[i][j] != other.data[i][j])
					return false;
		return true;
	}
	
	Matriz add(const Matriz& other) const {
		Matriz result;
		if (rows != other.rows || cols != other.cols) {
			std::cerr << "Erro: dimensões diferentes.\n";
			return result;
		}
		result.rows = rows;
		result.cols = cols;
		result.data.resize(rows, std::vector<int>(cols));
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result.data[i][j] = data[i][j] + other.data[i][j];
		return result;
	}
	
	void addRows(int row1, int row2, int constante) {
		if (row1 >= 0 && row1 < rows && row2 >= 0 && row2 < rows) {
			for (int j = 0; j < cols; j++) {
				data[row1][j] += constante * data[row2][j];
			}
		} else {
			std::cerr << "Erro: índices de linha inválidos.\n";
		}
	}
	
	void subtrairRows(int row1, int row2, int constante) {
		if (row1 >= 0 && row1 < rows && row2 >= 0 && row2 < rows) {
			for (int j = 0; j < cols; j++) {
				data[row1][j] -= constante * data[row2][j];
			}
		} else {
			std::cerr << "Erro: índices de linha inválidos.\n";
		}
	}
	
	int searchRows(int valor) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (data[i][j] == valor) {
					return i;
				}
			}
		}
		return -1;
	}
	
	int searchCols(int valor) const {
		for (int j = 0; j < cols; j++) {
			for (int i = 0; i < rows; i++) {
				if (data[i][j] == valor) {
					return j;
				}
			}
		}
		return -1;
	}
	
	void transpose() {
		std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; ++j)
				transposed[j][i] = data[i][j];
		data = transposed;
		std::swap(rows, cols);
	}
	
	int get(int i, int j) const {
		if (i >= 0 && i < rows && j >= 0 && j < cols)
			return data[i][j];
		throw std::out_of_range("Índices inválidos no get()");
	}
	
	void set(int i, int j, int valor) {
		if (i >= 0 && i < rows && j >= 0 && j < cols)
			data[i][j] = valor;
		else
			throw std::out_of_range("Índices inválidos no set()");
	}
	
	int getRows() const { return rows; }
	int getColumns() const { return cols; }
};


void ex_1() {
	Matriz matriz;
	matriz.readMatriz();
	matriz.randomGenerator(1, 100);
	matriz.saveFile("DADOS.TXT");
}

void ex_2() {
	Matriz matriz1 = Matriz::readMatrizFile("DADOS.TXT");
	Matriz matriz2 = matriz1.scalar(3);
	matriz2.print();
}

void ex_3() {
	Matriz matriz1 = Matriz::readMatrizFile("DADOS.TXT");
	std::cout << (matriz1.identidade() ? "Matriz identidade\n" : "NAO matriz identidade\n");
}

void ex_4() {
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	Matriz m2 = Matriz::readMatrizFile("DADOS2.TXT");
	std::cout << (m1 == m2 ? "SAO iguais\n" : "NAO sao iguais\n");
}

void ex_5() {
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	Matriz m2 = Matriz::readMatrizFile("DADOS2.TXT");
	Matriz soma = m1.add(m2);
	soma.print();
}

void ex_6() {
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	m1.addRows(0, 1, -1);
	m1.print();
}

void ex_7() {
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	m1.subtrairRows(0, 1, 2);
	m1.print();
}

void ex_8() {
	int procurado;
	std::cout << "\ndigite o valor a procurar: ";
	std::cin >> procurado;
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	int linha = m1.searchRows(procurado);
	std::cout << (linha >= 0 ? "valor encontrado na linha " + std::to_string(linha) : "valor nao encontrado") << "\n";
}

void ex_9() {
	int procurado;
	std::cout << "\ndigite o valor a procurar: ";
	std::cin >> procurado;
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	int coluna = m1.searchCols(procurado);
	std::cout << (coluna >= 0 ? "valor encontrado na coluna " + std::to_string(coluna) : "nao encontrado") << "\n";
}

void ex_10() {
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	m1.transpose();
	m1.print();
}

void extra_01() {
	Matriz m1 = Matriz::readMatrizFile("DADOS.TXT");
	bool condicao = true;
	for (int i = 0; i < m1.getRows() && condicao; i++) {
		for (int j = 0; j < m1.getColumns() && condicao; j++) {
			if (m1.get(i, j) < 0) condicao = false;
		}
	}
	std::cout << (condicao ? "Matriz satisfaz a condicao especial\n" : "Matriz NAO satisfaz a condicao especial\n");
}

void extra_02() {
	int n = 4;
	Matriz m;
	m.readMatriz();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m.set(i, j, (i + 1) * (j + 1));
		}
	}
	m.print();
}

int main() {
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
	std::cin.ignore();
	return 0;
}

