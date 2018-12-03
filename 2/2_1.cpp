#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string id;
    int total_twice = 0;
    int total_thrice = 0;

    while (std::cin >> id)
    {
        int tmp = 0;
        std::map<char, int> map;
        for (auto &i : id)
        {
            map[i] += 1;
            tmp += (int)i;
        }

        // bitfields are fun lmao
        int bitfield = 0;
        for (auto [j, k] : map)
        {
            if (k == 2)
                bitfield |= 1;
            if (k == 3)
                bitfield |= 1 << 1;
        }

        if ((bitfield & 1) == 1)
            total_twice += 1;
        if (bitfield & 1<<1)
            total_thrice += 1;
    }
    std::cout << total_twice * total_thrice << std::endl;
}
