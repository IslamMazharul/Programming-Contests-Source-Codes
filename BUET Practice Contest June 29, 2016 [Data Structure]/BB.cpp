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
#define MAXN 2000
ST Map[MAXN] ;
int R[MAXN],C[MAXN] ;
int main(){
    int n,m,cnt=0 ;
    cin>>n>>m ;
    rep(i,0,n){
        cin>>Map[i] ;
    }
    rep(i,0,n){
        rep(j,0,m){
            if(Map[i][j]=='*') {
                    R[i]++ ;
                    C[j]++ ;
                    cnt++ ;
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            int cc=R[i]+C[j] ;
            if(Map[i][j]=='*'){
                    cc-- ;
            }
            if(cc==cnt){
                printf("YES\n%d %d\n",i+1,j+1) ;
                return 0 ;
            }
        }
    }
    printf("NO\n") ;
    return 0;
}




