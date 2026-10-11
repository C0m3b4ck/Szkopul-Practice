import turtle as t
from turtle import *

def draw_rectangle(width_pod, color_pod): #helper function for drawing rectangles, height not passed as it stays the same
	t.left(90) # face up
	fillcolor(color_pod) # fill color gets passed as function is called
	t.begin_fill()
	t.forward(400) # left side
	t.right(90)
	t.forward(width_pod) # top side
	t.right(90)
	t.forward(400) # right side
	t.right(90)
	t.forward(width_pod) # bottom side
	t.right(180) # turn around
	t.forward(width_pod) # go to next rectangle starting position
	t.end_fill()

def paski(ile_pas, s_pod, w_pod):
	# calculate number of orange stripes (s is brown, w is yellow)
	orange = ile - (s + w)
	#print(orange) #debug
	# for loop for brown (width = 45)
	for i in range(0, s_pod, 1):
		draw_rectangle(45, "brown")
	# for loop for orange (ammount can be 0, width = 30)
	for i in range(0, orange, 1):
		draw_rectangle(30, "orange")
	# for loop for yellow (width = 15)
	for i in range(0, w_pod, 1):
		draw_rectangle(15, "yellow")
	# draw_rectangle(45, "brown") # debug
	t.done()
if __name__ == "__main__":
	ile, s, w = input().split()
	ile, s, w = int(ile), int(s), int(w)
	# call drawing function
	paski(ile, s, w)
