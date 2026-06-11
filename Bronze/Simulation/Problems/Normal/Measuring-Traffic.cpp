#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Segment {
    string type;
    int low, high;
};

int main() {
    int N;
    cin >> N;

    vector<Segment> seg(N);

    for (int i = 0; i < N; i++) 
        cin >> seg[i].type >> seg[i].low >> seg[i].high;
    

    int low = 0;
    int high = 1000000;

    for (int i = N - 1; i >= 0; i--) {

        if (seg[i].type == "none") {
            low = max(low, seg[i].low);
            high = min(high, seg[i].high);
        }

        else if (seg[i].type == "on") {
            low -= seg[i].high;
            high -= seg[i].low;

            low = max(low, 0);
        }

        else { 
            low += seg[i].low;
            high += seg[i].high;
        }
    }

    cout << low << " " << high << "\n";

    low = 0;
    high = 1000000;

    for (int i = 0; i < N; i++) {

        if (seg[i].type == "none") {
            low = max(low, seg[i].low);
            high = min(high, seg[i].high);
        }

        else if (seg[i].type == "on") {
            low += seg[i].low;
            high += seg[i].high;
        }

        else {
            low -= seg[i].high;
            high -= seg[i].low;

            low = max(low, 0);
        }
    }

    cout << low << " " << high << endl;
}