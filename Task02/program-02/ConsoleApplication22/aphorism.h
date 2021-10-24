#pragma once
#ifndef __aphorism__
#define __aphorism__

//------------------------------------------------------------------------------
// aphorism.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"
#include <string>

// Афоризмы.
class Aphorism : public Shape {
public:
    virtual ~Aphorism() {}
    // Ввод параметров афоризма из файла
    virtual void In(FILE* file);
    // Случайный ввод параметров афоризма.
    virtual void InRnd();
    // Вывод параметров афоризма в форматируемый поток.
    virtual void Out(FILE* file);
    // Вычисление числа знаков препинания.
    virtual int NumberMarks();
    // Вычисление значения указанной функции.
    virtual double Mean();

private:
    std::string author;
};

#endif //__aphorism__