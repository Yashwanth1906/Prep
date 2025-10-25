#pragma once

#include <bits/stdc++.h>
using namespace std;
#include "user.hpp"
class Group {
    public:
        list<User*> users;
        void notify(string message);
        void subscribe(User* user);
        void unSubscribe(User* user);
};