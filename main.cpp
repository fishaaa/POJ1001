#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> power_fish(vector<int> num1,vector<int>num2)
{
	vector<int> temp;
	for(int i=0;i<num1.size()+num1.size()+1;++i)
		temp.push_back(0);
	for(int i=0;i<num1.size();++i)
	{
		for(int j=0;j<num2.size();++j)
		{
			temp[i+j]+=num1[i]*num2[j];//每位对应相乘
			temp[i+j+1]+=temp[i+j]/10;//有进位则进位
			temp[i+j]%=10;//当前位取余
		}
	}
	return temp;
}

int main()
{
	string R;
	int n;
	while(cin>>R>>n)
	{	
		int point=0; //判断是否有小数点
		int point_s=-1; //记录小数点的位置
		for(int i=0;i<R.size();++i)//记录小数点
		{
			if(R[i]=='.')
			{
				point_s=i;
				point=1;
			}
		}
		while(point==1&&(R[R.size()-1]=='0'))//将小数点后的无意义的0删除,当最后一位为小数点时，也将小数点删除
		{
			R=R.substr(0,R.size()-1);
		}
		if(R[R.size()-1]=='.')
		{
			R=R.substr(0,R.size()-1);
		}
		point=0;
		for(int i=0;i<R.size();++i)//将R变形后，再一次重新记录R的情况
		{
			if(R[i]=='.')
			{
				point_s=i;
				point=1;
			}
		}
	
		int point_num=R.size()-1-point_s;
		if(point==0)
			point_num=0;
		point_num*=n;//对于n次幂，小数点的个数

		for(string::iterator it=R.begin();it!=R.end();++it)//将string中的小数点去除，好进行计算
		{
			if(*it=='.')
			{
				R.erase(it);
			}
		}
		if(R.size()==1&&R[0]=='0')
		{
			cout<<"0"<<endl;
			continue;
		}
		vector<int> s;
		
		for(int i=0;i<R.size();++i) //将string转换成 vector<int>;
		{
			s.push_back(R[i]-'0');
		}
		int zeros=0;//记录去除小数点后，数末尾为0的数
		while(s[s.size()-1]==0)
		{
			s.pop_back();
			++zeros;
		}
		zeros*=n;
		int L=1;
		vector <int>ss;
		for(int i=s.size()-1;i>=0;--i)
		{
			ss.push_back(s[i]);
		}
		vector<int>result_temp=ss;
		vector<int> result1;
		if(n==0)
		{
			result1.push_back(1);
			cout<<result1[0]<<endl;
			continue;
		}
		while(L<n)
		{
			result_temp=power_fish(result_temp,ss);
			while(result_temp[result_temp.size()-1]==0)
				result_temp.pop_back();
			++L;
		}
		vector <int> result;
		for(int i=result_temp.size()-1;i>=0;--i)
		{
			result.push_back(result_temp[i]);
		}
		for(int i=0;i<zeros;++i)//将删除后的0添回来
		{
			result.push_back(0);
		}
		while(result_temp[0]==0)
		{
			result.erase(result.begin());
		}
		
		if(point_num!=0)
		{
			if(point_num>=result.size())
			{	
				while(result[result.size()-1]==0)
					result.pop_back();
				cout<<".";
				int t=point_num-result.size();
				while(t>0)
				{
					cout<<"0";
					--t;
				}
				for(int i=0;i<result.size();++i)
					cout<<result[i];
			}
			else
			{
				
				for(int i=0;i<result.size()-point_num;++i)
				{
					cout<<result[i];
				}
				cout<<".";
				for(int i=result.size()-point_num;i<result.size();++i)
				{
					cout<<result[i];
				}
			}
		}
		else
		{
			for(int i=0;i<result.size();++i)
					cout<<result[i];
		}
		cout<<endl;
	}
	system("PAUSE");
	return 0;
}