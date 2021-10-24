#ifndef __random__
#define __random__

#include <cstdlib>
#include <ctime>   // для функции time()

//------------------------------------------------------------------------------
// random.h - содержит генератор случайных чисел в заданном диапазоне,
// а также генератор случайного символа строки.
//------------------------------------------------------------------------------

class Random {
public:
    Random(int fst, int lst) {
        if (fst <= lst) {
            first = fst;
            last = lst;
        }
        else {
            first = lst;
            last = fst;
        }
        // Системные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));
    }
    // Генерация случайного числа в заданном диапазоне.
    int Get() {
        return rand() % (last - first + 1) + first;
    }
    // Генерация случайного символа в заданном диапазоне.
    char GetNew() {
        return rand() % (lastc - firstc + 1) + firstc;
    }

private:
    int first;
    int last;
    char firstc;
    char lastc;
};

#endif //__random__