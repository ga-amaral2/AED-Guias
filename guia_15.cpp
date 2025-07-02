#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
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

using namespace std;

char* str_push_back(char *s, char c) {
	int len = strlen(s);
	s[len] = c;
	s[len+1] = '\0';
	return s;
}

char* str_pop_back(char *s) {
	int len = strlen(s);
	if (len > 0) s[len-1] = '\0';
	return s;
}

char* str_push_front(char c, char *s) {
	int len = strlen(s);
	for (int i = len; i >= 0; i--) s[i+1] = s[i];
	s[0] = c;
	return s;
}

char* str_pop_front(char *s) {
	int len = strlen(s);
	if (len > 0) for (int i = 0; i < len; i++) s[i] = s[i+1];
	return s;
}

char* str_push_mid(char *s, char c) {
	int len = strlen(s);
	if (len < 2) return s;
	int mid = len / 2;
	for (int i = len; i >= mid; i--) s[i+1] = s[i];
	s[mid] = c;
	return s;
}

char* str_pop_mid(char *s) {
	int len = strlen(s);
	if (len < 2) return s;
	int mid = len / 2;
	for (int i = mid; i < len; i++) s[i] = s[i+1];
	return s;
}

char* str_insert(char *s, char c, int index) {
	int len = strlen(s);
	if (index < 0 || index > len) return s;
	for (int i = len; i >= index; i--) s[i+1] = s[i];
	s[index] = c;
	return s;
}

char* str_remove(char *s, int index) {
	int len = strlen(s);
	if (index < 0 || index >= len) return s;
	for (int i = index; i < len; i++) s[i] = s[i+1];
	return s;
}

char* str_chr(char *s, char c) {
	while (*s) {
		if (*s == c) return s;
		s++;
	}
	return nullptr;
}

char* str_tok(char *s, char delimiter) {
	static char *p;
	if (s) p = s;
	if (!p || *p == '\0') return nullptr;
	char *start = p;
	while (*p && *p != delimiter) p++;
	if (*p == delimiter) *p++ = '\0';
	return start;
}

char* str_prefix(char *prefix, char *s) {
	while (*s) {
		char *ps = s;
		char *pp = prefix;
		while (*pp && *ps == *pp) {
			ps++; pp++;
		}
		if (*pp == '\0') return s;
		s++;
	}
	return nullptr;
}

char* str_suffix_chr(char *s, char *suffix) {
	int len_s = strlen(s);
	int len_suf = strlen(suffix);
	if (len_s < len_suf) return nullptr;
	if (strcmp(s + len_s - len_suf, suffix) == 0) return s + len_s - len_suf;
	return nullptr;
}

void ex_1() {
	char s[100] = "hello";
	char c = '!';
	cout << "Antes: " << s << endl;
	str_push_back(s, c);
	cout << "Depois de push_back: " << s << endl;
	cin.get();
}

void ex_2() {
	char s[100] = "hello!";
	cout << "Antes: " << s << endl;
	str_pop_back(s);
	cout << "Depois de pop_back: " << s << endl;
	cin.get();
}

void ex_3() {
	char s[100] = "ello";
	char c = 'H';
	cout << "Antes: " << s << endl;
	str_push_front(c, s);
	cout << "Depois de push_front: " << s << endl;
	cin.get();
}

void ex_4() {
	char s[100] = "Hello";
	cout << "Antes: " << s << endl;
	str_pop_front(s);
	cout << "Depois de pop_front: " << s << endl;
	cin.get();
}

void ex_5() {
	char s[100] = "Heo";
	char c = 'l';
	cout << "Antes: " << s << endl;
	str_push_mid(s, c);
	cout << "Depois de push_mid: " << s << endl;
	cin.get();
}

void ex_6() {
	char s[100] = "Hello";
	cout << "Antes: " << s << endl;
	str_pop_mid(s);
	cout << "Depois de pop_mid: " << s << endl;
	cin.get();
}

void ex_7() {
	char s[100] = "Helo";
	char c = 'l';
	int pos = 2;
	cout << "Antes: " << s << endl;
	str_insert(s, c, pos);
	cout << "Depois de insert: " << s << endl;
	cin.get();
}

void ex_8() {
	char s[100] = "Hello";
	int pos = 2;
	cout << "Antes: " << s << endl;
	str_remove(s, pos);
	cout << "Depois de remove: " << s << endl;
	cin.get();
}

void ex_9() {
	char s[100] = "Hello";
	char c = 'l';
	char *p = str_chr(s, c);
	if (p) cout << "Encontrado '" << c << "' em: " << p << endl;
	else cout << "Caractere nao encontrado.\n";
	cin.get();
}

void ex_10() {
	char s[100] = "parte1,parte2";
	char *token = str_tok(s, ',');
	while (token) {
		cout << "Token: " << token << endl;
		token = str_tok(nullptr, ',');
	}
	cin.get();
}

void extra_01() {
	char s[100] = "abcdef";
	char prefix[100] = "abc";
	char *p = str_prefix(prefix, s);
	if (p) cout << "Prefixo encontrado em: " << p << endl;
	else cout << "Prefixo nao encontrado.\n";
	cin.get();
}

void extra_02() {
	char s[100] = "abcdef";
	char suffix[100] = "def";
	char *p = str_suffix_chr(s, suffix);
	if (p) cout << "Sufixo encontrado em: " << p << endl;
	else cout << "Sufixo nao encontrado.\n";
	cin.get();
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

