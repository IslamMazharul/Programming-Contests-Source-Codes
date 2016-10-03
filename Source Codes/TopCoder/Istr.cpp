#include<bits/stdc++.h>
using namespace std;

struct Istr{
int count(string s, int k)
{
    int ret=0;
    int Len=s.length() ;
    int cnt[200] ;
    memset(cnt,0,sizeof(cnt)) ;
    for(int i=0;i<Len;i++){
        cnt[s[i]]++ ;
    }
    priority_queue<int>pq ;
    for(char i='a';i<='z';i++){
        pq.push(cnt[i]) ;
    }

    while(k>0){

        int val=pq.top() ; pq.pop() ;
       // cout<<val<<endl ;
        if(val==0){
            break ;
        }
        pq.push(val-1) ;
        k-- ;
    }
    while(!pq.empty()){
        ret+=pq.top()*pq.top() ; pq.pop() ;
    }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abacaba"; int Arg1 = 0; int Arg2 = 21; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abacaba"; int Arg1 = 1; int Arg2 = 14; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abacaba"; int Arg1 = 3; int Arg2 = 6; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abc"; int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "wersrsresesrsesrawsdsw"; int Arg1 = 11; int Arg2 = 23; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
Istr ___test;
___test.run_test(-1);
int gbase;
//cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
