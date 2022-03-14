#include"PersonKeeper.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

PersonKeeper &PersonKeeper::Instance()
{
    // создаем единственный объект, поэтому указывает static и возвращаем его
    static PersonKeeper instance;
    return instance;
}

Stack <Person> PersonKeeper::ReadPersons(string way)
// Считывает из файла в стек возвращает стек, создает объекты класса Person и помещает их в стек
{
    // передан пусть до объекта класса ifstream , до файла
    ifstream file(way);
    file.open(way, ios::in);// открываем файл на чтение
    //file.open("D:\\lab\\ClassStack\\file.txt",ios::in);

    //проверка на удачное открытие файла
    if (file.is_open())
    {
         string s;// строка для хранения текущей строки
         Stack<Person> stack;
         while (getline(file, s) && !file.eof())
                {
                    //std::cout << s << std::endl;
                    //помещаем в стек объект класса человек ( с помощью конструктора из строки формируем объект)
                    stack.Push(Person(s));
                }
         return stack;
    }
    else{ throw "Error: the file did not open";}
    file.close();
}

//записывает в файл из стека
void PersonKeeper::WritePersons(Stack <Person> s) const
{
    ofstream file; // создаем объект
    file.open("D:\\lab\\ClassStack\\file.txt",ios::out); // открываем файл на запись

    Stack <Person> S1(s); //создаю копию передаваемого стека
    Person P= S1.Pop(); // вызвала Pop от копии-> получила текущего person
    file << P.getLastName()<<" "<< P.getFirstName()<<" "<<P.getPatronymic()<<endl ;// Объединила в одну строку и в файл

    file.close(); // закрываем файл
}

int PersonKeeper::Size(Stack <Person> s)
{
    return s.Size();
}


