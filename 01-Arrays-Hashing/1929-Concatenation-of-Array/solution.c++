#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> liste;

        for (int i = 0; i < nums.size(); i++) {
            liste.push_back(nums[i]);
        }
        for (int y = 0; y < nums.size(); y++) {
            liste.push_back(nums[y]);
        }
        return liste;
    }
};
