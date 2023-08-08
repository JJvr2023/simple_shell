This is the Simple_Shell project done by
Janine Janse van Rensburg and Amanda Magwaza

# Simple_Shell

This is a simple UNIX shell implemented in C. It supports the following commands:

* `echo`
* `cd`
* `ls`
* `pwd`
* `cat`
* `cp`
* `rm`
* `mv`
* `mkdir`
* `exit`

The shell also supports input and output redirection, as well as pipes.

## Installation

To install the Simple_Shell, clone the repository and compile the source code:

git clone https://github.com/[your-username]/Simple_Shell.git
cd Simple_Shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh


## Usage

To run the Simple_Shell, simply type the following command:

./hsh

The shell will then prompt you for a command. Type in a command and press enter to execute it.

Examples
The following are some examples of how to use the Simple_Shell:

To list the contents of the current directory, type ls and press enter.
To change the current directory to /home/user, type cd /home/user and press enter.
To print the current working directory, type pwd and press enter.
To display the contents of the file myfile.txt, type cat myfile.txt and press enter.
To copy the file myfile.txt to myfile_copy.txt, type cp myfile.txt myfile_copy.txt and press enter.
To remove the file myfile.txt, type rm myfile.txt and press enter.
To move the file myfile.txt to the directory /home/user, type mv myfile.txt /home/user and press enter.
To create a directory called mydir, type mkdir mydir and press enter.
To exit the shell, type exit and press enter.
