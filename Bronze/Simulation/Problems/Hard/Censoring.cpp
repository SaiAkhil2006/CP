#include<iostream>
using namespace std;

int main(){
    string s, t, fs = "";
    cin >> s >> t;

    for(char ch : s){
        fs += ch;

        if(fs.size() >= t.size())
            if(fs.substr(fs.size() - t.size()) == t)
                fs.erase(fs.size() - t.size());
    }

    cout << fs << endl;

    return 0;
}