#include "main.cpp"

int main(int argc, char** argv) {
    if(argc == 0) {
        throw std::invalid_argument("Null pointer");
    }
    else {
        for(int i = 0; i < argc; i++) {
            reverse(*(argv+i));
            std::cout << *(argv+i) ;
        }
    }
}