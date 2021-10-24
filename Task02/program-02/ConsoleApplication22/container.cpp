//------------------------------------------------------------------------------
// container.cpp - файл содержит методы для обработки контейнера
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "container.h"
#include <string>
#include <iostream>
#include "shape.h"
#include "hint.h"
#include "aphorism.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{ 0 } { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE* file) {
    int k;
    while (fscanf(file, "%d", &k) != EOF) {
        if ((storage[len] = Shape::StaticIn(file, k)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Shape::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//-------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE* file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i + 1);
        storage[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// Вывод обработки данных контейнера
void Container::ProcessingString(FILE* file) {
    double* qsorted = new double[len];
    for (int i = 0; i < len; i++) {
        qsorted[i] = storage[i]->Mean();
    }
    // Сортировка элементов контейнера.
    quicksort(qsorted, 0, len - 1);
    // Вывод отсортированных данных в файл.
    fprintf(file, "Output sorted container by Quick sort :\n");
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d : ", i + 1);
    //    storage[i]->Out(file);
        fprintf(file,"Function Quick sort : %d\n",char(qsorted[i])); 
    }
}
// -----------------------------------------------------------------------------
// Метод для сортировки элементов контейнера по заданной функции.
void Container::quicksort(double* mas, int first, int last)
{
    int mid, count;
    int f = first, l = last;
    // Вычисление центрального элемента.
    mid = mas[(f + l) / 2]; 
    do
    {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
        // Процесс перестановки элементов.
        if (f <= l) 
        {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}
