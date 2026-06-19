#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    int ans = INT_MIN;
    
    for(int i=0; i<n; i++){
        int total = 1;
        
        int curr = i;
        int r = 1;
        while(true){
            int next = curr;
            while(next+1 < n && nums[next+1] - nums[curr] <= r )
                next++;
            
            if(next == curr)
                break;

            total += next-curr;
            curr = next;
            r++;
        }

        curr = i;
        r = 1;
        while(true){
            int next = curr;
            while(next-1 >= 0 && nums[curr] - nums[next-1] <= r )
                next--;
            
            if(next == curr)
                break;

            total += curr - next;
            curr = next;
            r++;
        }

        ans = max(ans, total);
    }

    cout << ans << endl;

    return 0;
}
