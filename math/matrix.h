#ifndef MATRIX_H
#define MATRIX_H
#include "helper.h"
#include "tuple.h"

class Matrix
{
public:
    float **m_entries;
    unsigned int m_nRow;
    unsigned int m_nCol;

public:
    Matrix(unsigned int nRow, unsigned int nCol);
    Matrix(const Matrix &mat);
    ~Matrix();
    float *operator[](unsigned int index) const;
    static Matrix identity(unsigned int n);
    unsigned int nRow() const;
    unsigned int nCol() const;

    Matrix operator*(Matrix m);
    Matrix operator*(float a);
    Tuple operator*(Tuple t);
    Matrix operator=(Matrix &m);
    Matrix T();
    Matrix minor(unsigned int i, unsigned int j);
    Matrix inverse();

    float det();
};

bool operator== (Matrix a, Matrix b);
#endif // MATRIX_H
