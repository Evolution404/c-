#include "matrix.h"
#include <iostream>

using namespace std;
Matrix::Matrix(int r, int c)
{
    rows = r;
    columns = c;
    data = new double[c * r];
    memset(data, 0, c * r * sizeof(double));
}

Matrix::~Matrix()
{
    columns = 0;
    rows = 0;
}

int Matrix::getRows()
{
    return rows;
}

int Matrix::getColumns()
{
    return columns;
}

double &Matrix::operator()(int i, int j)
{
    // Unsafe
    return *(data + i * columns + j);
}

ostream &operator<<(ostream &os, Matrix m)
{
    string rs = "";
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.columns; j++)
        {

            os << m(i, j) << " ";
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matrix m)
{
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.columns; j++)
        {
            is >> m(i, j);
        }
    }
    return is;
}

bool Matrix::operator==(Matrix &m) //重载 ==
{
    bool rs = false;
    if (this->rows == m.rows && this->columns == m.columns)
    {
        rs = true;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (!((*this)(i, j) == m(i, j)))
                    rs = false;
            }
        }
    }
    return rs;
}

bool Matrix::operator!=(Matrix &m) //重载 !=
{
    return !(*this == m);
}

Matrix Matrix::operator+(Matrix &m)
{
    if (this->rows == m.rows && this->columns == m.columns)
    {
        Matrix sum(this->rows, this->columns);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                sum(i, j) = (*this)(i, j) + m(i, j);
            }
        }
        return sum;
    }
    Matrix sum(0, 0);
    return sum;
}

Matrix Matrix::operator-(Matrix &m)
{

    if (this->rows == m.rows && this->columns == m.columns)
    {
        Matrix min(this->rows, this->columns);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                min(i, j) = (*this)(i, j) - m(i, j);
            }
        }
        return min;
    }
    Matrix min(0, 0);
    return min;
}

Matrix Matrix::operator*(Matrix &m)
{

    if (this->rows == m.columns)
    {
        Matrix product(this->rows, m.columns);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < m.columns; j++)
            {
                double mul = 0;
                for (int p = 0; p < this->rows; p++)
                {
                    mul += (*this)(i, p) * m(p, j);
                }
                product(i, j) = mul;
            }
        }
        return product;
    }
    Matrix product(0, 0);
    return product;
}

void Matrix::operator+=(Matrix &m)
{
    if (this->rows == m.rows && this->columns == m.columns)
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                (*this)(i,j)+=m(i,j);
            }
        }
    }
}
