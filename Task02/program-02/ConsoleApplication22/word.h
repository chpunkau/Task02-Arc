#ifndef __word__
#define __word__

//------------------------------------------------------------------------------
// word.h - �������� �������� ��������������  � ��� ����������
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"
#include <string>

// ������ ����.
class Word : public Shape {
public:
    virtual ~Word() {}
    // ���� ���������� �� �����.
    virtual void In(FILE* file);
    // ��������� ���� ����������.
    virtual void InRnd();
    // ����� ���������� � ������������� �����
    virtual void Out(FILE* file);
    // ���������� ����� ������ ����������.
    virtual int NumberMarks();
    // ���������� �������� ��������� �������.
    virtual double Mean();

private:
    std::string country;
};
#endif //__word__