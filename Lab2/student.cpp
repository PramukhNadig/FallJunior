/*******************************************************************************
 * Name    : student.cpp
 * Author  : Pramukh Nadig
 * Version : 1.0
 * Date    : September 9, 2021
 * Description : Class for students and student information.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string first_;
    string last_;
    float gpa_;
    int id_;

public:
    string full_name()
    {
        return first_ + " " + last_;
    }

    int id()
    {
        return id_;
    }

    float gpa()
    {
        return gpa_;
    }

    void print_info()
    {
        cout << full_name() << ", GPA: " << gpa() << ", ID: " << id() << endl;
    }

    Student(string first, string last, float gpa, int id){
        first_ = first;
        last_ = last;
        gpa_ = gpa;
        id_ = id;
    }
};


const void print_students( vector<Student> &student){
    for(auto &s : student){
        s.print_info();
    }
}

vector<Student> find_failing_students(vector<Student> &students){
    vector<Student> failing_students;
        for(auto &s : students){
            if(s.gpa() < 1.0){
                failing_students.push_back(s);
            }
        }
        return failing_students;
} 

int main()
{
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;
    do
    {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa =  -1;
        while (gpa < 0 || gpa > 4)
        {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    cout << setprecision(2) << fixed  << endl  << "All students:" << endl; print_students(students); cout << endl << "Failing students:";
    if(find_failing_students(students).size() == 0){
        cout << " None";
    }else{
        cout << "\n";
        for(auto &s : find_failing_students(students)){
            s.print_info();
        }
    }
    return 0;
}