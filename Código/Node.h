#pragma once

#include <iostream>

template<typename NODETYPE>
class List;

template<typename NODETYPE>
class Node
{
    friend class List<NODETYPE>;

public:
    explicit Node(const NODETYPE& info)
        : data(info), next(nullptr), prev(nullptr) {}

    NODETYPE getData() const { return data; }

    Node<NODETYPE>* getNext() const { return next; }

    Node<NODETYPE>* getPrev() const { return prev; }

    void setNext(Node<NODETYPE>* newNext) { next = newNext; }

    void setPrev(Node<NODETYPE>* newPrev) { prev = newPrev; }

    void printData() const { std::cout << data << '\n'; }

private:
    NODETYPE data;
    Node<NODETYPE>* next;
    Node<NODETYPE>* prev;
};