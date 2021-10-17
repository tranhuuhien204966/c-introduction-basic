void replace_char(char *str, char c1, char c2)
{
if (str == NULL)
return;
while (*str != '\0')
{
if (*str == c1)
*str = c2;
++str;
}
}


