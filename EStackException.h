#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <cstring>

//Класс обработки исключительных ситуаций
class EStackException
{
private:
    char* message;
public:
    EStackException(const char* arg_message)
    {
        message = new char[strlen(arg_message)+1];
        strcpy_s(message,100,arg_message);
    }
    EStackException(const EStackException& arg)
    {
        message = new char[strlen(arg.message)+1];
       strcpy_s(message,100,arg.message);
    }
    ~EStackException()
    {
        delete message;
    }
    //публичный метод char* what(), возвращающий диагностическое сообщение
    const char* what() const { return message; }
};


#endif // ESTACKEXCEPTION_H

