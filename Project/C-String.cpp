
#include <iostream>

int mylen(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int compare(char s[], char t[]) {
    int lens = mylen(s);
    int lent = mylen(t);
    for (int i = 0; i < lens; i++) {
        if(t[i] == '\0') {
            return 1;
        }
        if(s[i] < t[i]) {
            return -1;
        }
        if(s[i] > t[i]) {
            return 1;
        }
    }
    if(lent > lens) {
        return -1;
    }
    else if(lent == lens) {
        return 0;
    }
}


int main() {
    char s[] = {'h','e','l','l','\0'};
    char t[] = {'h','e','l','l','o','\0'};
    printf("%d\n", compare(s,t));
}