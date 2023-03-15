#include "matrix.h"

unsigned int Matrix::nRow() const
{
    return m_nRow;
}

unsigned int Matrix::nCol() const
{
    return m_nCol;
}

Matrix::Matrix(unsigned int nRow, unsigned int nCol)
    : m_nRow(nRow),
      m_nCol(nCol)
{
    m_entries = new float*[nRow];
    for (unsigned int r = 0; r < nRow; r++)
    {
        m_entries[r] = new float[nCol];
        for (unsigned int i = 0; i < nCol; i++)
            m_entries[r][i] = 0;
    }
}

Matrix::~Matrix()
{
    for (unsigned int i = 0; i < m_nRow; i++)
    {
        delete[] m_entries[i];
    }
    delete[] m_entries;
}

float *Matrix::operator[](unsigned int index)
{
    if (index > m_nRow)
        return nullptr;
    return m_entries[index];
}

Matrix Matrix::identity(unsigned int n)
{
    Matrix m(n, n);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            m[i][j] = i == j ? 1 : 0;
        }
    }
    return m;
}

bool operator== (Matrix a, Matrix b)
{
    if (a.nRow() != b.nRow())
        return false;
    if (a.nCol() != b.nCol())
        return false;
    for (unsigned int r = 0; r < a.nRow(); r++)
    {
        for (unsigned int c = 0; c < a.nCol(); c++)
        {
            if (a[r][c] != b[r][c])
                return false;
        }
    }

    return true;
}






