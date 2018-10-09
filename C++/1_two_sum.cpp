#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numskeep;
        for(int i = 0; i != nums.size(); ++i){
            auto iter = numskeep.find(nums[i]);
            if(iter != numskeep.end()){
                vector<int> res = {iter->second, i};
                return res;
            }
            else{
                numskeep[target - nums[i]] = i;
            }
        }
    }
};