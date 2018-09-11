"""
#3 - Longest Substring Without Repeating Characters (Medium)

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", which the length is 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

"""
def lengthOfLongestSubstring(self, s):
	"""
	:type s: str
	:rtype: int
	"""
	"""
	Loop through the string, use a dict to record char with location, use i and j to define a sliding
	window, repeatly move j forward, update i to previous char's location if new char is repated.
	Update recorded char's location and max string length accordingly.
	O(n) <- loop through s only once
	"""
	# deal with base case
	if not s:
		return 0
	if len(s) < 2:
		return len(s)

	i, j, maxlength = 0, 1, 1
	chars = {}; chars[s[i]] = i # use chars to record seen chars and their location
	while j <= len(s):
		# repeatly move j forward
		j += 1
		# update i if we encounter a repeated char, also repeated char itself
		if s[j] in chars:
			i = char[s[j]]
			char[s[j]] = j
		# update max length of sliding window
		maxlength = max(maxlength, len(s[i:j]))

	return maxlength
