#include <iostream>
#include <vector>

// For every number inside of the array, add every other number and see if it = target.
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Loop represents every number inside of nums.
        for (int i = 0; i < nums.size(); i++) {
            // Another loop to check nums[i] vs every other number in list.
            for (int j = 0; j < nums.size(); j++) {
                // If the address is the same for both nums[i] & nums[j], skip that part of the loop.
                if (&nums[i] == &nums[j]) continue;

                int result = nums[i] + nums[j];

                if (result == target) {
                   std::cout << "[" << i << "," << j << "]" << std::endl;
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> arguments;
    int num_elements, target;

    std::cout << "Target: ";
    std::cin >> target;
    std::cout << "\nNumber elements: ";
    std::cin >> num_elements;

    for (int i = 0; i < num_elements; i++) {
        std::cin >> arguments[i];
    }
}