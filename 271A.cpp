#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

bool hasDistinctDigits(int year) {
    unordered_set<char> digits;
    stringstream ss;
    ss << year;
    string yearStr = ss.str();
    
    for (int i = 0; i < yearStr.size(); i++) {
        if (!digits.insert(yearStr[i]).second)
            return false;
    }
    return true;
}

int main() {
    int y;
    cin >> y;
    while (true) {
        y++;
        if (hasDistinctDigits(y)) {
            cout << y << endl;
            break;
        }
    }
    return 0;
}
