Base class constructor destructor should be protected bcoz this class build only for instance purpose
there is no mean to create an object of this.



template <class Derived>
class InstanceCounter
{
    static int count;

protected:

    InstanceCounter()
    {
        ++count;
    }

    ~InstanceCounter()
    {
        --count;
    }

public:

    static int instance_count()
    {
        return count;
    }
};

template <class Derived>
int InstanceCounter<Derived>::count = 0;

class Test : public InstanceCounter<Test>
{
};

int main()
{
    Test x;
    std::cout << Test::instance_count() << std::endl;
    {
        Test y;
        Test z;
        std::cout << Test::instance_count() << std::endl;
    }
    std::cout << Test::instance_count() << std::endl;
}
