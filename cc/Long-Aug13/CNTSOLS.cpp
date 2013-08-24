#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long

ll power(ll base,ll exp, ll rem){
    //if(base==0) return 0;
    ll ret=1;
    ll pres=base;
    while(exp){
        if(exp%2==1)ret=(ret*pres)%rem;
        exp=exp/2;
        pres=(pres*pres)%rem;
    }    
    //cout<<"power:"<<base<<" "<<ret<<" "<<rem<<" "<<endl;
    return ret;
}

ll n_pow_d[100];
void solve(){    
    ll upper, d, m, N;
    cin>>upper>>d>>m>>N;
    for (ll i = 0; i < N; i += 1){
        n_pow_d[i]=power(i,d,N);
        //cout<<n_pow_d[i]<<" ";
    }
    //cout<<"\n";
    ll retval=0;
    ll t = min(N,upper+1);
    for (ll n1 = 0; n1 < t; n1 += 1){
        for (ll n2 = 0; n2 < t; n2 += 1){
            for (ll n3 = 0; n3 < t; n3 += 1){
                ll sum = n_pow_d[n1] +n_pow_d[n2] +n_pow_d[n3];
                if(sum%N==m){
                    ll mult = 1;
                    mult = (mult*((upper-n1)/N + 1))%1000000007;
                    mult = (mult*((upper-n2)/N + 1))%1000000007;
                    mult = (mult*((upper-n3)/N + 1))%1000000007;
                    retval = (retval+mult)%1000000007;
                    
                }
            }
        }
    }
    
    cout<<retval<<endl;
}

int main ()
{
    ll tc; cin>>tc;
    for (ll i = 0; i < tc; i += 1){
        solve();
    }
    return 0;
}
