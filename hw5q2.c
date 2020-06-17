#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

void PrintWelcomeMessage();

void PrintSourceCityMessage();

void PrintDestinationCityMessage();

void PrintShortestPathMessage();

void PrintNumber(int num);

void PrintWhiteSpace();

int main() {
    int roads[N][N] = {{0}};

    PrintWelcomeMessage();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &roads[i][j]);
        }
    }

    int source = 0;
    PrintSourceCityMessage();
    scanf("%d", &source);

    int dest = 0;

    PrintDestinationCityMessage();
    scanf("%d", &dest);

    PrintShortestPathMessage();


    return 0;
}

void PrintWelcomeMessage() {
    printf("Please enter road matrix:\n");
}

void PrintSourceCityMessage() {
    printf("Please enter source city:\n");
}

void PrintDestinationCityMessage() {
    printf("Please enter destination city:\n");
}

void PrintShortestPathMessage() {
    printf("The shortest path is:\n");
}

void PrintNumber(int num) {
    printf("%d", num);
}

void PrintWhiteSpace() {
    printf(" ");
}
