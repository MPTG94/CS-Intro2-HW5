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

void PrintCurrentRoute(bool arr[N][N], int source, int dest);

void PrintNumber(int num);

void PrintWhiteSpace();

int main() {
    int roads[N][N] = {{0}};

    PrintWelcomeMessage();
    // Taking roads matrix as input
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &roads[i][j]);
        }
    }

    // Getting source city
    int source = 0;
    PrintSourceCityMessage();
    scanf("%d", &source);

    // Getting destination city
    int dest = 0;
    PrintDestinationCityMessage();
    scanf("%d", &dest);

    // Calling recursion handler
    FindShortestPath(roads, source, dest);
    return 0;
}

/**
 * Handler method to call the backtracking recursion
 * @param roads The roads matrix
 * @param source The starting city of the route
 * @param dest The destination city of the route
 * @return The length of the shortest route
 */
int FindShortestPath(int roads[N][N], int source, int dest) {
    bool used[N][N] = {{false}};
    bool passed[N] = {false};
    // Calling backtracking recursion, result will save the length of the shortest route
    int result = ShortestPath(roads, source, dest, used, 0, -1, passed);
    PrintShortestPathMessage();
    // Printing source city
    PrintNumber(source);
    PrintWhiteSpace();
    // Printing extra cities based on used array
    PrintCurrentRoute(used, source, dest);
    return result;
}

/**
 * Backtracking method to iterate through all paths and find the shortest one
 * @param roads The roads matrix
 * @param start The starting city of the current iteration
 * @param final The destination city
 * @param used An array marking the city intersections we passed through
 * @param currentDist The current distance
 * @param minDist The minimal distance we found up until now
 * @param passed An array marking cities we passed through
 * @return The minimal distance length of the current iteration
 */
int ShortestPath(int roads[N][N], int start, int final, bool used[N][N], int currentDist, int minDist, bool passed[N]) {
    // Reached the end of the track, current dist is final dist
    if (start == final) {
        return currentDist;
    }

    // Creating temporary array to remember where we've been in this route
    bool tempUsed[N][N] = {{false}};
    CopyBoolArr(used, tempUsed);

    for (int j = 0; j < N; j++) {
        // The diagonal is full of zeros, no need to check it
        if (start == j) {
            continue;
        }
        if (!passed[j]) {
            // We still haven't passed through the city j
            if (!tempUsed[start][j]) {
                // Marking city j in current route
                passed[j] = true;
                // adding distance
                currentDist += roads[start][j];
                // Marking as part of current route
                tempUsed[start][j] = true;
                // Next iteration, using current city j as source
                int receivedDist = ShortestPath(roads, j, final, tempUsed, currentDist, minDist, passed);
                // Checking if the distance is a new minimal
                if (receivedDist < minDist || minDist == -1) {
                    CopyBoolArr(tempUsed, used);
                    minDist = receivedDist;
                }
                // reverting current iteration
                currentDist -= roads[start][j];
                passed[j] = false;
                tempUsed[start][j] = false;
            }
        }
    }

    return minDist;
}

/**
 * Copies the values from source array to destination
 * @param source The source array
 * @param dest The destination array
 */
void CopyBoolArr(bool source[N][N], bool dest[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dest[i][j] = source[i][j];
        }
    }
}

/**
 * Iterates the used array and prints the cities that we passed during the shortest route
 * @param arr A boolean array with true in the place of the cities we really passed through
 * @param source The source city of the current print
 * @param dest The destination city from the user input
 */
void PrintCurrentRoute(bool arr[N][N], int source, int dest) {
    for (int j = 0; j < N; ++j) {
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
