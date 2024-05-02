#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

struct Student{
    int rollno;
    string name;
    char div;
    string address;
};

void AddStudent(){
    Student student;
    ofstream writing("student.txt", ios::app);
    if(!writing.is_open())
    {
        cout<<"Error while opening file!";
    }

    cout<<"Enter Student Roll Number:";
    cin>>student.rollno;
    cout<<"Enter Student name:";
    cin>>student.name;
    cout<<"Enter Student divivsion:";
    cin>>student.div;
    cout<<"Enter Student address:";
    cin>>student.address;

    writing<<student.rollno<<","<<student.name<<","<<student.div<<","<<student.address<<endl;
    writing.close();
    cout<<"record added to the file successfully\n"<<endl;
}

void SearchStudent(){
    string n;
    cout<<"Enter Roll Number to search:";
    cin>>n;

    ifstream reading("student.txt");
    if(reading.is_open())
    {
        string line;
        while(getline(reading, line))
        {
            if(line.substr(0,2) == n)
            {
                cout<<"................Record found"<<endl;

                stringstream ss(line);
                string token;
                string labels[4] = {"Roll No:", "Name:", "Division:", "Address:"};
                int index = 0;

                while(getline(ss, token, ','))
                {
                    cout << labels[index++] << token << "   "<<endl;
                }
                reading.close();
                cout<<endl;
                return;
            }//if
        }//while
        cout<<"Does not exists\n"<<endl;      
    }//if
    else
    {
        cout<<"Error opening file";
    }
    
}//search function

void DeleteStudent(){
    int n;
    cout<<"Enter the roll number of the student to delete:";
    cin>>n;

    ifstream reading("student.txt");
    ofstream writing("temp.txt", ios::app);   

    if(reading.is_open() && writing.is_open())
    {
        string line;
        while(getline(reading, line))
        {
            if(n != stoi(line.substr(0,2)))
            {
                writing<<line<<endl;
            }//if
        }//while
        
        reading.close();
        writing.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        cout<<".............Record Deleted\n"<<endl;

    }//if1
    else
    {
        cout<<"Error opening file";
    }//else1
}//delete function

int main(){

    int choice;
    do{
        cout<<"1. Add student record."<<endl;
        cout<<"2. Search Student record."<<endl;
        cout<<"3. Delete Student record."<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice; 
        cout<<endl; 

        switch(choice)
        {
            case 1:{
                AddStudent();
                break;
            }
            case 2:{
                SearchStudent(); 
                break;              
            }
            case 3:{
                DeleteStudent();
                break;
            }
            case 4:{
                break;
            }
            default:{
                cout<<"Enter valid choice"<<endl;
                break;
            }
        }     

    }while(choice != 4);  
    return 0;
}