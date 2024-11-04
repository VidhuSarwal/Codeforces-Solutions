#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct B {
    int b;
    int c;
};

bool cmp(const int &a, const int &b) {
    return a > b;
}

long long f(int n, int k, B bottles[]) {
    map<int, vector<int>> bb;

    for (int i = 0; i < k; i++) {
        bb[bottles[i].b].push_back(bottles[i].c);
    }

    vector<int> me;
    for (auto &e : bb) {
        sort(e.second.begin(), e.second.end(), cmp);
        int s = 0;
        for (int c : e.second) {
            s += c;
        }
        me.push_back(s);
    }

    sort(me.begin(), me.end(), cmp);

    long long maxE = 0;
    for (int i = 0; i < min(n, (int)me.size()); i++) {
        maxE += me[i];
    }

    return maxE;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        B bottles[200001];
        
        for (int i = 0; i < k; i++) {
            cin >> bottles[i].b >> bottles[i].c;
        }

        cout << f(n, k, bottles) << endl;
    }

    return 0;
}
