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

    cout << "Тестирование наивного алгоритма поиска:" << endl;
    vector<int> naiveResult = naiveSearch(text, pattern);
    printResult(naiveResult);

    cout << "Тестирование алгоритма КМП:" << endl;
    vector<int> kmpResult = KMPSearch(text, pattern);
    printResult(kmpResult);

    return 0;
}