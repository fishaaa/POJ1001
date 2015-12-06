#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
string power_fish(string R,int n);
int main()
{
	string R;
	int n;
	while(cin>>R>>n)
	{
		string s;
		s=power_fish(R,n);
		int len=s.size();
		if(len==1)
		{
			cout<<s;
			cout<<endl;
		}
		else if(s[0]=='0'&&s[1]=='.')
		{
			s=s.substr(1,s.size());
			cout<<s;
			cout<<endl;
		}
		else
			cout<<s;
			cout<<endl;
	}
	system("PAUSE");
	return 0;

}
string power_fish(string R,int n)
{
	string biao="0123456789";
	//string qq=R;
	int accout1=-1;
	if(n==0)          //n=0时直接返回1
	{
		string s="1";
		return s;
	}
	for(int i=0;i<R.size();++i)//判断小数点位置
	{
		if(R[i]=='.')
			accout1=i;
	}
	
	while(accout1==0&&R[R.size()-1]=='0')//当输入为.0100这种情况时，除去尾部的0
	{
	
		R=R.substr(0,R.size()-1);
		if(R.size()==1)
			break;
	}

	while(accout1!=0&&R[R.size()-1]=='0')//除去0.100这种情况下末尾的0
	{
		if(accout1==-1)
			break;
		R=R.substr(0,R.size()-1);
		if(R.size()==1)
			break;
	}

	if(accout1==1&&R.size()==2)//除去后为'1.'这种情况，将'.'除去，并将小数点标志位置0
	{
		R=R.substr(0,R.size()-1);
		accout1=0;
	}
	if(R[R.size()-1]=='.')//??????//除去末尾为‘.’这种情况
	{
		R=R.substr(0,R.size()-1);
	}
	while(accout1==0&&R.size()!=0)
	{
		int i=0;
		if(R[i]==0)
		{
			R=R.substr(1,R.size());
		}
		else
		{
			break;
		}
	}
	if(R.size()==0)//只剩下0的情况
	{
		string s="0";
		return s;
	}

	while(R[0]=='0'&&R.size()!=1)
	{
		R=R.substr(1,R.size());
	}
	
	if(R[0]=='0'&&R.size()==1)
	{
		string s="0";
		return  s;
	}
	
	vector <string> sum(n);
	sum[0]=R;
	accout1=-1;
	for(int i=0;i<R.size();++i)//判断小数点位置
	{
		if(R[i]=='.')
			accout1=i;
	}

	int n1=R.size();//乘数的长度
	int t1_r=accout1;//记录小数点的位置
	
	int t2_r=R.size()-t1_r-1;//记录小数的个数
	int t3_r=R.size()-1;//输入的数中除去小数点的个数
	if(t1_r==-1)
	{
		t2_r=0;
		t3_r=R.size();
	}

	//string *s=new string[t3_s];
	for(string::iterator it=R.begin();it!=R.end();++it)//将string中的小数点去除，好进行计算
	{
		if(*it=='.')
		{
			R.erase(it);
		}
	}

	vector<int> result;
	vector<char>result1;	
	int L=0;//记录已经乘法的次数
	
	
	while((L+1)<n)
	{
		int n2=sum[L].size();//sum的长度
		int accout2=-1;
		for(int i=0;i!=n2;i++)//记录sum中小数点位置
		{
			if(sum[L][i]=='.')
			{
				accout2=i;
				break;
			}
		}
	
		int t1_s=accout2;//记录小数点的位置
		int t2_s=sum[L].size()-t1_s-1;//记录小数的个数
		int t3_s=sum[L].size()-1;//输入的数中除去小数点的个数
		if(t1_s==-1)
		{
			t2_s=0;
			t3_s=sum[L].size();
		}

		int m=t2_r+t2_s;//记录当前乘法的乘数与被乘数一共有的小数点位数
		vector<string> s(t3_r);//生成进行乘法运算时需要进行的次数的string数组

		for(string::iterator it=sum[L].begin();it!=sum[L].end();++it)
		{
			if(*it=='.')
			{
				sum[L].erase(it);//将sum中的小数点删除
			}
		}


		
		for(int i=t3_r-1;i>=0;--i)//sum*R的每一位的结果在*s中存储
		{	
			int temp1=0;//记录进位
			for(int j=t3_s-1;j>=0;--j)
			{	
				int temp=0;
				temp=(sum[L][j]-48)*(R[i]-48)+temp1;//要将符号对应的数字转化成int型的数字
				if(temp<=9)
				{
					s[i].push_back(biao[temp]);
					temp1=0;
					//s[i][j]=biao[temp];
				}
				else
				{
					temp1=temp/10;
					s[i].push_back(biao[temp%10]);//赋值不成功？
					if(j==0&&(temp>9))
					{
						s[i].push_back(biao[temp1]);
					}	
				}
			}
			reverse(s[i].begin(),s[i].end());//将乘数的结果反转
			for(int p=0;p<t3_r-i-1;++p)//利用乘数的运算法则，进行移位处理。
				s[i].push_back(biao[0]);
			reverse(s[i].begin(),s[i].end());
		}
		
		for(int i=t3_r-1;i>=0;--i)//是每一行都进行相加，使多余为为0
		{
			for(int j=s[i].size();j<s[0].size();++j)
			{	
				s[i].push_back(biao[0]);
			}
		}

		int reg,reg1;//reg1记录进位数  求和
		reg=reg1=0;
		for(int j=0;j<s[0].size();++j)//对齐 每位相加
		{
			int reg=0;
			for(int i=t3_r-1;i>=0;--i)
			{
				reg+=s[i][j]-48;//符号转化为数字
			}
			reg=reg+reg1;
			if(reg<=9)
			{
				result.push_back(reg);
				reg1=0;
			}
			else
			{
				reg1=reg/10;
				reg=reg%10;
				result.push_back(reg);
			}
			if(j==s[0].size()&&reg1!=0)
			{
				result.push_back(reg1);
			}

		}

		//reverse(result.begin(),result.end());
		if(m!=0)
		{
			if(m>result.size())
			{
				for(int ix=0;ix<result.size();++ix)
				{
					result1.push_back(biao[result[ix]]);
				}
				for(int ix=result.size();ix<m;++ix)
				{
					result1.push_back('0');
				}
				result1.push_back('.');
			}
			else
			{
				for(int ix=0;ix<=result.size();++ix)//插入‘.’符号进去
				{
			

					if(ix<m)
					{
						result1.push_back(biao[result[ix]]);
					}
					else if(ix>m)
					{
						result1.push_back(biao[result[ix-1]]);
					}
					else
					{
						result1.push_back('.');
				
					}
				}
			}
		}
		else
		{
			for(int ix=0;ix<result.size();++ix)
				result1.push_back(biao[result[ix]]);	
		
		}
		reverse(result1.begin(),result1.end());
		++L;
		for(int ix=0;ix<result1.size();++ix)
		{
			sum[L].push_back(result1[ix]);
		} 
	result.erase(result.begin(),result.end());
	result1.erase(result1.begin(),result1.end());
	}
	string sum1=sum[n-1];
	return sum1;
}