#include <cstdio>
#include <cassert>
#include <cstring>
#include <climits>
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
//segtree code taken from http://letuskode.blogspot.in/2013/01/segtrees.html
//segtree code begins
//merge,fields pf node,createleaf functions should be modified based on the scenario
int n;
struct node{
   int val1,val2;
   void split(node& l, node& r){}
   void merge(node& a, node& b)
   {
      if(max(a.val1,a.val2) <= min(b.val1,b.val2)){
         val1 = b.val1;
         val2 = b.val2;
      }
      else if(max(b.val1,b.val2) <= min(a.val1,a.val2)){
         val1 = a.val1;
         val2 = a.val2;
      }
      else{
         val1 = max(b.val1,b.val2);
         val2 = max(a.val1,a.val2);
      }
   }
   int ans(){return val1+val2;}
};

node* tree;
node createleaf(int x){
   node n; 
   n.val1 = x;   
   n.val2 = -1;
   return  n;
}
node getIden(){
   return createleaf(-1);
}


void update_single_node(node& n, int new_val){
	n.val1 = new_val;
}



void init(int* values,int sz){
   n = msb(sz)+1; 
   if(setbits(sz)==1) n--; 
   tree = new node[1<<(n+1)];
   //bottom level
   for (int i = 0; i < sz; i += 1){
      tree[i+(1<<n)]  = createleaf(values[i]);
   }
   for (int i = (1<<n)+sz; i < (1<<(n+1)); i += 1){
      tree[i] = getIden();
   }
   for (int i = (1<<n)-1; i > 0; i --)
   {
      tree[i].merge(tree[2*i],tree[2*i+1]);
   }
}
node range_query(int root, int left_most_leaf, int right_most_leaf, int u, int v)
{
   //query the interval [u,v), ie, {x:u<=x<v}
   //the interval [left_most_leaf,right_most_leaf) is 
   //the set of all leaves descending from "root"
   if(u<=left_most_leaf && right_most_leaf<=v) return tree[root];
   int mid = (left_most_leaf+right_most_leaf)/2, 
      left_child = root*2, 
      right_child = left_child+1;
   tree[root].split(tree[left_child], tree[right_child]);
   node l=getIden(), r=getIden();
   //getIden() is an element such that merge(x,getIden()) = merge(getIden(),x) = x for all x
   if(u < mid) l = range_query(left_child, left_most_leaf, mid, u, v);
   if(v > mid) r = range_query(right_child, mid, right_most_leaf, u, v);
   
   tree[root].merge(tree[left_child],tree[right_child]);
   node n;
   n.merge(l,r);
   return n;
}

void range_update(int root, int left_most_leaf, int right_most_leaf, int u, int v, int new_val)
{
	if(u<=left_most_leaf && right_most_leaf<=v)
		return update_single_node(tree[root], new_val);
	int mid = (left_most_leaf+right_most_leaf)/2,
		left_child = root*2,
		right_child = left_child+1;
	tree[root].split(tree[left_child], tree[right_child]);
	if(u < mid) range_update(left_child, left_most_leaf, mid, u, v, new_val);
	if(v > mid) range_update(right_child, mid, right_most_leaf, u, v, new_val);
	tree[root].merge(tree[left_child], tree[right_child]);
}
void update(int pos, int new_val){
	return range_update(1,1<<n,1<<(n+1),pos+(1<<n),pos+1+(1<<n),new_val);
}
//segtree ends
int arr[100000];
int main (){
   int N; ni(N);
   for (int i = 0; i < N; i += 1) ni(arr[i]);
   init(arr,N);
   int q; ni(q);
   char c; int x,y;
   for (int i = 0; i < q; i += 1){
      cin>>c;
      scanf("%d %d",&x,&y);
      if(c=='Q'){ 
         printf("%d\n",range_query(1,1<<n,1<<(n+1),x-1+(1<<n),y+(1<<n)).ans());
      }
      else{
         update(x-1,y);
      }
   }
   
}

