#include <cstdio>
#include <memory>
#include <string>

using ShoppingList = std::shared_ptr<std::FILE>;

ShoppingList makeFile(const char* filename, const char* flags)
{
    /*Edit here*/
    auto file = std::fopen(filename, flags);
    return std::shared_ptr<std::FILE>(file);
}

class Partner
{
public:
    void addToFile(std::string element)
    {
        fprintf (shoppingList.get(), "%s" , element.c_str());
    }
    ShoppingList shoppingList;
};

int main()
{
    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");
    fclose(boy.shoppingList.get());
}
