#include<iostream>
#include<vector>
using namespace std;

class Shell{
public:
    int a, b, g;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Shell> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i].a >> nums[i].b >> nums[i].g;

    int maxScore = -1;
    
    for(int s=1; s<=3; s++){
        int pos = s;
        int score = 0;
        for(int i=0; i<n; i++){
            if(pos == nums[i].a)
                pos = nums[i].b;
            else if(pos == nums[i].b)
                pos = nums[i].a;
            
            if(nums[i].g == pos)
                score += 1;
        }

        maxScore = max(score, maxScore);
    }

    cout << maxScore << endl;

    return 0;
}