#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<pair<int,int>, int> lastVisit;

    int x = 0;
    int y = 0;
    int time = 0;

    lastVisit[{0,0}] = 0;

    int answer = 1e9;

    for(int i = 0; i < N; i++) {
        char dir;
        int steps;

        cin >> dir >> steps;

        for(int j = 0; j < steps; j++) {
            if(dir == 'N') y++;
            else if(dir == 'S') y--;
            else if(dir == 'E') x++;
            else x--;

            time++;
            pair<int,int> pos = {x,y};
            if(lastVisit.count(pos)) 
                answer = min(answer,time - lastVisit[pos]);

            lastVisit[pos] = time;
        }
    }

    if(answer == 1e9)
        cout << -1 << endl;
    else
        cout << answer << endl;

    return 0;
}