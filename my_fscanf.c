// file: my_fscanf.c
#define _CRT_SECURE_NO_WARNINGS
#include "my_fscanf.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list,format);
	while(*format) {
		if(*format == '%') {
			int d;
			int num = 0;
			size_t size = 0;
			char c;
			char* s = (char*)malloc(sizeof(char)*size);
			char* t;
			double f = 0;
			int pointSwitch = 0;
			double underPoint = 10;
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
				case 's':
					while (isspace(c=getc(fp))) {}
					while (isalpha(c)) {
						size++;
						s = (char*)realloc(s, sizeof(char)*size);
						s[num] = c;
						num++;
						c = getc(fp);
					}
					ungetc(c, fp);
					strcpy(t = va_arg(list, char*), s);
					t[num] = '\0';
					format++;
					break;
				case 'f':
					while (isspace(c = getc(fp)) || ispunct(c)) {}
					while (isdigit(c) || c == '.') {
						if (c == '.') {pointSwitch = 1;}
						else if (!pointSwitch) {
							f = f * 10 + atof(&c);
						}
						else {
							f = f + atof(&c) / underPoint;
							underPoint *= 10.0;
						}
						c = getc(fp);
					}
					ungetc(c, fp);
					*va_arg(list, double*) = f;
					format++;
					break;
			}
			free(s);
		}
		else if (isspace(*format)) {
			format++;
		}
		else if (ispunct(*format)) {
			getc(fp);
			format++;
		}
		else
			break;
	}
	va_end(list);
}
