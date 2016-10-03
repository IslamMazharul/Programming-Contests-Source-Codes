#include<bits/stdc++.h>
using namespace std;
bool dp[55][33][33] ;
struct ExplodingRobots{
string canExplode(int x1, int y1, int x2, int y2, string instructions)
{
    string ret;
    int Up=0,Don=0,lef=0,rig=0;
    for(int i=0;i<instructions.size();i++)
    {
        if(instructions[i]=='U') Up++ ;
        else if(instructions[i]=='D') Don++ ;
        else if(instructions[i]=='L') lef++ ;
        else rig++ ;
    }
    int x=abs(x1-x2) ;
    int y=abs(y1-y2) ;
    if( (Up+Don>=y)  && (rig+lef>=x)) ret="Explosion" ;
    else ret="Safe" ;
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 2; int Arg3 = 0; string Arg4 = "L"; string Arg5 = "Explosion"; verify_case(0, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 2; int Arg3 = 0; string Arg4 = "U"; string Arg5 = "Safe"; verify_case(1, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 2; int Arg3 = 0; string Arg4 = "UL"; string Arg5 = "Explosion"; verify_case(2, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 5; int Arg3 = 5; string Arg4 = "LURLL"; string Arg5 = "Safe"; verify_case(3, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 5; int Arg2 = -9; int Arg3 = -10; string Arg4 = "LULULULLLUULRULULULULULULLULULLULD"; string Arg5 = "Explosion"; verify_case(4, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ExplodingRobots ___test;
___test.run_test(-1);
int gbase;
//cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
