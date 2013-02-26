//c++ templeate by Yes-Tea-Pea(Sai Teja Pratap)

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
#include <map>
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
#define MLL map<LL,LL>
//pair
#define PLL pair<LL,LL> 
#define PII pair<int,int> 
#define fir first
#define sec second


int solve(int number){
	MLL mp;
	int sqrtNum = sqrt(number)	;
	LL presDeno = sqrtNum;
	LL presNume = 1;
	int iter=0;
	while(1){
		//cout<<presDeno<<" "<<presNume<<"\n";
		int stNum = presDeno*1000000+presNume;
		if(mp.find(stNum)!=mp.end()){
			cout<<number<<" "<<iter-mp[stNum]<<"\n";
			return (iter-mp[stNum] )%2;
		}
		mp[stNum]=iter++;
		// num/[sqrt_n - den]->[sqrt_n + num ]/den
		LL den = (number-presDeno*presDeno)/(presNume);
		LL num = presDeno;
		
		LL tmp = ( num+ sqrtNum )/den;
		tmp = (tmp*den)-num;
		presDeno = tmp;
		presNume = den;
		
	}
	
}


int main(){
	int answer=0;	
	for (int i = 1; i < 10000; i += 1)
	{
		int n = sqrt(i);
		if(n*n == i)continue;
		answer+=solve(i);		
	}
	cout<<answer<<"\n";
	return 0;
}

