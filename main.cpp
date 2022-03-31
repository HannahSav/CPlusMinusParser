#include <iostream>
#include <string>
#include <float.h>

using namespace std;

struct Mixed{
    enum {Inty = 1, Floaty, Stringy} type;
    int inty;
    float floaty;
    string stringy;
    Mixed(int inty){
        this->type = Inty;
        this->inty = inty;
    }
    Mixed(string stringy){
        this->type = Stringy;
        this->stringy = stringy;
    }
    Mixed(float floaty){
        this->type = Floaty;
        this->floaty = floaty;
    }

    public: void print(){
         switch(type)
        {
        case 1: cout << this->inty << '\n'; break;
        case 2: cout << this->floaty << '\n'; break;
        case 3: cout << this->stringy << '\n'; break;
        }
    }
};

int main()
{
    float f = 1.12345;
    Mixed mixy = Mixed(123);
    Mixed mixy2 = Mixed(f);
    Mixed mixy3 = Mixed("4567rtyuio");
    mixy3.print();
    mixy2.print();
    mixy.print();
    return 0;
}
