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
			temp[i+j]+=num1[i]*num2[j];//ÿλ��Ӧ���
			temp[i+j+1]+=temp[i+j]/10;//�н�λ���λ
			temp[i+j]%=10;//��ǰλȡ��
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
		int point=0; //�ж��Ƿ���С����
		int point_s=-1; //��¼С�����λ��
		for(int i=0;i<R.size();++i)//��¼С����
		{
			if(R[i]=='.')
			{
				point_s=i;
				point=1;
			}
		}
		while(point==1&&(R[R.size()-1]=='0'))//��С�������������0ɾ��,�����һλΪС����ʱ��Ҳ��С����ɾ��
		{
			R=R.substr(0,R.size()-1);
		}
		if(R[R.size()-1]=='.')
		{
			R=R.substr(0,R.size()-1);
		}
		point=0;
		for(int i=0;i<R.size();++i)//��R���κ���һ�����¼�¼R�����
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
		point_num*=n;//����n���ݣ�С����ĸ���

		for(string::iterator it=R.begin();it!=R.end();++it)//��string�е�С����ȥ�����ý��м���
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
		
		for(int i=0;i<R.size();++i) //��stringת���� vector<int>;
		{
			s.push_back(R[i]-'0');
		}
		int zeros=0;//��¼ȥ��С�������ĩβΪ0����
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
		for(int i=0;i<zeros;++i)//��ɾ�����0�����
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