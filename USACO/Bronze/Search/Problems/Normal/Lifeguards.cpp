#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calc(vector<pair<int,int>> &a) {
    sort(a.begin(), a.end());

    int total = 0;
    int l = a[0].first, r = a[0].second;

    for (int i = 1; i < a.size(); i++) {
        if (a[i].first > r) {
            total += (r - l);
            l = a[i].first;
            r = a[i].second;
        } else {
            r = max(r, a[i].second);
        }
    }
    total += (r - l);

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        vector<pair<int,int>> b;

        for (int j = 0; j < n; j++) 
            if (i != j) b.push_back(a[j]);

        ans = max(ans, calc(b));
    }

    cout << ans << endl;
}