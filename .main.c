#include "include/ft_printf.h"
#include "include/libft.h"
#include <stdio.h>
#include <string.h>


int main()
{
    ft_printf("----pattern(c)-------\n");
    printf("%c small string\n", 'a');
    ft_printf("%c small string\n", 'a');
    ft_printf("%c\n", 'a');
    printf("%c\n", 'a');
    ft_printf("%c\n", 0);
    printf("%c\n", 0);
    ft_printf("%c42\n", 0);
    printf("%c42\n", 0);
    printf("out %c %c %c \n", '0', 0, '1');
    ft_printf("out %c %c %c \n", 'A', 'B', 'C');

    ft_printf("----pattern(s)-------\n");
    ft_printf("%s\n", "hoge");
    printf("%s\n", "hoge");
    printf("%s\n", "");
    printf("%s\n", "");
    //printf("%s\n", NULL);
    ft_printf("%s\n", NULL);

    ft_printf("----pattern(p)-------\n");
    int *str;
    ft_printf("%p\n", &str);
    printf("%p\n", &str);
    ft_printf("%p %p %p %p %p %p %p %p %p %p\n");

    ft_printf("----pattern(i)-------\n");
    ft_printf("%i\n", 42);
    printf("%i\n", 42);
    printf("%i\n", 0);
    ft_printf("%i\n", 0);

    ft_printf("----pattern(d)-------\n");
    ft_printf("%d\n", 42);
    printf("%d\n", 42);
    ft_printf("%d\n", 0);
    printf("%d\n", 0);
    ft_printf("%d\n", INT_MAX);
    ft_printf("%d\n", INT_MIN);

    ft_printf("----pattern(u)-------\n");
    ft_printf("%u\n", 42);
    printf("%u\n", 42);
    ft_printf("%u\n", 0);
    printf("%u\n", 0);
    printf("%u\n", INT_MAX);
    ft_printf("%u\n", INT_MAX);

    ft_printf("----pattern(x)-------\n");
    ft_printf("%x\n", 42);
    printf("%x\n", 42);
    ft_printf("%x\n", 0);
    printf("%x\n", 0);

    ft_printf("----pattern(X)-------\n");
    ft_printf("%X\n", 42);
    printf("%X\n", 42);
    ft_printf("%X\n", 0);
    printf("%X\n", 0);

    ft_printf("----pattern(%%)-------\n");
    ft_printf("%%%%\n");
    printf("%%%%\n");
    ft_printf("----all pattern-------\n");
    printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    
    return (0);
}
