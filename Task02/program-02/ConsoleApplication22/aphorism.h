#pragma once
#ifndef __aphorism__
#define __aphorism__

//------------------------------------------------------------------------------
// aphorism.h - �������� �������� ������������
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"
#include <string>

// ��������.
class Aphorism : public Shape {
public:
    virtual ~Aphorism() {}
    // ���� ���������� �������� �� �����
    virtual void In(FILE* file);
    // ��������� ���� ���������� ��������.
    virtual void InRnd();
    // ����� ���������� �������� � ������������� �����.
    virtual void Out(FILE* file);
    // ���������� ����� ������ ����������.
    virtual int NumberMarks();
    // ���������� �������� ��������� �������.
    virtual double Mean();

private:
    std::string author;
};

#endif //__aphorism__