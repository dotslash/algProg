#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>

#include <string>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define MAX 100000000
#define LL long long
//for loops
#define FRL(i,l) for(LL i=0;i<(l);i++)
#define FRSE(i,s,e) for(LL i=(s);i<(e);i++)
#define FRI(i,s,e,inc) for(LL i=(s);i<(e);i+=(inc))
//vector
#define VL vector<LL>
#define VI vector<int>
#define PB push_back
//pair
#define PLL pair<LL,LL> 
#define PII pair<int,int> 
#define fir first
#define sec second

class triple{
	public : 
	LL x,y,z;
	triple(){}
	triple(int i1,int i2, int i3){
		x=i1; y=i2; z=i3;
	}
	LL toNum(LL base){
		return base*base*x + base*y + z;
	}
};

int check(int num){
	set<LL> st;
	triple pres = triple(1,1,1);
	
	while(1){
		LL next = pres.toNum(num);		
		if(st.find(next)!=st.end()){
			return 1;
		}
		st.insert(next);
		int n = ( pres.x + pres.y + pres.z ) % num;
		if(n==0) return 0;
		pres = triple(pres.y,pres.z,n);
	}
}

int main(){
	int found = 0;

	for (int i = 1;found<124 ; i += 2)
	{
		int pres =check(i);
		if(pres){
			cout<<found<<" "<<i<<"\n";
			//int x;cin>>" ">>x;
		}
		found+=pres;
		
	}		
}

