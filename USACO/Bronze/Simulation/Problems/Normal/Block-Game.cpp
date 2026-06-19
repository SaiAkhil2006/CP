#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ans(26, 0);

    for(int i = 0; i < n; i++) {
        string up, down;
        cin >> up >> down;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for(char ch : up)
            cnt1[ch - 'a']++;

        for(char ch : down)
            cnt2[ch - 'a']++;

        for(int j = 0; j < 26; j++)
            ans[j] += max(cnt1[j], cnt2[j]);
    }

    for(int i = 0; i < 26; i++)
        cout << ans[i] << endl;

    return 0;
}