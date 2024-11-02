#include <iostream>
#include <algorithm>
using namespace std;

int func() {
    int lt = 0;
    int count = 0;

    cin >> lt;

    int arr[2 * lt];
    for (int i = 0; i < 2 * lt; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 2 * lt; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }

    int minlt = (count % 2 == 0) ? 0 : 1;
    int maxlt ;
    if (count<=lt) {
        maxlt = count;
    }
    else if(count>lt) {
        maxlt = 2*lt-count;
    }
    //if number smaller than n, then maximum is equal to number on switches
    //if number larger than n, then maximum is equal to n-(on-n) = 2n - on

    cout << minlt << " " << maxlt << endl;
    return 0;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        func();
    }

    return 0;
}
