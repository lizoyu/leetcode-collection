"""
#1 - Two Sum (Easy)

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].

"""
def twoSum(self, nums, target):
	"""
	:type nums: List[int]
	:type target: int
	:rtype: List[int]
	"""
	"""
	Use a hash table to save corresponding num for each num, and if encountered,
	we can find out its location in the hash table and return both.
	O(n) <- only loop through the list once
	"""
	if not nums:
		return []

	numkeep = {}
	for i in range(len(nums)):
		if nums[i] in numkeep:
			return [numkeep[nums[i]], i]
		else:
			numkeep[target-nums[i]] = i
