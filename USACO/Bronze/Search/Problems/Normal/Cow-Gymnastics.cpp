#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    vector<vector<int>> rank(K, vector<int>(N));

    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            cin >> rank[i][j];

    int ans = 0;

    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {

            if (a == b) continue;

            bool consistent = true;

            for (int session = 0; session < K; session++) {

                int posA, posB;

                for (int p = 0; p < N; p++) {
                    if (rank[session][p] == a) posA = p;
                    if (rank[session][p] == b) posB = p;
                }

                if (posA > posB) {
                    consistent = false;
                    break;
                }
            }

            if (consistent) ans++;
        }
    }

    cout << ans << endl;
}