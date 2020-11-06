#include <iostream>
#include <vector>
using namespace std;
class MyQueue
{
private:
    //Stored Data in the Queue
    vector<int> data;
    // Pointer Pointing to first address of the Queue.
    int start_pointer;

public:
    // Create an object of MyQueue Class
    MyQueue() { start_pointer = 0; };

    // Insert an element to Queue at the End.
    // Note : No need to change the pointer of the queue.
    void enQueue(int x)
    {
        data.push_back(x);
    }
    // Delete an element from Queue at the Start.
    // Note : We need to increment the pointer by one.
    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        start_pointer++;
    }
    // Recieve the first element from Queue from the Start.
    int getFirstElement()
    {
        return data.at(start_pointer);
    }

    // Check whether Queue is Empty or not
    bool isEmpty()
    {
        return start_pointer >= data.size();
    }
};
