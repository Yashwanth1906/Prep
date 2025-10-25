#include "group.hpp"
#include "user.hpp"


int main() {
    Group* group1 = new Group();
    User* yashwanth = new User(1);
    User* hariprasath = new User(2);
    group1->subscribe(yashwanth);
    group1->subscribe(hariprasath);
    group1->notify("Hello World");
    cout<<"_____________________________"<<endl;
    group1->unSubscribe(hariprasath);
    group1->notify("Hello world2");
}