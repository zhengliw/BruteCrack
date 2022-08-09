# BruteCrack - A simple and extremely lightweight 
# password lister using Brute Force

# Code by zhengliw
# Feel free to modify it to your needs.
# If you want to fork my scripts, it would
# be pretty nice to mention my username
# in your README. Thx!!!

from os import read
import sys # import sys to access CL arguments

usage = '''Please read the usage file for the instructions\n''' # define usage instruction text



###### veri gud code ahead

def crack(length, charlist, password, op_file):
	'''length specifies how long the password should be, 
	charlist specifies which characters are allowed, 
	and password is used for temp. password storage, 
	just pass through an !empty! list to it,
	op_file specifies the output file
	
	Advanced usage for the password parameter: You can theoretically
	add a beginning of the to-be-cracked passwords by modifying this
	list, since crack() will append the to-be-cracked password and not
	overwrite existing content. However, this hasn't been tested and
	I honestly don't know if this function can be painlessly ported
	to other scripts.'''

	for char in charlist:
		password.append(char) # append current character
		if length > 1:
			print("crack: " + str(length))
			crack(length - 1, charlist, password, op_file) # recurse when to-crack length bigger than 1
		else: 										# if this is the last recursion loop
			op_file.write(''.join(password) + '\n') # write to file
			print("bottom of crack")
		password.pop() # pop current character


def exceptionHandler(usage): # handle exceptions
	'''handle exceptions (print usage and exit with error code 1)'''
	print(usage)
	exit(1)

######



if len(sys.argv) != 2: # if no argument is given (the first argument is the command) or too many arguments
	exceptionHandler(usage) # handle exception

CLoptions = sys.argv[1] # only read the second argument as specifications
					  
char_list = "abcd"      # modify this yourself to specify
						# which characters the to-be-cracked
						# password should contain

options = CLoptions.split(sep=':')
						# read the options and make a list


# read the actual values
try:
	if(len(options) != 4): # if there are more / less than 4 args
		raise Exception # IT'S BAD, SO STOP THE SCRIPT

	min_length = int(options[0])
	max_length = int(options[1])
	output_file = options[2]
	temp_output_file = options[3]

except: # if anything goes wrong
	exceptionHandler(usage) # handle exception


i = int(min_length) # counter

# New algorithm below, more details in the changelog

half_of_char_list = int(len(char_list) / 2) # get the approx. half length of char_list

with open(temp_output_file,'w+') as temp_file: # open a file for storing in write mode
	print(temp_output_file)
	print(output_file)
	while i <= max_length:
		crack(i, char_list, list(), temp_file)
		i += 1
	with open(output_file, 'w+') as op_file:
		print("here we go")
		j = 0
		print(op_file.name)
		for line in temp_file:
			print(line)
			op_file.write( str(char_list[j]) + line + '\n' )
			print(str(char_list[j]))
			op_file.write( str(char_list[j+half_of_char_list]) + line + '\n' )
			print(str(char_list[j+half_of_char_list]))
			j += 1

# yes i know this code looks ugly
# at least i don't have the
# infinite-rewriting problem