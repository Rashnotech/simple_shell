# simple_shell

This repository countain a school                     This is a school project with the aim of building a shell with command execution capability.                

## Non built-in

the programm can execute commands with their full path
 e.g /bin/ls
It can also execute commands without their full path e.g ls

## Inbuilt Commands
                                                      The shell execute the following inbuilt commands

### exit:
- This is use to exit the shell. It exit with a
default status except specified.
Usage: exit
Usage with argument: exit <status>

###- env:
- This command list all the environment variable Usage: env

### setenv:
- This command set an environment variable if
it does not exist reset it if it exist.               Usage: setenv <VARIABLE_NAME> <value>

### unsetenv:
- This command unset an environment variable
Usage: unsetenv <VARIABLE_NAME>

### cd:
- This command changes the specified directory or
the home directory if no directory was specified. It c
hanges to the previous directory if "-" is passed as a
n argument
Usage: cd <DIR_NAME>                                  

This project is still ongoing and there might be some
failures some times.
