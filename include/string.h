#ifndef STRING_H
#define STRING_H
#ifndef NULL
#define NULL	0
#endif
void *memcpy(void *dest, const void *src, unsigned int count);
void *memcpy32bit(void *dest, const void *src, unsigned int count);
void *memset(void *s, int c, unsigned int count);
int strcmp(const char *cs, const char *ct);
int strlen(const char *s);
int strncmp(const char *cs, const char *ct, int count);
char *strncpy(char *dest, const char *src, int count);
char *strcpy(char *dest, const char *src);
char *strchr(const char *s, int c);
int atoi(const char *s);
int atoh(const char *s); 

char *reverse(char *s);
char *tohex_str(int k);
char *my_itoa(int n);

#endif