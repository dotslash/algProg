#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int primes[25];
int prod[100001][25]; 
int fact[101][25];
int n;

ll expon(ll base,ll pow, ll mod){
   ll pres=base,ret=1;
   while(pow){
      if( pow&1 == 1) ret = (ret*pres)%mod;
      pow=pow>>1;
      pres=(pres*pres)%mod;
   }
   return ret;
}
void solve(){    
    int l,r,mod; scanf("%d %d %d",&l,&r,&mod);
    l--; r--;
    ll ret =1;
    for (int i = 0; i < 25; i += 1){
       int pow = prod[r][i];
       if(l>0) pow = pow-prod[l-1][i];
       ret = ret*expon(primes[i],pow,mod);
       ret = ret%mod;
    }
    printf("%lld\n",ret);
}


void init(){
   int nums[100]; 
   memset(nums,0,400);
   memset(fact,0,10100);
   memset(prod,0,100001*100);
   
   int pres=0;
   for (int i = 2; i < 100; i += 1){
      if(nums[i]) continue;
      for (int j = i*i; j < 100; j += i){
         nums[j]=1;
      }
      primes[pres++]=i;
   }
   
   for (int i = 2; i < 101; i += 1){
      int tmp=i;
      while(tmp!=1){
         for (int j = 0; j < 25; j += 1){
            while(tmp%primes[j]==0){
               tmp=tmp/primes[j];
               fact[i][j]++;
            }
         }
      }
   }
   
   
   
   scanf("%d",&n);
   for (int i = 0; i < n; i += 1)
   {
      int a;
      scanf("%d",&a);
      for (int j = 0; j < 25; j += 1){
         prod[i][j]+=fact[a][j];
         prod[i+1][j]=prod[i][j];
      }
      
   }
}
int main ()
{   
    init();
    int tc; scanf("%d",&tc);
    
    for (int i = 0; i < tc; i += 1){
        solve();
    }
    return 0;
}