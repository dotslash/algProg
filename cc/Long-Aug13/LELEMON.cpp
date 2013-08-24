#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int route[10000];
long long cap[100][100];
int bottles[100];
int next[100];
bool cmp(int a,int b){
    return a>b;
}
void solve(){    
    int rooms,trips; cin>>rooms>>trips;
    for (int i = 0; i < trips; i += 1)
    {
        cin>>route[i];
    }
    for (int i = 0; i < rooms; i += 1)
    {
        int b; cin>>b;
        bottles[i]=b;
        for (int j = 0; j < b; j += 1)
        {
            cin>>cap[i][j];
        }
        sort(cap[i],cap[i]+b,cmp);
    }
    memset(next,0,400);
    long long answer=0;
    for (int i = 0; i < trips; i += 1)
    {
        int p=route[i];
        if(bottles[p]>next[p])
            answer+=cap[p][next[p]];
        
        next[p]++;
    }
    cout<<answer<<endl;
}

int main ()
{
    int tc; cin>>tc;
    for (int i = 0; i < tc; i += 1){
        solve();
    }
    return 0;
}