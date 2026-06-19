#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> first(26, -1), second(26, -1);

    for (int i = 0; i < 52; i++) {
        int c = s[i] - 'A';
        if (first[c] == -1) first[c] = i;
        else second[c] = i;
    }

    int ans = 0;

    for (int cow = 0; cow < 26; cow++) {
        vector<int> freq(26, 0);

        for (int i = first[cow] + 1; i < second[cow]; i++) {
            freq[s[i] - 'A']++;
        }

        for (int other = 0; other < 26; other++) {
            if (freq[other] == 1)
                ans++;
        }
    }

    cout << ans / 2 << endl;
}