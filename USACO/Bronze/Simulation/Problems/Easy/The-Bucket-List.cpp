#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> buckets(1001, 0);

    for(int i = 0; i < N; i++) {
        int s, t, b;
        cin >> s >> t >> b;

        for(int time = s; time <= t; time++)
            buckets[time] += b;
    }

    int ans = 0;

    for(int x : buckets) 
        ans = max(ans, x);

    cout << ans << endl;

    return 0;
}