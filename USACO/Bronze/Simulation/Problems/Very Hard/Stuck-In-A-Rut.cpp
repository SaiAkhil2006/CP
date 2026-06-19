#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Cow{
    char d;
    long long x, y;
};

struct Event{
    long long stopTime;
    int stopper;
    int stopped;
    long long needTime;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Cow> cows(n);
    for(int i=0; i<n; i++)
        cin >> cows[i].d >> cows[i].x >> cows[i].y;

    vector<Event> events;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cows[i].d != 'E' || cows[j].d != 'N')
                continue;

            long long ex = cows[i].x;
            long long ey = cows[i].y;
            long long nx = cows[j].x;
            long long ny = cows[j].y;

            long long dx = nx - ex;
            long long dy = ey - ny;

            if(ex >= nx || ny >= ey)
                continue;

            if(dx == dy)
                continue;

            if(dx > dy)
                events.push_back({dx, j, i, dy});
            else
                events.push_back({dy, i, j, dx});
        }
    }

    sort(events.begin(), events.end(), [](const Event &a, const Event &b){
        return a.stopTime < b.stopTime;
    });

    const long long INF = 1e18;
    vector<long long> stop(n, INF);

    for(auto e : events){
        if(stop[e.stopped] != INF)
            continue;
        if(stop[e.stopper] <= e.needTime)
            continue;

        stop[e.stopped] = e.stopTime;
    }

    for(int i=0; i<n; i++)
        if(stop[i] == INF)
            cout << "Infinity" << endl;
        else
            cout << stop[i] << endl;
    
    return 0;
}