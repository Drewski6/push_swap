import numpy as np
import re
import sys

# print(sys.argv)
try:
	number = int(sys.argv[1])
except (NameError, IndexError, ValueError):
	try:
		number = int(input("How many arguments should we generate?"))
	except TypeError:
		print("Please enter a number.")
		exit()

args = np.random.choice(range(-number, number), size=number, replace=False)

print(args)
print(*args)
