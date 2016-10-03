#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
LL dp[11][111111] ; // length last number
struct DivFreed2{
LL count(int n, int k)
{
    LL ret;
    for(LL i=1;i<=k;i++) dp[1][i]=1 ;
    for(LL i=2;i<=n;i++){
        LL last_tot=0 ;
        for(int num=1;num<=k;num++) {
                last_tot+=dp[i-1][num] ;
                last_tot%=MOD ;
        }
      //  cout<<last_tot<<endl ;
        for(int num=1;num<=k;num++) dp[i][num]=last_tot ;
        for(int num=1;num<=k;num++){
            for(int j=2;j*num<=k;j++){
                dp[i][num]=(dp[i][num]-dp[i-1][j*num]+2*MOD)%MOD ;
            }
        }
    }
    ret=0;
    for(int num=1;num<=k;num++) { ret+=dp[n][num] ; ret%=MOD ; }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 15; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 107; int Arg2 = 107; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 83; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 1234; int Arg2 = 1515011; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 326; verify_case(6, Arg2, count(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 10; int Arg1 = 100000; int Arg2 = 526882214; verify_case(7, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
DivFreed2 ___test;
___test.run_test(-1);
int gbase;
//cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
