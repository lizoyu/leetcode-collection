#include <string>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // handle special inputs
        if (s.size() < 2)
            return s.size();

        // use a hash table to store the substring (char -> location)
        unordered_map<char, int> substr;

        // head, tail of the non-repeat substring, length of the longest substring
        int head = 0, tail = 1, max_length = 1;
        substr[s[0]] = 0;

        // loop through the string
        while (tail < s.size() && head < s.size()) {
            // check if the tail is included in the substring
            auto char_pos = substr.find(s[tail]);

            // yes, then shrink the substring
            if (char_pos != substr.end()){
                substr.erase(s[head]);
                head += 1;
            }
            // no, then expand the substring
            else {
                substr[s[tail]] = tail;
                tail += 1;

                // update the max length
                max_length = max(max_length, tail - head);
            }
        }

        return max_length;
    }
};

// driver
int main() {
    string s = "pwwkew";

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    system("pause");
    return 0;
}