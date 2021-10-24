#pragma once
#ifndef __Hint__
#define __Hint__

//------------------------------------------------------------------------------
// Hint.h - �������� �������� �������.
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"
#include <string>

// ��������� �������.
class Hint : public Shape {
public:
    virtual ~Hint() {}
    // ���� ���������� ������� �� �����.
    virtual void In(FILE* file);
    // ��������� ���� ���������� �������.
    virtual void InRnd();
    // ����� ���������� ������� � �����.
    virtual void Out(FILE* file);
    // ���������� ����� ������ ����������.
    virtual int NumberMarks();
    // ���������� �������� �������.
    virtual double Mean();

private:
    std::string hint;
};

#endif //__Hint__