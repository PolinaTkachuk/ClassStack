#include"PersonKeeper.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

//возвращ ссылку на объект instance
PersonKeeper &PersonKeeper::Instance()
{
    // создаем единственный объект, поэтому указывает static и возвращаем его
    static PersonKeeper instance;
    return instance;
}

Stack <Person> PersonKeeper::ReadPersons(string way)
// Считывает из файла в стек, возвращает стек, создает объекты класса Person и помещает их в стек
{
    // передан путь до объекта класса ifstream , до файла
    ifstream file(way);
    // открываем файл на чтение
    file.open(way, ios::in);

    //проверка на удачное открытие файла
    if (!file)
    {
         string s;// строка для хранения текущей строки
         Stack<Person> stack;// создали объект
         while ( !file.eof())//пока не конец файла
                {
                    getline(file, s); // из файла считалась строка s
                     // file >> s ;
                    //помещаем в стек объект класса человек ( с помощью конструктора из строки формируем объект)
                    stack.Push(Person(s));
                }
         //возвращаем стек
         return stack;
    }
    //если файл не удалось открыть- сообщаем
    else{ throw "Error: the file did not open";}
    //закрытие файла
    file.close();
}

//записывает в файл из стека
void PersonKeeper::WritePersons(Stack <Person> s) const
{
    ofstream file; // создаем объект
    file.open("D:\\lab\\file.txt",ios::out); // открываем файл на запись

    Stack <Person> S1(s); //создаю копию передаваемого стека
    Person P= S1.Pop(); //вызвала Pop от копии-> получила текущего person, ведь стек не должен поменяться!(поэтому использ копию)
    // Объединила в одну строку и в файл записала
    file << P.getLastName()<<" "<< P.getFirstName()<<" "<<P.getPatronymic()<<endl ;

    file.close(); // закрываем файл
}

int PersonKeeper::Size(Stack <Person> s)
{
    //возвращаем размер переденного стека с типом person
    return s.Size();
}


