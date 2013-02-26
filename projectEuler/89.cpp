#include <iostream>
#include <string>
using namespace std;
int count=0;
string patterns[]={"DCCCC","LXXXX","VIIII","CCCC","XXXX","IIII"};
int cnt[]={1,1,1,2,2,2};
void solve(){
	string str; cin>>str;
	for (int i = 0; i < 6; i += 1){
		string sub = patterns[i];
		int pos= str.find(sub, 0);;
		while(pos != string::npos){
			 pos = str.find(sub,pos+1);
			 count+=cnt[i];
		}
	}	
		
}

int main (int argc, char const* argv[])
{
	
	for (int i = 0; i < 1000; i += 1){
		solve();
	}
	cout<<count<<"\n";
	return 0;
}

