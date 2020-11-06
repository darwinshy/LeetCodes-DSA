#include <iostream>
#include <vector>
using namespace std;
class MinStack
{
public:
    vector<int> minStack;
    vector<int> minValueStack;

    MinStack()
    {
        minValueStack.push_back(INT_MAX);
    };
    void push(int newItem)
    {
        minStack.push_back(newItem);

        if (newItem <= minValueStack.back() || minValueStack.empty())
        {
            minValueStack.push_back(newItem);
        }
    }
    void pop()
    {
        if (getMin() == minStack.back())
        {
            minValueStack.pop_back();
        }

        minStack.pop_back();
    }
    int top()
    {
        return minStack.back();
    }
    int getMin()
    {
        return minValueStack.back();
    }
};