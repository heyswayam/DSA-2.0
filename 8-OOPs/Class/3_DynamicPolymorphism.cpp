#include <iostream>

// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    virtual void makeSound()
    {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        std::cout << "Dog barks" << std::endl;
    }
    Dog(){
        std::cout<<"default constructor called"<<std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        std::cout << "Cat meows" << std::endl;
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
