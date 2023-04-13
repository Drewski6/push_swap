"""Permutation Generator

Creates a list of all permutations between 1 and 5 members and saves them
to a file for use as arguments for later
"""
import itertools as it

with open("permutations.txt", "w") as f:
	for size in range(1, 6):
		for item in it.permutations(range(1, size + 1), size):
			f.write(' '.join(str(tup) for tup in item) + "\n")
