#ifndef MATRIX_H
#define MATRIX_H
#include "helper.h"

class Matrix
{
public:
    float **m_entries;
    unsigned int m_nRow;
    unsigned int m_nCol;

public:
    Matrix(unsigned int nRow, unsigned int nCol);
    ~Matrix();
    float *operator[](unsigned int index);

    static Matrix identity(unsigned int n);
    unsigned int nRow() const;
    unsigned int nCol() const;
};

bool operator== (Matrix a, Matrix b);
#endif // MATRIX_H
