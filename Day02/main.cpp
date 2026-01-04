#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funkcija preveri, če se niz 's' sestavi s ponavljanjem vzorca dolžine 'd'
bool sePonavlja(string s, int d) {
    if (s.length() % d != 0) return false;
    string vzorec = s.substr(0, d);
    for (size_t i = d; i < s.length(); i += d) {
        if (s.substr(i, d) != vzorec) return false;
    }
    return true;
}

int main() {
    ifstream datoteka("input.txt");
    string segment;
    long long suma1 = 0, suma2 = 0;

    // Beremo dele datoteke, ločene z vejico
    while (getline(datoteka, segment, ',')) {
        size_t crtica = segment.find('-');
        if (crtica == string::npos) continue;

        long long spodnja = stoll(segment.substr(0, crtica));
        long long zgornja = stoll(segment.substr(crtica + 1));

        for (long long i = spodnja; i <= zgornja; ++i) {
            string s = to_string(i);
            int n = s.length();

            // Pogoj 1: Točno dve polovici
            if (n > 1 && n % 2 == 0 && s.substr(0, n/2) == s.substr(n/2)) {
                suma1 += i;
            }

            // Pogoj 2: Poljubno ponavljanje
            for (int d = 1; d <= n / 2; ++d) {
                if (sePonavlja(s, d)) {
                    suma2 += i;
                    break;
                }
            }
        }
    }

    cout << suma1 << "\n" << suma2 << endl;
    return 0;
}