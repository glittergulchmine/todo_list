#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "ctype.h"

int isValidDate(const char* date) {
    // Simple validation: check format and verify characters are digits where expected
    return strlen(date) == 10 && date[4] == '-' && date[7] == '-' &&
           isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) &&
           isdigit(date[5]) && isdigit(date[6]) && isdigit(date[8]) && isdigit(date[9]);
}

int isValidTime(const char* time) {
    // Simple validation: check format and verify characters are digits where expected
    return strlen(time) == 5 && time[2] == ':' &&
           isdigit(time[0]) && isdigit(time[1]) &&
           isdigit(time[3]) && isdigit(time[4]);
}