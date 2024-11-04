#include <iostream>
#include <string>
using namespace std;

bool chk1100(const string &s, int pos) {
    return pos >= 0 && pos + 3 < s.size() && s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int q;
        cin >> s >> q;
        bool has1100 = false;
        for (int i = 0; i + 3 < s.size(); i++)
            if (chk1100(s, i)) {
                has1100 = true;
                break;
            }
        while (q--) {
            int i, v;
            cin >> i >> v;
            i--; 
            if (s[i] - '0' != v) {
                for (int j = i - 3; j <= i; j++) 
                    has1100 &= !chk1100(s, j);
                s[i] = v + '0';
                for (int j = i - 3; j <= i; j++) 
                    has1100 |= chk1100(s, j);
            }
            cout << (has1100 ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
