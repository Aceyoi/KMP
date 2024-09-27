//���������� ���� ���-22
#pragma once

#include<exception>
#include <iostream>
#include <vector>

using namespace std;

// ��������� ������� �������� ������ ���������
//���������: O((n - m + 1) * m), ��� n � ����� ������, m � ����� ��������.
//��� ������� ���������� ������ ������ ���������, ��������� �� ��������� � �������
template <typename T>
vector<int> naiveSearch(const T& text, const T& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();

    // ���������� ��� ��������� ������ � ������
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        // ���������, ��������� �� ���������
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        // ���� ���������, ���������� �������
        if (j == m) {
            result.push_back(i);
        }
    }
    return result;
}

// abca       //     abca
// abcdabca   // abcdabca  
// ��������� ������� ��� �������� ������� ��������� (������� ��������)
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

// ��������� ������� ������ ���
//���������: O(n + m)
//���������� ������� ��������� ��� ����, ����� �������� ������ ���������
template <typename T>
vector<int> KMPSearch(const T& text, const T& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();

    vector<int> prefix = computePrefixFunction(pattern);
    int j = 0;

    // ����� �� ������
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

// ��������������� ������� ��� ������ ����������
void printResult(const vector<int>& result) {
    if (result.empty()) {
        cout << "��������� �� �������." << endl;
    }
    else {
        cout << "��������� ������� �� ��������: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    }
}