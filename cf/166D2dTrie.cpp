/********************************************************
Question: http://codeforces.com/contest/271/problem/D
Given each character is good or bad and the tolerance 
upto which a string can be accepted as good, 
find the number of good substrings of a string
ex: 
tolerance = 2  
'a' : good and all the other chars are bad 
=> bb : good bbb: bad ab: good
string length : upto 1500

Add all the suffix strings of the input string into a trie.
While adding a suffix, count the number of bad chars in the 
present prefix of the suffix. If this is less than tolerance 
and the part of suffix is not seen upto now then increase the 
count of good substrings by one
**********************************************************/
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int trie[1500*760][26];
string str;
string good;
int tol;

int main(){
	memset(trie,0,(1500*760*26*4));
	cin>>str>>good;
	cin>>tol;
		
	int n= str.length();
	int last=0;
	int ans=0;
	for (int i = 0; i < n; i += 1){
		int bad=0;
		int pres=0;
		for (int j = i; j < n; j += 1)
		{
			int c = str[j]-'a';
			if(good[c]=='0')bad++;
			int next = trie[pres][c];
			
			if(next==0){
				next = last+1;
				last++;
				if(bad<=tol) ans++;
				trie[pres][c] = next;
			}		
			pres = next;			
		}
	}
	cout<<ans<<"\n";
}
