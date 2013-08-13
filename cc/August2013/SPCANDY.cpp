#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

void solve(){    
    long long  n,k; cin>>n>>k;
    if(k==0) cout<<"0 "<<n<<endl;
    else cout<<n/k<<" "<<n%k<<endl;   
}

int  main ()
{
    long long  tc; cin>>tc;
    for (long long  i = 0; i < tc; i += 1){
        solve();
    }
    return 0;
}