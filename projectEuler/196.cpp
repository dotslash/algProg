#include <cstdio>
#include <cstring>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define pb push_back
#define long long long
#define nl(x) scanf("%lld",&x)
#define ni(x) scanf("%d",&x)
#define pii pair<long,long>
#define val1 first
#define val2 second

#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)

#define msb(x) 31-__builtin_clz (x)
#define setbits(x) __builtin_popcount(x)

using namespace std;
#define prepCnt 5500000
long bm1[prepCnt];
vector<long> primes;
char bm2[5][8000000];
long start2[5];
vector<long> primes2;
void fillPrimeBM(char* bm,long* strt,long n){
   long end = n*(n+1)/2 + 1;
   long start = end - n;
   *strt = start;
   printf("%lld %lld %lld\n",start,end,end-start);
   for(long i=1;i<primes.size();i++){
      long inc = 2*primes[i];
      long st = start/primes[i];  if(st*primes[i]!=start) st++; 
      st = max((long)primes[i]*(long)primes[i],
               st*(long)primes[i]);
      
      if(st%2==0) st+=primes[i];
      for(long j = st;j<end; j+= inc){
         bm[j-start]=1;
      }
   }
   for (long i = start; i < end; i += 1){
      if(i%2==0) bm[i-start]=1;
   }
}
long number;
long check(long row,long col){
   if(number+row-2 <= col) return 0;
   if(col<0) return 0;
   return bm2[row][col]==0?1:0;
}

long countNeighPrimes(long row, long col){
   return (check(row-1,col-1)+ check(row+1,col-1)+
          check(row-1,col)+ check(row+1,col)+
          check(row-1,col+1)+ check(row+1,col+1)+
          check(row,col-1)+ check(row,col+1))*check(row,col);  
}



int main (){
   
   long n; nl(n);
   number=n;
   fill(bm1,bm1+prepCnt,0);
   fill(bm2[0],bm2[4]+8000000,0);
   
   for (long i = 2; i < prepCnt; i += 1){
      if(bm1[i]) continue;
      primes.pb(i);
      for (long j = i*i; j < prepCnt; j += i){
         bm1[j]=1;
      }
   }
   printf("%d primes less than prepCnt\n",primes.size());
   //primes
   
   fillPrimeBM(bm2[0],start2,n-2);
   fillPrimeBM(bm2[1],start2+1,n-1);
   fillPrimeBM(bm2[2],start2+2,n);
   fillPrimeBM(bm2[3],start2+3,n+1);
   fillPrimeBM(bm2[4],start2+4,n+2);  
   
   for(long i=0;i< n; i++){
      if(check(2,i)) primes2.pb(i);
   }
   long answer=0;
   for (long it = 0; it < primes2.size(); it += 1){
      long pr = primes2[it];
      for (long i = 0; i < 9; i += 1)
      {
         long a = 1+(i/3) ,b = pr+(i%3)-1;
         if(countNeighPrimes(a,b)>=2) {
            answer+=(primes2[it]+start2[2]);
            break;
         }
      }
   }
   printf("%lld\n",answer);
}
