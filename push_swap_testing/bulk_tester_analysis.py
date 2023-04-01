import pandas as pd
import subprocess
import sys

SIZE = int(sys.argv[1])
LOOPS = int(sys.argv[2])

subprocess.run(["chmod", "755", "bulk_tester.sh"])
subprocess.run(["./bulk_tester.sh", f"{SIZE}", f"{LOOPS}"])
df = pd.read_csv(f"bulk_moves{SIZE}.csv")
index_of_min = df['Number'].idxmin()
index_of_max = df['Number'].idxmax()
total_result = df[df['Result'] != "OK"].groupby('Result')['Result'].count()
total_100 = df[df['Number'] > 700].groupby('Number')['Number'].count()
total_500 = df[df['Number'] > 5500].groupby('Number')['Number'].count()

print(f"SIZE: {SIZE}")
print(f"LOOPS: {LOOPS}")
if (total_result.sum()):
	print(f"Total number of FAILED runs: {total_result.sum()}")
else:
	print(f"All runs PASSED checker_linux")
if (SIZE == 100):
	print(f"Total number greater than 700: {total_100.sum()}")
if (SIZE == 500):
	print(f"Total number greater than 5500: {total_500.sum()}")
print(f"Max Number: {df.loc[index_of_max]['Number']}")
print(f"Min Number: {df.loc[index_of_min]['Number']}")
print(f"Mean Number: {df['Number'].mean()}")
