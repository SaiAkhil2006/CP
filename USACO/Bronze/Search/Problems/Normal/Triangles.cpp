#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> p(n);

    unordered_map<int, int> minX, maxX, minY, maxY;

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;

        if (!minX.count(p[i].y)) {
            minX[p[i].y] = maxX[p[i].y] = p[i].x;
        } else {
            minX[p[i].y] = min(minX[p[i].y], p[i].x);
            maxX[p[i].y] = max(maxX[p[i].y], p[i].x);
        }

        if (!minY.count(p[i].x)) {
            minY[p[i].x] = maxY[p[i].x] = p[i].y;
        } else {
            minY[p[i].x] = min(minY[p[i].x], p[i].y);
            maxY[p[i].x] = max(maxY[p[i].x], p[i].y);
        }
    }

    long long ans = 0;

    for (auto &pt : p) {
        long long base = max(abs(pt.x - minX[pt.y]), abs(maxX[pt.y] - pt.x));
        long long height = max(abs(pt.y - minY[pt.x]), abs(maxY[pt.x] - pt.y));

        ans = max(ans, base * height);
    }

    cout << ans << "\n";
}