#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype> 

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std;
#define MAXN 50*50+10
int DP[MAXN][MAXN] ;
string S ;
int Call(int i,int j){
	
	if(i>j) return 0 ;
		
	if(DP[i][j]!=-1) return DP[i][j] ;
	DP[i][j] = S[i]==S[j]?1:0 ;
	for(int I=i+1;I<j;I++){
		for(int J=I;J<j;J++){
			DP[i][j] +=Call(I,J) ;
		}
	}
	
	return DP[i][j] ;	
}

struct PalindromicSubstringsDiv2{
int count(vector <string> S1, vector <string> S2){

    int ret;
    S = "" ;
    ret = 0 ;
    for(int i=0;i<(int)S1.size();i++) {
		S+=S1[i] ;
	}
	for(int i=0;i<(int)S2.size();i++) {
		S+=S2[i] ;
	}
	
	cout<<S<<endl ;
	//cout<<S[0]<<" "<<S[3]<<endl ;
	//memset(DP,-1,sizeof(DP)) ;
	for(int i=0;i<(int)S.length();i++) DP[i][i] = 1 ;
	
	for(int i=0;i<(int)S.length();i++){
		for(int j=0;j<(int)S.length();j++){
			cout<<Call(i,j)<<" " ;
			ret += Call(i,j) ;
		}
		cout<<"\n" ;
	}
	
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","a",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"zaz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"top"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"coder"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"daata"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
PalindromicSubstringsDiv2 ___test;
___test.run_test(-1);
//int gbase;  
//cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
