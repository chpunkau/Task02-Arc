//------------------------------------------------------------------------------
// aphorism.cpp - �������� ��������� ��� ������ � �������������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"
#include "aphorism.h"

//------------------------------------------------------------------------------
// ���� ���������� �������� �� ������.
void Aphorism::In(FILE* file) {
	fscanf(file, "%d", &author);
}

// ��������� ���� ���������� ��������.
void Aphorism::InRnd() {
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
	author = speech;

}

//------------------------------------------------------------------------------
// ����� ���������� �������� � �����.
void Aphorism::Out(FILE* file) {
	fprintf(file, "It is Aphorism. Text and Number of marks:\n");
	for (int i = 0; i < author.length(); i++) {
		putc(author[i], file);
	}
	double mean = Mean();
	fprintf(file, "\n%d\nMean function : %d\n", NumberMarks(), char(mean));
}

//------------------------------------------------------------------------------
// ���������� ����� ������ ����������.
int Aphorism::NumberMarks() {
	char mas[] = { '.', ',', '!', '?', ';', ':', '-' };
	int number_marks = 0;
	for (int i = 0; i < author.length(); ++i) {
		for (size_t k = 0; k < sizeof(mas); ++k) {
			if (author[i] == mas[k]) {
				number_marks++;
			}
		}
	}
	return number_marks;
}
// ���������� �������� ��������� �������.
double Aphorism::Mean() {
	if (NumberMarks() != 0)
		return author.length() / NumberMarks();
	return 0;
}