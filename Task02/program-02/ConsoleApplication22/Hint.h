#pragma once
#ifndef __Hint__
#define __Hint__

//------------------------------------------------------------------------------
// Hint.h - содержит описание загадок.
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"
#include <string>

// Параметры загадок.
class Hint : public Shape {
public:
    virtual ~Hint() {}
    // Ввод параметров загадки из файла.
    virtual void In(FILE* file);
    // Случайный ввод параметров загадки.
    virtual void InRnd();
    // Вывод параметров загадок в поток.
    virtual void Out(FILE* file);
    // Вычисление числа знаков препинания.
    virtual int NumberMarks();
    // Вычисление значения функции.
    virtual double Mean();

private:
    std::string hint;
};

#endif //__Hint__