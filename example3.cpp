#include <iostream>
#include <stdexcept>

void validateArguments(int argc)
{
    if(argc != 2)
    {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class my_logic_error : std::logic_error {

public:
    explicit my_logic_error(const char *arg) : logic_error(arg){}
    const char* what() const noexcept override {return(arg);}
private:
    const char *arg;
};


class Resource
{
public:
    void use(const char* arg)
    {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd')
        {
            throw my_logic_error("Passed d. d is prohibited.");
        }
    }
};

int main(int argc, char* argv[])
{
    validateArguments(argc);

    const char* argument = argv[1];
    Resource* rsc = nullptr;

    try
    {
        rsc = new Resource();
        rsc->use(argument);
        delete rsc;
    }
    catch (my_logic_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

