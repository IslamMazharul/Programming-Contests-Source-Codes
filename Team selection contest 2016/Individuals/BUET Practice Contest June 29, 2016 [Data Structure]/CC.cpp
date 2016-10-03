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
#define MAXN 100
int arr[MAXN+7] ,n,DP[MAXN+7][MAXN+7] ;

int call(int day,int last){
    if(day==n){
        return 0 ;
    }
    if(DP[day][last]!=-1) return DP[day][last] ;

    int ret=n ;
    rep(i,0,3){
        if(i==0) ret=min(ret,call(day+1,i)+1) ;
        if(last!=i){
            if(i==0) ret=min(ret,call(day+1,i)+1) ; // resting
            else if(i==1){ // contest
                if(arr[day]!=0 && arr[day]!=2){
                    ret=min(ret,call(day+1,i)) ;
                }
            }
            else if(i==2){ //gym
                if(arr[day]!=0 && arr[day]!=1){
                    ret=min(ret,call(day+1,i)) ;
                }
            }
        }
    }
    DP[day][last]=ret ;
    return ret ;
}

int main(void){
    mem(DP,-1) ;
    cin>>n ;
    rep(i,0,n){
        cin>>arr[i] ;
    }
    int res=call(0,0) ;
    res=min(res,min(call(0,1),call(0,2))) ;
    printf("%d\n",res) ;
    return 0;
}





