import pandas as pd
import os
from time import gmtime, strftime

logfile = "failed_runs_saved_inputs.txt"

df = pd.read_csv("bulk_moves500.csv")
loc_greatest = df[df['Number'] > 5500]
# print(loc_greatest.Number)
loc_greatest.reset_index()
with open(logfile, "a") as f:
	if (not os.path.getsize(logfile)):
		f.write("DateTime,Number,Input\n")
	if (not loc_greatest.empty):
		for index, row in loc_greatest.iterrows():
			f.write(f"{strftime('%d/%m/%Y_%H:%M:%S', gmtime())},{row['Number']},{row['Input']}\n")
	f.close()
