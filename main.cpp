#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
#pragma region 创建两个矩阵对象
    int rows[2], columns[2];
    cout << "Please enter to matrixs\n";
    cout << "The first matrix M1's rows and columns are:\n";
    cin >> rows[0];
    cin >> columns[0];
    Matrix *m = new Matrix(rows[0], columns[0]);
    cout<<"Please enter the matrix by rows\n";
    cin>>*m;

    cout << "The second matrix M1's rows and columns are:\n";
    cin >> rows[1];
    cin >> columns[1];
    Matrix *n = new Matrix(rows[0], columns[0]);
    cout<<"Please enter the matrix by rows\n";
    cin>>*n;

#pragma endregion

#pragma region + 重载
    cout << "The sum of two matrix M1+M2 = sum:\n";
    Matrix sum = *m + *n;
    cout << "The information of the result: " << sum.getRows() << " rows "
         << sum.getColumns() << " columns\n";
    cout<<sum;

#pragma endregion

#pragma region - 重载
    cout << "The min of two matrix M1-M2 = min:\n";
    Matrix min = *m - *n;
    cout << "The information of the result: " << min.getRows() << " rows "
         << min.getColumns() << " columns\n";
    cout<<min;
#pragma endregion

#pragma region *重载
    cout << "The product of two matrix M1*M2 = product:\n";
    Matrix product = *m * *n;
    cout << "The information of the result: " << product.getRows() << " rows "
         << product.getColumns() << " columns\n";
    cout<<product;
#pragma endregion

#pragma region == 判断
    cout<<"==overload\n";
    cout << "Judge the two matrix are equal or not:\n";
    if (*m == *n)
    {
        cout << "The two matrix are equal\n";
    }
    else
    {
        cout << "The two matrix are not equal\n";
    }
#pragma endregion

#pragma region != 判断
    cout<<"!=overload\n";
    cout << "Judge the two matrix are equal or not:\n";
    if (*m != *n)
    {
        cout << "The two matrix are not equal\n";
    }
    else
    {
        cout << "The two matrix are equal\n";
    }
#pragma endregion

#pragma region +=重载
    cout<<"The result of M1 after plus with M2 is M1+=M2:\n";
    (*m)+=(*n);
    cout << "The information of the result: " << m->getRows() << " rows "
         << m->getColumns() << " columns\n";
    cout<<*m;
#pragma endregion


}