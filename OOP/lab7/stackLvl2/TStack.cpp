#include <iostream>
#include <memory>
#include "TStack.h"

template <class T>
TStack<T>::TStack()
{
    head = nullptr;
    count = 0;
}

template <class T>
void TStack<T>::Push(const T &item)
{
    TStackItem<T> *tmp = new TStackItem<T>(item, head);
    head = tmp;
    ++count;
}

template <class T>
bool TStack<T>::IsEmpty() const
{
    return !count;
}

template <class T>
uint32_t TStack<T>::GetSize() const
{
    return count;
}

template <class T>
void TStack<T>::Pop()
{
    if(head) {
        TStackItem<T> *tmp = &head->GetNext();
        delete head;
        head = tmp;
        --count;
    }
}

template <class T>
T &TStack<T>::Top()
{
    return head->Pop();
}

template <class T>
TStack<T>::~TStack()
{
    for(TStackItem<T> *tmp = head, *tmp2; tmp; tmp = tmp2) {
        tmp2 = &tmp->GetNext();
        delete tmp;
    }
}


template <class T>
void TStack<T>::RemByType(const int& type)
{
    if(this->IsEmpty()) {
        return;
    }

    TStack<T> *tmp = new TStack<T>();

    TStackItem<T> *tmp = this->head;
    for(uint32_t i = this->count; i > 0; --i) {
        if(this->head->value->Type() == type) {
            this->Pop();
        } else {
            tmp->Push(this->head->value);
        }
    }
    for(uint32_t i = tmp->count; i > 0; --i) {
        this->Push(tmp->head->value);
    }
    delete tmp;
}

template <class T>
void TStack<T>::RemLesser(double value)
{
    if(this->IsEmpty()) {
        return;
    }

    TStack<T> *tmp = new TStack<T>();

    TStackItem<T> *tmp = this->head;
    for(uint32_t i = this->count; i > 0; --i) {
        if(this->head->value->Square() < value) {
            this->Pop();
        } else {
            tmp->Push(this->head->value);
        }
    }
    for(uint32_t i = tmp->count; i > 0; --i) {
        this->Push(tmp->head->value);
    }
    delete tmp;
}

template <class T>
void TStack<T>::RemGreater(double value)
{
    if(this->IsEmpty()) {
        return;
    }

    TStack<T> *tmp = new TStack<T>();

    TStackItem<T> *tmp = this->head;
    for(uint32_t i = this->count; i > 0; --i) {
        if(this->head->value->Square() > value) {
            this->Pop();
        } else {
            tmp->Push(this->head->value);
        }
    }
    for(uint32_t i = tmp->count; i > 0; --i) {
        this->Push(tmp->head->value);
    }
    delete tmp;
}

typedef unsigned char Byte;

template class
TStack<void *>;