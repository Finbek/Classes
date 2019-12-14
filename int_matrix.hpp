class int_matrix
{
public:
    ~int_matrix();
    int_matrix(int r, int c, int v);
    int_matrix(int r, int c, int a[]);
    int at(int i,int j);
    int getRow();
    int getColumn();
    int* operator [](int i);
private:
    unsigned int row;
    unsigned int col;
    int **_buf;
};
