#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int p_inp[100],num_inp[100];
double prob[100][5001]; //number of flags from 0 to 5000
int n; 
void solve(){    
    cin>>n;
    memset(prob[0],0,4*100*5001);
    //input
    //cout<<"val of n is "<<n<<endl;
    int total_flags=0,target;
    for (int i = 0; i < n; i += 1){
        cin>>num_inp[i];
        total_flags+=num_inp[i];
    }
    target = total_flags - (total_flags/2);
    //cout<<"val of target is "<<target<<endl;
    for (int i = 0; i < n; i += 1){
        cin>>p_inp[i];
    }

    prob[0][0]=(100.0-p_inp[0])/100;
    prob[0][num_inp[0]] = 1-prob[0][0];
    
    for (int level = 1; level < n; level += 1)
    {
        for (int sum = 0; sum < target; sum += 1)
        {   
            prob[level][sum]= prob[level-1][sum]*(100-p_inp[level]);
            if(num_inp[level]<=sum)     
                prob[level][sum] += prob[level-1][ sum-num_inp[level] ]*p_inp[level];
            prob[level][sum]/=100;   
        }
    }
    double retval=0;
    for (int i = 0; i < target; i += 1){
        retval+=prob[n-1][i];
    }
    
    printf("%.7f\n",1-retval);      
    
}

int main ()
{
    int tc; cin>>tc;
    for (int i = 0; i < tc; i += 1){
        solve();
    }
    return 0;
}