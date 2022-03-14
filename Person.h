#ifndef PERSON_H
#define PERSON_H
#include<string>
#include <sstream>
using namespace std;

//Класс Человек
class Person{
private:
    string last_name;
    string first_name;
    string patronymic;

public:
    Person(){last_name="";first_name="";patronymic="";}
    Person(const Person& P){last_name=P.last_name; first_name=P.first_name; patronymic=P.patronymic;}

    string* fragment(string bap) //вспомагательная функция для Person(string fullname)
    //разбивает строку на 3 слова
    {
        static string ans[3];
        int count = 0;
        int j = 0;
        for (; count < 3; count++)
        {
            while (bap[j] != ' ' || j < bap.length())
            {
                ans[count].append(1, bap[j]);j++;
            }
        j++;
        }
        return ans;
    }

    // подаем строку из 3х слов и инициализируем членданные ими: фамилия,имя,отчество
    Person(string fullname)
    {

     // разбиваем полученную строку на не пустые слова
     string *str=fragment(fullname);
     //инизиализируем
     last_name=str[0];
     first_name=str[1];
     patronymic=str[2];


    }

    const string& getLastName() const { return last_name; }
    const string& getFirstName() const { return first_name; }
    const string& getPatronymic() const { return patronymic; }

    void setLastName(const string& LastName) { last_name = LastName; }
    void setFirstName(const string& FirstName) {first_name=FirstName;}
    void setPatronymic(const string& Patronymic){patronymic=Patronymic;}

};

#endif // PERSON_H
