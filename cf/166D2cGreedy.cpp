#include <iostream>
using namespace std;

int main (int argc, char const* argv[])
{
	int n,k ; cin>>n>>k;
	if((n/k)<3){
		cout<<"-1\n";
		return 0;
	}
	int cnt = k;
	int pres=0;
	int tmp[n+100];
	for (int i = 0; i < k;i++){
		tmp[i]=(pres+1);
		pres = (pres+1)%cnt;
	}
	for (int i = k; i < n;)
	{
		tmp[i]=(pres+1);
		tmp[i+1] = (pres+1);
		pres= (pres+1)%cnt;
		i+=2;
	}
	for (int i = 0; i < n; i += 1)
	{
		cout<<tmp[i]<<" ";
	}
	cout<<"\n";
	
}
