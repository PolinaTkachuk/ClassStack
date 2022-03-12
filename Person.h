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
    Person(const Person&);
    // подаем строку из 3х слов и инициализируем членданные ими: фамилия,имя,отчество
    Person(string fullname)
    {
        int i=0;
        while(i!=strlen(fullname))
        {
            int j=0;
           if(fullname[i+1]!=' ')
           {
               last_name=fullname[i];
               i++;

           }
        for(i=0;fullname[i]!=' ';i++)
         {

          }
        last_name=buf[0];
        }

        /*string* str;
        int n=strlen(fullname);
        str = new string[];
         // разбиваем полученную строку на не пустые слова
        str= fullname.split(' ');
            while (ptr){                //while (ptr != NULL)
                cout << ptr << '\n';
                ptr = strtok(0,SEPARATORS);   //Подбираем слово
            }
            */
    }

    const string& getLastName() const { return last_name; }
    const string& getFirstName() const { return first_name; }
    const string& getPatronymic() const { return patronymic; }

    void setLastName(const string& LastName) { last_name = LastName; }
    void setFirstName(const string& FirstName) {first_name=FirstName;}
    void setPatronymic(const string& Patronymic){patronymic=Patronymic;}

};

#endif // PERSON_H
