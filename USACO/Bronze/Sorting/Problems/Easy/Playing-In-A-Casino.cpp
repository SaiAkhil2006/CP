#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> a(n, vector<long long>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        long long ans = 0;

        for (int col = 0; col < m; col++) {
            vector<long long> v;

            for (int row = 0; row < n; row++) {
                v.push_back(a[row][col]);
            }

            sort(v.begin(), v.end());

            long long pref = 0;

            for (int i = 0; i < n; i++) {
                ans += v[i] * i - pref;
                pref += v[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}