#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    long long bestRevenue = 0;
    long long bestTuition = 0;

    for(int i=0; i<n; i++){
        long long revenue = a[i] * (n - i);

        if(revenue > bestRevenue){
            bestRevenue = revenue;
            bestTuition = a[i];
        }
    }

    cout << bestRevenue << " " << bestTuition << '\n';
}