#include "user.hpp"

User::User(int id) {
    User::id = id;
}

void User::notify(string message) {
    cout<<"User "<<User::id<<" received the message : "<<message<<endl;
}