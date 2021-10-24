//------------------------------------------------------------------------------
// word.cpp - содержит процедуры для работы с фигурами речи.
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "word.h"
#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров из файла.

void Word::In(FILE* file) {
	fscanf(file, "%d", &country);

}
//------------------------------------------------------------------------------
// Случайный ввод параметров.
void Word::InRnd() {
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
	country = speech;
}

//------------------------------------------------------------------------------
// Вывод параметров в форматируемый поток
void Word::Out(FILE* file) {
	fprintf(file, "It is Word. Text and Number of marks:\n");
	for (int i = 0; i < country.length(); i++) {
		putc(country[i], file);
	}
	double mean = Mean();
	fprintf(file, "\n%d\nMean function : %d\n", NumberMarks(),char(mean));
}

//------------------------------------------------------------------------------
// Вычисление числа знаков препинания
int Word::NumberMarks() {
	char mas[] = { '.', ',', '!', '?', ';', ':', '-' };
	int number_marks = 0;
	for (int i = 0; i < country.length(); ++i) {
		for (size_t k = 0; k < sizeof(mas); ++k) {
			if (country[i] == mas[k]) {
				number_marks++;
			}
		}
	}
	return number_marks;
}
// -----------------------------------------------------------------------------
// Вычисление значения указанной функции.
double Word::Mean() {
	if (NumberMarks() != 0)
		return country.length() / NumberMarks();
	return 0;
}