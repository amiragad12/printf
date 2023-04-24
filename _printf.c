#include "main.h"
int _printf(const char *format, ...) 
{
    va_list args;
    va_start(args, format);
    
    int count = 0;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c':
                    count += printf("%c", va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    count += printf("%%");
                    break;
            }
        } else {
            count += printf("%c", format[i]);
        }
    }
    
    va_end(args);
    return count;
}

