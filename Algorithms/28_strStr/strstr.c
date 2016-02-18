// int lenOfstr(char* string) {
//     int len = 0;
//     while (*string != '\0') {
//         len++;
//         string++;
//     }
//     return len;
// }

int strStr(char* haystack, char* needle) {
    int lenOfHaystack = strlen(haystack);
    int lenOfNeedle = strlen(needle);
    int diff = lenOfHaystack - lenOfNeedle;
    for (int i = 0; i <= diff; i++) {
        int j = i;
        int count = 0;
        while (haystack[j] == needle[count] && needle[count] != '\0') {
        // while (j < lenOfHaystack && count < lenOfNeedle && haystack[j] == needle[count]) {
            count++;
            j++;
        }
        if (count == lenOfNeedle) return i;
    }
    return -1;
}
