#include <iostream>
using namespace std;
// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << std::endl;
    }
    virtual ~Animal(){
        cout<<"animal is deleted"<<std::endl;;
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << "Dog barks" << std::endl;
    }
    Dog(){
        cout<<"default constructor called"<<std::endl;
    }
    ~Dog(){        //weather u write virtual or not, dog will be called, coz ~Animal() has virtual
        cout<<"Dog is deleted"<<std::endl;;
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        cout << "Cat meows" << std::endl;
    }
    ~Cat(){
        cout<<"Cat is deleted"<<std::endl;
    }
};

void sound(Animal *animal)
{
    animal->makeSound(); //Polymorphic
    // animal->makeSound() is behaving as per required object allocated at runtime
}

int main()
{
    // Animal *animal = new Dog();
    Animal *animal = new Dog;

    sound(animal);
    delete animal;

    animal = new Cat;
    sound(animal);
    delete animal;



    // Animal *animalPtr;
    // Dog dogObj;
    // Cat catObj;

    // animalPtr = &dogObj;
    // animalPtr->makeSound(); // Output: "Dog barks"

    // // animalPtr = &catObj;
    // // animalPtr->makeSound(); // Output: "Cat meows"

    return 0;
}
