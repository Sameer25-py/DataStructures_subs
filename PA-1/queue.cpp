#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{}
    
template <class T>
Queue<T>::Queue(Queue<T>& otherQueue)
{
    shared_ptr<ListItem<T>> tmp = otherQueue.list.getHead();
    list.insertAtHead(tmp->value);
    
    while(tmp->next!=NULL){
        T prev = tmp->value;
        list.insertAfter(tmp->next->value,prev);
        tmp=tmp->next;
    }
}

template <class T>
Queue<T>::~Queue()
{}

template <class T>
void Queue<T>::enqueue(T item)
{
    if(list.getHead() == NULL)list.insertAtHead(item);
    else{
        shared_ptr<ListItem<T>> tmp = list.getHead();
        while(tmp->next !=NULL)tmp=tmp->next;
        list.insertAfter(item,tmp->value);
    }
}

template <class T>
T Queue<T>::front()
{   
    return list.getHead()->value;
}

template <class T>
T Queue<T>::dequeue()
{
    T val = list.getHead()->value;
    list.deleteHead();
    return val;
}

template <class T>
int Queue<T>::length()
{
    return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
    if (list.getHead() == NULL) return true;
    else return false;
}


#endif
