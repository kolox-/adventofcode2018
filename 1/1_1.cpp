#include <iostream>

int main()
{
    int num;
    int total = 0;
    while (std::cin >> num){
        total += num;
    }
    std::cout << "Total: " << total << std::endl;
}
