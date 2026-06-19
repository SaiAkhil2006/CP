#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum == 0) {
            cout << 0 << '\n';
            continue;
        }

        int ans = n - 1;

        for (int target = 1; target <= sum; target++) {
            if (sum % target) continue;

            int cur = 0;
            int segments = 0;
            bool ok = true;

            for (int x : a) {
                cur += x;

                if (cur == target) {
                    segments++;
                    cur = 0;
                } else if (cur > target) {
                    ok = false;
                    break;
                }
            }

            if (ok && cur == 0) {
                ans = min(ans, n - segments);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}