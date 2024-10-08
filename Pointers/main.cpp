#include <iostream>

int mylen(const char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* reverse(char* s) {
    const int lens = mylen(s);
    char rev[lens+1];
    rev[lens] = '\0';
    for(int i = 0; i <lens; i++) {
        rev[lens-1-i] = s[i];
    }
    for(int i = 0; i <lens; i++) {
        s[i] = rev[i];
    }

    // printf("%s",rev);
    return s;
}

char* concatenate(const char* s1, const char* s2) {
    int len1 = mylen(s1);
    int len2 = mylen(s2);
    int lens = len1 + len2;
    char* result = new char[lens];
    for(int i = 0; i <lens; i++) {
        if(i<len1) {
            result[i] = s1[i];
        }
        else {
            result[i] = s2[i-len1];
        }
    }
    result[lens] = '\0';
    return result;
}

// int main() {
//     const char* s = "rizz";
//     char* t = new char[8]{'r','i','z','z','l','e','r','\0'};
//     char pal[] = {'t','a','c','o','c','a','t','\0'};
//     printf("%s\n", reverse(t));
//     char* test = concatenate(s, t);
//     printf("%s\n", test);
//     delete[] test;
//     delete[] t;
//     return 0;
// }
