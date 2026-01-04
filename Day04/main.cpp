#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Funkcija prešteje sosednje zvitke ('@') okoli določene celice
int prestej_sosede(const vector<string>& mreza, int r, int c) {
    int rows = mreza.size();
    int cols = mreza[0].size();
    int sosedje = 0;

    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (mreza[nr][nc] == '@') sosedje++;
            }
        }
    }
    return sosedje;
}

int main() {
    ifstream f("input.txt");
    vector<string> mreza;
    string vrstica;

    while (getline(f, vrstica)) {
        if (!vrstica.empty()) mreza.push_back(vrstica);
    }
    f.close();

    if (mreza.empty()) return 0;

    // Prvi del: Preštejemo dostopne zvitke v začetnem stanju
    int prvi_del = 0;
    for (int r = 0; r < mreza.size(); ++r) {
        for (int c = 0; c < mreza[0].size(); ++c) {
            if (mreza[r][c] == '@' && prestej_sosede(mreza, r, c) < 4) {
                prvi_del++;
            }
        }
    }

    // Drugi del: Ponavljajoče odstranjevanje zvitkov
    vector<string> delovna_mreza = mreza;
    int skupno_odstranjenih = 0;
    while (true) {
        vector<pair<int, int>> za_odstranit;
        for (int r = 0; r < delovna_mreza.size(); ++r) {
            for (int c = 0; c < delovna_mreza[0].size(); ++c) {
                if (delovna_mreza[r][c] == '@' && prestej_sosede(delovna_mreza, r, c) < 4) {
                    za_odstranit.push_back({r, c});
                }
            }
        }

        if (za_odstranit.empty()) break;

        for (auto p : za_odstranit) {
            delovna_mreza[p.first][p.second] = '.';
        }
        skupno_odstranjenih += za_odstranit.size();
    }

    cout << "Število dostopnih zvitkov (1. del): " << prvi_del << endl;
    cout << "Skupno število odstranjenih zvitkov (2. del): " << skupno_odstranjenih << endl;

    return 0;
}