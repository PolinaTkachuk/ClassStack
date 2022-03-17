#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "ClassStack.h"
#include "Person.h"
#include<fstream>// работа с файлами
#include<string>

class PersonKeeper{
    // в соответствие с шаблоном Singleton
private:
    PersonKeeper(){ } // конструктор недоступен, класс можно создать только через Instance
    ~PersonKeeper(){ } // и деструктор
    // необходимо также запретить копирование
    PersonKeeper (PersonKeeper const&); // реализация не нужна
    PersonKeeper& operator= (PersonKeeper const&); // и тут не нужна

public:
    static PersonKeeper &Instance();// статическая функция обязательно
    Stack <Person> ReadPersons(string way);// Считывает из файла в стек, возвращает стек, создает объекты класса Person и помещает их в стек
    void WritePersons(Stack <Person> s) const;//записывает в поток из стека,стек не меняется (стек передается аргументом)
    int Size(Stack <Person> s); // количество persons в заданом стеке

};

#endif // PERSONKEEPER_H
