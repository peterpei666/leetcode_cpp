#include <iostream>
#include <algorithm>
using namespace std;

class MyCircularDeque
{
private:
    int size,capacity;
    int front,rear;
    vector<int> list;
    
public:
    MyCircularDeque(int k)
    {
        front=0;
        rear=0;
        size=0;
        capacity=k;
        list.resize(k);
    }
    
    bool insertFront(int value)
    {
        if(isFull())
        {
            return false;
        }
        front=(front-1+capacity)%capacity;
        size++;
        list[front]=value;
        return true;
    }
    
    bool insertLast(int value)
    {
        if(isFull())
        {
            return false;
        }
        list[rear]=value;
        rear=(rear+1)%capacity;
        size++;
        return true;
    }
    
    bool deleteFront()
    {
        if(isEmpty())
        {
            return false;
        }
        size--;
        front=(front+1)%capacity;
        return true;
    }
    
    bool deleteLast()
    {
        if(isEmpty())
        {
            return false;
        }
        size--;
        rear=(rear-1+capacity)%capacity;
        return true;
    }
    
    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return list[front];
    }
    
    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return list[(rear-1+capacity)%capacity];
    }
    
    bool isEmpty()
    {
        return size==0;
    }
    
    bool isFull()
    {
        return size>=capacity;
    }
};
