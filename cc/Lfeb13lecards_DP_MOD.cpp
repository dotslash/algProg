
<!-- saved from url=(0045)http://www.codechef.com/viewplaintext/1816599 -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8"></head><body><pre># include &lt;iostream&gt;
# include &lt;string&gt;
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
    for(int i=1; i&lt;lim;i++){
        val1[i]=(val1[i-1]*2)%rem;
        val2[i][0]=1;
        ans[i]=0;
        for(int j=1;j&lt;lim;j++){
            val2[i][j] = (val2[i-1][j]+val2[i-1][j-1])%rem;
            if(j&gt;(i/2)) ans[i]= ((ans[i]+val2[i][j])%rem);
        }
    }
    int tc; cin&gt;&gt;tc;
    for(int i=0;i&lt;tc;i++){
        int cnt; cin&gt;&gt;cnt;
        int x;
        for(int i=0;i&lt;cnt;i++)cin&gt;&gt;x;
        //ll ans = (val1[cnt]-((cnt+1)%2)*val2[cnt][cnt/2])/2;
        //cout&lt;&lt;(ans+rem)%rem&lt;&lt;endl;
        cout&lt;&lt;ans[cnt]&lt;&lt;endl;
    }
}

</pre></body></html>