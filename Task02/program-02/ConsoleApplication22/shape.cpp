#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "word.h"
#include "aphorism.h"
#include "hint.h"
#include <iostream>
//------------------------------------------------------
Random Shape::rnd25(1, 25);
Random Shape::rnd3(1, 3);
Random Shape::rnd7(1, 7);
Random Shape::rndChar(33, 123);

//------------------------------------------------------
// Ввод параметров обобщенного текста из указанного файла.
Shape *Shape::StaticIn(FILE *file, int k) {
    Shape* sp = nullptr;
    std::cout << k;
    switch(k) {
        case 1:
            sp = new Word;
            break;
        case 2:
            sp = new Aphorism;
            break;
        case 3:
            sp = new Hint;
       //     sp->color = color;
            break;
        default:
            return 0;
    }
    sp->In(file);
    return sp;
}
// -----------------------------------------------------
// Случайный ввод обобщенного текста.
Shape *Shape::StaticInRnd() {
    auto k = Shape::rnd3.Get();
    Shape* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Word;
            break;
        case 2:
            sp = new Aphorism;
            break;
        case 3:
            sp = new Hint;
            break;
    }
    sp->InRnd();
    return sp;
}