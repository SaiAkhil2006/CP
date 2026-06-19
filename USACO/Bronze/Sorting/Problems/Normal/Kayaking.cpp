#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 1e9;

    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {

            vector<int> rem;

            for (int k = 0; k < 2 * n; k++) {
                if (k != i && k != j) {
                    rem.push_back(a[k]);
                }
            }

            int cost = 0;

            for (int k = 0; k < rem.size(); k += 2) {
                cost += rem[k + 1] - rem[k];
            }

            ans = min(ans, cost);
        }
    }

    cout << ans << '\n';

    return 0;
}