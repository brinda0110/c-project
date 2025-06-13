/*. Define an abstract class `Animal` with virtual functions `sound()` and `move()`. 
Implement concrete/normal classes `Dog` and `Bird` that inherit from `Animal`. 
Demonstrate polymorphism by creating an array of `Animal` pointers pointing to objects of both `Dog` and `Bird`.
 Call the `sound()` and `move()` functions for each object.*/
#include <iostream>
using namespace std;


class Animal 
{
public:
    virtual void sound() = 0; 
    virtual void move() = 0;   
   	virtual ~Animal() {}    
};


class Dog : public Animal
 {
public:
    void sound() 
	{
        cout << " Woof!" << endl;
    }
    void move() 
	{
        cout << "Dog run" << endl;
    }
};


class Bird : public Animal
{
public:
    void sound() 
	 {
        cout << " Tweet!" << endl;
    }
    void move() 
	{
        cout << "Bird flies" << endl;
    }
};

int main() 
{
   
    Animal* animals[4];
    
  
    animals[0] = new Dog();
    animals[1] = new Bird();
    animals[2] = new Dog();
    animals[3] = new Bird();
    
   
    for (int i = 0; i < 4; i++) 
	{
        animals[i]->sound();
        animals[i]->move();
        cout << "----" << endl;
    }
    
   
    for (int i = 0; i < 4; i++)
	 {
        delete animals[i];
    }
    
  
}

/*output:
 Woof!
Dog run
----
 Tweet!
Bird flies
----
 Woof!
Dog run
----
 Tweet!
Bird flies
----
*/
