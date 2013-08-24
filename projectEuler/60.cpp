#include <cstdio>
#include <cstring>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back
#define long long long
#define nl(x) scanf("%lld",&x)
#define ni(x) scanf("%d",&x)
#define pii pair<int,int>
#define val1 first
#define val2 second

#define msb(x) 31-__builtin_clz (x)
#define setbits(x) __builtin_popcount(x)

using namespace std;

#define MAX 100000000
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

bool check(int* p,int sz){
   for (int i = 0; i < sz; i += 1){
      for (int j = 0; j < i; j += 1){
         if(!conc(p[i],p[j])) return false;
      }
   }
   return true;
}
int presInd;
void next(int* p,int sz){
   for(int i=0;i<
}
int main (){
   fill(bm,bm+MAX,0);
   bm[0]=1; bm[1]=1;
   for (long i = 2; i < MAX; i += 1){
      if(bm[i]) continue;
      primes.pb(i);
      for (long j = i*i; j < MAX; j += i){
         bm[j]=1;
      }
   }
   int p[5]{2,3,5,7,11};
   
}
