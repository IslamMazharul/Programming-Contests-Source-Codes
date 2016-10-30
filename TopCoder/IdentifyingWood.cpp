#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

struct IdentifyingWood{
string check(string s, string t)
{
    string ret;
    int i, j=0;
    for(i=0;i<s.length();i++){
		if(s[i]==t[j]) {
				j++ ;
				 if(j==t.length()) return "Yep, it's wood." ;
		}
    }


    return "Nope.";
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
