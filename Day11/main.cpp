#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Funkcija za iskanje v globino
void findPaths(const string& current, map<string, vector<string>>& adj, set<string>& visited, long long& path_count) {
    // Če dosežemo cilj, povečamo števec poti
    if (current == "out") {
        path_count++;
        return;
    }

    // Preprečevanje ciklov v trenutni poti
    if (visited.count(current)) return;

    // Označimo vozlišče kot obiskano in raziščemo sosede
    visited.insert(current);
    for (const string& neighbor : adj[current]) {
        findPaths(neighbor, adj, visited, path_count);
    }

    visited.erase(current);
}

int main() {
    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Napaka pri branju datoteke input.txt!" << endl;
        return 1;
    }

    map<string, vector<string>> adj;
    string line;

    // Branje datoteke in gradnja grafa
    while (getline(infile, line)) {
        size_t colon_pos = line.find(':');
        if (colon_pos == string::npos) continue;

        string parent = line.substr(0, colon_pos);
        stringstream ss(line.substr(colon_pos + 1));
        string child;
        while (ss >> child) {
            adj[parent].push_back(child);
        }
    }

    long long path_count = 0;
    set<string> visited;
    
    // Začetek iskanja od točke "you"
    findPaths("you", adj, visited, path_count);

    cout << "Skupno stevilo poti: " << path_count << endl;

    return 0;
}