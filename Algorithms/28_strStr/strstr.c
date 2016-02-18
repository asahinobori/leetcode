int lenOfstr(char* string) {
    int len = 0;
    while (*string != '\0') {
        len++;
        string++;
    }
    return len;
}

int strStr(char* haystack, char* needle) {
    int lenOfHaystack = lenOfstr(haystack);
    int lenOfNeedle = lenOfstr(needle);
    int diff = lenOfHaystack - lenOfNeedle;
    int count = 0;
    int i = 0;
    char* p = needle;
    char* q = haystack;
    if (diff < 0) {
        return -1;
    }
    for (; i <= diff; i++) {
        while (*p == *q && *p != '\0') {
            count++;
            p++;
            q++;
        }
        if (count == lenOfNeedle) {
            return i;
        }
        count = 0;
        p = needle;
        q = haystack + i + 1;
    }
    return -1;
}
