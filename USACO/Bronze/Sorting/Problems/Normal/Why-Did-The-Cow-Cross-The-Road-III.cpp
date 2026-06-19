#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for(int i=0; i<n; i++)
        cin >> cows[i].first >> cows[i].second;
    
    sort(cows.begin(), cows.end(), [](const pair<int, int> a, const pair<int, int> b){
        return a.first < b.first;
    });

    int time = cows[0].first + cows[0].second;

    for(int i=1; i<n; i++){
        time = max(time, cows[i].first);
        time += cows[i].second;
    }

    cout << time << endl;

    return 0;
}