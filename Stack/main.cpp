#include <iostream>
#include <string>
#include "convert.h"

using namespace std;

int main()
{
    string post = "", pre = "";
    string str = "";
    // test for convert
    cout << "Please input the infix operation: ";
    while (getline(cin, str, '\n'))
    {
        cout << endl;

        cout << "Prefix Convertion:" << endl;
        pre = postToPrefix(str);
        cout << endl;
        cout << "The prefix version of the infix: " << pre << endl;
        cout << endl;

        cout << "Postfix Convertion:" << endl;
        post = postfix(str);
        cout << endl;
        cout << "The postfix version of the infix: " << post << endl;
        cout << endl;

        cout << "Please input the infix operation: ";
    }

    return 0;
}