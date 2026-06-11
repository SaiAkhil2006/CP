#include <iostream>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        string enlarged = "";

        for(char c : s) {
            for(int j = 0; j < k; j++)
                enlarged += c;
        }

        for(int j = 0; j < k; j++)
            cout << enlarged << endl;
    }

    return 0;
}