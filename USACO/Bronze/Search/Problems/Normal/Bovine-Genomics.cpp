#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> genomes(2*n, vector<char>(m));
    for(int i=0; i<2*n; i++)
        for(int j=0; j<m; j++)
            cin >> genomes[i][j];

    vector<set<char>> geneS(m), geneP(m);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            geneS[i].insert(genomes[j][i]);
        for(int j=n; j<2*n; j++)
            geneP[i].insert(genomes[j][i]);
    }
    
    int ans = 0;
    for(int i=0; i<m; i++){
        bool ok = true;
        for(char ch : geneS[i])
            if(geneP[i].count(ch) != 0)
                ok = false;
        if(ok)
            ans++;
    }

    cout << ans << endl;

    return 0;
}