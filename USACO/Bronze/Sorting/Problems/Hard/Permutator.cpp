#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];

    long long ans = 0;
    for(int i=0; i<n; i++)
        a[i] = a[i]*(n-i)*(i+1);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0; i<n; i++)
        ans += a[i]*b[n-i-1];
    
    cout << ans << endl;

    return 0;
}