#include <cstdio>
#include <cstring>
#include <cassert>
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
vector<int> pf[MAX];
long factsum[MAX];

long pow(long base,long exp){
   long ret =1;
   for(int i=0;i<exp;i++) ret*=base;
   return ret;
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
   printf("computed prime factors\n");
   bm[1]=-1; bm[0]=-1;
   for(int i=2;i<MAX;i++){
      bm[i]=-1;
      //if(i%1==0) printf("%d\n",i);
      int num=i;
      long ret=1,tmp;
      for(int j=0;j<pf[i].size() && num!=1;j++){
         tmp=pf[i][j];
         while(num%pf[i][j]==0) tmp=tmp*pf[i][j],num/=pf[i][j];
         tmp-=1;
         tmp=tmp/(pf[i][j]-1);
         ret=ret*tmp;
         if(ret> 1000000+i) { ret=-1; bm[i]=-2; break;}
      }
      factsum[i]=ret-i;     
   }
   printf("computed factor sums\n");
   int bc=-1,bv=-1;
   for (int i = 2; i < MAX; i += 1){
      int j=factsum[i];
      int c=1;
      bm[i]=i;
      while(j>i && j!=-1 && bm[j]!=i){
         bm[j]=i;
         j=factsum[j];
         c++;
      }
      if(j==i && bv<c) {
         bv=c;
         bc=i;
      }
   }
   printf("%d %d\n",bc,bv);
   
}
