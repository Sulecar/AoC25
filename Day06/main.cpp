#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


long long solve_op(const vector<long long>& numbers, char op) {
    if (numbers.empty()) return 0;
    long long res = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (op == '+') res += numbers[i];
        else if (op == '*') res *= numbers[i];
    }
    return res;
}

int main() {
    ifstream file("input.txt");
    if (!file) return 1;

    vector<string> lines;
    string line;
    size_t width = 0;
    while (getline(file, line)) {
        lines.push_back(line);
        width = max(width, line.length());
    }
    if (lines.size() < 2) return 0;

    long long total1 = 0, total2 = 0;
    size_t col = 0;

    while (col < width) {
        // Preskoči prazne stolpce med problemi
        bool empty_col = true;
        for (const auto& l : lines) {
            if (col < l.length() && l[col] != ' ') { empty_col = false; break; }
        }
        if (empty_col) { col++; continue; }

        // Določi meje trenutnega problema
        size_t start = col;
        while (col < width) {
            bool current_empty = true;
            for (const auto& l : lines) {
                if (col < l.length() && l[col] != ' ') { current_empty = false; break; }
            }
            if (current_empty) break;
            col++;
        }
        size_t end = col;

        // Poišči operacijo v zadnji vrstici
        char op = '\0';
        for (size_t c = start; c < end && c < lines.back().length(); ++c) {
            if (lines.back()[c] == '+' || lines.back()[c] == '*') {
                op = lines.back()[c];
                break;
            }
        }

        // Ekstrakcija števil za oba dela
        vector<long long> nums1, nums2;
        for (size_t r = 0; r < lines.size() - 1; ++r) {
            string s1 = "";
            for (size_t c = start; c < end && c < lines[r].length(); ++c) {
                if (lines[r][c] != ' ') s1 += lines[r][c];
            }
            if (!s1.empty()) nums1.push_back(stoll(s1));
        }

        for (size_t c = start; c < end; ++c) {
            string s2 = "";
            for (size_t r = 0; r < lines.size() - 1; ++r) {
                if (c < lines[r].length() && isdigit(lines[r][c])) s2 += lines[r][c];
            }
            if (!s2.empty()) nums2.push_back(stoll(s2));
        }

        if (op != '\0') {
            total1 += solve_op(nums1, op);
            total2 += solve_op(nums2, op);
        }
    }

    cout << "Rezultat 1. dela: " << total1 << endl;
    cout << "Rezultat 2. dela: " << total2 << endl;

    return 0;
}