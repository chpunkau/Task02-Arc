#pragma once
#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

//------------------------------------------------------------------------------
// класс, обобщающий все имеющиеся фигуры
class Shape {
protected:
    static Random rnd25;
    static Random rnd3;
    static Random rnd7;
    static Random rndChar;
    int color;

public:
    virtual ~Shape() {};
    // Ввод обобщенной фигуры речи.
    static Shape* StaticIn(FILE* file, int k);
    virtual void In(FILE* file) = 0;
    // Случайный ввод обобщенной фигуры речи.
    static Shape* StaticInRnd();
    virtual void InRnd() = 0;
    // Вывод обобщенной фигуры речи.
    virtual void Out(FILE* file) = 0;
    // Вычисление периметра обобщенной фигуры речи.
    virtual int NumberMarks() = 0;
    // Вычисление значения указанной функции.
    virtual double Mean() = 0;
};

#endif
