#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include "singleton_class.cpp"

void Test()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto& a = Singleton::Instance();
    std::cout << &a << std::endl;
}

/*
    Singleton은 보통 쓰지 말자고 (혹은 신중하게 사용하자고) 권해지고 있습니다.
    참고 : https://softwareengineering.stackexchange.com/questions/40373/so-singletons-are-bad-then-what
*/

int main()
{
    std::cout << "Start!" << std::endl;
    std::vector<std::thread> vec;
    for (int i = 0; i < 800; ++i)
        vec.emplace_back(Test);
    for (auto &elem : vec)
        elem.join();
}
