#include "group.hpp"


void Group::notify(string message) {
    list<User*>& users = Group::users;
    for(auto user : users) {
        user->notify(message);
    }
}

void Group::subscribe(User* user) {
    Group::users.push_back(user);
}

void Group::unSubscribe(User* user) {
    Group::users.remove(user);
}