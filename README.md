# CDIES
An integrated IDE running on a Linux shell

Please give permission to run
Please give this script permission to run!
Select script to run
Can run
#Command parsing

rc compile and run C/C++ commands
Usage: rc [absolute path]

clc clears all compiled binaries
Usage: clc

cdie neovim execute command
Usage: cdie file/directory

cnpc creates a new C project
Usage: cnp [project name]//If not, create a project project (in the pro-folder folder)

cnpc+ Create a new C++ project
Usage: cnp [project name]//If not, create project+project (in the pro-folder folder)

delete delete all configuration files
Usage: delete
delete parameter [file name, binary file name, item]
-f delete files
-p delete c project
-p+ delete c++ project
-h || --help View help
-v || --verison view version
-all delete all configuration files

clp delete all project files
Usage: clp

msc compile c/c++ into system commands (requires sudo)
Usage: sudo msc [absolute path]

Shortcut keys (commonly used):
Space+p+t+r asynchronous tasks (compile and run, etc.)
Space+pte edit asynchronous task
Space+ft window file management
Create new file in window file manager N
Gd transfer definition in the file

ps: This script can be changed, and the unreasonable parts can be removed