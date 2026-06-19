#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct Cow{
    char d;
    int x;
};

int main(){
    int n;
    cin >> n;
    vector<Cow> cows(n);
    for(int i=0; i<n; i++)
        cin >> cows[i].d >> cows[i].x;


    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        int liars = 0;
        for(int j=0; j<n; j++){
            if(cows[i].x > cows[j].x && cows[j].d == 'L')
                liars++;
            if(cows[i].x < cows[j].x && cows[j].d == 'G')
                liars++;
        }

        ans = min(ans, liars);
    }

    cout << ans << endl;

    return 0;
}