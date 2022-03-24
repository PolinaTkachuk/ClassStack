#ifndef PERSON_H
#define PERSON_H
#include<string>
#include <sstream>
using namespace std;

//Класс Человек
class Person{
private://членданные
    string last_name;//фамилия
    string first_name;//имя
    string patronymic;//отчество

public:
    Person(){last_name="";first_name="";patronymic="";}//конструктор по умолчанию
    //конструктор копирования
    Person(const Person& P){last_name=P.last_name; first_name=P.first_name; patronymic=P.patronymic;}

    string* fragment(string bap) //вспомагательная функция для Person(string fullname)
    //разбивает строку на 3 слова
    {
        static string ans[3];//массив для записи фамилия имя отчество
        int count = 0;// счетчик слов
        size_t j = 0; //счетчик букв
        for (; count < 3; count++)//пока не считали 3 слова
        {
            while (bap[j] != ' ' || j < bap.length())//пока не встретили пробел или пока не конец строки
            {
                //Формируем слово,и сохр его в массив под счетчиком count,
                //append-Добавляет в конец строки 1 символ равный j-тому эл-ту
                ans[count].append(1, bap[j]);j++;
            }
        j++;// учитываем пробел
        }
        return ans;// возвращ массив слов
    }

    // подаем строку из 3х слов и инициализируем членданные ими: фамилия,имя,отчество
    Person(string fullname)
    {

     // разбиваем полученную строку на  слова
     string *str=fragment(fullname);
     //инизиализируем
     last_name=str[0];
     first_name=str[1];
     patronymic=str[2];


    }
    //возвращение член данных через функции get и коопирование член данных через set
    const string& getLastName() const { return last_name; }
    const string& getFirstName() const { return first_name; }
    const string& getPatronymic() const { return patronymic; }

    void setLastName(const string& LastName) { last_name = LastName; }
    void setFirstName(const string& FirstName) {first_name=FirstName;}
    void setPatronymic(const string& Patronymic){patronymic=Patronymic;}

};

#endif // PERSON_H
