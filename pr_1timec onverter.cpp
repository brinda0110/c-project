#include<iostream>
using namespace std;
void second()
{
	int second;
	cout<<"enter total seconds:";
	cin>>second;
	int h,m,s;
	h=second/3600;
	m=second%3600/60;
	s=second%60;
	cout<<"HH:MM:SS=>"<<h<<":"<<m<<":"<<s;
	cout<<endl;
}
void hour()
{
	int hour,min,sec;
	cout<<"enter hour:";
	cin>>hour;
	cout<<"enter min:";
	cin>>min;
	cout<<"enter sec:";
	cin>>sec;
	
	int h=(hour*3600)+(min*60)+(sec);
	cout<<"total seconds:"<<h;

}
int main()
{
	second();
	hour();
}
/*
enter total seconds:4200
HH:MM:SS=>1:10:0
enter hour:4
enter min:34
enter sec:30
total seconds:16470
*/
                   