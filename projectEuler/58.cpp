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
   printf("hello\n");
   int n = 2;
   int tot=1,pr=0;
   while(1){
      int p1 = (2*n-1)*(2*n-1);
      int p2 = p1-2*(n-1);
      int p3 = p2-2*(n-1);
      int p4 = p3-2*(n-1);
      if(isprime(p2))pr++;
      if(isprime(p3))pr++;
      if(isprime(p4))pr++;
      tot+=4;
      if(tot==13) cout<<pr<<endl;
      if(tot> pr*10){
         cout<<2*n-1<<endl;
         return 0;
      }
      n++;
   }
   cout<<pr<<" "<<tot<<endl;
}
