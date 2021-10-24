//------------------------------------------------------------------------------
// container.cpp - ���� �������� ������ ��� ��������� ����������
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
// ����������� ����������
Container::Container() : len{ 0 } { }

//------------------------------------------------------------------------------
// ���������� ����������
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// ������� ���������� �� ��������� (������������ ������)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// ���� ����������� ���������� �� ���������� ������
void Container::In(FILE* file) {
    int k;
    while (fscanf(file, "%d", &k) != EOF) {
        if ((storage[len] = Shape::StaticIn(file, k)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// ��������� ���� ����������� ����������
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Shape::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//-------------------------------------------------------------------------------
// ����� ����������� ���������� � ��������� �����
void Container::Out(FILE* file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i + 1);
        storage[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// ����� ��������� ������ ����������
void Container::ProcessingString(FILE* file) {
    double* qsorted = new double[len];
    for (int i = 0; i < len; i++) {
        qsorted[i] = storage[i]->Mean();
    }
    // ���������� ��������� ����������.
    quicksort(qsorted, 0, len - 1);
    // ����� ��������������� ������ � ����.
    fprintf(file, "Output sorted container by Quick sort :\n");
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d : ", i + 1);
    //    storage[i]->Out(file);
        fprintf(file,"Function Quick sort : %d\n",char(qsorted[i])); 
    }
}
// -----------------------------------------------------------------------------
// ����� ��� ���������� ��������� ���������� �� �������� �������.
void Container::quicksort(double* mas, int first, int last)
{
    int mid, count;
    int f = first, l = last;
    // ���������� ������������ ��������.
    mid = mas[(f + l) / 2]; 
    do
    {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
        // ������� ������������ ���������.
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
