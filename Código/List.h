#include <iostream>
#include "Node.h"

template<typename NODO>
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

            Node<NODO>* actual = primero;
            Node<NODO>* temp = nullptr;

            while (actual!= nullptr)
            {
                temp = actual;
                actual = actual->getNext();
                delete temp;
            }

            std::cout << "Se han destruido todos los nodos\n\n";
        }
    }
    
    friend std::ostream& operator<<(std::ostream& os, const List<NODO>& list) {
        if (list.isEmpty())
        {
            os << "Conjunto Vacío\n";
            return os;
        }

        Node<NODO>* actual = list.primero;
        os << "La lista es: ";
        while (actual != nullptr)
        {
            os << actual->getData() << " ";
            actual = actual->getNext();
        }

        os << "\n\n";
        return os;
    }


    template<typename T, int N>
        void insertList(const T (&array)[N]) {
        for (int i = 0; i < N; ++i) {
            insertLast(array[i]);
            }
        }


   void insertLast(const NODO& obj)
   {
        Node<NODO> *nuevoNodo = getNewNode(obj);

        if (isEmpty())
        {
            primero = nuevoNodo;
            ultimo = nuevoNodo;
        }
        else
        {
            ultimo->setNext(nuevoNodo);
            nuevoNodo->setPrev(ultimo);
            ultimo = nuevoNodo;
        }
        ultimo->setNext(nullptr); 
        }

    bool isEmpty() const { return primero == nullptr; }

    void print() const
    {
        if (isEmpty()) 
        {
            std::cout << "Conjunto Vacío\n";
            return;
        }

        Node<NODO>* actual = primero;
        std::cout << "La lista es: ";
        while (actual!= nullptr)
        {
            std::cout << actual->getData() << " ";
            actual = actual->getNext();
        }

        std::cout << "\n\n";
    }

    Node<NODO>* getLast() const {
        if (isEmpty()) {
            throw std::runtime_error("La lista está vacía");
        }
        return ultimo;
    }
    
private:
    Node<NODO> *primero;
    Node<NODO> *ultimo;
    
    Node<NODO>* getNewNode(const NODO& obj) const
    {
        return new Node< NODO >(obj);
    }
};

