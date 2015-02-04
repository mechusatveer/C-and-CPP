class Base1 {  
public:  
    Base1();  
    virtual ~Base1();  
    virtual void speakClearly();  
    virtual Base1 *clone() const;  
protected:  
    float data_Base1;  
};  

class Base2 {  
public:  
    Base2();  
    virtual ~Base2();  
    virtual void mumble();  
    virtual Base2 *clone() const;  
protected:  
    float data_Base2;  
};  

class Derived : public Base1, public Base2 {  
public:  
    Derived();  
    virtual ~Derived();  
    virtual Derived *clone() const;  
protected:  
    float data_Derived;  
}; 

Base1 memory layout
-------------------
Base1 vtable  -------------->         type_info for Base1
Base1 data member                     Base1::~Base1()
                                      Base1::speakClear()
                                      Base1::clone()
Base2 memory layout
-------------------
Base2 vtable  -------------->         type_info for Base2
Base2 data member                     Base2::~Base2()
                                      Base2::mumble() 
                                      Base2::clone()
Derived memory layout
---------------------

Base1 subobject--------------> Derived vtable(shared with Base1)
                               type_info of Derived
                               Derived::~Derived()
                               Base1::speakClear()
                               Derived::clone()
                               Base2::mumble()
Base2 subobject-------------->Derived/Base2 vtable
                              type_info of Derived
                              Derived::~Derived()
                              Base2::mumble()
                              Derived::clone()
                              
data_Derived
