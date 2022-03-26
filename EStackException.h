#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <cstring>

//Класс обработки исключительных ситуаций
class EStackException
{
private:
    char* message;//член данное хранящее текст сообщения
public:
    EStackException(const char* arg_message)//конструктор, который вызывается в Pop
    {
        //выделяем память под сообщение равную длинне сообщения +1 , так как добавл /0
        message = new char[strlen(arg_message)+1];
//копируем данные входные в message учитывая размер, в моем случае размер сообщения(Stack is empty!!) фиксированный 16+1
        strcpy_s(message,17,arg_message);
    }
    EStackException(const EStackException& arg)// конструктор копирования
    {
        //выделяем память под сообщение равную длинне сообщения +1 , так как добавл /0
        message = new char[strlen(arg.message) + 1];
        //копируем данные входные в message учитывая размер, в данном случае размер зависит от переданного аргумента
        strcpy_s(message, strlen(arg.message) + 1, arg.message);
    }
    ~EStackException() //деструктор
    {
        delete message;
    }
    //публичный метод char* what(), возвращающий диагностическое сообщение,(из конструктора нельзя вызвать сообщение)
    const char* what() const { return message; }
};


#endif // ESTACKEXCEPTION_H

