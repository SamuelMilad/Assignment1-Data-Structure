
//Problem  4

#include <iostream>
using namespace std;
                                            
void RecPermute(string soFar, string rest)
{
    if (rest == "")
    {
        cout << endl << soFar << endl;
        return;
    }
    for (int i = 0; i < rest.length(); i++)
    {
        string next = soFar + rest[i];
       
        string remaining = rest.substr(0, i) + rest.substr(i + 1);
        RecPermute(next,  remaining);
    }

}

int main()
{
    string s;
    string re = "";

    cout << "Enter the string : ";
    cin >> s;

    cout <<endl<< "All possible strings are : ";
    RecPermute(re, s);

    return 0;
}

