klocki = input()
klocki = int(klocki)
i = 1 # for incrementing in while loop
h = 0 # height incremented in while loop

for i in range(1, klocki, 1): # minimizes for loop range
	klocki = klocki - i;
	h += 1 # careful not to switch + and =
	# print("Klocki: ", klocki, " h: ", h) # debug
	if (klocki <= i):
		print(h)
		break
