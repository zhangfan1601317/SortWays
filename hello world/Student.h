#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

struct Student{
    string name;
    int score;
    bool operator<(const Student &otherStudent)
    {
        return score!=otherStudent.score? score>otherStudent.score:name>otherStudent.name;
    }
    friend ostream& operator<<(ostream &os, const Student &stu)
    {
        os<<"Student: "<<stu.name<<" "<<stu.score<<endl;
        return os;
    }
};
#endif // STUDENT_H_INCLUDED
