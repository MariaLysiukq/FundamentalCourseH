// First Homework
#include <iostream>
#include <map>
#include <string>
using namespace std;

class StudentManager
{
    public:

    map<string, string> globalStudentMap;

    string studentName;
    string passOrFail;
    
void AddStudent()
{
    
    char choice;
    do
    {    
        cout << "What student would you like to add? " << endl;
        getline(cin >> ws, studentName); //cin >> ws help not to eat empty line
        cout << studentName << "pass or fail (p/f)? " << endl;
        cin >> passOrFail;
        globalStudentMap[studentName] = passOrFail;
        cout << "Added. ";
        
        cout << "Add one more student? (y/n) ";
        cin >> choice; 
    }
    while (choice == 'y');
    
    
};

void ShowListOfStudents()
{
    cout << "List of students: " << endl;
    for(auto& studentPair : globalStudentMap)
    {
        cout << "- " << studentPair.first << endl; //first - key(name) second - value(p\f)
    }
};

void CheckStatus()
{
    cout << "What student's status would you like to check? " << endl;
    cin >> studentName;
    
    if(globalStudentMap.find(studentName) != globalStudentMap.end()) // якщо результат пошуку не дорівнює кінцю списку (тобто студент знайдений)
    {
        cout << globalStudentMap[studentName] << endl;
    }
    else {cout << "There is no information about this student. ";}
};

void Studentstatistic()
{
    cout << "Student statistic: " << endl;
        for(auto& studentPair : globalStudentMap) //first - key(name) second - value(p\f)
    {
        cout << "- " << studentPair.first << "Status: " << studentPair.second << endl; //first - key(name) second - value(p\f)
    }
};

};

int main() 
{
    cout << "Hi! Welcome to students manager\nWhat would you like to do?" << endl;
    char continueOrExit = '.';
    int managerChoice;
    StudentManager data;
    while(true)
    {
        cout << "for exit press 'e' for continue press 'c' " << endl;
        cin >> continueOrExit;

        if(continueOrExit == 'e') 
        {break;}
        else
        {
            
            cout << "1.Add student to list\n2.Show list.\n3.Check status\n4.Show statistics\n(write only number)" << endl;
            cin >> managerChoice;
            
            switch(managerChoice)
            {
                
                case 1:
                data.AddStudent(); 
                break;
                case 2:
                data.ShowListOfStudents(); 
                break;
                case 3:
                data.CheckStatus(); 
                break;
                case 4:
                data.Studentstatistic();
                break;
                
            }
            
            
        }
    }

    return 0;
}
