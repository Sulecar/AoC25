#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) return 1;

    vector<pair<uint64_t, uint64_t>> obmocja;
    vector<uint64_t> vrednosti;
    string vrstica;
    bool branje_obmocij = true;

    // 1. Branje podatkov
    while (getline(file, vrstica)) {
        if (vrstica.empty()) {
            branje_obmocij = false;
            continue;
        }

        if (branje_obmocij) {
            size_t ločilo = vrstica.find('-'); 
            uint64_t s = stoull(vrstica.substr(0, ločilo));
            uint64_t e = stoull(vrstica.substr(ločilo + 1));
            obmocja.push_back({s, e});
        } else {
            vrednosti.push_back(stoull(vrstica));
        }
    }

    // Del 1: Preverjanje prisotnosti vrednosti v območjih
    int del1 = 0;
    for (uint64_t v : vrednosti) {
        for (auto const& [start, end] : obmocja) {
            if (v >= start && v <= end) {
                del1++;
                break;
            }
        }
    }

    // Del 2: Izračun vseh unikatnih točk
    uint64_t del2 = 0;
    if (!obmocja.empty()) {
    
        sort(obmocja.begin(), obmocja.end());

        auto trenutno = obmocja[0];
        for (size_t i = 1; i < obmocja.size(); ++i) {
            // Če se naslednje območje prekriva s trenutnim
            if (obmocja[i].first <= trenutno.second + 1) {
                trenutno.second = max(trenutno.second, obmocja[i].second);
            } else {
                del2 += (trenutno.second - trenutno.first + 1);
                trenutno = obmocja[i];
            }
        }
        del2 += (trenutno.second - trenutno.first + 1);
    }

    cout << del1 << "\n" << del2 << endl;

    return 0;
}