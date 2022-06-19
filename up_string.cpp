#include "up_string.h"

// Реализация констукторов/деструкторов
T_Upgrade_String::T_Upgrade_String()
{
    cout << "создан пустой объект класса, воспользуйтесь деструктором для очищения памяти" << endl;
}
T_Upgrade_String::T_Upgrade_String(string s)
{
    str = s;
}
T_Upgrade_String::~T_Upgrade_String()
{

}

// Реализация методов для переменной типа string
void T_Upgrade_String::del_space_str()
{
    string ans_str = NULL_STR;
    for (int i(0); i<str.length(); i++)
    {
        if (str[i] != SPACE)
        {
            ans_str += str[i];
        }
    }
    str = ans_str;
}
void T_Upgrade_String::del_first_space_str()
{
    string ans_str = NULL_STR;
    for (int i(0); i<str.length(); i++)
    {
        if (str[i] == SPACE and i==0)
        {
            continue;
        }
        ans_str += str[i];
    }
    str = ans_str;
}
void T_Upgrade_String::del_space_two_and_more_str()
{
    string ans_str = NULL_STR;
    for (int i(0); i<str.length(); i++)
    {
        if (not(str[i] == SPACE and str[i+1] == SPACE))
        {
            ans_str += str[i];
        }
    }
    str = ans_str;
}
void T_Upgrade_String::del_word_str(string to_del)
{
    string ans_str = NULL_STR;
    bool need_to_write;
    int i = 0;
    while (i<str.length())
    {
        need_to_write = false;
        for (int j(0); j<to_del.length(); j++)
        {
            if (str[i+j] != to_del[j]) need_to_write = true;
        }
        if (!need_to_write) i+= to_del.length();
        if (i<str.length()) ans_str+=str[i];
        i++;
    }
    str = ans_str;
    T_Upgrade_String::del_space_two_and_more_str();
    del_first_space_str();

}
int T_Upgrade_String::search_repeat_str()
{
    int counter = 0;
    label:
    string word = NULL_STR;
    string word_repeat = NULL_STR;
    for (int i(0); i<str.length(); i++)
    {
        if (str[i] != SPACE) word += str[i];
        else
        {
            for (int j(i+1); j<str.length(); j++)
            {
                if (str[j] != SPACE and j!=str.length()-1)
                {
                    word_repeat += str[j];
                }
                else
                {
                    if (j == str.length()-1)
                    {
                        word_repeat += str[j];
                    }
                    if (word_repeat == word)
                    {
                        counter += 1;
                        del_word_str(word);
                        goto label; // с 83 на 66, используется для сброса настроек цикла фор
                    }
                    word_repeat = NULL_STR;
                }
            }
            word = NULL_STR;
        }
    }
    return counter;
}
int T_Upgrade_String::string_to_int()
{
    int num = 0;
    for (int i(0); i<str.length(); i++)
    {
        if ((str[i] < '0' or str[i] > '9') and str[i]!=SPACE)
        {
            cout << "Невозможно преобразовать в число, попробуйте воспользоваться методом" << endl;
            cout << "del_all_but_not_nums чтобы преобразовать строку в число";
            return -1;
        }
    }
    string back_up = str;
    del_space_str();
    for (int i(0); i<str.length(); i++)
    {
        num += (int(str[i])-int('0')) * pow(10, str.length()-i);
    }
    str = back_up;
    if (num < 0)
    {
        cout << "your number is too large" << endl;
        return 0;
    }
    return num/10;
}
int **T_Upgrade_String::string_to_arr()
{
    string back_up = str;
    del_space_two_and_more_str();
    del_first_space_str();
    if (string_to_int() == -1)
    {
        return nullptr;
    }
    int n = 1; int m = 0;
    int temp = 0;
    for (int i(0); i<str.length(); i++)
    {
        if (str[i] != SPACE)
        {
            temp += 1;
        }
        else
        {
            if (temp > m)
            {
                m = temp;
            }
            temp = 0;
            n += 1;
        }
    }
    if (m == 0)
    {
        cout << "data uncorrect for matrix N X M, maybde you have not any space in string" << endl;
        return 0;
    }
    int**arr = new int* [n];
    int stop_counter = 0;
    for (int i(0); i<n; i++)
    {
        arr[i] = new int [m];
    }
    for (int i(0); i < n; i++)
    {
        int counter = 0;
        for (int g(stop_counter); g<str.length(); g++)
        {
            if (str[g] != SPACE)
            {
                arr[i][counter] = int(str[g]) - int('0');
                counter+=1;
            }
            else
            {
                stop_counter = g+1;
                break;
            }
        }
        for (int j(counter); j<m; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i(0); i<n; i++)
    {
        for (int j(0); j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr;
}