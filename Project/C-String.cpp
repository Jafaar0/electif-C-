
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

bool palindrome(char s[]) {
    int lens = mylen(s);
    int demi = lens/2;
    for (int i = 0; i < demi; i++) {
        if(s[i] != s[lens-1-i]) {
            return false;
        }
    }
    return true;

}

void reverse(char s[]) {
    int lens = mylen(s);
    char rev[lens+1];
    rev[lens] = '\0';
    for(int i = 0; i <lens; i++) {
        rev[lens-1-i] = s[i];
    }
    printf("%s",rev);
}


int main() {
    // char s[] = {'h','e','l','l','\0'};
    // char t[] = {'h','e','l','l','o','\0'};
    char s[] = {'r','i','z','z','\0'};
    char t[] = {'r','i','z','z','l','e','r','\0'};
    char pal[] = {'t','a','c','o','c','a','t','\0'};
    printf("%d\n", compare(s,t));
    printf("%s\n", palindrome(s) ? "true" : "false");
    printf("%s\n", palindrome(pal) ? "true" : "false");
    reverse(s);
}