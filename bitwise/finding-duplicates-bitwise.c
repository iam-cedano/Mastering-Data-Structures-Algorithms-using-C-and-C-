#include <stdio.h>

int main() {
    int repository = 0;

    char verifier = 12;

    char H = 'z';

    char letterToFind = 'f';

    repository = repository | H;

    char result = repository & letterToFind;

    printf("%i \n", result);

    if ( ( repository & letterToFind ) == letterToFind ) {
        printf("Letter duplicated!");
    } else {
        printf("Letter is not duplicated!");
    }

    return 0;
}