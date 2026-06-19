#include<iostream>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    set<int> nums;
    for(int i=0; i<n; i++){
        cin >> x;
        nums.insert(x);
    }

    cout << nums.size() << endl;

    return 0;
}