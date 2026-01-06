// g++ source.cpp -o program

#include <iostream>
#include <vector>

// For every number inside of the array, add every other number and see if it = target.
class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            // i represents every number inside of nums.
            for (int i = 0; i < nums.size(); i++) {
                // Skips self comparisons and guarantees unique index pairs.
                // Starts at (i + 1) to never compare an element w/ itself and checks each unique pair only once.
                for (int j = (i + 1); j < nums.size(); j++) {
                    if (nums[i] + nums[j] == target) {
                        std::cout << "[" << i << "," << j << "]" << std::endl;
                        return {i, j};
                    }
                }
            }

            std::cerr << "\nNo solution found." << std::endl;
            return {}; // Empty vector = no solution.
        }
};

int main(int argc, char* argv[]) {
    std::vector<int> arguments;
    int target, temp_input;

    std::cout << "Target: ";
    std::cin >> target;

    std::cout << "\nInput any number of ints, stop input by inputting any non-int." << std::endl;
    while (std::cin >> temp_input) {
        arguments.push_back(temp_input);
    }

    // Clearing the failure state so we can keep using cin. Thank you CS3 lol.
    std::cin.clear();

    /*
    // Debugging, been a minute since I've used vectors without AI help :(
    std::cout << "\n***DEBUG*** You entered:\n";
    for (int v : arguments) {
        std::cout << v << " ";
    }
    */

    Solution sol;
    std::vector<int> result = sol.twoSum(arguments, target);

    std::cout << "\n\nProgram complete." << std::endl;
    return 0;
}