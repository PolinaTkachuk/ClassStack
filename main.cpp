#include"PersonKeeper.h"
#include <iostream>
using namespace std;


int main()
{
    PersonKeeper& keeper = PersonKeeper::Instance();
    string s = "D:\\lab\\ClassStack\\file.txt";
    keeper.ReadPersons(s);

    Stack <int> S1;
    Stack <int> S2(5);

    if (S1.Empty()) cout << "S1 is Empty"<<endl;
    else cout << "S1 is not empty";

    if(S2.Empty()) cout<<"S2 is Empty";
    else cout<<"S2 is not empty"<<endl;

    //исключение при пустом стеке
    //S1.Pop();

       cout << "enter 6 integer numbers: " << endl; // вводим 6 чисел
       for (int i = 0; i != 6;i++) {
        int a;
        cin >> a;

        S1.Push(a);  // добавляем введенные числа
      }
       S1.print();

       cout << endl<<"S2:" << endl;
       S2.print();
       cout << endl<<"delete element from S2 " << endl;
       S2.Pop();
       S2.print();
       cout <<endl<< "Size S2=";
       cout<<S2.Size()<<endl;

       cout << endl<<"Size S1=";
       cout << S1.Size()<<endl;

}
