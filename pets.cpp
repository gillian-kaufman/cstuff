// Program Assignment 6 - Polymorphic Pets Program P3
/* Add a virtual method called eat to the base class Pet
 this method should say "" in the base class of Pet
 then in dog class it should say "petname eats dog food"

 Add a new class Cat that inherits from Pet
 it should override the speak method to say "petname says 'Meow!'"
 it should override the eat method and say "petname eats cat food"
 it should override the sit method and say "petname sits proudly"

 add a new class Poodle that inherits from Dog
 it should override the sit virtual method and say "petname sits precisely"

 change the main program to do the following
 NO PROMPTS
 from standard input (cin)
    read an integer that represents the number of pets
    for each pet read in its type which will be a string - "pet", "dog", “poodle” or "cat" followed by the pet's name - string with no spaces
    create an array of pointers, maxium 100, to Pet objects for each pet that you read in

 once you've read in each pet and created a pet object and stored address in your array, read in a list of integers, one per line, and for each integer call the cooresponding pet's speak, eat and sit methods

 stop when user enters a number that is invalid (less than 1 or greater than number of pets)

 don't forget to destroy each of your dynamically created pet objects before you exit the Program

SAMPLE INPUT
4
dog fred
cat fretta
poodle pretty
dog fido
2
1
3
4
0

SAMPLE OUTPUT
fretta says 'Meow!'
fretta eats cat food
fretta sits proudly
fred says 'Bark!'
fred eats dog food
fred sits boldly
pretty says ‘Bark!’
pretty eats dog food
pretty sits precisely
fido says 'Bark!'
fido eats dog food
fido sits boldly

submit pets.cpp to codepost
complete form - https://form.jotform.com/200302477347046
*/

/*  Gillian Kaufman
 *  Program 6 - polymorphic pets
 *  Due date: April 25, 2020    */

#include <iostream>
#include <string>
using namespace std;
class Pet {
private:
    string pname;
public:

    Pet(const string& petName) : pname(petName) {}
    virtual string name() const { return pname; }
    virtual string speak() const { return ""; }
    virtual string sit() const { return ""; }
    virtual string eat() const { return ""; }
    virtual ~Pet() {}
};

class Dog : public Pet {
private:
    string name;
public:
    Dog(const string& petName) : Pet(petName) {}
    // New virtual function in the Dog class:
    string sit() const 
    {
        return Pet::name() + " sits boldly";
    }
    string eat() const 
    {
        return Pet::name() + " eats dog food";
    }
    string speak() const 
    { // Override
        return Pet::name() + " says 'Bark!'";
    }
    ~Dog() {}
};

class Cat : public Pet {
private:
    string name;
public:
    Cat(const string& petName) : Pet(petName) {}
    // New virtual function in the Cat class:
    string sit() const 
    {
        return Pet::name() + " sits proudly";
    }
    string eat() const 
    {
        return Pet::name() + " eats cat food";
    }
    string speak() const 
    { // Override
        return Pet::name() + " says 'Meow!'";
    }
    ~Cat() {}
};

class Poodle : public Pet 
{
private:
    string name;
public:
    Poodle(const string& petName) : Pet(petName) {}
    // New virtual function in the Poodle class:
    string sit() const 
    {
        return Pet::name() + " sits precisely";
    }
    string eat() const 
    {
        return Pet::name() + " eats dog food";
    }
    string speak() const 
    { // Override
        return Pet::name() + " says 'Bark!'";
    }
    ~Poodle() {}
};

// here's the logic that will solve the program assignment main()
#define MAXPETS 100

int main(int argc, char** argv) 
{ 
  // declare variables for number of pets, pet number selected name of pet and type of pet
    int i, numOfPets, pnumber;
    string pname, ptype;

  // also declare an array of pointers to class Pet - make it able to hold MAXPETS
    Pet* p[MAXPETS] = {};
 
  // read in number of pets from cin (standard input)
  // NO PROMPTS!
    cin >> numOfPets;

  // loop to input each pet type and pet name
    for (i = 0; i < numOfPets; ++i)
    {
        //inside loop create the appropriate type of pet based upon the pet type that you read in - this can be done with 4 if statements
        cin >> ptype >> pname;
        if (ptype == "pet")
        {
            p[i] = new Pet(pname);
        }
        else if (ptype == "dog")
        {
            p[i] = new Dog(pname);
        }
        else if (ptype == "cat")
        {
            p[i] = new Cat(pname);
        }
        else if (ptype == "poodle")
        {
            p[i] = new Poodle(pname);
        }
    }

  // input from cin the number that represents which pet the user wants to access
  // NO PROMPTS!
    cin >> pnumber;

  // loop until this number is invalid
    while (pnumber > 0 && pnumber <= numOfPets)
    {
        //inside of loop call the speak, eat, and sit methods of the pet and output what each one returns
        cout << p[pnumber - 1]->speak() << endl;
        cout << p[pnumber - 1]->eat() << endl;
        cout << p[pnumber - 1]->sit() << endl;
        //read the next number at the end of the loop
        cin >> pnumber;
    }

  // google how to destroy dynamically allocated objects in C++
  // you will need a loop to go thru the pet array and destroy each one
    for (i = 0; i < numOfPets; ++i)
    {
        delete p[i];
    }
    return 0;
}

