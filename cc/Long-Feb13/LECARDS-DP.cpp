# include <iostream>
# include <string>
using namespace std;
#define lim  1003
#define rem  1000000007 
#define ll  long long  

ll val1[lim];
ll val2[lim][lim];
ll ans[lim];
int main(){
    val2[0][0] = 1;
    val1[0]=1;
    for(int i=1; i<lim;i++){
        val1[i]=(val1[i-1]*2)%rem;
        val2[i][0]=1;
        ans[i]=0;
        for(int j=1;j<lim;j++){
            val2[i][j] = (val2[i-1][j]+val2[i-1][j-1])%rem;
            if(j>(i/2)) ans[i]= ((ans[i]+val2[i][j])%rem);
        }
    }
    int tc; cin>>tc;
    for(int i=0;i<tc;i++){
        int cnt; cin>>cnt;
        int x;
        for(int i=0;i<cnt;i++)cin>>x;
        //ll ans = (val1[cnt]-((cnt+1)%2)*val2[cnt][cnt/2])/2;
        //cout<<(ans+rem)%rem<<endl;
        cout<<ans[cnt]<<endl;
    }
}
