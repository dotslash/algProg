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
#define pii pair<int,long> 
#define val1 first
#define val2 second
#define mp make_pair

#define msb(x) 31-__builtin_clz (x)
#define setbits(x) __builtin_popcount(x)

#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define MAX_ID 100000LL
#define INT_MAX 0x7f7f7f7f

using namespace std;
long arr[80][80];
int sz = 80;
pii get(int node){
   return mp(node,arr[node/sz][node%sz]);
}

long nodeCnt;
long distArr[MAX_ID+1];
vector<pii > neigh(long node){
   vector<pii > ret;
   long i = node/sz,j = node%sz;
   if(i>0) ret.pb(get(node -sz ));
   if(i<sz ) ret.pb(get(node+sz));
   if(j<sz) ret.pb(get(node+1));
   if(j>0) ret.pb(get(node-1));
   return ret;
}
long dijkstra(long source,long dest){
   set<long> pq;
   fill(distArr,distArr+nodeCnt,INT_MAX);
   pq.insert(source+ MAX_ID*0);
   distArr[source]=0;
   while(!pq.empty()){
      long node = *pq.begin();
      long dist = node/MAX_ID;
      node=node%MAX_ID;
      pq.erase(pq.begin()); 
      vector<pii > nb = neigh(node);
      if(node==dest) return dist;
      foreach(iter,nb){
         pii p = *iter;
         if(distArr[p.val1] > (dist+p.val2)){
            pq.insert((dist+p.val2)*MAX_ID +p.val1);
            distArr[p.val1]=dist+p.val2;
         }
      }
   }
   return INT_MAX;
}

int main (){
    nodeCnt=sz*sz;
    for (long i = 0; i < sz; i += 1){
       for (long j = 0; j < sz; j += 1){
          cin>>arr[i][j];
       }
    }
    for (long i = 0; i < sz; i += 1){
       for (long j = 0; j < sz; j += 1){
          cout<<arr[i][j]<<" ";
       }
       cout<<"\n";
    }
    cout<<dijkstra(0,sz*sz-1)<<endl;
    return 0;
}
