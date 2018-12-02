#include <iostream>
#include <vector>
#include <set>

int main()
{
    // Build a vector of the inout so we can loop repeatedly
    std::vector<int> deltas;
    int num;
    while (std::cin >> num){
        deltas.push_back(num);
    }

    // Set to store the frequencies we see
    int total = 0;
    std::set<int> frequencies;

    for (auto iter = deltas.begin(); ; ++iter)
    {
        if (iter == deltas.end()){
            // Reached the end, let's loop again
            iter = deltas.begin();
        }
        
        total += *iter;
        // If we fail to insert a new elemtnt to the set, we've hit a repetition
        if (auto [iter, inserted] = frequencies.insert(total); !inserted)
        {
            std::cout << "Repeated frequency: " << total << std::endl;
            break;
        }
    }
}
