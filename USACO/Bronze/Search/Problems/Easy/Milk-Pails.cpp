#include<iostream>
using namespace std;

int main(){
    int x, y, m, ans = -1;
    cin >> x >> y >> m;

    for(int i=0; i*x<=m; i++)
        for(int j=0; i*x + j*y <= m; j++)
            ans = max(ans, i*x + j*y);

    cout << ans << endl;

    return 0;
}