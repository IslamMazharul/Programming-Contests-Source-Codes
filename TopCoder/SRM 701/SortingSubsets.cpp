#include <bits/stdc++.h>
using namespace std;

struct SortingSubsets{
int getMinimalSize(vector <int> a)
{
    int ret=0;
    vector <int> aa = a ;
    sort(a.begin(),a.end()) ;
    for(int i=0;i<a.size();i++){
		if(a[i]!=aa[i]){
			ret++ ;
		}
    }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMinimalSize(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMinimalSize(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 4, 4, 3, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getMinimalSize(Arg0)); }
	void test_case_3() { int Arr0[] = {11, 11, 49, 7, 11, 11, 7, 7, 11, 49, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, getMinimalSize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
SortingSubsets ___test;
___test.run_test(-1);
return 0;
}
// END CUT HERE
