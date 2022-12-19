#include "Doubleconnlist.h"
#include "iostream"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    DoubleConnList <int> listint;
    listint.add(1);
    listint.add(2);
    listint.add(3);
    listint.add(4);
    listint.add(5);
    listint.add(6);
    listint.show();

    DoubleConnList <char> list;
    list.add('a');
    list.add('b');
    list.add('c');
    list.add('d');
    list.add('e');
    list.add('f');
    list.show();
    cout << "Перевернутый список" << endl;
    list.reverse();
    list.show();

    cout << "Создан новый двусвязный список list_Copy";
    DoubleConnList <char> list_Copy;
    list_Copy = DoubleConnList<char>(list);
    cout << endl;
    list_Copy.show();

    list_Copy.clear();
    cout << "Применение оператора присваивания" << endl;
    list_Copy = list;
    list_Copy.show();

    cout << "Удаление элемента по индексу" << endl;
    int index;
    cin >> index;
    cout << endl;
    list.remove(index);

    list.show();
    list_Copy.show();

    list_Copy.clear();
    cout << "Применение конструктора перемещения" << endl;
    list_Copy = DoubleConnList<char>(std::move(list));

    list.show();
    list_Copy.show();

    cout << "Применение оператора перемещения" << endl;
    list.clear();
    list = std::move(list_Copy);

    list.show();
    list_Copy.show();


    cout << "\nДобавление элемента по индексу\nВведите index: ";
    int idx = 0;
    cin >> idx;
    list.show();
    list.insert('g', idx);
    list.show();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

