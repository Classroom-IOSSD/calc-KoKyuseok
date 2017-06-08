// file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list,format);
	while(*format) {
		if(*format == '%') {
			int d = 0;
			int num = 0;
			format++;
			switch (*format){
				case 'd':
				while (isdigit(d = getc(fp))) {
					num = num*10 + d-'0';
				}
				*va_arg(list,int*) = num;
				format++;
				break;
				case 'c':
				*va_arg(list,char*) = getc(fp);
				getc(fp);
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
