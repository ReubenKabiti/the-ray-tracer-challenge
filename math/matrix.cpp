#include "matrix.h"

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

Matrix::Matrix(const Matrix &mat)
    : m_nRow(mat.nRow()),
      m_nCol(mat.nCol())
{
    m_entries = new float*[m_nRow];
    for (unsigned int r = 0; r < m_nRow; r++)
    {
        m_entries[r] = new float[m_nCol];
        for (unsigned int c = 0; c < m_nCol; c++)
        {
            m_entries[r][c] = mat[r][c];
        }
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

unsigned int Matrix::nRow() const
{
    return m_nRow;
}

unsigned int Matrix::nCol() const
{
    return m_nCol;
}

Matrix Matrix::operator*(Matrix m)
{
    if (m_nCol != m.nRow())
        return Matrix(1, 1);
    Matrix out(m_nRow, m.nCol());

    for (unsigned int i = 0; i < out.nRow(); i++)
    {
        for (unsigned int j = 0; j < out.nCol(); j++) {
            float a = 0;
            for (unsigned int k = 0; k < m_nCol; k++)
            {
                a += (*this)[i][k] * m[k][j];
            }
            out[i][j] = a;
        }
    }
    return out;
}

Matrix Matrix::operator*(float a)
{
    Matrix out(m_nRow, m_nCol);

    for (unsigned int i = 0; i < m_nRow; i++)
    {
        for (unsigned int j = 0; j < m_nCol; j++)
        {
            out[i][j] = (*this)[i][j] * a;
        }
    }
    return out;
}

Tuple Matrix::operator*(Tuple t)
{
    assert(m_nRow == 4);
    assert(m_nCol == 4);

    Matrix m(4, 1);
    m[0][0] = t.x();
    m[1][0] = t.y();
    m[2][0] = t.z();
    m[3][0] = t.w();

    Matrix out = (*this) * m;
    return Tuple(out[0][0], out[1][0], out[2][0], out[3][0]);
}

Matrix Matrix::operator=(Matrix &m)
{
    Matrix m1 = m;
    return m1;
}

Matrix Matrix::T()
{
    Matrix out(m_nCol, m_nRow);
    for (unsigned int i = 0; i < m_nRow; i++)
    {
        for (unsigned int j = 0; j < m_nCol; j++)
        {
            out[j][i] = (*this)[i][j];
        }
    }
    return out;
}

Matrix Matrix::minor(unsigned int i, unsigned int j)
{
//     brute force now, optimize later
    Matrix out(m_nRow - 1, m_nCol - 1);
    for (unsigned int k = 0; k < i; k++)
    {
        for (unsigned int m = 0; m < j; m++)
        {
            out[k][m] = (*this)[k][m];
        }
    }

    for (unsigned int k = i + 1; k < m_nRow; k++)
    {
        for (unsigned int m = 0; m < j; m++)
        {
            out[k - 1][m] = (*this)[k][m];
        }
    }

    for (unsigned int k = 0; k < i; k++)
    {
        for (unsigned int m = j + 1; m < m_nCol; m++)
        {
            out[k][m - 1] = (*this)[k][m];
        }
    }

    for (unsigned int k = i + 1; k < m_nRow; k++)
    {
        for (unsigned int m = j + 1; m < m_nCol; m++)
        {
            out[k - 1][m - 1] = (*this)[k][m];
        }
    }

    return out;
}

Matrix Matrix::inverse()
{
    Matrix out(m_nRow, m_nCol);
    for (unsigned int r = 0; r < m_nRow; r++)
    {
        for (unsigned int c = 0; c < m_nCol; c++)
        {
            float sign = (r + c) % 2 == 0 ? 1 : -1;
            out[r][c] = sign * this->minor(r, c).det();
        }
    }
    return out.T() * (1.0f / this->det());
}

float Matrix::det()
{
    assert(m_nRow == m_nCol);
    Matrix m = *this;

    if (m_nRow == 2)
    {
        return m[0][0] * m[1][1] - m[1][0] * m[0][1];
    }

    float d = 0;
    for (unsigned int i = 0; i < m_nCol; i++)
    {
        float sign = i % 2 == 0 ? 1 : -1;
        d += sign * m[0][i] * m.minor(0, i).det();
    }
    return d;
}

float *Matrix::operator[](unsigned int index) const
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






