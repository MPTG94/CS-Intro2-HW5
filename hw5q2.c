#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

void PrintWelcomeMessage();

void PrintSourceCityMessage();

void PrintDestinationCityMessage();

void PrintShortestPathMessage();

int FindShortestPath(int roads[N][N], int source, int dest, int path[N]);

int ShortestPath(int roads[N][N], int start, int final, bool used[N][N], int currentDist, int minDist);

void CopyBoolArr(bool source[N][N], bool dest[N][N]);

void PrintBoolArr(bool arr[N][N]);

void PrintCurrentRoute(bool arr[N][N], int source);

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
    bool used[N][N] = {{false}};
    int result = ShortestPath(roads, source, dest, used, 0, roads[source][dest]);
//    bool test[N][N] = {{false, false, false, true},
//            {false, false, false, false},
//            {false, false, false, false},
//            {false, true,  false, false}};
//    printf("start at city %d\n", source);
    PrintCurrentRoute(used, source);
    return result;
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

int ShortestPath(int roads[N][N], int start, int final, bool used[N][N], int currentDist, int minDist) {
    if (start == final) {
        return currentDist;
    }

    bool tempUsed[N][N] = {{false}};
    CopyBoolArr(used, tempUsed);

    for (int j = 0; j < N; j++) {
        // Setting current distance
        if (!tempUsed[start][j]) {
            currentDist += roads[start][j];
            tempUsed[start][j] = true;
            int receivedDist = ShortestPath(roads, j, final, tempUsed, currentDist, minDist);
            if (receivedDist < minDist) {
                CopyBoolArr(tempUsed, used);
                minDist = receivedDist;
            }
            currentDist -= roads[start][j];
            tempUsed[start][j] = false;
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

void PrintCurrentRoute(bool arr[N][N], int source) {
    for (int j = 0; j < N; ++j) {
        if (source == j && arr[source][j]) {
            printf("Passed through city: %d\n", j);
            continue;
        }
        if (arr[source][j]) {
            printf("Passed through city: %d\n", j);
            PrintCurrentRoute(arr, j);
            break;
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
