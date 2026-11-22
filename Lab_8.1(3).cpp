// Lab_8.1(3).cpp
// Лабораторна робота № 8.1. Пошук та заміна символів у літерному рядку.
// Варіант 8. Використання стандартних функцій мови С для рядків char[].
// Виконала: Кучер Софія.
//
// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Вияснити, чи є серед цих символів всі букви, що входять в слово "while".
// 2. Замінити кожну групу букв "while" парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// чи входять до рядка s всі букви слова "while"
bool ContainsAllLetters(const char* s)
{
    const char letters[] = "while";

    for (size_t j = 0; j < strlen(letters); j++)
        if (strchr(s, letters[j]) == NULL)   // strchr – пошук символу в рядку
            return false;
    return true;
}

// замінює кожну групу букв "while" парою зірочок "**";
// змінений рядок записується в параметр s і повертається як результат
char* Change(char* s)
{
    char* tmp = new char[strlen(s) + 1];
    *tmp = '\0';

    char* start = s;                         // start = початок ще не опрацьованої частини
    char* p;                                 // p     = вказівник на знайдене "while"

    while ((p = strstr(start, "while")) != NULL)
    {
        strncat(tmp, start, p - start);      // символи перед "while"
        strcat(tmp, "**");                   // заміна
        start = p + strlen("while");         // продовжуємо після "while"
    }
    strcat(tmp, start);                      // залишок рядка

    strcpy(s, tmp);

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (ContainsAllLetters(str))
        cout << "String contains all letters of \"while\"" << endl;
    else
        cout << "String does not contain all letters of \"while\"" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    system("pause");    // щоб вікно не закривалося одразу
    return 0;
}
