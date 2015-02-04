If you have an interface hierarchy and a corresponding implementation hierarchy, 
making the interface base classes virtual bases is necessary.

struct IBasicInterface
{
    virtual ~IBasicInterface() {}
    virtual void f() = 0;
};

struct IExtendedInterface : virtual IBasicInterface
{
    virtual ~IExtendedInterface() {}
    virtual void g() = 0;
};

// One possible implementation strategy
struct CBasicImpl : virtual IBasicInterface
{
    virtual ~CBasicImpl() {}
    virtual void f();
};

struct CExtendedImpl : virtual IExtendedInterface, CBasicImpl
{
    virtual ~CExtendedImpl() {}
    virtual void g();
};

Usually this only makes sense if you have a number of interfaces that extend the basic
interface and more than one implementation strategy required
 in different situations. This way you have a clear interface hierarchy and your
 implementation hierarchies can use inheritance to avoid the duplication
 of common implementations.
