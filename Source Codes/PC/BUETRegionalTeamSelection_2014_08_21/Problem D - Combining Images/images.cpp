#include <iostream>
#include <string>

using namespace std;

const char *Bin[16]={
"0000","0001","0010","0011",
"0100","0101","0110","0111",
"1000","1001","1010","1011",
"1100","1101","1110","1111"};

const char *Hex[16]={
"0","1","2","3","4","5","6","7",
"8","9","A","B","C","D","E","F"};

string toBin(char c)
{
	int i;
	for(i=0;i<16;i++)
	if(c==Hex[i][0]) return Bin[i];
	return "";
}

string toBin(string s)
{
	int i,n;
	string r;
	n=s.size();
	r="";
	for(i=0;i<n;i++)
	{
		r+=toBin(s[i]);
	}
	return r;
}

string inter(string &a,string &b,int &i,int &j)
{
	string r;
	if(a[i]=='1' && b[j]=='1')
	{
		i++; j++;
		if(a[i]=='1' && b[j]=='1')
		{
			r="11";
		}
		else 
		{
			r="10";
		}
		i++; j++;
		return r;
	}
	else
	{
		int x;
		int asave,bsave;
		r="0";
		
		asave=bsave=-1;
		if(a[i]=='1')
		{
			asave=i;
		}
		else i++;

		if(b[j]=='1')
		{
			bsave=j;
		}
		else j++;

		for(x=0;x<4;x++)
		{
			if(asave>=0) i=asave;
			if(bsave>=0) j=bsave;
			r+=inter(a,b,i,j);
		}
		return r;
	}
	return "";
}

string toHex(string s)
{
	int i,n;
	n=s.size();
	if(s.size()==4)
	{
		for(i=0;i<16;i++)
		if(s==Bin[i]) return Hex[i];
		return "";
	}
	string r="";
	for(i=0;i<n;i+=4)
	{
		r+=toHex(s.substr(i,4));
	}
	return r;
}

string compress(string &s,int &i)
{
	string r;
	if(s[i]=='1') 
	{
		i++;
		r=string("1")+s[i];
		//cout<<"r = "<<r<<endl;
		i++;
		return r;
	}
	r="0";
	int x;
	i++;
	for(x=0;x<4;x++)
	{
		r+=compress(s,i);
	}
	if(r=="010101010") return "10";
	if(r=="011111111") return "11";
	return r;
}

int main()
{
	string a,b,c;
	int i,j,n,x;
	int cc;

	cc=1;
	while(cin>>a && a!="0")
	{
		if(cc>1) cout<<endl;

		cin>>b;
		a=toBin(a);
		b=toBin(b);
//		cout<<"Bin:"<<endl;
//		cout<<a<<endl<<b<<endl;

		i=0;
		while(a[i]=='0') i++;
		j=0;
		while(b[j]=='0') j++;
		i++; j++;
		c=inter(a,b,i,j);
		x=0;
		c=compress(c,x);
		c="1"+c;
//		cout<<"c:"<<endl<<c<<endl;

		while(c.size()%4>0) c="0"+c;

		cout<<"Image "<<cc<<":"<<endl;
		cout<<toHex(c)<<endl;
		cc++;
	}
	return 0;
}