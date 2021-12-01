#include "IntroSort.h"

int main(int argc, char *argv[]) {
    srand((unsigned int) time(NULL));
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = rand() % 100;
    }
    int size = sizeof array / sizeof array[0];
    ShowArray(array, size);
    IntroSort(array, size);
    ShowArray(array, size);
    return 0;
}
