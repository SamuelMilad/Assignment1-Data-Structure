#include "PhoneDirectory.h"

PhoneDirectory::PhoneDirectory()
{
    firstname = " ";
    lastname = " ";
    phonenumber = " ";
}

PhoneDirectory::PhoneDirectory(string first, string last, string number)
{
    firstname = first;
    lastname = last;
    phonenumber = number;
}

void PhoneDirectory::set_firstname(string name)
{
    firstname = name;
}

void PhoneDirectory::set_lastname(string name)
{
    lastname = name;
}

void PhoneDirectory::set_phonenumber(string number)
{
    phonenumber = number;
}

string PhoneDirectory::get_firstname()
{
    return firstname;
}

string PhoneDirectory::get_lastname()
{
    return lastname;
}

string PhoneDirectory::get_phonenumber()
{
    return phonenumber;
}

bool PhoneDirectory::lookup_phonenumber(string number)
{
    if (number == phonenumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PhoneDirectory::lookup_firstname(string name)
{
    if (name == firstname)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PhoneDirectory::operator<(PhoneDirectory& ob)
{
    if (firstname < ob.get_firstname())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PhoneDirectory::InsertSort(PhoneDirectory* ptr, int index)
{
    string first, last, number;
    cout << "Enter First Name\n";
    cin >> first;
    cout << "Enter Last Name\n";
    cin >> last;
    cout << "Enter Phone Numebr\n";
    cin >> number;
    ptr[index].set_firstname(first);
    ptr[index].set_lastname(last);
    ptr[index].set_phonenumber(number);
    int i = index;
    for (i; ptr[index] < ptr[i - 1] && i >= 0; i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[i] =ptr[index];
}

void PhoneDirectory::SelectionSort(PhoneDirectory* ptr, int index)
{
    string first, last, number;
    cout << "Enter First Name\n";
    cin >> first;
    cout << "Enter Last Name\n";
    cin >> last;
    cout << "Enter Phone Numebr\n";
    cin >> number;
     ptr[index].set_firstname(first);
     ptr[index].set_lastname(last);
     ptr[index].set_phonenumber(number);
    for (int i = 0, j, least; i <= index ; i++)
    {
        for (j = i + 1, least = i; j <= index; j++)
            if (ptr[j] < ptr[least])
                least = j;

        swap(ptr[least], ptr[i]);
    }
}


void PhoneDirectory::BubbleSort(PhoneDirectory* ptr, int index)
{
    string first, last, number;
    cout << "Enter First Name\n";
    cin >> first;
    cout << "Enter Last Name\n";
    cin >> last;
    cout << "Enter Phone Numebr\n";
    cin >> number;
    ptr[index].set_firstname(first);
    ptr[index].set_lastname(last);
    ptr[index].set_phonenumber(number);
    bool flag = true;
    int c = 0 ;
    
    for (int i = 0,j=index; i <= j ; j--)
    {
        for (i;  i!=j ; i++)
        {
            if (ptr[i + 1] < ptr[i])
            {
                swap(ptr[i], ptr[i + 1]);
                flag = false;
            }
            c++;
        }
          if (flag == true)
            break;
    }

}

PhoneDirectory::~PhoneDirectory()
{
}
