#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> limit(100);
    vector<int> speed(100);

    int pos = 0;

    for (int i = 0; i < N; i++) {
        int len, s;
        cin >> len >> s;

        for (int j = 0; j < len; j++) {
            limit[pos++] = s;
        }
    }

    pos = 0;

    // Bessie's speeds
    for (int i = 0; i < M; i++) {
        int len, s;
        cin >> len >> s;

        for (int j = 0; j < len; j++) {
            speed[pos++] = s;
        }
    }

    int ans = 0;

    for (int i = 0; i < 100; i++) {
        ans = max(ans, speed[i] - limit[i]);
    }

    cout << ans << endl;

    return 0;
}