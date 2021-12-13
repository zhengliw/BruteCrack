# Now here we go
# BruteCrack finally in Python
# (But it kinda sucks, so i will push updates)

# BruteCrack - A simple and extremely lightweight 
# password lister using Brute Force

import sys # import sys to access CL arguments


###### veri gud code ahead
def crack(length, charlist, password, op_file):
	'''length specifies how long the password should be, 
	charlist specifies which characters are allowed, 
	and password is used for temp. password storage, 
	just pass through an !empty! list to it, 
	op_file specifies the output file (wow)'''
	
	for char in charlist:	
		password.append(char) # append current character
		if length > 1:
			crack(length - 1, charlist, password, op_file) # recurse when to-crack length bigger than 1
		else:
			op_file.write(''.join(password) + '\n') # write to file
		password.pop() # pop current character
######

CLoptions = sys.argv[1] # since this is the first (ok-ish) version of
					    # BruteCrack, it will only read the second
					    # CL argument, in this case the argument
					    # immediately after the command
					  
char_list = "abcd"      # modify this yourself to specify
						# which characters the to-be-cracked
						# password should contain

options = CLoptions.split(sep=':')
						# read the options and make a list

# read the actual values
min_length = options[0]
max_length = options[1]
output_file = options[2]

i = int(min_length) # counter

with open(output_file,'w') as file: # open a file for storing in write mode
	while i <= int(max_length): # while i is smaller than max_length
		crack(i, char_list, list(), file) # crack password in i's length
		i += 1 # i += 1

