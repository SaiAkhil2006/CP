#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct Log{
    int day;
    string name;
    int change;
};

int main(){
    int n;
    cin >> n;
    vector<Log> logBook(n);
    for(int i=0; i<n; i++)
        cin >> logBook[i].day >> logBook[i].name >> logBook[i].change;

    sort(logBook.begin(), logBook.end(), [](const Log &a, const Log &b){
        return a.day < b.day;
    });

    map<string, int> cows;
    cows["Bessie"] = 7;
    cows["Elsie"] = 7;
    cows["Mildred"] = 7;

    string lb = "BEM";
    int changes = 0;

    for(int i=0; i<n; i++){
        cows[logBook[i].name] += logBook[i].change;
        int newLead = max(cows["Bessie"], max(cows["Elsie"], cows["Mildred"]));

        string nlb = "";

        for(auto it : cows)
            if(it.second == newLead)
                nlb += it.first[0];

        if(nlb != lb)
            changes++;

        lb = nlb;
    }

    cout << changes << endl;

    return 0;
}