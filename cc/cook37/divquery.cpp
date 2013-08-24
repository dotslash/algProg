#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>


#define pb push_back
#define long long long
#define ni(x) scanf("%lld",&x)
#define pii pair<long,long>
#define val1 first
#define val2 second

using namespace std;
map<long,long> mp;

long factors[100001][150];
long cnt[100001];
vector<int> v[100001];

int main (){
   long n,tc,x; ni(n); ni(tc);
   memset(cnt,0,400004);
   
   for (long i = 1; i <= 100000; i += 1){
      for (long j = i; j <= 100000; j += i){
         factors[j][cnt[j]++]=i;
      }
   }

   for (long i = 0; i < n; i += 1){
      ni(x);
      for (long j = 0; j < cnt[x]; j += 1){
         v[factors[x][j]].pb(i);
      }
   }
   long l,r,k,l1,r1;
   while(tc--){
      scanf("%lld %lld %lld",&l,&r,&k);
      l1=(upper_bound(v[k].begin(),v[k].end(),l-2) -v[k].begin());
      r1=(upper_bound(v[k].begin(),v[k].end(),r-1)-v[k].begin());
      
      printf("%lld\n",r1-l1);
   }            
}
