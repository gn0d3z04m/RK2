#include <iostream>
class Singleton final
{
public:
    static Singleton& Instance()
    {
        // Thread safety since C++11 (VS2015) - Magic Statics
        static Singleton instance;
        return instance;
    }

    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

private:
    Singleton() { std::cout << "Lazy creation!" << std::endl; }
};

