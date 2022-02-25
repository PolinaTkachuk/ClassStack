#ifndef CLASSSTACK_H
#define CLASSSTACK_H
#include <iostream>
using namespace std;
#include"EStackException.h"
#include"EStackEmpty.h"
//Контейнер стека список однонаправленный

//Стек  последним пришёл — первым вышел

template <class T> class Stack
{
private:
    class Node
    {
    public:
        int key=0;

        Node* next = nullptr;//указатель на след эл
        Node* head = nullptr; //текущий эл-т, голова

        Node() { head = 0; }
        Node(int _key, Node* _next)
        {
            key = _key;
            next = _next;
        }

    };
    Node* head;
    int size = 0;// размер
public:
    Stack() { head = 0; } //конструктор
    Stack(int n);
    ~Stack(); // деструктор

    void Push(const T&); // Помещение объекта в стек
    void Pop(); //  Извлечение объекта из стека
    int Size(); // размер стека
    bool Empty();// проверка на пустоту
    void print();// вывод стека для main.cpp
    void Clear(); // извлечение из стека всех узлов, для деструктора
};
// конструктор
template <class T> Stack<T>::Stack(int n) {
    Node *head = new Node();
    for (int i = n - 1; i > 0; i--)
        Push(i);
}
// деструктор
template <class T>
Stack<T>::~Stack()
{
    Clear();
}

template <class T>
void Stack<T>::Clear()
{
    while (head) {
        size--; Pop();
    }// пока в стеке есть элементы,удаляем
}

template <class T> void Stack<T>::Push(const T& k)
{
    Node* node = new Node(); // создаем новый узел
    //и записываем его в голову
    node->key = k;
    node->next = head;//бывшая голова сдвигается вправо
    head = node;
    size++; // увеличиваем размер

}

template <class T> void Stack<T>::Pop()
{
    if (Empty()) // если стек пуст, возвращаем исключение
    {
        throw EStackEmpty();
    }
    //исключаем и удаляем текущую голову
    Node* p = head;
    head = head->next;
    delete p;

    size--; // уменьшаем размер стека
}


template <class T> bool Stack<T>::Empty()
{
    if (head)return false;
    return true;
}
template <class T> void Stack<T>::print()
{
    Node* p = head;
    while (p) {
        cout << p->key <<" ";
        p = p->next;
    }
}
template <class T> int Stack<T>::Size()
{
    //return size;
    int count = 0;
    Node* t = head;
    while (t)
    {
        count++;
        t = t->next;
    }
    return count;
}

#endif // CLASSSTACK_H
