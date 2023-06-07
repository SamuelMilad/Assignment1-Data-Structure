#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H
#include "matrix.h"

class MatrixCalculator
{
    public:
        MatrixCalculator();
    template<class t>
	void DISPLAY(matrix<t>& A);
        virtual ~MatrixCalculator();

    protected:

    private:
};

#endif // MATRIXCALCULATOR_H


MatrixCalculator::MatrixCalculator()
{

}

template<class t>
MatrixCalculator::DISPLAY(matrix<t>& A)
{
    cout << "Welcome to your Matrix Calculator \n";
    cout << "----------------------------------------\n";
    int option;
    bool count=true;
    matrix<t> mat2,mat3;
    while (count)
    {
           cout << "Enter 1 to Perform Matrix Addition(+)."
				<< "\nEnter 2 to Perform Matrix Subtraction(-)."
				<< "\nEnter 3 to Perform Matrix Multiplication(*)."
				<< "\nEnter 4 to Matrix Transpose(Matrix sup(-1))."
				"\nEnter 0 to Exit.\n";

			cin>> option;

        if(option==1)
        {
            cout << "Enter Your First Matrix : ";
            cin >> A;
            cout << "Enter Your Second Matrix : ";
            cin>>mat2;

            if(A.get_row()==mat2.get_row() && A.get_col()==mat2.get_col())
            {
                mat3 = A + mat2;
                cout <<"\n Matrix 1 + Matrix 2 = "<< mat3<<endl;
            }
            else cout<<"\n Rows and Columns are not equal\n";
            break;
        }
        if(option==2)
        {
            cout << "Enter Your First Matrix : ";
            cin >> A;
            cout << "Enter Your Second Matrix : ";
            cin>>mat2;

            if(A.get_row()==mat2.get_row() && A.get_col()==mat2.get_col())
            {
                mat3 = A - mat2;
                cout <<"\n Matrix 1 - Matrix 2 = "<< mat3;
            }
            else cout<<"\n Rows and Columns ate not equal \n";
            break;
        }
        if(option==3)
        {
            cout << "Enter Your First Matrix : ";
            cin >> A;
            cout << "Enter Your Second Matrix : ";
            cin>>mat2;

            if(A.get_col()==mat2.get_row())
            {
                cout <<"\n Matrix 1 * Matrix 2 = "<< (A*mat2);
            }
            else cout<<"\n Rows and Columns ate not equal \n";
            break;
        }
        if(option==4)
        {
            cout << "Enter Your First Matrix : ";
            cin >> A;

            cout << "Transposed Matrix : \n";
            cout << transpose(A) << endl;
            break;
        }
        if(option==0)
        {
            count = false;
            break;
        }

    }
}

MatrixCalculator::~MatrixCalculator()
{

}
