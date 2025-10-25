#include <bits/stdc++.h>
using namespace std;

class Boy {
protected:
    string nickName;
    string gfName;
public:
    string name;
    int age;
    Boy(string name, int age) {
        this->name = name;
        this->age = age;
    }
    Boy(string name, int age , string nickName, string gfName) : Boy(name, age) {
        this->nickName = nickName;
        this->gfName = gfName;
    }
};


class Student : public Boy {
public:
    int rollNo;
    int standard;
    Student(string name, int age, int rollNo, int standard, string nickName, string gfName) : Boy(name, age,nickName,gfName) {
        this->rollNo = rollNo;
        this->standard = standard;
    }
    void display() {
        cout<<this->name<<" "<<this->age<<" "<<this->rollNo<<" "<<this->standard<<" "<<this->nickName<<" "<<this->gfName<<endl;
    }
};


int main() {
    Boy* boy1 = new Boy("Yashwanth S", 18);
    Student* stud1 = new Student("Yashwanth S", 18, 43, 12, "Yash", "Summa");
    stud1->display();
}