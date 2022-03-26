#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
#include "EStackException.h"
//Наследник класса EStackException

class EStackEmpty : public EStackException
{
public:
    //по умолчанию, сообщение- стек пуст
     EStackEmpty() : EStackException("Stack is empty!!") { }
    // конструктор копирования
     EStackEmpty(const EStackEmpty& arg) : EStackException(arg) { }
};


#endif // ESTACKEMPTY_H
