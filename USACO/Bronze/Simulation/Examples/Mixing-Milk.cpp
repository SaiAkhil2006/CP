#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N = 3;
    vector<int> capacity(3), milk(3);
    for(int i=0; i<3; i++)
        cin >> capacity[i] >> milk[i];
    
    for(int i=0; i<100; i++){
        int b1 = i % N;
        int b2 = (i+1) % N;

        int amount = min(milk[b1], capacity[b2] - milk[b2]);
        milk[b1] -= amount;
        milk[b2] += amount;
    }

    for(int m : milk)
        cout << m << endl;

    return 0;
}