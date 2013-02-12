#include <iostream>
using namespace std;
#define ll long long
#define LIMIT 200002
#define INF 1000000000
ll isPrime[LIMIT];
ll inc[LIMIT];
void init(){

	fill(isPrime,isPrime+LIMIT,1);
	fill(inc,inc+LIMIT,0);
	isPrime[0]=0;
	isPrime[1]=0;
	for(ll i=2;i<LIMIT;i++){
		if(isPrime[i]==0)continue;
		for (ll j = i*i; j < LIMIT; j += i){
			isPrime[j]=0;
		}
	}
	int prev = INF;
	for (int i = (LIMIT-1); i >=0; i --)
	{
		if(isPrime[i]){
			prev=i;
		}
		inc[i] = prev-i;
	}
	
}

int arr[600][600];
int main (int argc, char const* argv[])
{
	init();
	int m,n; cin>>m>>n;
	ll best= (ll)2500*INF;
	
	for (int i = 0; i < m; i += 1)
	{
		ll sum=0;
		for (int j = 0; j < n; j += 1)
		{
			cin>>arr[i][j];
			sum+=inc[arr[i][j]];
		}
		best = min(sum,best);
		
	}
	for (int i = 0; i < n; i += 1)
	{
		ll sum=0;
		for (int j = 0; j < m; j += 1)
		{
			sum+=inc[arr[j][i]];
		}
		best = min(sum,best);
	}
	cout<<best<<endl;
}
