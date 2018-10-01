#include <iostream>
#include <string>
#include "convert.h"

using namespace std;

int main()
{
    string str = "";
    // test for convert
    cout << "Please input the infix operation: ";
    while (getline(cin, str, '\n'))
    {
        cout << endl;

        cout << "Prefix Convertion:" << endl;
        prefix(str);
        cout << endl;

        cout << "Postfix Convertion:" << endl;
        postfix(str);
        cout << endl;

        cout << "Please input the infix operation: ";
    }

    return 0;
}