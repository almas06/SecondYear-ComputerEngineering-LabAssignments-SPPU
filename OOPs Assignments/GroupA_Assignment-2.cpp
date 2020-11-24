/*Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete as well as exception handling.*/


#include <iostream>
#include <string>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
using namespace std;

class Personal_Info
{
public:
  string lic_no, dob, blood_grp;

  Personal_Info()
  {
    lic_no = "1234abcd";
    dob = "6/10/2000";
    blood_grp = "O+";
  }
  Personal_Info(Personal_Info &);

  friend class Student;
};

Personal_Info::Personal_Info(Personal_Info &obj)
{
  this->lic_no = obj.lic_no;
  this->dob = obj.dob;
  this->blood_grp = obj.blood_grp;
}

class Student
{
public:
  int roll;
  long phone_no;
  string name, class_name, address, email_id;

  void create(Personal_Info &);
  void display(Personal_Info &);
  
  Student()
  {
    name = "Almas Dinani";
    roll = 22;
    class_name = "SE COMP2";
    address = "Yerwada, Pune-06";
    phone_no = 1234567890;
    email_id = "almas.dinani@gmail.com";
  }
  Student(Student &);

};
Student::Student(Student &obj)
{
  this->name = obj.name;
  this->roll = obj.roll;
  this->class_name = obj.class_name;
  this->address = obj.address;
  this->phone_no = obj.phone_no;
  this->email_id = obj.email_id;
}

void Student ::create(Personal_Info &obj)
{
  cout << "Enter Roll Number :=>";
  cin >> roll;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter Class :=>";
  getline(cin,class_name);

  cout << "Enter Full Name:=>";
  getline(cin,name);

  cout << "Enter Phone Number:=>";
  cin >> phone_no;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter Email Id:=>";
  getline(cin,email_id);

  cout << "Enter Address:=>";
  getline(cin,address);

  cout << "Enter Date of birth:=>";
  getline(cin,obj.dob);

  cout << "Enter Blood Group:=>";
  getline(cin,obj.blood_grp);

  cout << "Enter Driving License no.:=>";
  getline(cin,obj.lic_no);
}

void Student ::display(Personal_Info &obj)
{
  cout << "---------------------------------------------------------" << endl;
  cout << "        Details => "
       << " " << name << endl;
  cout << "----------------------------------------------------------" << endl;
  cout << "Class Name          :=>  " << class_name << endl;
  cout << "Roll No             :=>  " << roll << endl;
  cout << "Name                :=>  " << name << endl;
  cout << "Phone No            :=>  " << phone_no << endl;
  cout << "Email Id            :=>  " << email_id << endl;
  cout << "Address             :=>  " << address << endl;
  cout << "Date of birth       :=>  " << obj.dob << endl;
  cout << "Blood Group         :=>  " << obj.blood_grp << endl;
  cout << "Driving License no. :=>  " << obj.lic_no << endl;

  cout << "-----------------------------------------------------------" << endl;
}

int main()
{
  cout << "\t============= STUDENT DATABASE MANAGEMENT SYSTEM =============";
  cout << "\n\n";
  int ch;
  int n;
  int ans;

  cout << "\nEnter number of Students :=> ";
  cin >> n;
  Student *stud = new Student[n];
  Personal_Info *p = new Personal_Info[n];
  cout << "\n";
  try
  {
    if (n < 0)
    {
      throw n;
    }
    else
    {
      while (true)
      {
        cout << "----------------------------------\n";
        cout << "\t1.Create Database\n";
        cout << "\t2.Display Database\n";
        cout << "\t3.Default Constructor\n";
        cout << "\t4.Copy Constructor\n";
        cout << "\t5.Delete Record\n";
        cout << "\t6.Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter choice :=> ";
        cin >> ch;
        cout << "\n";
        switch (ch)
        {
        case 1:

          for (int i = 0; i < n; i++)
          {
            stud[i].create(p[i]);
            cout << "\n";
          }
          cout << "\n";
          break;

        case 2:
        {
          for (int i = 0; i < n; i++)
          {
            stud[i].display(p[i]);
          }
          cout << "\n";
          break;
        }
        case 3:
         {
          Student obj1;
          Personal_Info obj2;
          obj1.display(obj2);
          cout << "Default Constructor Called !!\n\n";
        }
        break;

        case 4:
        {
          Student obj1;
          Personal_Info obj2;
          obj1.create(obj2);
          Student obj3(obj1);
          Personal_Info obj4(obj2);
          obj3.display(obj4);
          cout << " Copy Constructor Called !!\n\n";
        }
        break;

        case 5:
          delete[] stud;
          delete[] p;
          cout << "Record Deleted Successfully !!\n\n";
          break;

        case 6:
          cout << "\n---------------EXIT---------------\n\n";
          exit(1);
          break;
        }
      }
    }
  }
  catch (int n)
  {
    cout << "Error : Bad memory allocation!!\n";
    cout << "Number of students can't be -ve,please enter a positive number\n\n";
  }

  return 0;
}
