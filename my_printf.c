#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int my_printf(char* str, ...);
int printNum(int num);
int octal(int dec);
int hexal(int dec);
int hexAddress(long long int address);
int my_putchar(char c);

// int main(void)
// {
//     char hello[] = "";
//     printf("\n%d", my_printf("%p!\n", hello));
//     return 0;
// }

int my_printf(char* str, ...)
{
    va_list ap;
    va_start (ap, str);

    int dec, index, len = 0;
    char ch;
    char* arr;
    long long int address;

    for (index = 0; str[index] != '\0'; index += 1)
    {
        if (str[index] == '%')
        {
            switch (str[index+1])
            {
                case 'd':
                    dec = va_arg(ap, int);
                    len += printNum(dec);
                    break;
                case 'o':
                    dec = va_arg(ap, int);
                    len += printNum(octal(dec));
                    break;
                case 'u':
                    dec = va_arg(ap, int);
                    if (dec < 0)
                    {
                        dec *= -1;
                    } 
                    len += printNum(dec);
                    break;
                case 'x':
                    dec = va_arg(ap, int);
                    len += hexal(dec);
                    break;
                case 'c':
                    ch = va_arg(ap, int);
                    my_putchar(ch);
                    len += 1;
                    break;
                case 's':
                    arr = va_arg(ap, char*);
                    if (arr == NULL)
                    {
                        my_putchar('(');
                        my_putchar('n');
                        my_putchar('u');
                        my_putchar('l');
                        my_putchar('l');
                        my_putchar(')');
                        len += 6;
                    } 
                    else
                    {
                        for (int i = 0; arr[i] != '\0'; i += 1)
                        {
                            my_putchar(arr[i]);
                            len += 1;
                        }
                    }
                    break;
                case 'p':
                    address = (long long int) va_arg(ap, void*);
                    len += hexAddress(address);
                    break;
    	    }  
            index += 1;
        }
        else
        {
            putc(str[index], stdout);
            len += 1;
        }
    }

    va_end (ap);
    return len;
}

int printNum(int num)
{
    int index = 1;
    if (num != 0)
    {
        char numStr[10];
        _Bool sign = 0;
        int remain;

        if (num < 0)
        {
            sign = 1;
            num *= -1;
        }
        for (index = 0; num != 0; index += 1)
        {
            remain = num % 10;
            numStr[index] = 48 + remain;
            num /= 10;
        }
        numStr[index] = '\0';

        if (sign == 1)
        {
            my_putchar('-');
        }
        for (int i = index-1; i >= 0; i -= 1)
        {
            my_putchar(numStr[i]);
        }
        if (sign == 1)
        {
            index += 1;
        }
    }

    return index;
}

int octal(int dec)
{
    int octal = 0, i = 1;

    while (dec != 0)
    {
        octal += (dec % 8) * i;
        dec /= 8;
        i *= 10;
    }

    return octal;
}

int hexal(int dec)
{
    char hex[10];
    int remain, index = 0;

    while (dec != 0)
    {
        remain = dec % 16;
        if (remain < 10)
        {
            hex[index] = 48 + remain;
        }
        else
        {
            hex[index] = 87 + remain;
        }
        index += 1;
        dec /= 16;
    }
    hex[index] = '\0';

    for (int i = index-1; i >= 0; i -= 1)
    {
        my_putchar(hex[i]);
    }

    return index;
}

int hexAddress(long long int dec)
{
    char hex[15];
    int remain, index = 0;

    while (dec != 0)
    {
        remain = dec % 16;

        if (remain < 10)
        {
            hex[index] = 48 + remain;
        }
        else
        {
            hex[index] = 87 + remain;
        }
        index += 1;
        dec /= 16;
    }
    hex[index] = '\0';

    putc('0', stdout);
    putc('x', stdout);
    for (int i = index-1; i >= 0; i -=)
    {
        my_putchar(hex[i]);
    }

    return index+2;
}

int my_putchar(char c)
{
    return write(1, &c, 1);
}
