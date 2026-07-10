#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        std::unordered_set<int> liste;

        for (int i = 0; i < nums.size(); i++) {
            if (liste.count(nums[i])) {
                return true;
            }
            liste.insert(nums[i]);
        }
        return false;
    }
};