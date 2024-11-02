#include <iostream>
using namespace std;

void toggle_element(int (*sw)[3], int i, int j) {
    if (sw[i][j] == 1) {
        sw[i][j] = 0;
    } else if (sw[i][j] == 0) {
        sw[i][j] = 1;
    }
}

void toggle_matrix(int sw[3][3], int i, int j) {
    // Toggle the main element at (i, j)
    toggle_element(sw, i, j);

    if (i - 1 >= 0) {
        toggle_element(sw, i - 1, j);
    }

    if (i + 1 < 3) {
        toggle_element(sw, i + 1, j);
    }

    if (j - 1 >= 0) {
        toggle_element(sw, i, j - 1);
    }

    if (j + 1 < 3) {
        toggle_element(sw, i, j + 1);
    }
}

int main() {

    int sw[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int in[3][3];


    for (int r = 0; r < 3; r++) {
        for (int q = 0; q < 3; q++) {
            cin >> in[r][q];
        }
    }

    // Traverse the array and do switching work
    for (int r = 0; r < 3; r++) {
        for (int q = 0; q < 3; q++) {
            while (in[r][q] != 0) {
                in[r][q]--;  // Decrease the value by 1
                toggle_matrix(sw, r, q);  // Toggle the surrounding elements
            }
        }
    }

    // spit out the result
    for (int r = 0; r < 3; r++) {
        for (int q = 0; q < 3; q++) {
            cout << sw[r][q];
        }
        cout << endl;
    }

    return 0;
}
