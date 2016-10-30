#include<bits/stdc++.h>


using namespace std;
#define MAX 1000000
vector<string> mat[MAX];
vector<string> course;
map<string,int> table;
int ans[MAX];
bool cmp(string str1,string str2)
{
    return str1<str2;
}
int main()
{
        freopen("in.txt","r",stdin) ;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        //mat.clear();
        int i;
        for(i=1;i<=n;i++)
        {
            mat[i].clear();
        }
        course.clear();
        table.clear();
        string str1,str2,str3;
        string str;
        int num=0;
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;i++)
        {
            cin>>str1>>str2>>str3;
            str=str1+str2;
            if(/*course.find(str3)!=course.end()*/find(course.begin(),course.end(),str3)!=course.end())
            {
                int id=table[str3];
                if(/*mat[id].find(str)==mat[id].end()*/find(mat[id].begin(),mat[id].end(),str)==mat[id].end())
                {
                    mat[id].push_back(str);
                }
            }
            else
            {
                course.push_back(str3);
                table[str3]=num;
                mat[num].push_back(str);
                num++;
            }
        }
        for(i=0;i<num;i++)
        {
            ans[i]=mat[i].size();
        }
        sort(course.begin(),course.end(),cmp);
        vector<string>::iterator it;
        for(it=course.begin();it!=course.end();it++)
        {
            cout<<(*it)<<" "<<ans[table[*it]]<<endl;
        }
    }
}
