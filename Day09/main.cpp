#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Struktura za shranjevanje koordinat točke
struct Koordinata {
    long long x; 
    long long y; 
};

long long izracunaj_najvecjo_povrsino() {
    const std::string ime_datoteke = "input.txt";
    std::ifstream datoteka(ime_datoteke);
    std::vector<Koordinata> koordinate;
    
    if (!datoteka.is_open()) {
        std::cerr << "Napaka: Ne morem odpreti datoteke '" << ime_datoteke << "'." << std::endl;
        return 0;
    }

    std::string vrstica;
    // Branje datoteke vrstico po vrstico
    while (std::getline(datoteka, vrstica)) {
        std::stringstream ss(vrstica);
        std::string x_str, y_str;
        
        // Ločevanje vrednosti glede na vejico
        if (std::getline(ss, x_str, ',') && std::getline(ss, y_str)) {
            try {
                koordinate.push_back({std::stoll(x_str), std::stoll(y_str)});
            } catch (...) {
                // Preskok neveljavnih vrstic
                continue;
            }
        }
    }

    if (koordinate.size() < 2) return 0;

    long long najvecja_povrsina = 0;

    // Iteracija skozi vse možne pare točk
    for (size_t i = 0; i < koordinate.size(); ++i) {
        for (size_t j = i + 1; j < koordinate.size(); ++j) {
            
            // Izračun širine in višine s korekcijo +1 (vključno z robnimi točkami)
            long long sirina = std::abs(koordinate[i].x - koordinate[j].x) + 1;
            long long visina = std::abs(koordinate[i].y - koordinate[j].y) + 1;
            
            long long trenutna_povrsina = sirina * visina;
            
            if (trenutna_povrsina > najvecja_povrsina) {
                najvecja_povrsina = trenutna_povrsina;
            }
        }
    }

    return najvecja_povrsina;
}

int main() {
    long long rezultat = izracunaj_najvecjo_povrsino();
    std::cout << "Najvecja povrsina pravokotnika je: " << rezultat << std::endl;
    return 0;
}