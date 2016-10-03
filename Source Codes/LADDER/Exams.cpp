#include <bits/stdc++.h>
using namespace std ;
#define LL long long
class Exam {
    public:
    LL a,b ;
    bool operator<(const Exam &other)const
    {
        if(a!=other.a) return a<other.a ;
        else return b<other.b ;
    }
};
Exam exam[5000+7] ;

int main(void){
    int n ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&exam[i].a,&exam[i].b) ;
    }
    sort(exam,exam+n) ;
    LL res = exam[0].b ;
    for(int i=1;i<n;i++)
    {
        //printf("%I64d %I64d\n",exam[i].a,exam[i].b) ;
        if(res<=exam[i].b)
        {
            res = exam[i].b ;
        }else{
            res = exam[i].a ;
        }
    }
    printf("%I64d\n",res) ;
}
