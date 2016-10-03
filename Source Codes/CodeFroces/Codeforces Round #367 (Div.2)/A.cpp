/*
 * Mazharul Islam , BUET
 * Problem Link:
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
#define MAXN 100
struct PT{
    double x,y ,v;
};
int main(void){
    freopen("in.txt","r",stdin) ;
    PT home ,taxi;
    int n ;
    double res=10000000000000000 ;
    cin>>home.x>>home.y>>n ;
    rep(i,0,n){
        cin>>taxi.x>>taxi.y>>taxi.v ;
        res=min(res,hypot(home.x-taxi.x,home.y-taxi.y)/taxi.v) ;
    }
    cout<<fixed<<setprecision(15)<<res<<endl ;
    return 0;
}
