#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
private:
    //Stored Data in the Queue
    vector<int> data;
    // Pointer Pointing to first address of the Queue.
    int start_pointer;
    // Pointer Pointing to last address of the Queue.
    int end_pointer;
    // Whether Queue is Empty or not
    bool empty;

public:
    // Create an object of MyCircularQueue Class
    MyCircularQueue(int size)
    {
        start_pointer = 0;
        end_pointer = 0;
        // Size of Data(vector/array) is set to "size"
        data.resize(size);
        empty = true;
    };

    // Insert an element to Queue at the End.
    bool enQueue(int newItem)
    {
        // Return false if Queue if Empty
        if (isFull())
            return false;
        // Update empty when enQueue is called
        if (isEmpty())
            empty = false;
        // Add newItem to the vector array data
        data[end_pointer] = (newItem);
        end_pointer = (end_pointer + 1) % myCircularQueueSize();
        return true;
    }

    // Delete an element from Queue at the Start.
    // Note : We need to increment the start pointer by one.
    bool deQueue()
    {
        if (isEmpty())
            return false;

        start_pointer = (start_pointer + 1) % myCircularQueueSize();
        if (isFull())
            empty = true;

        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return data.at(start_pointer);
    }
    int Rear()
    {
        if (isEmpty())
            return -1;
        return data.at((end_pointer + myCircularQueueSize() - 1) % myCircularQueueSize());
    }

    int myCircularQueueSize()
    {
        return data.size();
    }
    bool isEmpty()
    {
        return empty;
    }
    bool isFull()
    {
        return (empty) ? false : start_pointer == end_pointer;
    }
};

// MyCircularQueue circularQueue = MyCircularQueue(3); // set the size to be 3
// circularQueue.enQueue(1);                           // return true
// circularQueue.enQueue(2);                           // return true
// circularQueue.enQueue(3);                           // return true
// circularQueue.enQueue(4);                           // return false, the queue is full
// circularQueue.Rear();                               // return 3
// circularQueue.isFull();                             // return true
// circularQueue.deQueue();                            // return true
// circularQueue.enQueue(4);                           // return true
// circularQueue.Rear();                               // return 4
