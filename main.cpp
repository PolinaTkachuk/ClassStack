#include"PersonKeeper.h"
#include <iostream>
#include<fstream>
using namespace std;


int main()
{

      // тестирование часть№1 лаба№1
        Stack <int> S; //создание пустого стека
        try
        {
           S.Pop();//проверка работы исключения при пустом стека
         }
        catch (const EStackException& e )//ловим исключение из throw в функции Pop
        {
            cout << e.what()<<endl; //вывод сообщения
        }

        Stack <int> S1; //создание стека
        cout << "Использование Push" << endl;
        for(int i=5;i>0;i--) //заполнение его 5ю значениями int
        S1.Push(i); //проверка работы функции добавления
        S1.print(); //вывод на консоль

        cout << endl<<"Удаляем 1элемент, использование Pop" << endl;
        S1.Pop();
        S1.print();//вывод на консоль

        cout<<endl<<"размер стека S1="<<S1.Size()<<endl;
        S1.Clear();
        cout << "cтек S1 удален";
        S1.print();
        cout << endl << "размер удаленного стека S1=" << S1.Size() << endl;

  // тестирование часть№2 лаба№1
    ifstream in("file.txt");// Открыли файл на чтение
    if(!in) cout<<"error"; //проверка открытия
    PersonKeeper& keeper = PersonKeeper::Instance(); //создали единственный объект класса одиночки
    string s = "D:\\lab\\file.txt";
    Stack <Person> P;//создали объект типа человек
        try { //обработка исключения

           P= keeper.ReadPersons(in);// вызвали функцию чтения из файла
        }
        catch (...) {
            cout <<"Error: the file did not open" << endl; //сообщение об ошибке

        }

   PersonKeeper::Instance().WritePersons(P);//вызвана функция записи

    //для инструкции пользователя часть1
    /*
        Stack <int> S1; //создание стека
        cout << "Использование Push для разных типов" << endl;
        for (int i = 5; i > 0; i--) //заполнение его 5ю значениями int
            S1.Push(i); //проверка работы функции добавления
        cout << "S1:";
        S1.print(); //вывод на консоль
        cout << "\n";
        Stack<string> s; //создание стека типа string
        s.Push("a"); //добавление строки а
        cout << "s:";
        s.print(); //вывод
        */
}

