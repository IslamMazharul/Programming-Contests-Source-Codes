/*
 * Mazharul Islam , BUET
 * Problem Link:http://acm.hust.edu.cn/vjudge/contest/view.action?cid=120288#problem/I
 */
using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define endl "\n"
typedef long long  Long;
typedef unsigned long long uint;
typedef string ST;
typedef vector<int> vi;
typedef vector<ST> vs;
typedef map<int,int> mii;
typedef map<ST,int> msi;
typedef set<int> si;
typedef set<ST> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define deb(x) cerr << #x << " = " << x << endl;
#define MAXN 2000007
char s[MAXN] ;
Long arr[MAXN] ;
int main(){
    int n ;
    scanf("%d%s",&n,s) ;
    rep(i,0,n){
        scanf("%I64d",&arr[i]) ;
    }
    int idx=-1 ;
    Long res=20000000000 ;
    rep(i,0,n){
        if(idx!=-1 && s[i]=='L'){
            res=min(res,(arr[i]-arr[idx])/2) ;
        }
        if(s[i]=='R') idx=i ;
    }
    if(res==20000000000){
        puts("-1") ;
    }else{
        printf("%I64d\n",res) ;
    }

    return 0;
}




