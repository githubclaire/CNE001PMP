#include "string.h"
void *memcpy(void *dest, const void *src, unsigned int count)
{
	char *tmp = dest;
	const char *s = src;

	while (count--)
		*tmp++ = *s++;
	return dest;
}
void *memcpy32bit(void *dest, const void *src, unsigned int count)
{
	unsigned int len= count/4;
	volatile int *tmp = dest;
	volatile const int  *s = src;

	while (len--)
		*tmp++ = *s++;
	return dest;
}
void *memset(void *s, int c, unsigned int count)
{
	char *xs = s;

	while (count--)
		*xs++ = c;
	return s;
}
/**
 * memmove - Copy one area of memory to another
 * @dest: Where to copy to
 * @src: Where to copy from
 * @count: The size of the area.
 *
 * Unlike memcpy(), memmove() copes with overlapping areas.
 */
void *memmove(void *dest, const void *src, unsigned int count)
{
	char *tmp;
	const char *s;

	if (dest <= src) {
		tmp = dest;
		s = src;
		while (count--)
			*tmp++ = *s++;
	} else {
		tmp = dest;
		tmp += count;
		s = src;
		s += count;
		while (count--)
			*--tmp = *--s;
	}
	return dest;
}
/**
 * strncmp - Compare two length-limited strings
 * @cs: One string
 * @ct: Another string
 * @count: The maximum number of bytes to compare
 */
int strncmp(const char *cs, const char *ct, int count)
{
	unsigned char c1, c2;

	while (count) {
		c1 = *cs++;
		c2 = *ct++;
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
		if (!c1)
			break;
		count--;
	}
	return 0;
}
/**
 * strncpy - Copy a length-limited, %NUL-terminated string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 * @count: The maximum number of bytes to copy
 *
 * The result is not %NUL-terminated if the source exceeds
 * @count bytes.
 *
 * In the case where the length of @src is less than  that  of
 * count, the remainder of @dest will be padded with %NUL.
 *
 */
char *strncpy(char *dest, const char *src, int count)
{
	char *tmp = dest;

	while (count) {
		if ((*tmp = *src) != 0)
			src++;
		tmp++;
		count--;
	}
	return dest;
}

int strcmp(const char *cs, const char *ct)
{
	unsigned char c1, c2;

	while (1) {
		c1 = *cs++;
		c2 = *ct++;
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
		if((!c1) && (c1==c2)){
			break;
		}
		else if (!c1){
			return 1;
		}
		else if(!c2){
			return -1;
		}
		//	break;
	}
	return 0;
}

/**
 * strchr - Find the first occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to search for
 */
char *strchr(const char *s, int c)
{
	for (; *s != (char)c; ++s)
		if (*s == '\0')
			return NULL;
	return (char *)s;
}
/**
 * strlen - Find the length of a string
 * @s: The string to be sized
 */
