#include <iostream>
#include <chrono>
#include <memory>

struct Partner {};

std::size_t getCurrentTime()
{
    return std::chrono::system_clock::now().time_since_epoch().count();
}

bool process()
{
    if (getCurrentTime() % 17 == 0) throw 17;
    return true;
}

bool processSecond()
{
	if (getCurrentTime() % 2) throw 3.14;
	return true;
}

void convertMe()
{
    //Partner* pFirst = new Partner();
    std::unique_ptr<Partner> pFirst(new Partner());

    process();

//    Partner* pSecond = new Partner();
    std::unique_ptr<Partner> pSecond(new Partner());

    processSecond();

    process();
}

int main()
{
    try
    {
        convertMe();
    }
    catch(int i)
    {
        std::cout << "Ups: " << i << std::endl;
    }
    catch(double d)
    {
        std::cout << "Ups: " << d << std::endl;
    }
    return 0;
}
