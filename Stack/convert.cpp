#include "convert.h"
#include "stack.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int priority(char op)
{
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/' || op == '%') return 2;
    else return 0;
}

string postfix(string str)
{
    // Declare a Stack
    Stack* stack = new Stack();
    // Declare a string for postfix
    string p = "";
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
           while (stack->top() != '(')
           {
               p += stack->pop();
           }
           stack->pop();
       }
       else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
       {
           strng = "";
           strng += str[i];
           
           while (priority(stack->top() ) >= priority(str[i]) )
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

string postToPrefix(string str)
{
    cout << "Step 1: Convert the infix to postfix" << endl;
    str = postfix(str);

    // Declare a Stack
    Stack *stack = new Stack();
    // Declare two vectors to revcord some info
    vector<string> infixScanned;
    vector<string> stackList;
    
    cout << "Next, convert the postfix to the prefix" << endl;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
        {
            // Pop two operands from the stack
            string op1 = stack->pop();
            string op2 = stack->pop();

            // Concatenate operands and operator
            string temp = str[i] + op2 + op1;

            // Push temp string into the stack
            stack->push(temp);
        }
        else
            stack->push(string(1, str[i]) );

        infixScanned.push_back(string(1, str[i]) );
        stackList.push_back(stack->print());
    }

    // Print all the info
   cout << setw(10) << "Infix Scanned" << setw(10) << "|"
        << setw(20) << "Stack" << setw(5) << endl;
   for (int i = 0; i < infixScanned.size(); i++)
   {
       cout << setw(10) << infixScanned[i] << setw(10)
            << setw(30) << stackList[i] << setw(5) << endl;
   }

    return stack->str_top();
}
