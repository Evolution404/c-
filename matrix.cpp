#include"matrix.h"
#include<iostream>

using namespace std;
Matrix::Matrix(int l,int r)
{
    lines = l;
    rows = r;
    data = new double[l*r];
    memset(data,0,l*r*sizeof(double));
}

Matrix::~Matrix()
{
    lines = 0;
    rows = 0;
    if(data!=NULL)
    {
        delete data;
    }
}

double& Matrix::operator ()(int i, int j)
{
    // Unsafe
    return *(data + i*lines+j); 
}

void Matrix::input()
{
    int d[lines][rows];
    cout<<"Please enter the matrix by lines";
    for(int i =0;i<lines;i++)
    {
        for(int j=0;j<rows;j++)
        {
            cin>>d[i][j];
        }
    }
    data = d[0];
    for(int i=0;i<lines;i++)
    {
        for(int j=0;j<rows;j++)
        {
            cout<<d[i][j];
        }
    }
}

bool Matrix::operator == (const Matrix& m)//重载 ==
{
    bool rs = false;
    if(this->rows==m.rows && this->lines==m.lines)
    {

    }
}   


