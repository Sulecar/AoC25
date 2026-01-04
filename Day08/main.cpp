#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

struct Point {
    long long x, y, z;
};

struct Edge {
    int u, v;
    long long dist_sq;
    bool operator<(const Edge& other) const {
        return dist_sq < other.dist_sq;
    }
};

// Struktura za združevanje množic
struct UnionFind {
    vector<int> parent, size;
    int num_components;

    UnionFind(int n) : num_components(n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            num_components--;
            return true;
        }
        return false;
    }
};

int main() {
    ifstream input("input.txt");
    if (!input) return 1;

    vector<Point> points;
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        long long x, y, z;
        char c;
        if (ss >> x >> c >> y >> c >> z) points.push_back({x, y, z});
    }

    int n = points.size();
    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dx = points[i].x - points[j].x;
            long long dy = points[i].y - points[j].y;
            long long dz = points[i].z - points[j].z;
            edges.push_back({i, j, dx*dx + dy*dy + dz*dz});
        }
    }
    sort(edges.begin(), edges.end());

    // 1. del: Produkt velikosti 3 največjih vezij po 1000 povezavah
    UnionFind uf1(n);
    for (int i = 0; i < min((int)edges.size(), 1000); ++i) {
        uf1.unite(edges[i].u, edges[i].v);
    }

    vector<int> sizes;
    for (int i = 0; i < n; ++i) {
        if (uf1.parent[i] == i) sizes.push_back(uf1.size[i]);
    }
    sort(sizes.rbegin(), sizes.rend());
    
    if (sizes.size() >= 3) {
        cout << (long long)sizes[0] * sizes[1] * sizes[2] << endl;
    }

    // 2. del: Produkt X koordinat zadnje povezave, ki vse združi
    UnionFind uf2(n);
    for (const auto& e : edges) {
        if (uf2.unite(e.u, e.v)) {
            if (uf2.num_components == 1) {
                cout << points[e.u].x * points[e.v].x << endl;
                break;
            }
        }
    }

    return 0;
}