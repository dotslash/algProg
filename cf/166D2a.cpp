#include <iostream>
using namespace std;
bool isvalid(int num){
	int set=0;
	while(num>0){
		int rem = num%10;
		num = num/10;
		int prev = 1<<rem;
		if(prev&set) return false;
		set = set+prev;
	}
	return true;
}
int main (int argc, char const* argv[])
{
	int num; cin>>num;
	num++;
	
	
	while(true){
		if(isvalid(num)){
			cout<<num<<"\n";
			return 0;
		}
		num++;
		
		
	}
	return 0;
}
