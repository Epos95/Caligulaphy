import curses
import argparse
import time

keys = {
113 : "q",
119 : "w",
101 : "e",
114 : "r",
116 : "t",
121 : "y",
117 : "u",
105 : "i",
111 : "o",
112 : "p",
97 : "a",
115 : "s",
100 : "d",
102 : "f",
103 : "g",
104 : "h",
106 : "j",
107 : "k",
108 : "l",
122 : "z",
120 : "x",
99 : "c",
118 : "v",
98 : "b",
110 : "n",
109 : "m",
32 : " ",
47 : "/",
48 : "0",
49 : "1",
50 : "2",
51 : "3",
52 : "4",
53 : "5",
54 : "6",
55 : "7",
56 : "8",
57 : "9",
}

while 1:
	try:
		k = self.cli.screen.getch()
		if k == "\n":
			k = None
		#cli.screen.addstr(10,0,k)
	except:
		k = None

	# backspace was pressed, remove last character from the string
	if (k == 127 or k == 8) and k != "":
		string = string[:-1]
		self.cli.input_window()
		self.cli.input.refresh()
		self.cli.screen.addstr(self.cli.height-self.cli.input_height,self.cli.side_width+5, string)

	# key was pressed, add it to the string
	if k in keys:
		string += keys[k]
		self.cli.screen.addstr(self.cli.height-self.cli.input_height,self.cli.side_width+5, string)

	# TODO: lägg till space här istället för enter
	# enter was pressed, handle the input
	if not string.isspace() and k == 10 and string != "":

		print(string)
		#clear string
		string = ""

		# purge messagelist
		if len(self.messagelist) > self.cli.main_height-2:
			del self.messagelist[self.cli.main_height-2:]

		# print out the messagelist
		var = 1
		for thing in self.messagelist:
			self.cli.main_window()
			self.cli.main.refresh()

			#self.cli.screen.addstr(self.cli.main_height-1, self.cli.side_width+5, " "*(self.cli.main_width-1))
			self.cli.screen.addstr(self.cli.main_height-var, self.cli.side_width+5, str(thing))
			var += 1

		# updatera input_window
		self.cli.input_window()
		self.cli.input.refresh()

	# resize event
	if k == curses.KEY_RESIZE:
		self.cli.screen.erase()
		self.cli = Frontend()

	# flytta cursor efter input
	self.cli.screen.move(self.cli.height-self.cli.input_height, self.cli.side_width+5+len(string))
