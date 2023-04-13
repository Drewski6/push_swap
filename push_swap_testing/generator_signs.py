"""Writes to stdout a list of random numbers without repeating numbers.

	argv[1]: integer size of how many numbers you would like generate.

	This version includes a + in front of positive numbers.
"""
import sys
import numpy as np

try:
	number = int(sys.argv[1])
except ValueError:
	number = 100
lst_num = [int(item) for item in np.random.choice(range(-number, number), size=number, replace=False)]
print(*list(map(lambda x: ("+" if x >= 0 else "") + str(x), lst_num)))
