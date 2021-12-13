// BruteCrack - A simple brute force password list generator written 
// in C

// PLEASE DO NOT USE THIS FOR ILLEGAL OR CRIMINAL PURPOSES. 

// This serves as a small and easy-to-use Hydra-style password list generator with
// noticeable less features.

// Code by Zhengli Wang -
// Written using the awesome GNU tool called
// Gedit :-)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define OUTPUT_FILE_LENGTH 256
#define CHAR_LIST_LENGTH 16
#define PW_TEMP_STORAGE_LENGTH 256


//leave this line to #define DEBUG

void crack_and_output(char * password_temp_storage, char * char_list, long length, FILE * output, int current_index);
// password...storage is used to store the worked on password temporarily (must be pointer with minimum memory with 
																		// the size of length
// char_list contains possible characters for each password character
// length specifies the length of the password to guess
// output decides where to write out data
// current_index: set this to 0


int main (int argc, void **argv) // Accepts CL arguments
{
	
	/************ VARIABLES FIRST ************/
	
	long i = 0; //GLOBAL COUNTER
	_Bool command_was_used = true; //Was the command used successfully?
	char password_temp_storage[PW_TEMP_STORAGE_LENGTH] = {0}; //temporary storage for crack_and_output
	
	//Some char_lists
	char uppercase_letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char lowercase_letters[26] = "abcdefghijklmnopqrstuvwxyz";
	char numbers[10] = "0123456789";
	
	//CL Args Name
	const char min_length_name[] = "--min-length";
	const char max_length_name[] = "--max-length";
	const char output_file_name[] = "--output";
	const char char_list_name[] = "--charlist";
		//char_list names
		const char uppercase_letters_name = 'u';
		const char lowercase_letters_name = 'l';
		const char numbers_name = 'n';
	
	//CL Args Storage
	char output_file[OUTPUT_FILE_LENGTH] = {0}; //Filename for password list output file
	char separator = '\n';       //Separator between generated passwords
	long min_length = -1; //Minimum password length
	long max_length = -1; //Maximum password length
	char char_list[CHAR_LIST_LENGTH] = {0}; //which charlist(s) should be used
	
	//Operating File
	FILE * password_file; //file for storing the password list
	
	//Other
	char * strtol_end = (char *) malloc(sizeof(char *));
	
	/************ Code ************/

	//CL Args processing
	for(i = 1; i < argc; i++) //i = 1 so the command itself doesnt get read
	{
		#ifdef DEBUG
			puts(argv[i]);
		#endif
		
		if(strlen(min_length_name) == strlen(argv[i])) //check is argv[i] is as long as min_length_name
			if(strncmp(min_length_name, argv[i], strlen(argv[i])) == 0) //If min_length_name matches current argv
			{
					min_length = strtol(argv[i+1], &strtol_end, 10); //set min_length to the next number of argv (e.g. on the CL --min-length 1
																 // would be min_length=1)
				#ifdef DEBUG 
					printf("minlength set to %u\n", min_length);
				#endif	
			
			}
			
		if(strlen(max_length_name) == strlen(argv[i])) //check is argv[i] is as long as max_length_name
			if(strncmp(max_length_name, argv[i], strlen(argv[i])) == 0) //If max_length_name matches current argv
			{
				max_length = strtol(argv[i+1], &strtol_end, 10); //set max_length to the next number of argv (e.g. on the CL --min-length 1
																 // would be min_length=1)
				#ifdef DEBUG 
					printf("maxlength set to %u\n", max_length);
				#endif
			}
			
		if(strlen(output_file_name) == strlen(argv[i])) //check is argv[i] is as long as output_file_name
			if(strncmp(output_file_name, argv[i], strlen(argv[i])) == 0) //If output_file_name matches current argv
			{
				strncpy(output_file, argv[i+1], OUTPUT_FILE_LENGTH); //set output_file to the next arg of argv
				#ifdef DEBUG 
					printf("outputfile set to %s\n", output_file);
				#endif	
			}
			
		if(strlen(char_list_name) == strlen(argv[i])) //check is argv[i] is as long as char_list_name
			if(strncmp(char_list, argv[i], strlen(argv[i])) == 0)
			{
				strncpy(char_list_name, argv[i+1], CHAR_LIST_LENGTH);
				#ifdef DEBUG 
					printf("char_list_name set to %s\n", char_list_name);
				#endif	
			}
	}
	
	//CL Args Error Processing
	
	if( max_length == -1 || min_length == -1 || strncmp(output_file, "", 1) )  //See if any of the options is set invalidly
	{
		command_was_used = false; //set command_was_used to false
	}
	
	//Open file for storing
	
	password_file = fopen(output_file, "w");
	
	// Crack/Guess password
	
	for(i = min_length; i <= max_length, command_was_used; i++) // iterate from min_length to max_length, but command had to be used
	{
		crack_and_output(password, i, , password_file); //lists possible passwords and outputs into the given file pointer
	}	
	
	//Command was used?
	
	if(!command_was_used)
	{
		/*write usage here*/
	}
	
	return 0;
}

// functions

void crack_and_output(char * password_temp_storage, long length, char * char_list, FILE * output, int current_index)
{
	if(length == 1)
	{	
		for(int i = 0; i <= strlen(char_list); i++)
		{
			password_temp_storage[current_index] = char_list[i];
			fprintf(output, "%s\n", password_temp_storage);
		}
	}
	else
	{
		for(int i = 0; i <= strlen(char_list); i++)
		{
			password_temp_storage[current_index] = char_list[i];
			crack_and_output(password_temp_storage, length, char_list, output, current_index + 1);
		}
	}
}
		
		
		
