#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> a[i];

    vector<int> cows(N + 1);

    for (int i = 1; i <= N; i++) 
        cin >> cows[i];
    

    for (int t = 0; t < 3; t++) {
        vector<int> prev(N + 1);

        for (int i = 1; i <= N; i++) 
            prev[i] = cows[a[i]];
        
        cows = prev;
    }

    for (int i = 1; i <= N; i++) 
        cout << cows[i] << endl;
    
    return 0;
}