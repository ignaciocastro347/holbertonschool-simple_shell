# My printf function

In this project we are going to create our own printf function that works the same way as the original function. This means handling format specifications (%) such as the simple printing.

## Function Prototype

__int _printf(const char *format, ...)__

__format__: the constant character string.

### Libraries

We used the stdarg.h library and one of our own called "main.h" which contains the prototypes of the functions used all along the project.

### Compiler

To compile our files we used the gcc compiler.

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

And to test our _printf we added the __-Wno-format__ flag.

## printf function

Printf is a c function that sends a formatted string to standard output by taking a constant string as the first function argument and we can print different data type using the format specificators. Oppositely to the puts function, in printf we need to manually add a new line where we want it to be as the function itself does not add it automatically.

### Format Specifications

As mentioned above with printf we can print different data type. This happens when printf takes more than one argument then the format of the output is defined by a % symbol followed by a character that describes it.


| Operator | Format |
| ------ | ------ |
| %c | is used for printing a character |
| %s | is used for printing a string |
| %d | is used for printing a decimal number |
| %i | is used for printing an integer base 10 |
| %u | is used for printing an unsigned decimal |
| %b | is used for printing a binary |
| %o | is used for printing an octal |
| %x | is used for printing a hexadecimal |
| %X | is used for printing an uppercase hexadecimal |
| %% | is used for printing a percent sign |

For example:

```sh
int main(void){
int age = 20;

printf("I'm %d years old.\n", age);
}
Output: I'm 20 years old.
```

## Flowchart

Here we'll show the printf source code in a graphical way.






### Contributors

[Ignacio Castro](https://github.com/ignaciocastro347) and  [Victoria Márquez](https://github.com/vicomarquez)
Cohort 18 Holberton School
