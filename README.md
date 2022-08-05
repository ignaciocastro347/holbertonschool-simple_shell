# Mishell

A command shell is a command interpreter which is used to execute actions on an operative system. 

In this project we simulate a bash shell. It includes some basic functionalities in order to has the same behavior as the original.

## Requirements

- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded


## Run Mishell

First of all, clone this project. 

Then, compile this c program:
```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Finally, run this executable file:
```sh
$ ./hsh
```

## Non Interactive Mode

When running Mishel, you can concat commands. In this way, the program understand that the user wants to execute these commands, after that the program will die.

For instance:

### Example 1
```sh
$ echo "ls -l" | ./hsh
```

### Output

```
total 88
-rw-r--r-- 1 root root   166 Aug  5 07:05 AUTHORS
-rw-r--r-- 1 root root   272 Aug  3 19:19 free_string_list.c
-rwxr-xr-x 1 root root 22864 Aug  5 12:47 hsh
-rw-r--r-- 1 root root  1865 Aug  5 11:21 main.c
-rw-r--r-- 1 root root   692 Aug  3 19:19 _printf.c
-rw-r--r-- 1 root root   563 Aug  3 19:19 _printf_get_print_function.c
-rw-r--r-- 1 root root   923 Aug  3 19:19 _printf.h
-rw-r--r-- 1 root root   906 Aug  3 19:19 _printf_more_use_cases.c
-rw-r--r-- 1 root root   454 Aug  3 19:19 _printf_putchar.c
-rw-r--r-- 1 root root  1184 Aug  3 19:19 _printf_use_cases.c
-rw-r--r-- 1 root root   435 Aug  3 19:19 _printf_utils.c
-rw-r--r-- 1 root root  1165 Aug  5 10:25 README.md
-rw-r--r-- 1 root root   551 Aug  5 10:40 shell.h
-rw-r--r-- 1 root root  1277 Aug  5 10:38 split.c
-rw-r--r-- 1 root root  1398 Aug  5 10:43 _string.c
-rw-r--r-- 1 root root   182 Aug  3 19:19 _string.h
-rw-r--r-- 1 root root  1562 Aug  5 10:29 utils.c
```

### Example 2

```sh
$ echo "ls -l
   pwd    
sudo apt-get update" | ./hsh
```

### Output
```
total 88
-rw-r--r-- 1 root root   166 Aug  5 07:05 AUTHORS
-rw-r--r-- 1 root root   272 Aug  3 19:19 free_string_list.c
-rwxr-xr-x 1 root root 22864 Aug  5 12:47 hsh
-rw-r--r-- 1 root root  1865 Aug  5 11:21 main.c
-rw-r--r-- 1 root root   692 Aug  3 19:19 _printf.c
-rw-r--r-- 1 root root   563 Aug  3 19:19 _printf_get_print_function.c
-rw-r--r-- 1 root root   923 Aug  3 19:19 _printf.h
-rw-r--r-- 1 root root   906 Aug  3 19:19 _printf_more_use_cases.c
-rw-r--r-- 1 root root   454 Aug  3 19:19 _printf_putchar.c
-rw-r--r-- 1 root root  1184 Aug  3 19:19 _printf_use_cases.c
-rw-r--r-- 1 root root   435 Aug  3 19:19 _printf_utils.c
-rw-r--r-- 1 root root  1165 Aug  5 10:25 README.md
-rw-r--r-- 1 root root   551 Aug  5 10:40 shell.h
-rw-r--r-- 1 root root  1277 Aug  5 10:38 split.c
-rw-r--r-- 1 root root  1398 Aug  5 10:43 _string.c
-rw-r--r-- 1 root root   182 Aug  3 19:19 _string.h
-rw-r--r-- 1 root root  1562 Aug  5 10:29 utils.c
/pre-shell
Get:1 http://security.ubuntu.com/ubuntu focal-security InRelease [114 kB]
Hit:2 http://archive.ubuntu.com/ubuntu focal InRelease
Get:3 http://archive.ubuntu.com/ubuntu focal-updates InRelease [114 kB]
Hit:4 http://ppa.launchpad.net/brightbox/ruby-ng/ubuntu focal InRelease
Get:5 http://archive.ubuntu.com/ubuntu focal-backports InRelease [108 kB]
Get:6 http://archive.ubuntu.com/ubuntu focal-updates/main amd64 Packages [2,498 kB]
Get:7 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 Packages [1,174 kB]
Fetched 4,008 kB in 11s (356 kB/s)
Reading package lists... 21%
```

## Interactive Mode

In this way, first user needs to execute Mishel like:

```sh
$ ./hsh
```
And then a prompt will appear in your terminal. User can write not only full path commands but also just its name. Mishell will search for this program the executable paths. 

### Example 1
```
mkdir new_dir
```

### Output
```
total 0
drwxr-xr-x 2 root root 6 Aug  5 12:57 new_dir
```

### Example 2

```
cp -r new_dir/ copy_new_dir
```

### Output
```
total 0
drwxr-xr-x 2 root root 6 Aug  5 12:58 copy_new_dir
drwxr-xr-x 2 root root 6 Aug  5 12:57 new_dir
```

## Flowchart

![Shell flowchart drawio](https://user-images.githubusercontent.com/46456405/183103662-462fcbd8-69cd-4478-a657-126d5d55e6dc.png)

## Authors

Writen by [Ignacio Castro](https://github.com/ignaciocastro347) & [José Alvarez](https://github.com/BesterGG).
