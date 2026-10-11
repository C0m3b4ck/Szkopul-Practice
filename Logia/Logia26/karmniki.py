if __name__ == "__main__":
	k, m, c = input().split() # get input (k - initial production start cost, m - cost of production per unit, c - price sold per unit)
	k, m, c = int(k), int(m), int(c) # convert to int

	if (m >= c): # production cost is equal or greater than profit (for single unit)
		print(-1)
	else:
		# how many sales to go above initial production cost
		#margin = c - m # profit per unit (cost sold - production cost)
		#ammount = (k // margin) + 1 # how many units to be sold before initial cost is broken even, +1 is needed because k // margin shows when you break even 
		# even simpler (like official solution):
		ammount = (k // (c - m)) + 1
		print(ammount)
