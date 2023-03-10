import numpy as np

def generator(number):
	lst_num = np.random.randint(-2147483648, 2147483647, size=number)
	s = str(lst_num)
	s = s.replace('[', '')
	s = s.replace(']', '')
	s = s.replace('\n', '')
	return s

with open("numbers.txt", 'w') as f:
	s = generator(100)
	f.write(s)
