#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
#include "EStackException.h"
//Наследник класса EStackException

class EStackEmpty : public EStackException
{
public:
    //по умолчанию, сообщение- стек пуст
    EStackEmpty(): EStackException("Stack is empty!!") { }
};


#endif // ESTACKEMPTY_H
