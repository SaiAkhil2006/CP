#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<string> board(3);

    for(int i = 0; i < 3; i++)
        cin >> board[i];

    set<char> individual;
    set<pair<char,char>> teams;

    vector<vector<char>> lines;

    for(int i = 0; i < 3; i++)
        lines.push_back({board[i][0],board[i][1],board[i][2]});

    for(int j = 0; j < 3; j++)
        lines.push_back({board[0][j],board[1][j],board[2][j]});

    lines.push_back({board[0][0],board[1][1],board[2][2]});
    lines.push_back({board[0][2],board[1][1],board[2][0]});

    for(auto &line : lines) {
        set<char> s(line.begin(), line.end());

        if(s.size() == 1) 
            individual.insert(*s.begin());
        else if(s.size() == 2) {
            auto it = s.begin();

            char a = *it;
            ++it;
            char b = *it;

            teams.insert({a,b});
        }
    }

    cout << individual.size() << endl;
    cout << teams.size() << endl;

    return 0;
}