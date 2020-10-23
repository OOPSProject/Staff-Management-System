 #include<iostream>
#include<iomanip>
using namespace std;

class Employee      //This is the class that we will use
{

    public:
        static int countObjects;

        string name,DOJ;    //DOJ is Date Of joining- Format- DD/MM/YYYY
        float salary;
        int emp_ID,age;    //emp_id will become Primary key (if database is used in future)
        Employee* next;
        Employee(string name="noname",float salary=0.0,int emp_ID=0, int age=18,string DOJ="01-11-2020" )  //constructor
        {
            countObjects++;
            this->name=name;
            this->salary=salary;
            this->emp_ID=emp_ID;
            this->age=age;
            this->DOJ=DOJ;
        }
};

int Employee::countObjects  = 0;

Employee* first = NULL;

//Menu
inline void menu()
{
    cout<<"\n\nEnter 1 to add details of an employee"<<endl;
    cout<<"Enter 2 to delete the employee record"<<endl;
    cout<<"Enter 3 to search a credential"<<endl;
    cout<<"Enter 4 to display the employee record"<<endl;
    cout<<"Enter 5 to exit system"<<endl;
}

//create a new Employee node
inline void addCredentials()
{
    string name,DOJ;
    float salary;
    int emp_ID,age;

    //take credential inputs

    cout<<"Enter Employee ID- ";
    cin>>emp_ID;
    fflush(stdin);

    cout<<"Enter employee name- ";
    getline(cin,name);

    cout<<"Enter the Age- ";
    cin>>age;

    cout<<"Enter Date of Joininge (DD/MM/YYYY)- ";
    cin>>DOJ;

    cout<<"Enter employee salary- ";
    cin>>salary;




    //Enter credentials for a particular employee
    Employee* newNode = new Employee();
    newNode->next = NULL;
    newNode->name = name;
    newNode->salary = salary;
    newNode->emp_ID = emp_ID;
    newNode->age = age;
    newNode->DOJ = DOJ;

    if(first==NULL)
        first = newNode;


    else
    {
        Employee* ptr = first;

        while(ptr->next!=NULL)
            ptr = ptr->next;

        ptr->next = newNode;
    }


}

//delete a node
inline void deleteCredentials()
{
    int id,tracker=1;
    cout<<"Enter the employee ID to be deleted : ";
    cin>>id;

    Employee* ptr = first;

    while(ptr->emp_ID!=id)
        {
            ptr = ptr->next;
            tracker++;
        }

    if(tracker==1)
    {
        first = first->next;
        return;
    }

    else
    {
        Employee* ptr = first;

        while(ptr->next->emp_ID!=id)
        {
            ptr = ptr->next;
        }

        ptr->next = ptr->next->next;
        return;
    }

    cout<<"there is no employee with the given id : "<<id<<endl;

}

//search a credential node of employee
inline void searchCredential()
{
    int id;
    cout<<"Enter the employee ID : ";
    cin>>id;

    Employee* ptr = first;

    while(ptr->emp_ID!=id && ptr!=NULL)
        ptr = ptr->next;

    if(ptr==NULL)
    {
        cout<<"there is no employee with the id : "<<id<<endl;
        return;
    }
    cout<<"\nThe employee name is : "<<ptr->name<<endl;
    cout<<"The employee salary  is : "<<ptr->salary<<endl;
    cout<<"The employee ID is : "<<ptr->emp_ID<<endl;
    cout<<"The employee age is : "<<ptr->age<<endl;
    cout<<"The employee date of joining is : "<<ptr->DOJ<<endl;
}

//Display all record
inline void displayRecord()
{
    int sno = 0;
    cout<<"Total number of employees who have worked till now in the company : "<<Employee::countObjects<<"\n\n";

    cout<<"S.No"<<setw(10)<<"Employee ID"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Date of Joining"<<setw(10)<<"Salary\n";

    Employee* ptr = first;
    while(ptr!=NULL)
    {
        sno++;

        cout<<sno<<setw(10)<<ptr->emp_ID<<setw(10)<<ptr->name<<setw(10)<<ptr->age<<setw(10)<<ptr->DOJ<<setw(10)<<ptr->salary<<endl;

        ptr = ptr->next;
    }

}

//driver method
int main(void)
{
    int choice=0,i=4;
    string s;
    //login code
    do
    {
        cout<<"Enter the password- ";
        getline(cin,s);
        cout<<"Attempts left- "<<--i<<endl;
        if(i==0)
        {
            cout<<"Attemps over!!";
            exit(1);
            system("cls");
        }
    }while(s!="pass");
    //application loop
    while(choice!=-1)
    {
        menu();
        cin>>choice;

        //switch choices

        system("cls");

            switch(choice)
        {
            case 1: addCredentials(); break;
            case 2: deleteCredentials(); break;
            case 3: searchCredential(); break;
            case 4: displayRecord(); break;
            case 5: exit(0);

            default: cout<<"!!--Error--!!\nChoice1 not available, Try again"<<endl; break;
        }

        system("pause");

    }

    return EXIT_SUCCESS;
}
