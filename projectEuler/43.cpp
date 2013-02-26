#include <iostream>     
#include <algorithm>    
#define LL long long
using namespace std;

int digits[] = {0,1,2,3,4,5,6,7,8,9};
LL number(){
	if(digits[0]==0) return 0;
	LL pres=0;
	for (int i = 0; i < 10; i += 1)
	{
		pres = pres*10+digits[i];
	}
	cout<<pres<<"\n";
	return pres;
}

int ok(int s,int e,int num){
	int ret=0;
	e--; s--;
	for (int i = s; i <= e; i += 1)
	{
		ret=ret*10+digits[i];
	}
	return (ret%num)==0;
}

LL answer(){
	bool n2=ok(2,4,2),n3=ok(3,5,3),n5=ok(4,6,5);
	bool n7=ok(5,7,7),n11=ok(6,8,11),n13=ok(7,9,13),n17=ok(8,10,17);
	if(n2 && n3 && n5 && n7 && n11 && n13 && n17){
		return number();
	}
	return 0;
}

int main () {
	LL sum=0;
	do {
		sum+=answer();
	} while ( next_permutation(digits,digits+10) );

 	cout<<sum<<endl;
	return 0;
}
