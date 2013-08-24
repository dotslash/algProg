#include <cstdio>
#include <cstring>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <map>

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

//code for BIT taken from http://www.stanford.edu/~liszt90/acm/notebook.html
#define LOGSZ 15
int tree[(1<<LOGSZ)+1];
int N;
// add v to value at x
void set(int x, int v) {
  while(x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}
// get cumulative sum up to and including x
int get(int x) {
  int res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}

/*actual and logic code starts here*/
struct triple {int end,start,ind;};
bool cmp(const triple t1,const triple t2){
   return t1.end<t2.end;
}


int array[1000000];
triple queries[1000000];
int answers[1000000];

int main (){
   int n; ni(n); N = (1<<(msb(n)+1));
   for (int i = 0; i < n; i += 1){
      ni(array[i]);
   }
   int q; ni(q);
   for (int i = 0; i < q; i += 1){
      ni(queries[i].start); ni(queries[i].end);
      queries[i].start--;
      queries[i].end--;
      queries[i].ind = i;
   }
   map<int,int> mp;
   map<int,int>::iterator pointer;
   sort(queries,queries+q,cmp);
   int pres_q = 0,prev;
   triple *t;
   for (int i = 0; i < n; i += 1){
      pointer = mp.find(array[i]);
      if(pointer!=mp.end()){
         prev = pointer->val2;
         set(n-prev,1);
      }
      mp[array[i]]=i;
      while( pres_q < q && queries[pres_q].end == i){
         t = &queries[pres_q];
         answers[t->ind] = (t->end - t->start + 1) - get(n- t->start); 
         pres_q++;
      }
   }
   for (int i = 0; i < q; i += 1){
      printf("%d\n",answers[i]);
   }
   return 0;
}

