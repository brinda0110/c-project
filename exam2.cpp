#include<iostream>
using namespace std;
class employee
{
   private:
   char name[50];
   int salary;
   char designation[50];
   
   public:
   void setdata()
   {
   	cout<<"enter name:";
   	cin>>name;
   	cout<<"enter salary:";
   	cin>>salary;
   	cout<<"enter designation:";
   	cin>>designation;
   	cout<<endl;
	   }	
	   
	void getdata()
	{
		cout<<"name:"<<name<<endl
		<<"salary:"<<salary<<endl
		<<"designation:"<<designation<<endl;
	   }   
};

int main()
{
	employee e1,e2;
	e1.setdata();
	e2.setdata();
	e1.getdata();
	e2.getdata();
	}
	
/*output:
enter name:raja
enter salary:200000
enter designation:rampur

enter name:ram
enter salary:23000
enter designation:surat

name:raja
salary:200000
designation:rampur

name:ram
salary:23000
designation:surat
*/