#include <iostream>
#include <string>
#include "stack.h"
#include "convert.h"

using namespace std;

int main()
{
    string str = "";
    // test for convert
    while (getline(cin, str, '\n'))
    {
        cout << postfix(str) << endl;
        cout << prefix(str) << endl;
    }

    return 0;
}