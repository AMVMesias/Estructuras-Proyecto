#pragma once
#include <iostream>
#include "Node.h"

template<typename NODETYPE>
class List
{
public:
    List()
        : primero(nullptr), ultimo(nullptr)
    {}
    
    ~List()
    {
        if (!isEmpty())
        {
            std::cout << "Destruyendo nodos... \n";

            Node<NODETYPE>* actual = primero;
            Node<NODETYPE>* temp = nullptr;

            while (actual!= nullptr)
            {
                temp = actual;
                actual = actual->getNext();
                delete temp;
            }

            std::cout << "Se han destruido todos los nodos\n\n";
        }
    }


    template<typename T, int N>
        void insertList(const T (&array)[N]) {
        for (int i = 0; i < N; ++i) {
            insertLast(array[i]);
            }
        }


    void insertLast(const NODETYPE& value)
    {
        Node<NODETYPE> *newNode = getNewNode(value);

        if (isEmpty())
        {
            primero = newNode;
            ultimo = newNode;
        }
        else
        {
            newNode->setPrev(ultimo);
            ultimo->setNext(newNode);
            ultimo = newNode;
        }
    }

    bool isEmpty() const { return primero == nullptr; }

    void print() const
    {
        if (isEmpty()) 
        {
            std::cout << "Conjunto vacío\n";
            return;
        }

        Node<NODETYPE>* actual = primero;
        std::cout << "La lista es: ";
        while (actual!= nullptr)
        {
            std::cout << actual->getData() << " ";
            actual = actual->getNext();
        }

        std::cout << "\n\n";
    }

    Node<NODETYPE>* getLast() const {
        if (isEmpty()) {
            throw std::runtime_error("La lista está vacía");
        }
        return ultimo;
    }
    
private:
    Node<NODETYPE> *primero;
    Node<NODETYPE> *ultimo;
    
    Node<NODETYPE>* getNewNode(const NODETYPE &value) const
    {
        return new Node< NODETYPE >(value);
    }
};

