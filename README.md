# simple_shell

This repository contains all you need to know about the simple shell project.       This is a school project with the aim of building a command interpreter (shell) withand the objective of knowing how shell works behind the hooks.                

## Non built-in

This software can execute non built-in commands directly with the kernel. You may beasking yourself how did you implemented communication with the kernel. When a command is enter it checks all the execution files in the /bin directory if the specified command execution file exist then get it's required full path
e.g /bin/ls or `Type: which command (e.g ls)`
It can also execute commands without their full path e.g ls

## Inbuilt Commands
In-built commands are commands we implement that doesn't exist in the the /bin directory. Some of these commands are as follows:

### exit:
- This is use to exit the shell. It exit with a
default status except specified.
Usage: `exit`
Usage with argument: `exit <status>`

### env:
- This command list all the environment variable Usage: `env`

### setenv:
- This command set an environment variable if
it does not exist reset it if it exist.
Usage: `setenv <VARIABLE_NAME> <value>`

### unsetenv:
- This command unset an environment variable
Usage: unsetenv `<VARIABLE_NAME>`

### cd:
- This command changes the specified directory or
the home directory if no directory was specified. It c
hanges to the previous directory if "-" is passed as a
n argument
Usage: cd `<DIR_NAME>`

This project is still ongoing and there might be some
failures some times.
