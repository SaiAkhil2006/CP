#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];

    int ans = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            int no = j - i + 1;
            if(sum % no != 0)
                continue;
            int avg = sum / no;
            for(int k=i; k<=j; k++)
                if(avg == nums[k]){
                    ans++;
                    break;
                }
        }
    }

    cout << ans << endl;

    return 0;
}