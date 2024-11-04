#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        int melody[50];
        for (int i = 0; i < n; i++) {
            cin >> melody[i];
        }

        bool isPerfect = true;

        for (int i = 1; i < n; i++) {
            int interval = abs(melody[i] - melody[i - 1]);
            if (interval != 5 && interval != 7) {
                isPerfect = false;
                break;
            }
        }

        if (isPerfect) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
