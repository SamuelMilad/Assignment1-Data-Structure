#include <iostream>
#include <vector>
using namespace std;
class StudentName
{
private:
    string name;
public:
    StudentName(string n)
    {
        int space=0,aspace=0;
    for(int i=0;i<n.length();i++)
    {
        if (n[i] == ' ') {
          space++;
          aspace=i;}
    }
        if(space==0)
             name=n+' '+n+' '+n;
        else if (space==1)
             name=n+n.substr(aspace);
        else if(space>=2)
            name=n;
    }
    void Print()
    {
        vector <string> fullname;
        string fname="";
        for(int i=0; i<name.length(); i++)
        {
            if (name[i]==' ')
            {
                fullname.push_back(fname);
                fname="";
            }
            else if(i==name.length()-1)
            {
                fname+=name[i];
                fullname.push_back(fname);
            }
            else
                fname+=name[i];
        }
        int x=1;
        for(int i=0; i<fullname.size(); i++)
        {
            cout<<x<<") "<<fullname[i]<<endl;
            x++;
        }
    }

   bool Replace(int a,int b)
   {
vector <string> fullname;
string fname="";
for(int i=0;i<name.length();i++) {
    if (name[i] == ' ') {
        fullname.push_back(fname);
        fname = "";
    } else if (i == name.length() - 1)
    {
    fname += name[i];
    fullname.push_back(fname);
    }
    else
        fname+=name[i];

}
if(a>fullname.size()||b>fullname.size())
    return false;
else{
    string temp = fullname[b - 1];
    fullname[b - 1] = fullname[a - 1];
    fullname[a - 1] = temp;
    string f;
    for(int i = 0 ; i < fullname.size() ; i++)
    {
        f+=fullname[i] + " ";
    }
    name = f;
    cout << name<<endl;
    return true;
}

   }

};
int main()
{
     cout<<"Test Case(1): Eman "<<endl;
    StudentName testcase1("Eman");
    if(testcase1.Replace(1,3))
      testcase1.Print();
  cout <<endl;

    cout<<"Test Case(2): Mona Samir Samuel "<<endl;
    StudentName testcase2("Mona Samir Samuel");
    if(testcase2.Replace(2,3))
     testcase2.Print();
    cout <<endl;

    cout<<"Test Case(3): Amir Medhat Mounir "<<endl;
    StudentName testcase3("Amir Medhat Mounir");
    if(testcase3.Replace(1,3))
       testcase3.Print();
    cout <<endl;

    cout<<"Test Case(4): Eman Medhat Mounir Attalah"<<endl;
    StudentName testcase4("Eman Medhat Mounir Attalah");
    if(testcase4.Replace(2,4))
      testcase4.Print();
    cout <<endl;

    cout<<"Test Case(5): Sohir Sadik "<<endl;
    StudentName testcase5("Sohir Sadik");
    if(testcase5.Replace(1,3))
      testcase5.Print();
     cout <<endl;


    return 0;
}
/*void print(string fullName)
   {


       int firstSpace = fullName.find_first_of(' ');
       int secondSpace = fullName.find_last_of(' ');


      string firstName = fullName.substr(0, firstSpace);
       string middleName = fullName.substr(firstSpace + 1 , secondSpace );
       string lastName= fullName.substr(secondSpace + 1,fullName.length()-1);


           cout<<1<<") "<<firstName<<endl;
       cout<<2<<") "<<middleName<<endl;
       cout<<3<<") "<<lastName<<endl;



   }*/