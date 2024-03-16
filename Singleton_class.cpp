/*
Write Singleton class. Only once instance can be created of this class.
This uses Static function and varibale.
*/


#include<iostream>
#include<algorithm>
using namespace std;

class Singleton {
    public:

        static Singleton* instance;  //  static variable
        int val;                    //  non-static variable

        // Constructor
        Singleton() {
            val = 10;
        }

        // static function can be defined inside or outside the class
        static Singleton* getInstance() {  
            if (instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }

        // if function is defined outside the class, then its declaration should be as below
        // static Singleton* getInstance();

};
// static variable should be defined outside the class
Singleton* Singleton::instance = nullptr;   

/* Static function defined outside class as below. This is also allowed.
Singleton* Singleton::getInstance() {
            if (Singleton::instance == nullptr){
                Singleton::instance = new Singleton();
            }
        return Singleton::instance;
    }
*/

int main() {

    // static function can be called by using object or without object as below
    Singleton* s = Singleton::getInstance();     // without object
    //Singleton* s = s->getInstance();       // with object.
    std::cout << "Printing value = " << s->val << std::endl;

    return 0;

}



