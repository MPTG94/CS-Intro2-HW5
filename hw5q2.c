#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

void PrintWelcomeMessage();

void PrintSourceCityMessage();

void PrintDestinationCityMessage();

void PrintShortestPathMessage();

int FindShortestPath(int roads[N][N], int source, int dest);

int ShortestPath(int roads[N][N], int start, int final, bool used[N][N], int currentDist, int minDist, bool passed[N]);

void CopyBoolArr(bool source[N][N], bool dest[N][N]);

void PrintBoolArr(bool arr[N][N]);

void PrintCurrentRoute(bool arr[N][N], int source, int dest);

void PrintNumber(int num);

void PrintWhiteSpace();

int main() {
    setbuf(stdout, 0);
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

    int pathLength = 0;
    pathLength = FindShortestPath(roads, source, dest);

    //PrintShortestPathMessage();


    return 0;
}

int FindShortestPath(int roads[N][N], int source, int dest) {
    bool used[N][N] = {{false}};
    bool passed[N] = {false};
    passed[source] = true;
    int result = ShortestPath(roads, source, dest, used, 0, -1 , passed);
    PrintShortestPathMessage();
    PrintNumber(source);
    PrintWhiteSpace();
    PrintCurrentRoute(used, source, dest);
    return result;
}

int ShortestPath(int roads[N][N], int start, int final, bool used[N][N], int currentDist, int minDist, bool passed[N]) {
    if (start == final) {
        return currentDist;
    }

    bool tempUsed[N][N] = {{false}};
    CopyBoolArr(used, tempUsed);

    for (int j = 0; j < N; j++) {
        if (start == j) {
            continue;
        }
        // Setting current distance
        if (!passed[j]) {
            if (!tempUsed[start][j]) {
                passed[j] = true;
                currentDist += roads[start][j];
                tempUsed[start][j] = true;
                int receivedDist = ShortestPath(roads, j, final, tempUsed, currentDist, minDist, passed);
                if (receivedDist < minDist || minDist == -1) {
                    CopyBoolArr(tempUsed, used);
                    minDist = receivedDist;
                }
                currentDist -= roads[start][j];
                passed[j] = false;
                tempUsed[start][j] = false;
            }
        }

    }

    return minDist;
}

void CopyBoolArr(bool source[N][N], bool dest[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dest[i][j] = source[i][j];
        }
    }
}

void PrintCurrentRoute(bool arr[N][N], int source, int dest) {
    for (int j = 0; j < N; ++j) {
//        if (source == j && arr[source][j]) {
//            printf("origin city: %d\n", j);
//            continue;
//        }
        if (arr[source][j]) {
            PrintNumber(j);
            if (j != dest) {
                PrintWhiteSpace();
            }
            PrintCurrentRoute(arr, j, dest);
            break;
        }
    }
}

void PrintBoolArr(bool arr[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j]) {
                printf("Should pass through city %d %d\n", i, j);
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
