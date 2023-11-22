# 0x16. C - Simple Shell 
> **We do hard things 💪**
## Features
> - Handle a simple command (pwd, ls...) ✅
> - Handle a command with the argument (ls -a, ls -la, vim textfile, touche filename...) ✅
> - Handle a command with the argument and PATH (ls -a /tmp, cat filename /usr...) ✅
> - and more...
### An ALX Software Engineering Project : ⬇
### Simple UNIX command interpreter, created by : ⬇️
#### $AUTHOR : @Git-SalahEdd, @legenduzo
###	shell.h
####		function prototype and headers
####	main.c
###		main entry to the shell (work in progress...)
###	check_spaces.c: 
####		count spaces in a string
###	check_dir.c :
####		check if the given string is a dir
###	manage_cmd.c :
####		handle and execute the commands
####		function to remove space or new line from a string
###	string_manage.c:
####		contain 4 function : strcpy + strcat + strlen + strncmp
###	loop_shell.c:
####		loop that let the shell continue runing (work in progress...)
###	exctract_dir_from_string.c:
####	check if a dir exist in the string and exctracts it
###	check_char
####		counts the number of small letters in a string, if there are none, returns 0. Used in split_string
###	split_string
####		splits a string with a provided delimiters into an array of strings
###	where.c
####		locates a dir in the path env variable
###	free_split.c
####		frees memory allocated in split_sptring
