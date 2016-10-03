
/*
 * Mazharul Islam
 * BUET
 */

using namespace std;
#include <bits/stdc++.h>

#define rep(i,a,n) for(int i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define PB push_back
#define clr clear()
#define INF (1<<30)
#define ins insert
#define xxx first
#define yyy second
#define eps 1e-9
#define endl "\n"
#define mp make_pair
#define ST string
typedef long long Long;
typedef unsigned long long Ulong;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define MAXN 30+7

/*
        Debug Extensions
*/

/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
/* Debug
*/
ST str1,str2 ;
int Len1,Len2 ;
Long DP[MAXN][MAXN] ,unique_cyborgs[MAXN][MAXN];
pii call(int I,int J){

    if(I==Len1 && J==Len2){
        return mp(0,1) ;
    }
    else if(I==Len1){
        return mp(Len2-J,1) ;
    }
    else if(J==Len2){
        return mp(Len1-I,1) ;
    }
    if(DP[I][J]!=-1) return mp(DP[I][J],unique_cyborgs[I][J]) ;
    pii ret,temp ;

    if(str1[I]==str2[J]){
        ret = call(I+1,J+1) ;
        ret.first++ ;
    }else{
        ret = call(I+1,J) ;
        temp = call(I,J+1) ;
        if(ret.first>temp.first){
            ret = temp ;
        }else if(ret.first==temp.first){ /// they are of same length
            ret.second+=temp.second ;
        }
        ret.first++ ;
    }
    DP[I][J] = ret.first ;
    unique_cyborgs[I][J]=ret.second ;
    return ret ;
}

int main(void) {
    freopen("in.txt","r",stdin) ;
    ios_base::sync_with_stdio(0);

    int testcases,testcaseNo=1 ;
    cin>>testcases ;
    getline(cin,str1) ;
    while(testcases--){
        getline(cin,str1) ;
        getline(cin,str2) ;
       // cout<<str1<<"\n"<<str2<<endl ;
        Len1=str1.length() ;
        Len2=str2.length() ;
        /*
        mem(DP,-1) ;
        pii res = call(0,0) ;
        cout<<"Case #"<<testcaseNo++<<": " ;
        cout<<res.first<<" "<<res.second<<endl ;
        */
        rep(i,0,MAXN) {
            DP[0][i]=   i ;
            DP[i][0] =  i ;
            unique_cyborgs[0][i]=1 ;
            unique_cyborgs[i][0]=1 ;
        }
        rep(i,1,Len1+1){
            rep(j,1,Len2+1){
                if(str1[i-1]==str2[j-1]){
                    DP[i][j] = DP[i-1][j-1]+1 ;
                    unique_cyborgs[i][j] = unique_cyborgs[i-1][j-1] ;
                }
                else{
                    DP[i][j]=min(DP[i-1][j],DP[i][j-1])+1 ;
                    if(DP[i-1][j]<DP[i][j-1]) unique_cyborgs[i][j] = unique_cyborgs[i-1][j] ;
                    else if(DP[i-1][j]>DP[i][j-1]) unique_cyborgs[i][j] = unique_cyborgs[i][j-1] ;
                    else{
                        unique_cyborgs[i][j]=unique_cyborgs[i-1][j]+unique_cyborgs[i][j-1] ;
                    }
                }
            }
        }
        pii res = mp(DP[Len1][Len2],unique_cyborgs[Len1][Len2]) ;
        cout<<"Case #"<<testcaseNo++<<": " ;
        cout<<res.first<<" "<<res.second<<endl ;
    }
    return 0;
}
