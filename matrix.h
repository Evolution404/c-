class Matrix
{
  public:
    Matrix(int l, int r);
    ~Matrix();
    void input();
    bool operator==(const Matrix &m); //重载 ==
    double& operator ()(int i, int j);

        private : int lines;
    int rows;
    double *data;
};