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
inline void read() {
#ifdef Mazharul
    freopen("/home/mazharul/in.txt","r",stdin) ;
#endif
}

#define all(x) x.begin(),x.end()
#define sz(x) ((long long)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf 1000000000
#define ins insert
#define ff first
#define ss second
#define eps 1e-9
#define endl "\n"

typedef long long  Long ;
typedef unsigned long long ULong;
typedef string ST;
typedef vector<Long> vi;
typedef vector<ST> vs;
typedef map<Long,Long> mii;
typedef map<ST,Long> msi;
typedef set<Long> si;
typedef set<ST> ss;
typedef pair<Long,Long> pii;
typedef vector<pii> vpii;


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
#define MAXN 100
void DFS(int cur,Long carry,Long last,vector<char> res,Long s){
    cout<<res<<endl ;
    if(s==0){
       // cout<<res<<endl ;
        return ;
    }
    Long ss = s%10 ;
    rep(i,0,17){
        Long nxtlast = i*10+ss-carry ;
        cout<<last<<" "<<nxtlast<<" "<<s<<endl ;
        Long d= last-nxtlast ;
     //   cout<<d<<endl ;
        if(d>=0){
            res.pb(d%10+'0') ;
            DFS(cur+1,i,i*10+ss,res,s/10) ;
            res.pop_back() ;
        }
    }
}
struct LastDigit{
long long findX(long long S){
    long long ret;
    vector<char>res ;
  //  rep(i,1,17){
        Long s  =S%10;
      //  res.pb(s+'0') ;
        Long last = s+1*10 ;
        DFS(1,1,last,res,S/10) ;
        //res.pop_back() ;
    //}
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 564LL; long long Arg1 = 509LL; verify_case(0, Arg1, findX(Arg0)); }
	void test_case_1() { long long Arg0 = 565LL; long long Arg1 = -1LL; verify_case(1, Arg1, findX(Arg0)); }
	void test_case_2() { long long Arg0 = 3000LL; long long Arg1 = 2701LL; verify_case(2, Arg1, findX(Arg0)); }
	void test_case_3() { long long Arg0 = 137174210616796LL; long long Arg1 = 123456789555123LL; verify_case(3, Arg1, findX(Arg0)); }
	void test_case_4() { long long Arg0 = 837592744927492746LL; long long Arg1 = -1LL; verify_case(4, Arg1, findX(Arg0)); }
	void test_case_5() { long long Arg0 = 999999999999999999LL; long long Arg1 = 900000000000000000LL; verify_case(5, Arg1, findX(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(void){
LastDigit ___test;
___test.run_test(-1);
return 0;
}
// END CUT HERE

