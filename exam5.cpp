#include <iostream>
using namespace std;

class Employee
 {
private:
    string name;
    int salary;

public:
    Employee() : name(""), salary(0) {}

    Employee(const string& n, int s) : name(n), salary(s) {}

    int getSalary()  {
        return salary;
    }

    string getName()  {
        return name;
    }

    
    int operator+(const Employee& other) const {
        return this->salary + other.salary;
    }
};

int main() 
{
    Employee emp1("ram", 50000);
    Employee emp2("Bobby", 60000);

    int totalSalary = emp1 + emp2;  

    cout << emp1.getName() << "' salary: " << emp1.getSalary() << endl;
    cout << emp2.getName() << " salary: " << emp2.getSalary() << endl;
    cout << "Total salary: " << totalSalary << endl;

   
}
/*output:
ram' salary: 50000
Bobby salary: 60000
Total salary: 110000
*/
	
