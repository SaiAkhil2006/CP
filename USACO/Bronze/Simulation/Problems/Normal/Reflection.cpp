#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, U;
    cin >> N >> U;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) 
        cin >> grid[i];

    int half = N / 2;

    vector<vector<int>> cnt(half, vector<int>(half, 0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == '#') {
                int gr = min(r, N - 1 - r);
                int gc = min(c, N - 1 - c);
                cnt[gr][gc]++;
            }
        }
    }

    long long answer = 0;

    for (int r = 0; r < half; r++) 
        for (int c = 0; c < half; c++) 
            answer += min(cnt[r][c], 4 - cnt[r][c]);

    cout << answer << endl;

    while (U--) {
        int r, c;
        cin >> r >> c;

        r--;
        c--;

        int gr = min(r, N - 1 - r);
        int gc = min(c, N - 1 - c);

        answer -= min(cnt[gr][gc], 4 - cnt[gr][gc]);

        if (grid[r][c] == '#') {
            grid[r][c] = '.';
            cnt[gr][gc]--;
        } else {
            grid[r][c] = '#';
            cnt[gr][gc]++;
        }

        answer += min(cnt[gr][gc], 4 - cnt[gr][gc]);

        cout << answer << endl;
    }

    return 0;
}