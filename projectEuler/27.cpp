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

#define MAX 10000000
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

VI primes;
int bprimes[MAX];
void genprimes(){
	fill(bprimes,bprimes+MAX,1);
	bprimes[1]=0;
	bprimes[0]=0;
	
	for (LL i = 2; i < MAX; i += 1){
		if(bprimes[i]==0)  continue;
		primes.PB(i);
		for (LL j = i*i; j < MAX; j += i)
		{
			bprimes[j]=0;
		}
	}
}

int main(){
	genprimes();		
	
	int pres=0;
	int besta,bestb,bestval=0;
	FRI(b,-1000,1001,1){
		FRI(a,-1000,1001,1){
			int n;
			for(n=0;;n++){
				int val = n*n+a*n+b;
				if(!bprimes[abs(val)])break;
			}
			//printf("%d %d %d\n",n,a,b);		
			if(bestval<n){
				bestval = n;
				besta=a;
				bestb=b;
			}
		}
	}	
	printf("%d %d %d\n",bestval,besta,bestb);
	return 0;
}

