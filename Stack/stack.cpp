#include <string>
#include "stack.h"

using namespace std;

Stack::Stack()
{
    s = new string[30];
    t = NULL;
    index = -1;
}

void Stack::push(char str)
{
    s[++index] = str;
    t = s + index;
}

void Stack::push(string str)
{
    s[++index] = str;
    t = s + index;
}

string Stack::pop()
{
    string str;
    str = s[index--];
    t = s + index;
    return str;
}

string Stack::top()
{
    return *t;
}

bool Stack::isEmpty()
{
    return index == -1 ? true : false;
}

string Stack::print()
{
    string str = "";
    for (int i = 0; i <= index; i++)
    {
        str += s[i];
    }
    return str;
}

Stack::~Stack()
{
    delete s;
    delete t;
}