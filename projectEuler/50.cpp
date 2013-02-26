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

#define MAX 1000000
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
string int2str(int num){
	stringstream ss; ss<<num;
	string ret; ss>>ret;
	return ret;
}

int str2int(string& num){
	return atoi(num.c_str());
}

string replace(string & str, char f,char r){
	string ret=str;
	bool sat=false;
	for (int i = 0; i < ret.length(); i += 1)
	{
		if(ret[i]==f){
			
			sat=true;	
			ret[i]=r;
		}
	}
	if(sat) return ret;
	else return "";
}


bool check(int prime){	
	for (int i = 0; i < 10; i += 1){
		
		int count=0;
		for (int j = i+1; j < 10; j += 1){
			string tmp = int2str(prime);
			string pres = replace(tmp,(char)('0'+i),(char)('0'+j));
			if(pres=="") {
				count=0;
				break;
			}
			int num = str2int(pres);
			count+=bprimes[num];
		}
		if(count>=7) return true;
	}
	return false;
}

int main(){
	genprimes();		
	for (int i = 0; i < primes.size(); i += 1)
	{
		if(check(primes[i])){
			cout<<primes[i]<<endl;
			return 0;
		}
	}			
}

