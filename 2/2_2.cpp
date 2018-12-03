#include <iostream>
#include <map>
#include <string>
#include <vector>

bool stringdiff(std::string &string1, std::string &string2)
{
    int c = 0;
    auto it1 = string1.begin();
    auto it2 = string2.begin();

    for (;it1 != string1.end(); ++it1, ++it2)
    {
        if (*it1 != *it2)
            ++c;
        if (c > 1)
            break;
    }
    
    if (c == 1)
        return true;
    else
        return false;
}



int main()
{
    std::string id;
    std::vector<std::string> ids;
    while (std::cin >> id)
    {
        ids.push_back(id);
    }

    for (auto i = ids.begin(); i != ids.end(); ++i)
    {
        for (auto j = i + 1; j != ids.end(); ++j)
        {
            if (stringdiff(*i, *j))
            {
                std::cout << *i << " - " << *j << std::endl;
                break;
            }
        }
    }
}

