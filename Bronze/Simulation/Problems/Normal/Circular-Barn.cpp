#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> r(n);

    for (int i = 0; i < n; i++) 
        cin >> r[i];
    
    long long answer = 1e18;

    for (int start = 0; start < n; start++) {
        long long cost = 0;

        for (int room = 0; room < n; room++) {
            int dist = (room - start + n) % n;
            cost += 1LL * r[room] * dist;
        }

        answer = min(answer, cost);
    }

    cout << answer << endl;
}