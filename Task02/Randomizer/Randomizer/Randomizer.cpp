#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "stdio.h"
#include <iostream>
#include <string>

// Файл для записи сгенерированных входных данных.
FILE* file_;
std::ofstream file(std::string(argv[2]));
// Запись данных для афоризмов, поговорок и загадок
void writeAphorisms();
void writeWords();
void writeHints();
// Генератор случайного числа.
int getRandomNumber(int min, int max);
// Случайный элемент строки для альтернатив.
char getRandomChar(char min, char max);

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("first argument must be the number of figures or 'r' - random number, and the second must be full path of file to write the result in");
        return 1;
    }

    int size;
    srand(static_cast<unsigned int>(time(0)));
    if (!strcmp(argv[1], "r")) {
        size = getRandomNumber(1, 10000);
    }
    else {
        size = atoi(argv[1]);
        if (size < 1 || size > 10000) {
            printf("number of figures must be positive and no more than 10000");
            return 2;
        }
    }
    file_ = fopen(argv[2], "w");

    int figure;
    std::string involve;
    for (int fig = 0; fig < size; ++fig) {
        figure = getRandomNumber(1, 3);
        involve = getRandomChar(33, 123);
        fprintf(file_, "%d ", figure);
        std::cout << figure;
        switch (figure) {
        case 1:
            writeAphorisms();
            break;
        case 2:
            writeWords();
            break;
        case 3:
            writeHints();
            break;
        }
    }

    return 0;
}

// Запись корректных координат вершин прямоугольника.
// Запись цитаты со знаками препинания в файл.
void writeAphorisms() {
    int count = getRandomNumber(1, 25);
    int count_word;
    std::string speech;
    for (int i = 0; i < count; i++) {
        count_word = getRandomNumber(1, 10);
        for (int j = 0; j < count_word; j++) {
            speech += getRandomChar(33, 123);
        }
        speech += " ";

    }
    fprintf(file_, "\n");
    for (int i = 0; i < speech.length(); i++) {
        putc(speech[i], file_);
    }
    fprintf(file_, "\n");
}

// Запись корректных координат вершин треугольника.
void writeWords() {

    int count = getRandomNumber(1, 3);
    int count_word;
    std::string speech;
    for (int i = 0; i < count; i++) {
        count_word = getRandomNumber(1, 7);
        for (int j = 0; j < count_word; j++) {
            speech += getRandomChar(33, 123);
        }
        speech += " ";

    }
    fprintf(file_, "\n");
    for (int i = 0; i < speech.length(); i++) {
        putc(speech[i], file_);
    }
    fprintf(file_, "\n");
}

// Запись корректных координаты вершины центра круга и его радиуса.
void writeHints() {
    int count = getRandomNumber(1, 2);
    int count_word;
    std::string speech;
    for (int i = 0; i < count; i++) {
        count_word = getRandomNumber(1, 5);
        for (int j = 0; j < count_word; j++) {
            speech += getRandomChar(33, 123);
        }
        speech += " ";

    }
    fprintf(file_, "\n");
    for (int i = 0; i < speech.length(); i++) {
        putc(speech[i], file_);
    }
    fprintf(file_, "\n");
}

// получение случайного числа от min до max включительно
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
char getRandomChar(char min, char max) {
    return rand() % (max - min + 1) + min;
}