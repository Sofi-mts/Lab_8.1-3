// Юніт-тест до лабораторної роботи № 8.1 (стандартні функції С для char[]), варіант 8
// Запуск: відкрити цей файл у VS Code і натиснути F5.

#define main lab_main          // беремо функції з лаби, але без її main()
#include "Lab_8.1(3).cpp"
#undef main

#include <string>

int passed = 0, failed = 0;

// перевірка: чи збігається отримане значення з очікуваним
#define CHECK_EQ(expected, actual)                                   \
    if ((expected) == (actual)) passed++;                            \
    else { failed++; cout << "FAIL line " << __LINE__ << endl; }

void TestContainsAllLetters() {
    CHECK_EQ(true,  ContainsAllLetters("hello world, i will"));    // всі букви є
    CHECK_EQ(false, ContainsAllLetters("hello"));    // немає "w" та "i"
}

void TestChange() {
    char str[100] = "do while(x) while";
    char* res = Change(str);
    CHECK_EQ(string("do **(x) **"), string(str));
    delete[] res;
}

int main() {
    TestContainsAllLetters();
    TestChange();

    cout << "Checks passed: " << passed << ", failed: " << failed << endl;
    cout << (failed == 0 ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << endl;
    system("pause");
    return failed == 0 ? 0 : 1;
}
