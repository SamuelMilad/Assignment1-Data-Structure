#include <iostream>
using namespace std;

template <class t>
class matrix
{
    public:
        matrix();
        matrix(int row, int col, t ind[]);
        matrix(int row, int col);
        matrix(const matrix<t>& old);
    template<class t2>
	friend istream& operator>> (istream& input, matrix<t2>& mat);
    template <class t2>
	friend ostream& operator<< (ostream& output, const matrix<t2>& mat);
	matrix<t> operator+(matrix<t> &mat2);
	matrix<t> operator-(matrix<t> &mat2);
	matrix<t> operator*(matrix<t> &mat2);
    template <class t2>
	friend matrix<t2>& transpose(matrix<t2>& mat);
        int get_row();
        int get_col();
        virtual ~matrix();

    protected:

    private:
        int row,col;
        t** matrix_content;

};


template <class t>
matrix::matrix()
{

}

template <class t>
matrix::matrix(int row, int col, t ind[])
{
    this->row = row;
    this->col = col;
    matrix_content = new t*[row];

    for (int i = 0; i < row; i++)
        matrix_content[i] = new t[col];

            for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix_content[i][j] = ind[i * col + j];
}

template <class t>
matrix::matrix (int row, int col)
{
    this->row = row;
    this->col = col;
    matrix_content = new t*[row];

    for (int i = 0; i < row; i++)
        matrix_content[i] = new t[col];
}

template <class t2>
istream& operator>> (istream& input, matrix<t2>& mat)
{
    cout<< "Enter size of rows \n";
    cin >> mat.row;
    cout<< "Enter size of columns \n";
    cin >> mat.col;

    mat.matrix_content = new t2*[mat.row];

    for (int i = 0; i < mat.row; i++)
        mat.matrix_content[i] = new t2[mat.col];

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            input >> mat.matrix_content[i][j];

    return input;
}

template <class t2>
ostream& operator<< (ostream& output, const matrix<t2>& mat)
{
  for (int i = 0; i < mat.row; i++)
    {
        output << endl;
        for (int j = 0; j < mat.col; j++)
            output << mat.matrix_content[i][j] << "\t";
    }
    output << "\n";

    return output;
}

template<class t>
matrix<t>::matrix(const matrix<t>& old)
{
    this->col = old.col;
    this->row = old.row;
    this->matrix_content = new t*[row];

    for (int i = 0; i < row; i++)
        this->matrix_content[i] = new t[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->matrix_content[i][j] = old.matrix_content[i][j];
}

template <class t>
matrix::matrix<t> operator+(matrix<t> & mat2)
{
    matrix<t> mat(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.matrix_content[i][j] = 0;

    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.matrix_content[i][j] = (matrix_content[i][j] + mat2.matrix_content[i][j]);

        }
    }
    return mat;
}

template <class t>
matrix::matrix<t> operator-(matrix<t> &mat2)
{
    matrix<t> mat(row, col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
           mat.matrix_content[i][j] =0;

    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.matrix_content[i][j] = (matrix_content[i][j] - mat2.matrix_content[i][j]);

        }
    }
    return mat;
}

template <class t>
matrix::matrix<t> operator*(matrix<t> &mat2)
{
    matrix<t> mat(row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat.matrix_content[i][j] = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < mat2.col; j++)
            for (int k = 0; k <col; k++)
            {
                mat.matrix_content[i][j] += matrix_content[i][k] * mat2.matrix_content[k][j];
            }
    return mat;
}

template <class t2>
matrix<t2>& transpose(matrix<t2>& mat)
{
    matrix<t2> mat1(mat.col, mat.row);

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat1.matrix_content[i][j] = mat.matrix_content[j][i];

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.matrix_content[i][j] = mat1.matrix_content[i][j];

    return mat;
}

template <class t>
matrix<t>::get_row()
{
    return row;
}

template <class t>
matrix<t>::get_col()
{
    return col;
}

template <class t>
matrix::~matrix()
{
  delete[] matrix_content;
}
