#ifndef AREUREADYKIDS__MATRIX_LIB_H
#define AREUREADYKIDS__MATRIX_LIB_H

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

class T_Matrix_R2 {
protected:
    int** matrix;
    int n; int m;
public:
    T_Matrix_R2();
    T_Matrix_R2(int, int, int l = 1);
    ~T_Matrix_R2();

    virtual void T();
    virtual void show();
    virtual void matrix_linop (T_Matrix_R2, char a='+');
    virtual void matrix_multi (T_Matrix_R2);
};

class T_Vector: public T_Matrix_R2 {
public:
    T_Vector(int, int l=1);
};

#endif //AREUREADYKIDS__MATRIX_LIB_H
