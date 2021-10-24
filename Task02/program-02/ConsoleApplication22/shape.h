#pragma once
#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - �������� �������� ���������� �������������� ������
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

//------------------------------------------------------------------------------
// �����, ���������� ��� ��������� ������
class Shape {
protected:
    static Random rnd25;
    static Random rnd3;
    static Random rnd7;
    static Random rndChar;
    int color;

public:
    virtual ~Shape() {};
    // ���� ���������� ������ ����.
    static Shape* StaticIn(FILE* file, int k);
    virtual void In(FILE* file) = 0;
    // ��������� ���� ���������� ������ ����.
    static Shape* StaticInRnd();
    virtual void InRnd() = 0;
    // ����� ���������� ������ ����.
    virtual void Out(FILE* file) = 0;
    // ���������� ��������� ���������� ������ ����.
    virtual int NumberMarks() = 0;
    // ���������� �������� ��������� �������.
    virtual double Mean() = 0;
};

#endif
