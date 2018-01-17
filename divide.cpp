#include<stdio.h>
#include<stdlib.h>
#include <string>// 注意是<string>，不是<string.h>，带.h的是C语言中的头文件
#include<iostream>
#include<math.h>
using namespace std;
string a, b;  // 用来存放相乘的两个多位数字
long long ssum[100];
class _sum
{
	public:
		long sum0;
		int exponent;
};
_sum con_sum[100];
long strtonumbertransform(string str,int n)           // 传过来待转换的字符串与字符串长度
{
	long sum = 0;
	for (int i = 0; i < str.size(); i++)      //位数低于long类型的数字字符串，全部可以转换
	{
	//	cout << str[i] << endl;
	//	printf("%d\n", int(str[i]));
		long number = long(str[i]) - 48;
		if (number < 0)
		{
			cout << "wrong answer1" << endl;
		}
	//	printf("%d\n", number);
		if (sum + number*pow(10, n - i - 1)< 0)
		{
			cout << "wrong answer3" <<sum<< endl;
		}
		sum += number*pow(10,n-i-1);
	}
//	cout <<"number:"<< sum << endl;
	if (sum < 0)
	{
		cout << "wrong answer2" << endl;
	}
	return sum;
}
string deal(string str1,string str2,int length1,int length2)
{
   	 string t[100];
	 int _expoent[100];
	 string sum;
	 int m=0;
	 for (int i = 0; i < length1; i+=4)
	 {
			string s1;
			int array_elements = 0;
			if (i + 3 <= length1)
			{
				 s1 = str1.substr(i,4);                             //取出长度为4的字串
		//		 cout << s1 << endl;
			}
			else
			{
				s1 = str1.substr(i,length1-i);
			}
			for (int j = 0; j < length2; j+=4)
			{
				if (j + 3 <= length2)
				{
					string	s2;
					s2 = str2.substr(j,4);
		//		cout << s2 << endl;
					con_sum[j].sum0 = strtonumbertransform(s1, 4)*strtonumbertransform(s2, 4);         //相乘    
		//			cout << con_sum[j].sum0 << endl;
	//				cout << con_sum[i].sum0 << endl;
					con_sum[j].exponent = length1 - i - 4 + length2 - j - 4;     //取出其对应的位数
	//				cout << length1 - i - 4 << " " << length2 - j - 4 << " " << con_sum[j].exponent << endl;
					array_elements+=4;
				}
				else
				{
					cout << "succeed" << endl;
					string s2;
					s2 = str2.substr(j, length2-j);
		//			cout << s2 << endl;
	//				cout << con_sum[j].sum0 << endl;
					con_sum[j].sum0 = strtonumbertransform(s1, 4)*strtonumbertransform(s2, 4);         //相乘    
					con_sum[j].exponent = length1 - i - 4 + length2 - j - 1-4;     //取出其对应的位数
					array_elements+=4;
				}
			}
	//		cout <<"array_elements: "<< array_elements << endl;
			string s;
			for (int k = array_elements; k >0; k -= 4)
			{
		//		cout << "number1: " << con_sum[k].sum0 << "number2: " << con_sum[k-4].sum0 << endl;
				con_sum[k - 4].sum0 += con_sum[k].sum0 / 10000;
	//			cout << "jin wei: " << con_sum[k - 4].sum0 << endl;
				con_sum[k].sum0 = con_sum[k].sum0 % 10000;
	//			cout << "sheng yu: " << con_sum[k].sum0 << endl;
	//			s += to_string(con_sum[k].sum0);          //把每一组乘积填入字符串
		//		cout <<"total string"<< s << endl;
			}
			
			for (int u = 0; u < array_elements; u+=4)
			{
				if (con_sum[u].sum0 < 1000 && con_sum[u].sum0 >100)
				{
					string str0;
					str0 = "0" + to_string(con_sum[u].sum0);
					s += str0;
				}
				else if (con_sum[u].sum0 < 100 && con_sum[u].sum0 >10)
				{
					string str0;
					str0 = "00" + to_string(con_sum[u].sum0);
					s += str0;	
				}
				else if (con_sum[u].sum0 < 10)
				{
					string str0;
					str0 = "000" + to_string(con_sum[u].sum0);
					s += str0;
				}
				else
				{
					s += to_string(con_sum[u].sum0);          //把每一组乘积填入字符串
				}
			}

	//		cout << "finished one" << endl;
			_expoent[m] = con_sum[array_elements-4].exponent;
	//		cout << _expoent[m] << endl;
			string _o;
			while (_expoent[m]> 0)
			{
				
				_o += "0";
				_expoent[m]--;
			}
			t[m].append(s + _o);
	//		cout << "after get 0 on the behind" << t[m] << endl;
			m++;
	 }
	 /*
			在处理乘积运算得到了m个string串存放到t数组里，然后需要将它们求和，进位之类的处理	 
	 */
	 for (int iii = 0; iii<m; iii++)
	 {
		 cout << t[iii] << endl;
	 }

	 int ss = t[0].size()/6;          //此为最大的那个字符串
	 int w = ss;
	 //cout <<"t[0].size"<< t[0].size() << endl;
	 if (t[0].size() % 6 > 0)
	 {
		 ss = ss + 1;  //查看它可以分成多少组10个字符
		 w = ss;
	 }
	 cout <<"ss: "<< ss << endl;
	 int s0 = ss,s10=0;				//s0用来记录到第n组，s1表示字符串遍历下标
	 while (ss>0)                                //开始计算每一组的和
	 {
		 for (int k = 0; k < m; k++)			//遍历每一个单独的乘积
		 {
			 if (int(t[k].size()) - s10 - 6>=0)			//每次取10个为一组
			 {
		//		 cout <<" string"<< t[k].substr(t[k].size() - s1 - 6, 6) << endl;
	//			 cout <<"字符串长度: "<<t[k].size()<<"计数器: "<<s10<<"字符串下标: " << int(t[k].size()) - s10 - 6 << endl;
				 cout << "number: " << strtonumbertransform(t[k].substr(t[k].size() - s10 - 6, 6), 6) << endl;
				 ssum[s0] += strtonumbertransform(t[k].substr(t[k].size() - s10 - 6, 6),6);
			 }
			 else if (int(t[k].size()) - s10 - 6 <0 && int(t[k].size()) - s10>0)
			 {
				 cout <<" 目前值"<< ssum[s0] << endl;
				 cout << int(t[k].size()) << endl;
				 cout << "预期 " << int(t[k].size()) - s10 - 6 << "当前 " << int(t[k].size()) - s10 << "数组标号 " << s10 << endl;
				 cout << "str: " << strtonumbertransform(t[k].substr(0, t[k].size() - s10), t[k].size() - s10) << endl;
				 cout << "once" << endl;
				 ssum[s0] += strtonumbertransform(t[k].substr(0, t[k].size() - s10),t[k].size()-s10);
			 }
			 else
			 {
				 ssum[s0] += 0;
			 }
		 }
		 cout << "ssum[s0-1]: " << ssum[s0 - 1] << " " << "ssum[s0]" << ssum[s0] << endl;
		 ssum[s0 - 1] += ssum[s0] / 1000000;
		 ssum[s0] = ssum[s0] % 1000000;
		 cout << "ssum[s0-1]: " << ssum[s0 - 1] << " " << "ssum[s0]" << ssum[s0] << endl;
		 cout << "one group" << endl;
		 s0--;
		 s10+= 6;
		 ss--;
	 }
	 cout << "done" << endl;
	 for (int i = 1; i <=w; i++)
	 {
		 if (ssum[i] < 100000&&ssum[i-1]!=0)
		 {
			 string str0;
			 int t = 0;
			 t = to_string(ssum[i]).size();
			 str0 =to_string(ssum[i]);
			 while (t <6)
			 {
				 str0 = "0" + str0;
				 t++;
			 }
			 //cout <<"insert: "<< str0 << endl;
			 sum += str0;
		 }
		 else
		 {
			 sum += to_string(ssum[i]);
		 }
	 }
	 return sum;
}

int main()
{
	int i, j, k, n=103;
	string sum;
//	printf("%d\n", n / 10);
	cin >> a >> b;
//	cout << a <<" "<< b<<" "<< a.size() <<" "<< b.size()<< endl;
//	sum=transform("12334", 5);
//	printf("%ld\n", sum);
	system("pause");
	sum=deal(a, b, a.size(), b.size());
	cout << sum << endl;
	system("pause");
	return 0;
}