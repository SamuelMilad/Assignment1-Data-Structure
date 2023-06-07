#include <iostream>
#include "BigInt.h"
#include <string>
using namespace std;

int main()
{
    BigInt n1(777777);
    BigInt n2(777777);
    cout << n1 - n2 << endl;
    BigInt n1("123456789012345678901234567890");
    BigInt n2("113456789011345678901134567890");
    BigInt n3 = n2 + n1;
    BigInt n4 = n2 - n1;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "n2 + n1 = " << n3 << endl;
    cout << "n2 - n1 = " << n4 << endl;
   
    return 0;
}