int strlen(const char *s)
{
	const char *sc;

	for (sc = s; *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}
/**
 * strcpy - Copy a %NUL terminated string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 */
char *strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while ((*dest++ = *src++) != '\0')
		/* nothing */;
	return tmp;
}
#define is_digit(c)	((c) >= '0' && (c) <= '9')
#define is_hex(c)	((c) >= 'a' && (c) <= 'f')
#define is_HEX(c)	((c) >= 'A' && (c) <= 'F')
/*
unsigned long simple_strtoul(const char *cp, char * *endp, unsigned int base)
{
	unsigned long result = 0, value;

	if (*cp == '0') {
		cp++;
		if ((*cp == 'x') && isxdigit(cp[1])) {
			base = 16;
			cp++;
		}
		if (!base) {
			base = 8;
		}
	}
	if (!base) {
		base = 10;
	}
	while (isxdigit(*cp) && (value = isdigit(*cp)*cp - '0' : (islower(*cp)
								     toupper(*cp) : *cp) - 'A' + 10) < base) {
		result = result * base + value;
		cp++;
	}
	if (endp)
		*endp = (char *)cp;
	return result;
}
*/
 int atoi(const char *s)
{
	int i = 0;
	if(s==0)
		return 0;
	while (is_digit(*s))
		i = i * 10 + *((s)++) - '0';

	return i;
}

 int atoh(const char *s)
{
	int i = 0;
	char a,b;
	if(s==0)
		return 0;
	a = *(s);
	b = *(s+1);
if((a == '0') && ((b == 'x') || (b = 'X')))
{
	(s)++;(s)++;
	while (is_digit(*s) || is_hex(*s) || is_HEX(*s)){
		if(is_digit(*s)){
			i = i * 16 + *(s++) - '0';
		}else if(is_hex(*s)){
			i = i * 16 + *(s++) - 'a' + 10;
		}else if(is_HEX(*s)){
			i = i * 16 + *(s++) - 'A' + 10;
		}else{
			return  -1;
		}

	}

}else{
	i = atoi(s);
}
	return i;
}

  char *reverse(char *s)
{
    char temp;
    char *p = s;
    char *q = s;
    while(*q)
        ++q;
    q--;
    while(q > p)
    {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
    return s;
}

static void a1(int k,int * p,int * q)
{
	int n=0;
	int m = 1;
	while(1)
	{
		if(k<=100*m)
		{
			n = (m-1)*10;
			k = k - (m-1)*100;
			while(k>=10)
			{
				k=k-10;
				n++;
			}
			*p = k;
			*q = n;
			break;
		}
		else
		{
			m++;
		}
	}
}

static void a2(int k,int * p,int * q)
{
	int n=0;
	int m = 1;
	while(1)
	{
		if(k<=1000*m)
		{
			n = (m-1)*100;
			k = k - (m-1)*1000;
			a1(k,p,q);
			*q = *q + n;
			break;
		}
		else
		{
			m++;
		}
	}
}

static void a3(int k,int * p,int * q)
{
	int n=0;
	int m = 1;
	while(1)
	{
		if(k<=10000*m)
		{
			n = (m-1)*1000;
			k = k - (m-1)*10000;
			a2(k,p,q);
			*q = *q + n;
			break;
		}
		else
		{
			m++;
		}
	}
}

static void a4(int k,int * p,int * q)
{
	int n=0;
	int m = 1;
	while(1)
	{
		if(k<=100000*m)
		{
			n = (m-1)*10000;
			k = k - (m-1)*100000;
			a3(k,p,q);
			*q = *q + n;
			break;
		}
		else
		{
			m++;
		}
	}
}

static void a5(int k,int * p,int * q)
{
	int n=0;
	int m = 1;
	while(1)
	{
		if(k<=1000000*m)
		{
			n = (m-1)*100000;
			k = k - (m-1)*1000000;
			a4(k,p,q);
			*q = *q + n;
			break;
		}
		else
		{
			m++;
		}
	}
}

static void a6(int k,int * p,int * q)
{
	int n=0;
	int m = 1;
	while(1)
	{
		if(k<=10000000*m)
		{
			n = (m-1)*1000000;
			k = k - (m-1)*10000000;
			a5(k,p,q);
			*q = *q + n;
			break;
		}
		else
		{
			m++;
		}
	}
}

static void chufa(int k,int * p,int * q) //p--%10,q--/10
 {   			
		if(k<=1000)
		{
			a1(k,p,q);
		}
		else if((k>1000) && (k<=10000))
		{
			a2(k,p,q);
		}
		else if((k>10000) && (k<=100000))
		{
			a3(k,p,q);
		}
		else if((k>100000)&&(k<=1000000))
		{
			a4(k,p,q);
		}
		else if((k>1000000)&&(k<=10000000))
		{
			a5(k,p,q);
		}
		else
		{
			a6(k,p,q);
		}
  }

 char *my_itoa(int n)
{
    unsigned int i = 0,isNegative = 0;
    static char s[100];
    int y=0,c=0;
    if((isNegative = n) < 0)
    {
        n = -n;
    }
    do
    {
	    chufa(n,&y,&c);
	    s[i++] = y + '0';
            n = c;	
    }while(n > 0);
    if(isNegative < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    return reverse(s);
}
 
char *tohex_str(int k)
{
	char a[8];
	static char s[10];
	unsigned char i=0,j=0,n=0;
	do{
		a[i] = k&0xf;
		k=(k>>4) & 0x0fffffff;
		i++;
	}while(k);
	i--;
	for(j=i;j>=0;j--)
	{
		if(a[j]<=9)
			s[n] = a[j] + '0';
		else s[n] = a[j] + 87;
		n++;
		if(j==0) break;
	}
	s[n] = '\0';

	return s;
}
