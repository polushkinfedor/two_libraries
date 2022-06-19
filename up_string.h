#pragma once
#include <iostream>
#include <string>
#include <cmath>
// блок присваивания
#define SPACE ' '
#define NULL_STR ""

using namespace std;

class T_Upgrade_String {
private:
    void del_space_str (); // этот метод можно вызвать только внутри класса
    void del_first_space_str();
public:
    // Блок переменных
    string str;
    char cstyle[255];

    // Блок конструкторов/деструкторов
    T_Upgrade_String();
    T_Upgrade_String(string);
    ~T_Upgrade_String();

    // Блок методов для строки типа string
    void del_word_str (string);
    void del_space_two_and_more_str ();
    int search_repeat_str();
    int string_to_int();
    int** string_to_arr();
};