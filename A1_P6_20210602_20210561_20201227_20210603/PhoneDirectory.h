#pragma once
#include <iostream>
#include<string>

using namespace std;
class PhoneDirectory
{
private:
    string  firstname, lastname, phonenumber;
public:
    PhoneDirectory();
    PhoneDirectory(string first, string last, string number);
    void set_firstname(string name);
    void set_lastname(string name);
    void set_phonenumber(string number);
    string get_firstname();
    string get_lastname();
    string get_phonenumber();
    bool lookup_phonenumber(string number);
    bool lookup_firstname(string name);
    bool operator <(PhoneDirectory& ob);
    void InsertSort(PhoneDirectory* ptr, int index);
    void SelectionSort(PhoneDirectory* ptr, int index);
    void BubbleSort(PhoneDirectory* ptr, int index);
    ~PhoneDirectory();
};

int main()
{
    int size = 0;
    PhoneDirectory* ptr;
    int choose = 0;
    int add = 0;
    int del = -1;
    string target_name = " ";
    string target_number = " ";
    cout << "Enter Directory Size\n";
    cin >> size;
    ptr = new PhoneDirectory[size];
    int A = 1;
    while (A)
    {

        cout << "Enter value correspond to needed option\n";
        cout << "1. Add an entry to the directory\n";
        cout << "2. Look up a phone number\n";
        cout << "3. Look up by first name\n";
        cout << "4. Delete an entry from the directory\n";
        cout << "5. List All entries in phone directory\n";
        cout << "6. Exit form this program\n";

        cin >> choose;


        if (choose == 1 && add == 0)
        {
            string first, last, number;
            cout << "Enter First Name\n";
            cin >> first;
            cout << "Enter Last Name\n";
            cin >> last;
            cout << "Enter Phone Numebr\n";
            cin >> number;

            ptr[add].set_firstname(first);
            ptr[add].set_lastname(last);
            ptr[add].set_phonenumber(number);
            add++;
        }
        else if (choose == 1 && add != 0)
        {
            if (add == size)
            {
                cout << "Directoery is full";
            }
            else
            {
                ptr[add].BubbleSort(ptr, add);
                add = add + 1;
            }
        }



        else if (choose == 2)
        {
            cout << "Enter phone number\n";
            cin >> target_number;
            for (int i = 0; i < add; i++)
            {
                if (ptr[i].lookup_phonenumber(target_number))
                {
                    cout << ptr[i].get_firstname() << '\t';
                    cout << ptr[i].get_lastname() << '\t';
                    cout << ptr[i].get_phonenumber() << '\n';
                    break;
                }
                if (i == add - 1) { cout << "Element not found\n"; }
            }
        }

        else if (choose == 3)
        {
            cout << "Enter first name: ";
            cin >> target_name;
            for (int i = 0; i < add; i++)
            {
                if (ptr[i].lookup_firstname(target_name))
                {
                    cout << ptr[i].get_firstname() << '\t';
                    cout << ptr[i].get_lastname() << '\t';
                    cout << ptr[i].get_phonenumber() << '\n';
                    break;
                }
                if (i == add - 1) { cout << "Element not found\n"; }
            }
        }


        else if (choose == 4)
        {
            cout << "Enter first name: ";
            cin >> target_name;
            for (int i = 0; i < add; i++)
            {
                if (ptr[i].lookup_firstname(target_name))
                {
                    del = i;
                }
                if (i == add - 1)
                {
                    cout << "Not found\n";
                }
            }

            if (del != -1)
            {

                for (del; del < add - 1; del++)
                {
                    ptr[del] = ptr[del + 1];
                }
                cout << "Element is successfully removed from Directory\n";
                add--;
            }
            del = -1;
        }


        else if (choose == 5)
        {
            if (add == 0)
            {
                cout << "The Directory is empty\n";
            }
            else
            {
                for (int i = 0; i < add; i++)
                {
                    cout << ptr[i].get_firstname() << '\t';
                    cout << ptr[i].get_lastname() << '\t';
                    cout << ptr[i].get_phonenumber() << '\n';
                }
            }
        }

        else if (choose == 6)
        {
            A = 0;
            return 0;
        }

        else { cout << "Error!.. Enter value within the valid range (from 1 to 6) \n"; }
        
    }

}