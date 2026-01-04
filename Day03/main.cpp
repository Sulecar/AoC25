#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

// Iskanje največjega 2-mestnega števila
int najvecja_2_mestna(const std::string& v) {
    int max_v = 0;
    for (size_t i = 0; i < v.length(); ++i) {
        for (size_t j = i + 1; j < v.length(); ++j) {
            int trenutna = (v[i] - '0') * 10 + (v[j] - '0');
            if (trenutna > max_v) max_v = trenutna;
        }
    }
    return max_v;
}


unsigned long long najvecja_12_mestna(const std::string& v) {
    if (v.length() < 12) return 0;
    
    unsigned long long rezultat = 0;
    int zac = 0;
    for (int i = 0; i < 12; ++i) {
        int konec = v.length() - (12 - 1 - i);
        char max_d = '0';
        int max_idx = zac;
        for (int j = zac; j < konec; ++j) {
            if (v[j] > max_d) {
                max_d = v[j];
                max_idx = j;
            }
        }

        rezultat = rezultat * 10 + (max_d - '0');
        zac = max_idx + 1;
    }
    return rezultat;
}

int main() {
    std::ifstream dat("input.txt");
    if (!dat.is_open()) return 1;

    std::string vrstica;
    long long vsota1 = 0;
    unsigned long long vsota2 = 0; 

    while (std::getline(dat, vrstica)) {
        if (vrstica.empty()) continue;
        
        // Prvi del: 2-mestna števila
        vsota1 += najvecja_2_mestna(vrstica);
        
        // Drugi del: 12-mestna števila
        vsota2 += najvecja_12_mestna(vrstica);
    }

    std::cout << vsota1 << std::endl;
    std::cout << vsota2 << std::endl;

    return 0;
}