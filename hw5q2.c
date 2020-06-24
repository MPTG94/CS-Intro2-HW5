#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

void PrintWelcomeMessage();

void PrintSourceCityMessage();

void PrintDestinationCityMessage();

void PrintShortestPathMessage();

int FindShortestPath(int roads[N][N], int source, int dest, int path[N]);

int ShortestPath(int roads[N][N], int start, int final, int used[N][N], int currentDist, int minDist);

void CopyIntArr(int source[N][N], int dest[N][N]);

void PrintIntArr(int arr[N][N]);

void PrintCurrentRoute(int arr[N][N]);

void PrintNumber(int num);

void PrintWhiteSpace();

int main() {
    setbuf(stdout, 0);
    int roads[N][N] = {{0}};
    int path[N] = {0};

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

    int pathLength = 0;
    pathLength = FindShortestPath(roads, source, dest, path);

    PrintShortestPathMessage();


    return 0;
}

int FindShortestPath(int roads[N][N], int source, int dest, int path[N]) {
    int used[N][N] = {{-1}};
    int result = ShortestPath(roads, source, dest, used, 0, roads[source][dest]);
    PrintIntArr(used);
    return result;
}

void PrintIntArr(int arr[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] != 0) {
                printf("Should pass through city %d %d\n", i, j);
            }
        }
    }
}

int ShortestPath(int roads[N][N], int start, int final, int used[N][N], int currentDist, int minDist) {
    if (start == final) {
        return 0;
    }

    int tempUsed[N][N] = {{-1}};
    CopyIntArr(used, tempUsed);

    for (int j = 0; j < N; j++) {
        if (tempUsed[start][j] == -1) {
            currentDist += roads[start][j];
            tempUsed[start][j] = j;
            int receivedDist = ShortestPath(roads, j, final, tempUsed, currentDist, minDist);
            receivedDist += currentDist;
            //PrintCurrentRoute(tempUsed);
            if (receivedDist < minDist) {
                // Found new minimum distance
                CopyIntArr(tempUsed, used);
                minDist = receivedDist;
            }
            currentDist -= roads[start][j];
            tempUsed[start][j] = -1;
        }
    }

    return minDist;
}

void CopyIntArr(int source[N][N], int dest[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dest[i][j] = source[i][j];
        }
    }
}

void PrintCurrentRoute(int arr[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] != -1) {
                printf("Passed through city %d\n", arr[i][j]);
            }
        }
    }
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
