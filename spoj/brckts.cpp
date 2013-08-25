//heavily copied from https://gist.github.com/utkarshl/4429155 with minor modifications
#include <cstdio>
#include <cassert>
#include <cstring>
#include <climits>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back
#define ll long long
#define nl(x) scanf("%lld",&x)
#define ni(x) scanf("%d",&x)
#define pii pair<int,int>
#define val1 first
#define val2 second

#define msb(x) 31-__builtin_clz (x)
#define setbits(x) __builtin_popcount(x)

using namespace std; 

#include"assert.h"
template<class node>
class segtree{/*{{{*/
	template<bool b>class param{};
	inline void spltdwn(int idx,param<true>){splt(idx);}
	inline void splt(int idx){/*{{{*/
		idx>>=1;
		if(idx>0)splt(idx);
		tree[idx].split(tree[idx<<1],tree[(idx<<1)|1]);
	}/*}}}*/
	inline void spltdwn(int,param<false>){};
	inline void split(node& a, node& b, node& c, param<true> ){return a.split(b,c);}
	inline void split(node&, node&, node&, param<false>){}
	template<typename t,void (t::*)(t&,t&)> class T{};
	template<typename t> static char test(T<t,&t::split>*){return 0;}
	template<typename t> static long double test(...){return 0;}
	int u,v;
	node query(int root, int left_range, int right_range){/*{{{*/
		if(u<=left_range && right_range<=v)
			return tree[root];
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		node res;
		if(u>=mid)res=query(r,mid,right_range);
		else if(v<=mid)res=query(l,left_range,mid);
		else{
			node n1 = query(l,left_range,mid),
				 n2 = query(r,mid,right_range);
			res.merge(n1,n2);
		}
                if(has_split) tree[root].merge(tree[l],tree[r]);
		return res;
	}/*}}}*/
 	template<void(*fn)(node&)>
	void local_update(int root, int left_range,int right_range){/*{{{*/
		if(u<=left_range && right_range<=v){
			return fn(tree[root]);
		}
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		if(v>mid)local_update<fn>(r,mid,right_range);
		if(u<mid)local_update<fn>(l,left_range,mid);
		tree[root].merge(tree[l],tree[r]);
	}/*}}}*/
	void mrgup(int idx){/*{{{*/
		idx>>=1;
		while(idx>0)
			tree[idx].merge(tree[idx<<1],tree[(idx<<1)|1]),
			idx>>=1;
	}/*}}}*/
public:
	static bool const has_split = (sizeof(test<node>(0))==sizeof(char));
	int N;
	int leftmost_leaf, rightmost_leaf;
	node* tree;
	node identity;
	~segtree(){
		delete tree;
	}
	void init(int n, const node a[], const node& identity,node* dataStore){/*{{{*/
		this->identity = identity;
		N=0;
		while((1<<N)<n)N++;
		leftmost_leaf = 1<<N;
		rightmost_leaf = leftmost_leaf<<1;
		tree = dataStore;
		if(sizeof(tree)<sizeof(node)*(rightmost_leaf)) 
		   tree = new node[rightmost_leaf];
		   
		for(int i=0;i<n;i++)
			tree[i+leftmost_leaf] = a[i];
		for(int i=n+leftmost_leaf;i<rightmost_leaf;i++)
			tree[i]=identity;
		for(int i=leftmost_leaf-1;i;i--)
			tree[i].merge(tree[i<<1],tree[(i<<1)|1]);
	}/*}}}*/
	node query(int u, int v){//[u,v]/*{{{*/
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return query(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	node query(int u){//faster version of query(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		return tree[u];
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u, int v){/*{{{*/
		//0-indexed
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return local_update<fn>(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u){//faster version of update(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		fn(tree[u]);
		mrgup(u);
	}/*}}}*/
	void split_down(int leaf_idx){/*{{{*/
		spltdwn(leaf_idx+leftmost_leaf,param<has_split>());
	}/*}}}*/
	void merge_up(int leaf_idx){/*{{{*/
		mrgup(leaf_idx+leftmost_leaf);
	}/*}}}*/
	bool is_leaf(int tree_idx){return tree_idx>=leftmost_leaf;}
	int binary_search(node k){/*{{{*/
	//search the last place i, such that merge( everyting to the left of i(including i) ) compares less than k
        int root = 1;
        node n=identity;
		//identity satisfies merge(identity,y) = merge(y,identity) = y for all y.
		assert(!(k<identity));
        while(!is_leaf(root)){
                int left_child = root<<1,
					right_child = left_child|1;
                if(has_split)
					split(tree[root],tree[left_child],tree[right_child],param<has_split>());
                node m;
                m.merge(n,tree[left_child]);
                if(m<k){//go to right side
                        n=m;
                        root=right_child;
                }else root=left_child;
        }
        node m;
        m.merge(n,tree[root]);
		mrgup(root);
        if(m<k)return root-leftmost_leaf;
        else return root-1-leftmost_leaf;
	}/*}}}*/
};/*}}}*/

struct node{
  int min,sum;
	void merge(node& l,node& r){
		sum = l.sum+r.sum;
		min = std::min(l.min,l.sum+r.min);
	}
};
void flip(node& n){
	n.min*=-1;
	n.sum=n.min;
}
node dataStore[1000000];
node arr[1000000];
char inp[1000000];
int main(){
	segtree<node> s;
	for(int i=0;i<10;i++){
		printf("Test %d:\n",i+1);
		int n;
		scanf("%d",&n);
		scanf("%s",inp);
		for(int i=0;i<n;i++)
			arr[i].min=arr[i].sum=inp[i]=='('?1:-1;
		arr[n].min=0x7f7f7f;arr[n].sum=0;
		s.init(n,arr,arr[n],dataStore);
		int m;
		scanf("%d",&m);
		while(m--){
			int k;
			scanf("%d",&k);
			if(k)
				s.update<&flip>(k-1);
			else{
				node x=s.query(0,100000000);
				printf("%s\n",(x.sum==0&&x.min==0)?"YES":"NO");
			}
		}
	}
}
