#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parenthesis;

        for (char &c : s)
        {
            switch (c)
            {
            case '{':

            case '[':

            case '(':
                parenthesis.push(c);
                break;
            case '}':
                if (parenthesis.empty() || parenthesis.top() != '{')
                    return false;
                else
                    parenthesis.pop();
                break;
            case ']':
                if (parenthesis.empty() || parenthesis.top() != '[')
                    return false;
                else
                    parenthesis.pop();
                break;
            case ')':
                if (parenthesis.empty() || parenthesis.top() != '(')
                    return false;
                else
                    parenthesis.pop();
                break;
            }
        }

        return parenthesis.empty();
    }
};