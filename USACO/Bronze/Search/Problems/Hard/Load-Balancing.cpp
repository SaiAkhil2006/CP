#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> cods(n);
    for(int i=0; i<n; i++)
        cin >> cods[i].first >> cods[i].second;
    
    int a, b;
    int ans = INT_MAX;

    for(int i=0; i<n; i++){
        a = cods[i].first+1;
        for(int j=0; j<n; j++){
            b = cods[j].second+1;
            int ne=0,nw=0,se=0,sw = 0;
            for(int k=0; k<n; k++){
                if(cods[k].first > a && cods[k].second > b) ne++;
                else if(cods[k].first < a && cods[k].second > b) nw++;
                else if(cods[k].first > a && cods[k].second < b) se++;
                else sw++;
            }

            int M = max(ne, max(nw, max(se, sw)));
            ans = min(ans, M);
        }
    }

    cout << ans << endl;

    return 0;
}