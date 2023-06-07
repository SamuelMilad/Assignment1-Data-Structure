#include <iostream>
#include <string>
using namespace std;

class BigInt
{
public:



    string num;
    int sum, carry;

    BigInt(string decstr);

    BigInt(int decint);
    BigInt();

    BigInt operator+(BigInt b);
    BigInt operator-(BigInt b);

    friend ostream& operator<< (ostream& output, BigInt a);
    friend bool checkvalid(BigInt& b);
    friend bool checksign(BigInt& b);
    friend bool checkequality(string a, string b);
    friend bool checkbigger(string a, string b);
    friend void removeleftzeros(string& a);

    int size();

};






