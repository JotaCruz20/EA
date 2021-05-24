#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <deque>
#include <numeric>

using namespace std;

vector<vector<tuple<int, int>>> adj;
vector<vector<vector<int>>> circuitoDis;
vector<vector<int>> scc;
vector<int> dfs, low;
vector<bool> onstack;
vector<int> set;
vector<int> rank1;
deque<int> S;
int longest = 0;
int sumSize = 0;
int maxSize = 0;
int counterCircuito = 0;
int t = 0;


void tarjan(int u) {
    dfs[u] = low[u] = t++;
    S.push_back(u);
    onstack[u] = true;
    for (auto x:adj[u]) {
        int i = get<0>(x);
        if (dfs[i] == -1) {
            tarjan(i);
            low[u] = min(low[u], low[i]);

        } else if (onstack[i]) {
            low[u] = min(low[u], dfs[i]);

        }
    }
    if (dfs[u] == low[u]) {
        vector<int> temp;
        vector<vector<int>> temp2;
        int v;
        do {
            v = S.back();
            S.pop_back();
            onstack[v] = false;
            for(int l:temp){
                for(auto tp:adj[v]){
                    if(get<0>(tp)==l){
                        temp2.push_back(vector<int>{v,l,get<1>(tp)});
                    }
                }
                for(auto tp:adj[l]){
                    if(get<0>(tp)==v){
                        temp2.push_back(vector<int>{l,v,get<1>(tp)});
                    }
                }
            }
            temp.push_back(v);
        } while (u != v);
        if(temp2.size()>0) {
            circuitoDis.push_back(temp2);
        }
        if (temp.size() > 1) {
            int x = temp.size();
            if (x > maxSize) {
                maxSize = temp.size();
            }
            scc.push_back(temp);
        }
    }
}


bool sortTuple(const vector<int> &a, const vector<int> &b) {
    return (a[2] < b[2]);
}


int find(int i) {
    if (set[i] != i) {
        set[i] = find(set[i]);
    }
    return set[i];
}


void union1(int a, int b) {
    a = find(a);
    b = find(b);
    if (rank1[a] > rank1[b]) {
        set[b] = a;
    } else {
        set[a] = b;
    }
    if (rank1[a] == rank1[b]) {
        rank1[b] += 1;
    }
}


void kruskalMST(vector<vector<int>> &pontos, int max) {
    set.resize(max);
    iota(set.begin(), set.end(), 0);
    rank1.resize(max, 0);
    int sum = 0;
    sort(pontos.begin(), pontos.end(), sortTuple);
    for (auto x:pontos) {
        int u = x[0];
        int v = x[1];
        if (find(u) != find(v)) {
            union1(u, v);
            sumSize += x[2];
            sum += x[2];
        }
    }
    if (sum > longest) {
        longest = sum;
    }
}


int main() {
    int n, n_POI, m_connections, questions, POI_A, POI_B, distance;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> n_POI;
        cin >> m_connections;
        cin >> questions;
        adj.resize(n_POI);
        low.resize(n_POI);
        dfs.resize(n_POI, -1);
        onstack.resize(n_POI);
        for (int j = 0; j < m_connections; ++j) {
            cin >> POI_A;
            cin >> POI_B;
            cin >> distance;
            adj[POI_A - 1].push_back(make_tuple(POI_B - 1, distance));
        }
        for (int k = 0; k < n_POI; ++k) {
            if (dfs[k] == -1) {
                tarjan(k);
            }
        }
        low.clear();
        dfs.clear();
        onstack.clear();
        adj.clear();
        S.clear();
        if (questions >= 3) {
            int size = scc.size();
            for (int j = 0; j < size; j++) {
                kruskalMST(circuitoDis[j], n_POI);
                set.clear();
                rank1.clear();
            }
            if (questions == 3) {
                cout << scc.size() << " " << maxSize << " " << longest << endl;
            } else {
                cout << scc.size() << " " << maxSize << " " << longest << " " << sumSize << endl;
            }
        } else {
            if (questions == 1) {
                cout << scc.size() << endl;
            } else if (questions == 2) {
                cout << scc.size() << " " << maxSize << endl;
            }
        }
        circuitoDis.clear();
        scc.clear();
        maxSize = 0;
        longest = 0;
        sumSize = 0;
        t = 0;
        counterCircuito = 0;
    }

}