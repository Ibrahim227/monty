/**
* _atoi - change str to int
* @n: var to convert
* Return: converted int
*/
int _atoi(char *n)
{
int i = 1;
unsigned int num = 0;
do {
if (*n == '-')
i *= -1;
else if (*n >= '0' && *n <= '9')
num = num * 10 + (*n - '0');
else if (num > 0)
break;
} while (*n++);
return (num *i);
}
