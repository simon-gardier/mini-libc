# ⚙️ Mini C standard library
![Release](https://img.shields.io/badge/Release-v1.0-blueviolet?style=for-the-badge)
![Language](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge)

Implementation of a small standard library to work with strings and numbers.
C library done for the libft project of School 19.

## Content

- ./conversion : conversions functions from int to string and the other way around.
- ./memory : memory related functions, see the man page of the related functions.
- ./string : string related functions, see the man page of the related functions.
- ./miscellaneous : 
    - ft_printf : simplified version of standard printf.
    - ft_get_next_line : file related function returning the next line of the file.

## Example
See `example.c` for some libft usage examples.
To compile and run the example :
```terminal
make
gcc example.c libft.a 
./a.out
```

## Credits
- [Simon Gardier](https://github.com/simon-gardier)
