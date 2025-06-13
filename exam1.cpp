#include<iostream>
using namespace std;
class rectangle
{
	private:
		int length;
		int width;
		
	public:
	 void setdata()
	 {
	 	cout<<"enter value of length:";
	 	cin>>length;
	 	cout<<"enter value of width:";
	 	cin>>width;
	 	cout<<endl;
		 }	
	
	
	void getdata()
	{
		cout<<"enter length:"<<length<<endl
		<<"enter width:"<<width<<endl;
		cout<<"area of rectangle:"<<length*width<<endl;
		 }	 
};
int main()
{
	rectangle r1;
	r1.setdata();
	r1.getdata();
	}
	
	
/*output:
enter value of length:12
enter value of width:12

enter length:12
enter width:12
area of rectangle:144
*/