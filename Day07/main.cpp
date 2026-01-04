#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> manifold;
int R, C;

// Iskanje začetne točke 'S'
pair<int, int> find_start() {
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (manifold[r][c] == 'S') return {r, c};
    return {-1, -1};
}

// 1. DEL: Štetje unikatnih razcepov
int splits_count = 0;
vector<vector<bool>> visited_splitters;

void trace_beam(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;

    if (manifold[r][c] == '^') {
        if (visited_splitters[r][c]) return;
        visited_splitters[r][c] = true;
        splits_count++;
        trace_beam(r + 1, c - 1);
        trace_beam(r + 1, c + 1);
    } else {
        trace_beam(r + 1, c);
    }
}

// 2. DEL: Štetje vseh aktivnih časovnih linij
long long solve_part_two(int start_r, int start_c) {
    vector<vector<long long>> timelines(R, vector<long long>(C, 0));
    timelines[start_r][start_c] = 1;

    for (int r = start_r; r < R - 1; ++r) {
        for (int c = 0; c < C; ++c) {
            if (timelines[r][c] == 0) continue;

            if (manifold[r][c] == '^') {
                if (c - 1 >= 0) timelines[r + 1][c - 1] += timelines[r][c];
                if (c + 1 < C)  timelines[r + 1][c + 1] += timelines[r][c];
            } else {
                timelines[r + 1][c] += timelines[r][c];
            }
        }
    }

    long long total = 0;
    for (int c = 0; c < C; ++c) total += timelines[R - 1][c];
    return total;
}

int main() {
    ifstream file("input.txt");
    string line;
    while (getline(file, line)) if (!line.empty()) manifold.push_back(line);
    file.close();

    if (manifold.empty()) return 1;
    R = manifold.size();
    C = manifold[0].size();

    pair<int, int> start = find_start();
    
    // Izračun prvega dela
    visited_splitters.assign(R, vector<bool>(C, false));
    trace_beam(start.first, start.second);
    
    // Izračun drugega dela
    long long p2_result = solve_part_two(start.first, start.second);

    cout << "Skupno število razcepov (splits): " << splits_count << endl;
    cout << "Skupno število aktivnih časovnih linij (timelines): " << p2_result << endl;

    return 0;
}