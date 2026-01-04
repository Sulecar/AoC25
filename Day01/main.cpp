#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Napaka pri odpiranju datoteke!" << endl;
        return 1;
    }

    // Začetni pogoji za oba dela
    int pozicija1 = 50; 
    int pozicija2 = 50;
    
    int geslo1 = 0; // Šteje samo postanke na koncu rotacije
    int geslo2 = 0; // Šteje vsak klik na številko 0

    string vrstica;
    while (getline(file, vrstica)) {
        if (vrstica.empty()) continue;

        char smer = vrstica[0];
        int koraki = stoi(vrstica.substr(1));

        // SIMULACIJA PREMIKA (korak po koraku)
        for (int i = 0; i < koraki; i++) {
            if (smer == 'R') {
                pozicija2++;
                if (pozicija2 == 100) pozicija2 = 0;
            } else {
                pozicija2--;
                if (pozicija2 == -1) pozicija2 = 99;
            }

            // DRUGI DEL: Preverimo ob VSAKEM kliku
            if (pozicija2 == 0) {
                geslo2++;
            }
        }

        // PRVI DEL: Preverimo samo, ko se celotna rotacija konča
        if (smer == 'R') {
            pozicija1 = (pozicija1 + koraki) % 100;
        } else {
            pozicija1 = (pozicija1 - (koraki % 100) + 100) % 100;
        }

        if (pozicija1 == 0) {
            geslo1++;
        }
    }

    file.close();

    cout << "Geslo za 1. del: " << geslo1 << endl;
    cout << "Geslo za 2. del: " << geslo2 << endl;

    return 0;
}