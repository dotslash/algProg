#include <iostream>
#include <string>
#include <cmath>
#define LL long long
using namespace std;
LL array[101];
LL vals[101][201];
LL solve(LL num){
	LL presLeft=0;
	LL presNum =num;
	LL presSum=0;
	cout<<num<<endl;
	for (LL i = 0; i < 101; i += 1){
		LL j;
		cout<<presNum<<"\n";
		for (j = 1; j <= 10; j += 1){
			if(presNum < (presLeft*10+j)*j){
				break;
			}
		}
		presSum+=(j-1);
		presNum = (presNum - (j-1)*(presLeft*10+(j-1)))*100;
		presLeft=presLeft*10+2*(j-1);
		vals[num][i]=(j-1);
	}

	presSum = presSum - (LL)sqrt(num);
	array[num]=presSum;
	
	for (LL i = 0; i < 101; i += 1)
	{
		cout<<vals[num][i];
		
	}
	cout<<"\n"<<presSum<<"\n";
	LL tmp; cin>>tmp;
	
	return presSum;
}

int main()
{
	LL result=0;
	for (LL i = 1; i < 101; i += 1){
		LL x = sqrt(i);
		if(x*x!=i)result+=solve(i);
	}
	return 0;
}

