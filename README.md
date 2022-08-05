# Mishell

A command shell is a command interpreter which is used to execute actions on an operative system. 

In this project we simulate a bash shell. It includes some basic functionalities in order to has the same behavior as the original.

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
```sh
$ echo "ls -l" | ./hsh
```

```sh
$ echo "ls -l
   pwd    
sudo apt-get update" | ./hsh
```

## Interactive Mode

In this way, first user needs to execute Mishel like:

```sh
$ ./hsh
```
And then a prompt will appear in your terminal. User can write not only full path commands but also just its name. Mishell will search for this program the executable paths. 

## Flowchart

![Shell flowchart drawio](https://user-images.githubusercontent.com/46456405/183103662-462fcbd8-69cd-4478-a657-126d5d55e6dc.png)

