#include <stdio.h>

void PrintEnterNumber();

void PrintIsPalindrome();

void PrintIsNotPalindrome();

int ReverseNum(int num, int temp);

int main() {
    int num = 0;
    PrintEnterNumber();
    scanf("%d", &num);
    int temp = ReverseNum(num, 0);

    if (num == temp) {
        PrintIsPalindrome();
    } else {
        PrintIsNotPalindrome();
    }
    return 0;
}

/**
 * Function to reverse the digits of a number,
 * The function receives the number to reverse and the temporary reversal result
 * The function will add the last digit of the input number to the end of the result
 * and recursively call the next iteration with the input number without it's last digit
 * @param num The number to reverse
 * @param temp The temporary reversal result
 * @return The reversed number
 */
int ReverseNum(int num, int temp) {
    if (num == 0) {
        // We finished reversing the number's digits
        return temp;
    }

    // Add the last digit of num to the end of temp
    temp = (temp * 10) + (num % 10);

    // Call a recursive reversal with the number without it's last digit
    // (Because we already took care of it)
    return ReverseNum(num / 10, temp);
}

void PrintEnterNumber() {
    printf("Please enter a number:\n");
}

void PrintIsPalindrome() {
    printf("It's a palindrome!");
}

void PrintIsNotPalindrome() {
    printf("It's not a palindrome!");
}