#include "convert.h"
#include "stack.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

string postfix(string str)
{
    // Declare a Stack
    Stack* stack = new Stack();
    // Declare a string for postfix
    string p = "";
    // Declare a map for checking out each operator's score
    map<string, int> score;
    score["+"] = 5;
    score["-"] = 5;
    score["*"] = 6;
    score["/"] = 6;
    score["%"] = 6;
    // Declare three vectors to revcord some info
    vector<string> infixScanned;
    vector<string> stackList;
    vector<string> postfixExpression;
    string strng = ""; // temp string
    int i = 0;

    // remove space firstly
    str.erase(std::remove(str.begin(), str.end(), ' '),
               str.end());

    // Step 1: Add ")" to the end of infix expression
    str += ")";

    // Step 2: Push "(" to the stack
    stack->push("(");
    // Initialize three vectors, which are used to record the verbose info
    infixScanned.push_back("");
    stackList.push_back("(");
    postfixExpression.push_back("");

    // Step 3: Repeat until each character in the infix notation is scanned
    /*
        If a "(" is encountered, push it on the stack
        If a operand (where a digit or a character) is encountered, add it to the postfix expression
        If a ")" us encountered, then
            a. Repeatedly pop from stack and add it to the postfix expression until a "(" is encountered
            b. Discard the "(". That is, remove the "(" from stack and do not add it to the postfix expression
        If an operator O is encountered, then
            a. Repeatedly pop from the stack and add each operator (pop from the stack) to the postfix expression
                which has the same precedence or a higher precedence than O
            b. Push the operator O to the stack
        [End of If]
    */
   for (i = 0; i < str.size(); i++)
   {
       if (str[i] == '(') stack->push(str[i]);
       else if (isdigit(str[i]) || isalpha(str[i]) ) p += str[i];
       else if (str[i] == ')')
       {
           while (stack->top() != "(")
           {
               p += stack->pop();
           }
           stack->pop();
       }
       else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
       {
           strng = "";
           strng += str[i];
           int temp = score[strng];
           while (score[stack->top()] >= temp)
           {
               p += stack->pop();
           }
           stack->push(strng);
       }
       else
       {
           // do nothing in this homework
       }

       // Record every step-by-step info
       strng = "";
       strng += str[i];
       infixScanned.push_back(strng);
       stackList.push_back(stack->print());
       postfixExpression.push_back(p);
   }    

   // Step 4: Repeatedly pop from the stack and add it to the postfix expression until the stack is empty
   while (!stack->isEmpty())
   {
       p += stack->pop();
       
       // Record every step-by-step info
       infixScanned.push_back("");
       stackList.push_back(stack->print());
       postfixExpression.push_back(p);
   }

   // Print all the info
   cout << setw(10) << "Infix Scanned" << setw(10) << "|"
        << setw(10) << "Stack" << setw(5) <<  "|" 
        << setw(10) << "Postfix Expression" << setw(5) << endl;
   for (int i = 0; i < infixScanned.size(); i++)
   {
       cout << setw(10) << infixScanned[i] << setw(10)
            << setw(20) << stackList[i] << setw(5)
            << setw(20) << postfixExpression[i] << setw(5) << endl;
   }

   // Step 5: Exit
    return p;
}

string prefix(string str)
{
    // Declare a prefix string
    string p = "";

    // Replace "(" to ")" and ")" to "("
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') p += ')';
        else if (str[i] == ')') p += '(';
        else p += str[i];
    }

    // Reverse all the string
    reverse(p.begin(), p.end());
    // Print the result after reversing firstly
    cout << "Step 1: " << p << endl;

    // Find the postfix string for this reverse string
    p = postfix(p);
    // Print the result after turning the postfix string
    cout << "Step 2: " << p << endl;

    // Finally, reverse this string again
    reverse(p.begin(), p.end());
    // Print the result after reversing lastly
    cout << "Step 3: " << p << endl;

    return p;
}