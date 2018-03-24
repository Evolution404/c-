#include <iostream>

using namespace std;
class Matrix
{
public:
  Matrix(int c, int r);
  ~Matrix();
  int getRows();
  int getColumns();
  bool operator==(Matrix &m);  //重载==
  bool operator!=(Matrix &m);  //重载!=
  Matrix operator+(Matrix &m); //重载+
  Matrix operator-(Matrix &m); //重载-
  Matrix operator*(Matrix &m); //重载*
  void operator+=(Matrix &m);
  friend ostream &operator<<(ostream &os, Matrix m);
  friend istream &operator>>(istream &is, Matrix m);

  double &operator()(int i, int j);

private:
  int columns;
  int rows;
  double *data;
};