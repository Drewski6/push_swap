import numpy as np
import re
import sys

def generator(number):
	# lst_num = np.random.randint(-2147483648, 2147483647, size=number)
	lst_num = np.random.choice(range(-number, number), size=number, replace=False)
	s = str(lst_num)
	s = s.replace('[', '')
	s = s.replace(']', '')
	s = s.replace('\n', '')
	return s

# print(sys.argv)
try:
	size = int(sys.argv[1])
except:
	try:
		size = int(input("How many numbers would you like to generate?\n"))
	except ValueError:
		print("Input needs to be a number.")
		exit()	

with open("numbers.txt", 'w') as f:
	s = generator(size)
	s = re.sub(' +', ' ', s)
	f.write(s)

# print(f"Generated {size} number(s) between -{size} and {size} and stored them in number.txt\n")
