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
	if(n==0)          //n=0ʱֱ�ӷ���1
	{
		string s="1";
		return s;
	}
	for(int i=0;i<R.size();++i)//�ж�С����λ��
	{
		if(R[i]=='.')
			accout1=i;
	}
	
	while(accout1==0&&R[R.size()-1]=='0')//������Ϊ.0100�������ʱ����ȥβ����0
	{
	
		R=R.substr(0,R.size()-1);
		if(R.size()==1)
			break;
	}

	while(accout1!=0&&R[R.size()-1]=='0')//��ȥ0.100���������ĩβ��0
	{
		if(accout1==-1)
			break;
		R=R.substr(0,R.size()-1);
		if(R.size()==1)
			break;
	}

	if(accout1==1&&R.size()==2)//��ȥ��Ϊ'1.'�����������'.'��ȥ������С�����־λ��0
	{
		R=R.substr(0,R.size()-1);
		accout1=0;
	}
	if(R[R.size()-1]=='.')//??????//��ȥĩβΪ��.���������
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
	if(R.size()==0)//ֻʣ��0�����
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
	for(int i=0;i<R.size();++i)//�ж�С����λ��
	{
		if(R[i]=='.')
			accout1=i;
	}

	int n1=R.size();//�����ĳ���
	int t1_r=accout1;//��¼С�����λ��
	
	int t2_r=R.size()-t1_r-1;//��¼С���ĸ���
	int t3_r=R.size()-1;//��������г�ȥС����ĸ���
	if(t1_r==-1)
	{
		t2_r=0;
		t3_r=R.size();
	}

	//string *s=new string[t3_s];
	for(string::iterator it=R.begin();it!=R.end();++it)//��string�е�С����ȥ�����ý��м���
	{
		if(*it=='.')
		{
			R.erase(it);
		}
	}

	vector<int> result;
	vector<char>result1;	
	int L=0;//��¼�Ѿ��˷��Ĵ���
	
	
	while((L+1)<n)
	{
		int n2=sum[L].size();//sum�ĳ���
		int accout2=-1;
		for(int i=0;i!=n2;i++)//��¼sum��С����λ��
		{
			if(sum[L][i]=='.')
			{
				accout2=i;
				break;
			}
		}
	
		int t1_s=accout2;//��¼С�����λ��
		int t2_s=sum[L].size()-t1_s-1;//��¼С���ĸ���
		int t3_s=sum[L].size()-1;//��������г�ȥС����ĸ���
		if(t1_s==-1)
		{
			t2_s=0;
			t3_s=sum[L].size();
		}

		int m=t2_r+t2_s;//��¼��ǰ�˷��ĳ����뱻����һ���е�С����λ��
		vector<string> s(t3_r);//���ɽ��г˷�����ʱ��Ҫ���еĴ�����string����

		for(string::iterator it=sum[L].begin();it!=sum[L].end();++it)
		{
			if(*it=='.')
			{
				sum[L].erase(it);//��sum�е�С����ɾ��
			}
		}


		
		for(int i=t3_r-1;i>=0;--i)//sum*R��ÿһλ�Ľ����*s�д洢
		{	
			int temp1=0;//��¼��λ
			for(int j=t3_s-1;j>=0;--j)
			{	
				int temp=0;
				temp=(sum[L][j]-48)*(R[i]-48)+temp1;//Ҫ�����Ŷ�Ӧ������ת����int�͵�����
				if(temp<=9)
				{
					s[i].push_back(biao[temp]);
					temp1=0;
					//s[i][j]=biao[temp];
				}
				else
				{
					temp1=temp/10;
					s[i].push_back(biao[temp%10]);//��ֵ���ɹ���
					if(j==0&&(temp>9))
					{
						s[i].push_back(biao[temp1]);
					}	
				}
			}
			reverse(s[i].begin(),s[i].end());//�������Ľ����ת
			for(int p=0;p<t3_r-i-1;++p)//���ó��������㷨�򣬽�����λ����
				s[i].push_back(biao[0]);
			reverse(s[i].begin(),s[i].end());
		}
		
		for(int i=t3_r-1;i>=0;--i)//��ÿһ�ж�������ӣ�ʹ����ΪΪ0
		{
			for(int j=s[i].size();j<s[0].size();++j)
			{	
				s[i].push_back(biao[0]);
			}
		}

		int reg,reg1;//reg1��¼��λ��  ���
		reg=reg1=0;
		for(int j=0;j<s[0].size();++j)//���� ÿλ���
		{
			int reg=0;
			for(int i=t3_r-1;i>=0;--i)
			{
				reg+=s[i][j]-48;//����ת��Ϊ����
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
				for(int ix=0;ix<=result.size();++ix)//���롮.�����Ž�ȥ
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