/****************************************************

This could have gone wrong. Because there might be a 
possiblity that the in smallest such number one need
need not replace all the occurances of a number to 
get another prime. 

Example : 113 is prime 173 is also a prime but this 
program does ignores such cases and only replaces 11
with all possible xx
 
******************************************************/
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

VI primes;
int bprimes[MAX];
int tot[MAX];

void genprimes(){
	fill(bprimes,bprimes+MAX,1);
	for (int i = 0; i < MAX; i += 1)
	{
		tot[i]=i;
	}
	bprimes[1]=0;
	bprimes[0]=0;
	tot[2]=1;
	
	for (LL i = 2; i < MAX; i += 1){
		if(bprimes[i]==0)  continue;
		primes.PB(i);
		for (LL j = 2*i; j < MAX; j += i)
		{
			bprimes[j]=0;
			tot[j]=(tot[j]/i)*(i-1);
		}
	}	
}

int main(){
	genprimes();		
	LL num2 = 15499;
	LL den2 = 94744;
	for (int i = 2; i < MAX; i += 1)
	{
		LL den1 = i-1;
		LL num1 = tot[i];
		
		//f2>f1 => n1/d1 < n2/d2 => n1*d2 < n2*d1
		if(num2*den1 > num1*den2){
			cout<<i<<"\n";
			return 0;
		}
		
	}
}

