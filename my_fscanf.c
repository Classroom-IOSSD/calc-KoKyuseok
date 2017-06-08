// file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list,format);
	while(*format) {
		if(*format == '%') {
			int d;
			int num = 0;
			char c;
			format++;
			switch (*format){
				case 'd':
				while (isspace(d=getc(fp))) {}
				while (isdigit(d)) {
					num = num*10 + d-'0';
					d = getc(fp);
				}
				ungetc(d,fp);
				*va_arg(list,int*) = num;
				format++;
				break;
				case 'c':
				while (isspace(c=getc(fp))) {}
				*va_arg(list,char*) = c;
				format++;
				break;
			}
		}
		else if(isspace(*format)) {
			format++;
		}
		else
			break;
	}
	va_end(list);
}
