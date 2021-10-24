#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "math.h"
#include "Hint.h"
#include <iostream>

//------------------------------------------------------------------------------
// Ввод строк из указанного потока.
void Hint::In(FILE* file) {
	fscanf(file, "%d", &hint);
}
// Случайный ввод параметров.
void Hint::InRnd() {
	int count = Shape::rnd25.Get();
	int count_word;
	std::string speech;
	for (int i = 0; i < count; i++) {
		count_word = Shape::rnd7.Get();
		for (int j = 0; j < count_word; j++) {
			speech += Shape::rndChar.Get();
		}
		speech += " ";
	}
	hint = speech;
}
//------------------------------------------------------------------------------
// Вывод параметров строк в поток.
void Hint::Out(FILE* file) {
	fprintf(file, "It is Hint. Text and Number of marks:\n");
	for (int i = 0; i < hint.length(); i++) {
		putc(hint[i], file);
	}
	double mean = Mean();
	fprintf(file, "\n%d\nMean function : %d\n", NumberMarks(), char(mean));
}
//------------------------------------------------------------------------------
// Вычисление числа знаков препинания.
int Hint::NumberMarks() {
	char mas[] = { '.', ',', '!', '?', ';', ':', '-' };
	int number_marks = 0;
	for (int i = 0; i < hint.length(); ++i) {
		for (size_t k = 0; k < sizeof(mas); ++k) {
			if (hint[i] == mas[k]) {
				number_marks++;
			}
		}
	}
	return number_marks;
}
// -----------------------------------------------------------------------------
// Вычисление значения указанной функции.
double Hint::Mean() {
	if (NumberMarks() != 0)
		return hint.length() / NumberMarks();
	return 0;
}