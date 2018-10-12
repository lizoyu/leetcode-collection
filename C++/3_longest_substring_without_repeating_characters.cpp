#include <string>
#include <unordered_map>
#include <algorithm>
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
        while (tail < s.size()) {
            // check if the tail is included in the substring
            auto search_char = substr.find(s[tail]);

            // yes, then shrink the substring
            if (search_char != substr.end())
                head = s[tail] + 1;
            // no, then expand the substring  
            else
                tail += 1;

            // update the hash table
            substr[s[tail]] = tail;

            // update the max length
            max_length = max(max_length, tail - head);
        }

        return max_length;
    }
};

// driver
int main() {

}