#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

void solve(){    
    double def,mins,offers;
    cin>>def>>mins>>offers;
    int pres=0; 
    double pBest=mins*def;
    for (int i = 1; i <= offers; i += 1)
    {
        double val,rate,add;
        cin>>val>>rate>>add;
        double cost = add/val + rate*mins;
        if(cost<pBest){
            pBest=cost;
            pres=i;
        }
    }
    cout<<pres<<endl;
}

int main ()
{
    int tc; cin>>tc;
    for (int i = 0; i < tc; i += 1){
        solve();
    }
    return 0;
}