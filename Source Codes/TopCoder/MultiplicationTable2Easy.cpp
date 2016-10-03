#include<bits/stdc++.h>
using namespace std;

struct MultiplicationTable2Easy{
string isGoodSet(vector <int> table, vector <int> t)
{
    bool f[303] ;
    memset(f,0,sizeof(f)) ;
    int n =sqrt(table.size()) ;
   // cout<<n<<endl ;
    for(int i=0;i<t.size();i++) f[t[i]]=1 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(f[table[i*n+j]]!=f[table[j*n+i]]){

                return "Not Good" ;
            }
        }
    }
    return "Good" ;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Good"; verify_case(0, Arg2, isGoodSet(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not Good"; verify_case(1, Arg2, isGoodSet(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Good"; verify_case(2, Arg2, isGoodSet(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not Good"; verify_case(3, Arg2, isGoodSet(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Good"; verify_case(4, Arg2, isGoodSet(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not Good"; verify_case(5, Arg2, isGoodSet(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
MultiplicationTable2Easy ___test;
___test.run_test(-1);
int gbase;
//cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
