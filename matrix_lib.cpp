#include "matrix_lib.h"

T_Matrix_R2::T_Matrix_R2()
{

}
T_Matrix_R2::T_Matrix_R2(int n, int m, int l)
{
    this->n = n;
    this->m = m;
    srand(time(NULL));
    this->matrix = new int* [n];
    for (int j(0); j<n; j++)
    {
        this->matrix[j] = new int[m];
        switch (l) {
            case 0:
                for (int i(0); i < m; i++) {
                    this->matrix[j][i] = 0;
                }
                break;
            case 1:
                for (int i(0); i < m; i++) {
                    this->matrix[j][i] = rand() % 101;
                }
                break;
            case 2:
                for (int i(0); i < m; i++) {
                    cin >> this->matrix[j][i];
                }
                break;
            }
        }

}
T_Matrix_R2::~T_Matrix_R2()
{

}
T_Vector::T_Vector(int n, int l): T_Matrix_R2(n, 1, l)
{

}

void T_Matrix_R2::T()
{
    int** only_for_t = new int* [m];
    for (int i(0); i<m; i++)
    {
        only_for_t[i] = new int[n];
        for (int j(0); j<n; j++)
        {
            only_for_t[i][j] = matrix[j][i];
        }
    }

    matrix = new int* [m];
    for (int i(0); i<m; i++)
    {
        matrix[i] = new int [n];
        for (int j(0); j<n; j++)
        {
            matrix[i][j] = only_for_t[i][j];
        }
    }
    int temp = this->n;
    this->n = this->m;
    this->m = temp;

    for (int i(m-1); i>=0; i--)
    {
        delete only_for_t[i];
    }
    delete[] only_for_t;
}
void T_Matrix_R2::show()
{
    for (int i(0); i<n; i++)
    {
        for (int j(0); j<m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void T_Matrix_R2::matrix_linop(T_Matrix_R2 matrixR2, char op)
{
    if (not(matrixR2.n == this->n and matrixR2.m == this->m))
    {
        cout << "Error whit size of matrix";
        return;
    }
    if (op == '+')
    {
        for (int i(0); i<n; i++)
        {
            for (int j(0); j<m; j++)
            {
                matrix[i][j] += matrixR2.matrix[i][j];
            }
        }
    }
    else if (op == '-')
    {
        for (int i(0); i<n; i++)
        {
            for (int j(0); j<m; j++)
            {
                matrix[i][j] -= matrixR2.matrix[i][j];
            }
        }
    }
    else
    {
        cout << "get correct second param (+/- with char type) or use default (+)" << endl;
        return;
    }
}
void T_Matrix_R2::matrix_multi(T_Matrix_R2 matrixR2) {
    if (matrixR2.n != m)
    {
        cout << "this matrix cannot being multiplied" << endl;
        return;
    }

    int** only_for_multi = new int* [n];
    for (int i(0); i<m; i++)
    {
        only_for_multi[i] = new int[matrixR2.m];
    }

    for (int i(0); i<n; i++)
    {
        for (int j(0); j<matrixR2.m; j++)
        {
            for (int g(0); g<m; g++)
            {
                only_for_multi[i][j] += matrix[i][g] * matrixR2.matrix[g][j];
            }
        }
    }

    matrix = new int* [n];
    for (int i(0); i<n; i++)
    {
        matrix[i] = new int [matrixR2.m];
        for (int j(0); j<matrixR2.m; j++)
        {
            matrix[i][j] = only_for_multi[i][j];
        }
    }

    this->m = matrixR2.m;

    for (int i(n-1); i>=0; i--)
    {
        delete only_for_multi[i];
    }
    delete[] only_for_multi;
}
