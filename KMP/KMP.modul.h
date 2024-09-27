//Сапожников Юрий ИВТ-22
#pragma once

#include<exception>
#include <iostream>
#include <vector>

using namespace std;

// Шаблонная функция наивного поиска подстроки
//Сложность: O((n - m + 1) * m), где n — длина текста, m — длина паттерна.
//Для каждого возможного сдвига строки проверяет, совпадает ли подстрока с текстом
template <typename T>
vector<int> naiveSearch(const T& text, const T& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();

    // Перебираем все возможные сдвиги в строке
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        // Проверяем, совпадает ли подстрока
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        // Если совпадает, запоминаем позицию
        if (j == m) {
            result.push_back(i);
        }
    }
    return result;
}

// abca       //     abca
// abcdabca   // abcdabca  
// Шаблонная функция для создания таблицы префиксов (функция префикса)
template <typename T>
vector<int> computePrefixFunction(const T& pattern) {
    int m = pattern.size();
    vector<int> prefix(m);
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        prefix[i] = j;
    }
    return prefix;
}

// Шаблонная функция поиска КМП
//Сложность: O(n + m)
//Использует таблицу префиксов для того, чтобы избежать лишних сравнений
template <typename T>
vector<int> KMPSearch(const T& text, const T& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();

    vector<int> prefix = computePrefixFunction(pattern);
    int j = 0;

    // Поиск по тексту
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            result.push_back(i - m + 1);
            j = prefix[j - 1];
        }
    }
    return result;
}

// Вспомогательная функция для вывода результата
void printResult(const vector<int>& result) {
    if (result.empty()) {
        cout << "Подстрока не найдена." << endl;
    }
    else {
        cout << "Подстрока найдена на позициях: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    }
}