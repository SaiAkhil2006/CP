#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    sort(nums.begin(), nums.end());

    int idx = 0, maxCount = -1;
    for(int idx = 0; idx < n-1; idx++){
        int count = 0;
        for(int i=idx+1; i<n; i++){
            if(nums[i] - nums[idx] <= k)
                count++;
            else
                break;
        }
        maxCount = max(maxCount, count);
    }

    cout << maxCount << endl;
    
    return 0;
}