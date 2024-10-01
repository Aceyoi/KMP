//Сапожников Юрий ИВТ-22
#include <iostream>
#include <cassert>
#include<exception>
#include <vector>
#include "KMP.modul.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    string text = "ababcabcabababd";
    string pattern = "ababd";

    // Тест наивного алгоритма поиска
    vector<int> naiveResult = naiveSearch(text, pattern);
    assert(naiveResult.size() == 1);  // Должен найти одно вхождение
    assert(naiveResult[0] == 10);     // Подстрока начинается с индекса 10

    // Тест алгоритма КМП
    vector<int> kmpResult = KMPSearch(text, pattern);
    assert(kmpResult.size() == 1);  // Должен найти одно вхождение
    assert(kmpResult[0] == 10);     // Подстрока начинается с индекса 10

    // Дополнительные тесты
    string text2 = "aaaaa";
    string pattern2 = "aa";

    vector<int> naiveResult2 = naiveSearch(text2, pattern2);
    assert(naiveResult2.size() == 4);  // Должен найти 4 вхождения: 0, 1, 2, 3
    assert(naiveResult2[0] == 0);
    assert(naiveResult2[1] == 1);
    assert(naiveResult2[2] == 2);
    assert(naiveResult2[3] == 3);

    vector<int> kmpResult2 = KMPSearch(text2, pattern2);
    assert(kmpResult2.size() == 4);  // Должен найти 4 вхождения: 0, 1, 2, 3
    assert(kmpResult2[0] == 0);
    assert(kmpResult2[1] == 1);
    assert(kmpResult2[2] == 2);
    assert(kmpResult2[3] == 3);

    // Тесты с отсутствием подстроки
    string text3 = "abcdefg";
    string pattern3 = "xyz";

    vector<int> naiveResult3 = naiveSearch(text3, pattern3);
    assert(naiveResult3.empty());  // Не должно быть вхождений

    vector<int> kmpResult3 = KMPSearch(text3, pattern3);
    assert(kmpResult3.empty());    // Не должно быть вхождений

    cout << "Все тесты пройдены успешно!" << endl;

    return 0;
}