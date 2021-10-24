#ifndef __word__
#define __word__

//------------------------------------------------------------------------------
// word.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"
#include <string>

// Фигура речи.
class Word : public Shape {
public:
    virtual ~Word() {}
    // Ввод параметров из файла.
    virtual void In(FILE* file);
    // Случайный ввод параметров.
    virtual void InRnd();
    // Вывод параметров в форматируемый поток
    virtual void Out(FILE* file);
    // Вычисление числа знаков препинания.
    virtual int NumberMarks();
    // Вычисление значения указанной функции.
    virtual double Mean();

private:
    std::string country;
};
#endif //__word__