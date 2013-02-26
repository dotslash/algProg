/*****************************************
diophotine equation: 2b**2 - n**2 -2b -n =0;
n_next = 3b+2n-2
b_bext = 4b+3n-3

b_start = 15
n_start = 21
*****************************************/

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>

#include <string>
#include <iostream>

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define MAX 500010
#define LL long long
//for loops
#define FRL(i,l) for(int i=0;i<(l);i++)
#define FRSE(i,s,e) for(int i=(s);i<(e);i++)
#define FRI(i,s,e,inc) for(int i=(s);i<(e);i+=(inc))
//vector
#define VL vector<LL>
#define VI vector<int>
#define PB push_back
//pair
#define PLL pair<LL,LL> 
#define PII pair<int,int> 
#define fir first
#define sec second


int main(){
	LL n=21;
	LL b=15;
	LL b_next,n_next;
	while(n<=(LL)1000000000000){
		b_next = 3*b + 2*n - 2;
		n_next = 4*b + 3*n - 3;
		n=n_next;
		b=b_next;
	}		
	cout<<b<<" "<<n<<"\n";
	return 0;
}

