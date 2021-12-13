Usage: 

python BruteCrack_1_1.py min:max:op

min: Minimum length of the password to list/crack.
max: Maximum length of the password to list/crack.
op: Output file name

The output file will be overwritten without any warnings.


If you want to modify which characters the to-be-cracked password can contain, you have to modify the source file in this version. Future versions might contain better methods :-). Just change char_list, it's pretty easy to find (if I coded more organized, maybe you could find it even easier)
