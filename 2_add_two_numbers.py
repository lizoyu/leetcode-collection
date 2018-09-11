"""
#2 - Add Two Numbers (Easy)

You are given two non-empty linked lists representing two non-negative integers. 

The digits are stored in reverse order and each of their nodes contain a single digit. 

Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

"""
#Definition for singly-linked list.
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
def addTwoNumbers(self, l1, l2):
	"""
	:type l1: ListNode
	:type l2: ListNode
	:rtype: ListNode
	"""
	"""
	Add two numbers bit by bit as usual, but be careful about carry and different situations.
	O(A+B) <- Loop through both linked list once
	"""
	# when one of the linked list is empty
	if l1 and not l2:
		return l1
	if l2 and not l1:
		return l2

	# save node in a list, 'up' saves the carry
	l3 = []
	up = 0
	# add up the num bit by bit
	while l1 and l2:
		# update the carry, remained is saved in l3
		add = l1.val + l2.val + up
		up = int(add >= 10)
		l3.append(ListNode(add % 10))
		if len(l3) > 1:
			# link them
			l3[-2].next = l3[-1]
		l1, l2 = l1.next, l2.next

	# if one of the linked list is exhausted, link remained to l3
	if l1 and not l2:
		l3[-1].next = l1
		l1.val += up
	if l2 and not l1:
		l3[-1].next = l2
		l2.val += up
	# if both exhausted, deal with the carry
	elif up:
		l3.append(ListNode(up))
		l3[-2].next = l3[-1]
	return l3[0]