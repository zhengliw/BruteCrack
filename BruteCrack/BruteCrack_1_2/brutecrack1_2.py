# BruteCrack - A simple and extremely lightweight 
# password lister using Brute Force

import sys # import sys to access CL arguments

usage = '''Please read the usage file for the instructions\n''' # define usage instruction text

###### veri gud code ahead

def crack(length, charlist, password, function):
	'''length specifies how long the password should be, 
	charlist specifies which characters are allowed, 
	and password is used for temp. password storage, 
	just pass through an !empty! list to it, 
	function is the function that is executed with every final loop'''
	
	for char in charlist:	
		password.append(char) # append current character
		if length > 1:
			crack(length - 1, charlist, password, function) # recurse when to-crack length bigger than 1
		else:
			function(password) # write to file
		password.pop() # pop current character

def exceptionHandler(usage): # handle exceptions
	'''handle exceptions (print usage and exit with error code 1)'''
	print(usage)
	exit(1)

######

def writetofile(password):
	global file
	file.write(''.join(password) + '\n')


if len(sys.argv) != 2: # if no or too many arguments are given (the first argument is the command)
	exceptionHandler(usage) # handle exception

CLoptions = sys.argv[1] # since this is the first update version of
					    # BruteCrack, it will only read the second
					    # CL argument, in this case the argument
					    # immediately after the command
					  
char_list = "abcd"      # modify this yourself to specify
						# which characters the to-be-cracked
						# password should contain

options = CLoptions.split(sep=':')
						# read the options and make a list

# read the actual values
try:
	min_length = int(options[0])
	max_length = int(options[1])
	output_file = options[2]
except: # if anything goes wrong
	exceptionHandler(usage) # handle exception

i = int(min_length) # counter

with open(output_file,'w') as file: # open a file for storing in write mode
	while i <= max_length: # while i is smaller than max_length
		crack(i, char_list, list(), writetofile) # crack password in i's length
		i += 1 # i += 1


# yes i know this code looks ugly
# at least i don't have the
# infinite-rewriting problem