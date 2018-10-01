#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class Stack
{
private:
    string *s;
    string *t;
    int index;
public:
    Stack();
    void push(char);
    void push(string);
    string pop();
    char top();
    bool isEmpty();
    string print();
    ~Stack();
};

#endif