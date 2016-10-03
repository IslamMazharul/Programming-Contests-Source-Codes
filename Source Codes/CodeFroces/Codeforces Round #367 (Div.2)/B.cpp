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
typedef set<Long> si;
typedef set<ST> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define deb(x) cerr << #x << " = " << x << endl;
#define MAXN 100
int main(void){
    freopen("in.txt","r",stdin) ;
    ios_base::sync_with_stdio(false) ;
    int n ;
    Long val;
    vector<Long>arr ;
    cin>>n ;
    rep(i,0,n){
        cin>>val ;
        arr.push_back(val) ;
    }
    sort(arr.begin(),arr.end()) ;
    int m ;
    cin>>m ;
   // cout<<*arr.begin()<<endl ;
    rep(i,0,m){
        cin>>val ;
        cout<<upper_bound(arr.begin(),arr.end(),val)-arr.begin()<<endl ;
    }
    return 0;
}
