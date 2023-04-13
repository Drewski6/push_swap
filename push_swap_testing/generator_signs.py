import numpy as np
import sys

number = int(sys.argv[1])
#number = 100
lst_num = [int(item) for item in np.random.choice(range(-number, number), size=number, replace=False)]
print(*list(map(lambda x: ("+" if x >= 0 else "") + str(x), lst_num)))
