
<!-- saved from url=(0045)http://www.codechef.com/viewplaintext/1827600 -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8"></head><body><pre>#include &lt;iostream&gt;
#include &lt;cstring&gt;
#include &lt;string&gt;
#include &lt;cstdio&gt;
#include &lt;cstdlib&gt;

using namespace std;

#define MAX 500010
class BIT
{
    int tree[MAX+1];
    int prev[MAX+1];
    int maxVal;
    public:
    BIT(){
        memset(tree,0,sizeof(int)*(MAX+1));
        memset(prev,0,sizeof(int)*(MAX+1));
        maxVal = MAX;
    }
    void update(int idx, int val){
       int old = prev[idx];
       prev[idx]=val;
       val = val-old;
       while (idx &lt;= maxVal){
            tree[idx] += val;
            idx += (idx &amp; -idx);
       }
    }
    //Returns the cumulative frequency of index idx
    int read(int idx){
        int sum=0;
        while (idx&gt;0){
            sum += tree[idx];
            idx -= (idx &amp; -idx);
        }
        return sum;
    }
};
BIT bits[4];


int RprevVal[MAX];
int RprevInd[MAX];
int CprevVal[MAX];
int CprevInd[MAX];
int pres;
int val,ind;

int indR[] = {0,1};
int indC[] = {2,3};
int n,q;

void rowQuery(int id){
    if(RprevVal[id]==0){
        int exc = bits[indC[1]].read(pres) - bits[indC[1]].read(RprevInd[id]);
        printf("%d\n",n-exc);
    }
    else{
        int exc = bits[indC[0]].read(pres) - bits[indC[0]].read(RprevInd[id]);
        printf("%d\n",exc);
    }
}

void colQuery(int id){
    if(CprevVal[id]==0){
        int exc = bits[indR[1]].read(pres) - bits[indR[1]].read(CprevInd[id]);
        printf("%d\n",n-exc);
    }
    else{
        int exc = bits[indR[0]].read(pres) - bits[indR[0]].read(CprevInd[id]);
        printf("%d\n",exc);
    }
}

void rowSet(int id,int val){
    int prevVal = RprevVal[id];
    RprevVal[id] = val;
    bits[indR[prevVal]].update(RprevInd[id],0);
    bits[indR[val]].update(pres,1);
    RprevInd[id]=pres;
}
void colSet(int id,int val){
    int prevVal = CprevVal[id];
    CprevVal[id] = val;
    bits[indC[prevVal]].update(CprevInd[id],0);
    bits[indC[val]].update(pres,1);
    CprevInd[id]=pres;
}
int main(){
    cin&gt;&gt;n&gt;&gt;q;
    fill(RprevInd,RprevInd+q+5,1);
    fill(RprevVal,RprevVal+q+5,0);
    fill(CprevInd,CprevInd+q+5,1);
    fill(CprevVal,CprevVal+q+5,0);
    char s[100];
    for (pres = 2; pres &lt;= (q+1); ++pres){
        scanf("%s",s);
        if(s[3]=='S'){
            scanf("%d %d",&amp;ind,&amp;val);
            if(s[0]=='R'){
                rowSet(ind,val);
            }
            else{
                colSet(ind,val);
            }
        }
        else{
            scanf("%d",&amp;ind);
            if(s[0]=='R'){
                rowQuery(ind);
            }
            else{
                colQuery(ind);
            }
        }
    }
}
</pre></body></html>