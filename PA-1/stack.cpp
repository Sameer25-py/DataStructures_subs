#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{}
    
template <class T>
Stack<T>::Stack(Stack<T>& otherStack)
{
    shared_ptr<ListItem<T>> tmp = otherStack.list.getHead();
    list.insertAtHead(tmp->value);
    
    

    while(tmp->next!=NULL){
        T prev = tmp->value;
        list.insertAfter(tmp->next->value,prev);
        tmp=tmp->next;
    }
}

template <class T>
Stack<T>::~Stack()
{}

template <class T>
void Stack<T>::push(T item)
{   
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
    return list.getHead()->value;
}

template <class T>
T Stack<T>::pop()
{
    T val = list.getHead()->value;
    list.deleteHead();
    return val;
}

template <class T>
int Stack<T>::length()
{
    return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (list.getHead() == NULL) return true;
    else return false;
}

#endif
