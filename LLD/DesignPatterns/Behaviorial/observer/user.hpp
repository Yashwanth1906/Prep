#pragma once
#include <iostream>
using namespace std;

class User {
    public:
        int id;
        User(int id);
        void notify(string message);
};