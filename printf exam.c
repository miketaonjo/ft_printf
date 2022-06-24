int ft_printchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_printstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbrbase(unsigned int n, char *base, int len_base)
{
    int len;

    len = 0;
    if (n < 0)
    {
        n = -n;
        len += ft_printchar('-');
    }
    if (n < len_base)
        len += ft_printchar(base[n]);
    else
        len += ft_putnbrbase((n / len_base), base, len_base);
        len += ft_putnbrbase((n % len_base), base, len_base);
}

int ft_printf(const char *str, ...)
{
    int len;
    int i;
    char *s;
    int n;
    unsigned int nb;
    va_list args;

    va_start(args, str);
    len = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
            {
                s = va_arg(args, char *);
                if (s == NULL)
                    len += ft_printstr("(null)");
                else
                    len += ft_printstr(str);
            }
            if (str[i] == 'd')
            {
                n = va_arg(args, int);
                len += ft_putnbrbase(n, "0123456789", 10);
            }
            if (str[i] == 'x')
            {
                nb = va_arg(args, unsigned int);
                len += ft_putnbrbase(nb, "0123456789abcdef", 16);
            }
            else
                len += ft_printchar(str[i]);
        }
        i++;
    }
    va_end(args);
    return (len);
}