#ifndef CLASSSTACK_H
#define CLASSSTACK_H
#include <iostream>
#include"EStackEmpty.h"
using namespace std;

//Контейнер стека список однонаправленный
//Суть Стека последним пришёл — первым вышел
//Класс является шаблонным
template <class T> class Stack
{
private:
    //Класс Узел
    class Node
        {
        public:
            T key = 0;//
            Node* head = nullptr;// указатель на голову
            Node* next = nullptr;//указатель на след эл
            Node() { head = nullptr; } //конструктор по умолчанию
            Node(T _key, Node* _next)//конструктор, создающий узел с заданым ключом и указателем на след эл
            {
                key = _key;
                next = _next;
            }

        };

        int size = 0;// размер стека
        Node* head = nullptr;
public:
    Stack() { head = nullptr; size=0; } //конструктор по умолчанию
    Stack(const Stack <T>&);// конструктор копирования
    ~Stack(); // деструктор

    void Push(const T&); // Помещение объекта в стек
    const T Pop(); //  Извлечение объекта из стека
    int Size(); // размер стека

    void print();// вывод стека для main.cpp
    void Clear(); // извлечение из стека всех узлов, для деструктора
    bool Empty();// проверка на пустоту

};

// деструктор
template <class T>
Stack<T>::~Stack()
{
    Clear();// удаляем все узлы и освобождаем память
}

//создается копия передаваемого стека
template <class T> Stack<T>::Stack(const Stack<T>& S)
{
    for (int i = S.size; i > 0; i--)//цикл с конца до головы стекаS,где S.size размер передаваемого стека
    {
        head = nullptr; //зануляем исходную голову
        Node* temp = S.head; //создаем новый узел равный голове переданного стека
        for (int j = 0; j < i; j++) // цикл с начала до i-го узла
        {
            temp = temp->next;//идем до i-го эл-та переданного стека  S
        }
        //создаем новый узел, с ключом узла tmp и со след эл-том (next) равным head
        Node* newNode = new Node{ temp->key, head };
        head = newNode;// исходная новая голова становится равной созданному узлу
    }
    size = S.size;// размеры исходного стека= размеру передаваемого стека
}

// пока в стеке есть элементы,удаляем
template <class T>
void Stack<T>::Clear()
{
    while (head)// пока стек не пуст
    {
        Node* h=head; //создание нового узла хранящего голову
        head=head->next; //голова теперь равна следующему элементу после головы
        delete h;// удаление узла хранящего голову
        size--; //уменьшение размера
    }
}
//Метод Push помещает объект, переданный в качестве аргумента функции, в начало стека
template <class T> void Stack<T>::Push(const T& k)
{
    Node* node = new Node(); // создаем новый узел
    //и записываем его в голову
    node->key = k;//создается новый узел, который имеет значение аргумента функции k
    node->next = head;//бывшая голова сдвигается вправо
    head = node;// а созданный узел становится головой
    size++; // увеличиваем размер

}

//Метод Pop извлекает объект из стека и возвращает его
template <class T> const T Stack<T>::Pop()
{
    if (head==nullptr) // если стек пуст, возвращаем исключение
    {
        throw EStackEmpty();// вызов сообщения
    }
    T data=head->key;//сохраняем значение того узла, который извлекается, то есть головы
    Node* p = head;//создание нового узла хранящего голову
    head = head->next;//голова теперь равна следующему элементу после головы
    delete p;// удаление узла хранящего голову

    size--; // уменьшаем размер стека
    return data;// возвращение значения удаленного узла
}

//проверка на пустоту
template <class T> bool Stack<T>::Empty()
{
    if (head)return false;
    return true;
}

// вывод стека на консоль
template <class T> void Stack<T>::print()
{
    Node* p = head;//создание нового узла хранящего голову
    while (p) { // цикл перебор всех узлов стека
        cout << p->key <<" "; //вывод значений узлов
        p = p->next; //переход к след эл-ту
    }
}
template <class T> int Stack<T>::Size()
{
    //return size;
    int count = 0;// счетчик с начала стека
    Node* t = head;//создание нового узла хранящего голову
    while (t)// цикл перебор всех узлов стека
    {
        count++;//считаем каждый узел
        t = t->next;//переход к след эл-ту
    }
    return count;// вывод количества узлов
}

#endif // CLASSSTACK_H






