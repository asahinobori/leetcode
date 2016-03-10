int romanToInt(char* s) {
    int result = 0;
    while (*s != '\0') {
        switch (*s) {
            case 'I' :
                result++;
                break;
            case 'V' :
                if (*(s-1) == 'I' && result != 0) {
                    result += 3;
                } else {
                    result += 5;
                }
                break;
            case 'X' :
                if (*(s-1) == 'I' && result != 0) {
                    result += 8;
                } else {
                    result += 10;
                }
                break;
            case 'L' :
                if (*(s-1) == 'X' && result != 0) {
                    result += 30;
                } else {
                    result += 50;
                }
                break;
            case 'C' :
                if (*(s-1) == 'X' && result != 0) {
                    result += 80;
                } else {
                    result += 100;
                }
                break;
            case 'D' :
                if (*(s-1) == 'C' && result != 0) {
                    result += 300;
                } else {
                    result += 500;
                }
                break;
            case 'M' :
                if (*(s-1) == 'C' && result != 0) {
                    result += 800;
                } else {
                    result += 1000;
                }
                break;
            default :
                ;
        }
        s++;
    }
    return result;
}

// Basic Character
// I V X  L  C   D   M
// 1 5 10 50 100 500 1000

