#include <bits/stdc++.h>
using namespace std;

struct ThueMorseGame{
string get(int n, int m)
{
    string ret;
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arg2 = "Alice"; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "Bob"; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 387; int Arg1 = 22; string Arg2 = "Alice"; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 499999999; int Arg1 = 50; string Arg2 = "Alice"; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 499999975; int Arg1 = 49; string Arg2 = "Bob"; verify_case(4, Arg2, get(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ThueMorseGame ___test;
___test.run_test(-1);
return 0;
}
// END CUT HERE
