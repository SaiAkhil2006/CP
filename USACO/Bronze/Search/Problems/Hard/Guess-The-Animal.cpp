#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<unordered_set<string>> animals(n);

    for (int i = 0; i < n; i++) {
        string name;
        int k;
        cin >> name >> k;

        for (int j = 0; j < k; j++) {
            string trait;
            cin >> trait;
            animals[i].insert(trait);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int common = 0;

            for (const auto &trait : animals[i]) {
                if (animals[j].count(trait))
                    common++;
            }

            ans = max(ans, common);
        }
    }

    cout << ans + 1 << '\n';
    return 0;
}