#include <cstdio>
#include <cstring>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back

#define double long double
#define long long long
#define nl(x) scanf("%lld",&x)
#define ni(x) scanf("%d",&x)
#define pii pair<int,int>
#define val1 first
#define val2 second

#define msb(x) 31-__builtin_clz (x)
#define setbits(x) __builtin_popcount(x)

using namespace std;

#define MAX 1000001
int bm[MAX]; 
vector<int>primes;
bool isprime(int num){
   if(num<MAX) return bm[num]==0;
   int pres = 0;
   int limit = sqrt(num)+1;
   while(primes[pres]<limit){
      if(num%primes[pres]==0) return false;
      pres++;
   }
   return true;
}
vector<int> pf[10000000];
long tot[10000000];
int d2[10];
int d1[10]; 
bool check(int num1,int num2){
   fill(d1,d1+10,0);
   fill(d2,d2+10,0);
   while(num1){
      d1[num1%10]++;
      num1/=10;
   }
   while(num2){
      d2[num2%10]++;
      num2/=10;
   }
   for(int i=0;i<10;i++) if(d1[i]!=d2[i]) return false;
   return true;
}
int main (){
   fill(bm,bm+MAX,0);
   bm[0]=1; bm[1]=1;
   int cnt=0;
   for (long i = 2; i < MAX; i += 1){
      if(bm[i]) continue;
      primes.pb(i);
      pf[i].pb(i);
      for (long j = i+i; j < MAX; j += i){
         bm[j]=1;
         pf[j].pb(i);
      }
   }
   tot[0]=0;tot[1]=0;
   for (int i = 2; i < MAX; i += 1){
      tot[i]=i;
      for (int j = 0; j < pf[i].size(); j += 1){
         tot[i]= (tot[i]/pf[i][j])*(pf[i][j]-1);
      }
   }
   long res=0;
   for(int i=0;i<MAX;i++) res+=tot[i];
   printf("%lld\n",res);
}
