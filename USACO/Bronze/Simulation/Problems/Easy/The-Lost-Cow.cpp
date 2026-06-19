#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    long long cur = x;
    long long dist = 1;
    long long total = 0;

    while (true) {
        long long target;

        if (dist > 0)
            target = x + dist;
        else
            target = x + dist;

        if ((cur <= y && y <= target) ||
            (target <= y && y <= cur)) {

            total += abs(y - cur);
            break;
        }

        total += abs(target - cur);
        cur = target;

        dist *= -2;
    }

    cout << total << endl;
    return 0;
}