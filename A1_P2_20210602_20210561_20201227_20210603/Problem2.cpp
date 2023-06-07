#include <iostream>
#include<cmath>
using namespace std;

class fraction
{
protected:
    int numerator, denominator;

public:
    fraction()
    {

    }
    fraction(int x, int y)
    {
        numerator = x;
        denominator = y;

    }
    fraction(const fraction& obj)
    {
        numerator = obj.numerator;
        denominator = obj.denominator;

    }
    fraction operator + (fraction  obj)
    {
        fraction f;
        f.numerator = numerator * obj.denominator + obj.numerator * denominator;
        f.denominator = denominator * obj.denominator;
        f.reduce();
        return f;
    }
    fraction operator - (fraction  obj)
    {
        fraction f;
        f.numerator = numerator * obj.denominator - obj.numerator * denominator;
        f.denominator = denominator * obj.denominator;
        f.reduce();
        return f;

    }
    fraction operator * (fraction  obj)
    {
        fraction f;
        f.numerator = numerator * obj.numerator;
        f.denominator = denominator * obj.denominator;
        f.reduce();
        return f;
    }
    fraction operator / (fraction  obj)
    {
        fraction f;
        f.numerator = numerator * obj.denominator;
        f.denominator = denominator * obj.numerator;
        f.reduce();
        return f;
    }



    bool operator < (fraction obj)
    {
        if ((float)numerator / denominator < (float)obj.numerator / obj.denominator)
            return 1;
        return 0;
    }
    bool operator > (fraction obj)
    {
        if ((float)numerator / denominator > (float)obj.numerator / obj.denominator)
            return 1;
        return 0;
    }
    bool operator == (fraction obj)
    {
        if (numerator == obj.numerator && denominator == obj.denominator)
            return 1;
        return 0;
    }

    bool operator <= (fraction obj)
    {
        if ((float)numerator / denominator <= (float)obj.numerator / obj.denominator)
            return 1;
        return 0;
    }
    bool operator >= (fraction obj)
    {
        if ((float)numerator / denominator >= (float)obj.numerator / obj.denominator)
            return 1;
        return 0;
    }
    int greatest_comman_divisor(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else {
            return greatest_comman_divisor(b, a % b);
        }
    }
    void reduce()
    {
        int x = greatest_comman_divisor(numerator, denominator);
        numerator /= x;
        denominator /= x;
    }


    friend istream& operator >> (istream& input, fraction& object)
    {
        cout << "please enter nominator : ";
        input >> object.numerator;
        cout << "please enter dominator : ";
        input >> object.denominator;
        object.reduce();
        return input;
    }
    friend ostream& operator << (ostream& output, fraction  object)
    {
        if (object.denominator == 0)
            output << "you can't divide by 0" << endl;
        else if (object.numerator == 0)
            output << 0 << endl;
        else if (object.denominator == object.numerator)
            output << 1 << endl;
        else
            output << object.numerator << '/' << object.denominator;
        return output;
    }



};
class fraction_calculator
{
public:
    fraction_calculator()
    {

    }
    void calculator()
    {
        fraction f1, f2;
        cout << "Enter your first fraction \n";
        cin >> f1;
        cout << "Enter your second fraction \n";
        cin >> f2;
        int choice;
        while (true) {
            cout << "1-Adding operation \n" << "2-subtracting operation " << endl << "3-multiplication operation " << endl << "4-dividing operation " << endl << "5-exit" << endl << "choose what operation you want to do : ";
            cin >> choice;
            if (choice == 1) {
                fraction f3(f1 + f2);
                cout << "-----------------------------------" << endl;
                cout << "fraction 1 + fraction 2 = " << f3 << endl;
                cout << "-----------------------------------" << endl;
                cout << endl;
            }

            else if (choice == 2) {

                fraction f3(f1 - f2);
                cout << "-----------------------------------" << endl;
                cout << "fraction 1 - fraction 2 = " << f3 << endl;
                cout << "-----------------------------------" << endl;
                cout << endl;

            }
            else if (choice == 3) {
                fraction f3(f1 * f2);
                cout << "-----------------------------------" << endl;
                cout << "fraction 1 * fraction 2 = " << f3 << endl;
                cout << "-----------------------------------" << endl;
                cout << endl;
            }
            else if (choice == 4) {
                fraction f3(f1 / f2);
                cout << "-----------------------------------" << endl;
                cout << "fraction 1 / fraction 2 = " << f3 << endl;
                cout << "-----------------------------------" << endl;
                cout << endl;

            }
            else if (choice == 5) {
                cout << "-----------------------------------" << endl;
                cout << "ok.......Have a nice time " << endl;
                cout << "-----------------------------------" << endl;
                break;

            }
        }
    }
};
int main()
{
    fraction_calculator f;
    f.calculator();
    return 0;

}