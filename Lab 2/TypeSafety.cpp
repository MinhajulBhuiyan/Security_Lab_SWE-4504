#include <bits/stdc++.h>

using namespace std;

class Duck 
{
    bool rubber;
public:
    
    Duck() : rubber(false) {}  
    virtual ~Duck() 
    { 
        cout << "Duck destroyed" << endl;
    }
    void setRubber(bool value) 
    {
        rubber = value;
    }
    void quack() const 
    {
        if (rubber) 
            cout << "Artificial Quack" << '\n';
        else 
            cout << "Real Quack" << '\n';
    }
};

class RubberDuck : public Duck 
{
public:
    RubberDuck() 
    {
        setRubber(true);
    }
    ~RubberDuck() 
    {
        cout << "RubberDuck destroyed" << endl;
    }
};

class RealDuck : public Duck 
{
public:
    RealDuck() 
    {
        setRubber(false);
    }
    ~RealDuck() 
    { 
        cout << "RealDuck destroyed" << endl;
    }
};

// Template function
template<typename T>
void processData(const T& data) 
{
    if (is_same<T, int>::value) 
    {
        cout << "Integer: " << data << endl;
    } 
    else if (is_same<T, double>::value) 
    {
        cout << "Double: " << data << endl;
    } 
    else 
    {
        cout << "Unknown type!" << endl;
    }
}

int main() 
{
    int i = 42;
    double d = 3.14;

    processData(i);  
    processData(d);  

    Duck* d1 = new RubberDuck();
    Duck* d2 = new RealDuck();

    //d1->quack();  
    //d2->quack(); 
    RealDuck *rd = static_cast<RealDuck*>(d1);
    //RealDuck *rd = dynamic_cast<RealDuck*>(d1);
    
    if(rd)rd->quack();
    else cout<<"Casting Error"<<'\n';


    delete d1;
    delete d2;

    return 0;
}
