#pragma once

#include <iostream>

template<typename NODO>
class List;

template<typename NODO>
class Node
{
    friend class List<NODO>;

public:
    explicit Node(const NODO& info)
        : data(info), next(nullptr), prev(nullptr) {}

    NODO getData() const { return data; }

    Node<NODO>* getNext() const { return next; }

    Node<NODO>* getPrev() const { return prev; }

    void setNext(Node<NODO>* newNext) { next = newNext; }

    void setPrev(Node<NODO>* newPrev) { prev = newPrev; }

    void mostrarDatos() const { std::cout << data << '\n'; }

private:
    NODO data;
    Node<NODO>* next;
    Node<NODO>* prev;
};