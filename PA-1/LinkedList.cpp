#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include <memory>
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    shared_ptr<ListItem<T>> tmp = otherLinkedList.head;
    insertAtHead(tmp->value);
    
    

    while(tmp->next!=NULL){
        T prev = tmp->value;
        insertAfter(tmp->next->value,prev);
        tmp=tmp->next;
    }
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    shared_ptr<ListItem<T>> tmp(new ListItem<T> (item));
    if(head == nullptr)head = tmp;
    else{
        head->prev= tmp;
        tmp->next = head;
        head = tmp;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    shared_ptr<ListItem<T>> tmp(new ListItem<T> (item));
    if (tail == nullptr) tail = tmp;
    else{
        tail -> next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    shared_ptr<ListItem<T>> node = searchFor(afterWhat);
     
        shared_ptr<ListItem<T>> tmp(new ListItem<T> (toInsert));
        if(node->next){tmp ->next = node->next;node->next->prev = tmp;}
        tmp->prev = node;
        node->next = tmp;
    
}


template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::getHead()
{  
    return head; 
}

template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::getTail()
{
    return tail;
}

template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::searchFor(T item)
{
    shared_ptr<ListItem<T>> node = getHead();
    while(node!=NULL){if(node->value == item)return node; node= node->next;}
    return NULL;
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
    shared_ptr<ListItem<T>> tmp = searchFor(item);
    
    if (tmp->prev == NULL) deleteHead();
    else if (tmp->next == NULL) deleteTail();
    else{
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        tmp->next = NULL;tmp->prev = NULL;
    }
}

template <class T>
void LinkedList<T>::deleteHead()
{   if(head == NULL)return;
    if(head->next == NULL){head = NULL; return;}
    shared_ptr<ListItem<T>> tmp = getHead();
    head = tmp->next;
    head->prev = NULL;
}

template <class T>
void LinkedList<T>::deleteTail()
{
    if(tail == NULL)return;
    shared_ptr<ListItem<T>> tmp = getTail();
    if(tail->prev == NULL){tail=NULL;return;}
    tail = tmp->prev;
    tail->next = NULL;
}

template <class T>
int LinkedList<T>::length()
{
    int count = 0;
    shared_ptr<ListItem<T>> tmp = getHead();
    while(tmp!=NULL){count+=1; tmp=tmp->next;}
    return count;
}

#endif
