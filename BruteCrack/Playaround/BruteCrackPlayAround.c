// BruteCrack - A simple brute force password list generator written 
// in C

// PLEASE DO NOT USE THIS FOR ILLEGAL OR CRIMINAL PURPOSES. 

// This serves as a small and easy-to-use Hydra alternative with
// noticeable less features.

// But this version is mainly for me playing around with
// Command-Line arguments and practising C language
// since I havent touched programming for a little while now


// Code by Zhengli Wang -
// Written using the awesome GNU tool called
// Gedit :-)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#def DEBUG false
int main (int argc, void **argv) // Accepts CL arguments
{

	 //CL Args processing
	 
	 _Bool no_stat = false; // Should the program show statistics?
	 int i = 0;             // The counter which is usable for every operation in main()
	 int debug_strncmp_return = 0; //Debug
	 
	 for(i = 0; argv[i] != NULL; i++) // Loop through the CL Args... 
	 {
	 	if(i != 0)                    // When the CL Arg isnt the command itself...
	 		if((debug_strncmp_return = strncmp("--no-stat", argv[i], 9)) == 0) 
	 		 						  // And "--no-stat" is being input as an arg... 
	 		{
	 	    	no_stat = true;       // Then set no_stat to false.
	 	    	if(DEBUG)			  // Debug code
	 	    	{
	 	    		puts("no_stat set to true\n");
	 	    		printf("strncmp returned %d\n", debug_strncmp_return);
	 	    	}
	 	    	
	 	    }
	 }
	 
	 
	 for(i = 0; argv[i] != NULL; i++) // Loop through the CL Args...
	 {
	 	if(i != 0) 					  // If the arg isnt the command itself...
	 		if(strncmp("-",argv[1],1) != 0) // and doesnt start with a dash (so the arg isnt an operating option e.g. --no-stat)...
	 	    	printf("%d: %s \n",i,argv[i]); // print the cl arg
	 }
	 
	 if(no_stat == false) // If the user hasnt specified to not show stats...
	 {
	 					  // Show the stats
	 	 printf("%d CL arguments (without the command itself) passed to BruteCrack playaround version\n", i-1); 
	 	 printf("%d CL args in total\n", i);
	 }
	 
	 return 0;
}
