#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <chrono>

bool annihilates(char &first, char &second)
{
    if (std::tolower(first) == std::tolower(second)) {
        // Base char is the same
        if ((std::isupper(first) && std::islower(second)) ||
            (std::islower(first) && std::isupper(second))) {
            // Polarised
            return true;
        }
    }
    return false;
}

int reactPolymer(std::string &polymer, char ignored = 0)
{
    std::stack<char> stack;
    for (auto &i : polymer)
    {
        if (i == ignored || i == toupper(ignored)){
            continue;
        }
        else if (stack.empty()) {
            stack.push(i);
        }
        else if (annihilates(stack.top(), i)) {
            stack.pop();
        }
        else {
            stack.push(i);
        }
    }
    return stack.size();
}

int main()
{
    std::string polymer;
    std::cin >> polymer;

    // Star 1
    auto start = std::chrono::high_resolution_clock::now();
    int reactedLength = reactPolymer(polymer);

    auto mid = std::chrono::high_resolution_clock::now();
    auto star1Time = std::chrono::duration_cast<std::chrono::duration<double>>(mid - start);
    std::cout << "Star1: Polymer length: " << reactedLength
              << ". Time taken: " << star1Time.count() << std::endl;

    // Star 2
    char minChar = 'a';
    int min = reactedLength;
    
    for (char ch = 'a'; ch <= 'z'; ++ch){
        int length = reactPolymer(polymer, ch);

        //std::cout << new_stack->size() << std::endl;
        if (length < min){
            min = length;
            minChar = ch;
        }
    }
    
    auto finish = std::chrono::high_resolution_clock::now();
    auto star2Time = std::chrono::duration_cast<std::chrono::duration<double>>(finish - mid);
    std::cout << "Star2: Polymer length after removing " << minChar << ": " << min
              << ". Time taken: " << star2Time.count() << std::endl;
}
