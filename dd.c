#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_int(const char *prompt) {
    char buf[128];
    int val;
    while (1) {
        if (prompt) printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) {
            clearerr(stdin);
            return 0;
        }
        if (sscanf(buf, "%d", &val) == 1) return val;
        printf("Invalid input. Please enter an integer.\n");
    }
}

static float get_float(const char *prompt) {
    char buf[128];
    float val;
    while (1) {
        if (prompt) printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) {
            clearerr(stdin);
            return 0.0f;
        }
        if (sscanf(buf, "%f", &val) == 1) return val;
        printf("Invalid input. Please enter a number.\n");
    }
}

int main(void) {
    const int pin = 1234;
    int enteredPin, choice;
    float balance = 5000.0f, withdraw, deposit;

    printf("****** WELCOME TO MINI ATM ******\n");
    enteredPin = get_int("Please enter your PIN: ");

    if (enteredPin != pin) {
        printf("Incorrect PIN. Exiting...\n");
        return 0;
    }

    do {
        printf("\n----- ATM Menu -----\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Exit\n");
        choice = get_int("Enter your choice: ");

        switch (choice) {
            case 1:
                printf("Your current balance is: %.2f\n", balance);
                break;
            case 2:
                withdraw = get_float("Enter amount to withdraw: ");
                if (withdraw > balance)
                    printf("Insufficient balance!\n");
                else if (withdraw <= 0.0f)
                    printf("Invalid amount!\n");
                else {
                    balance -= withdraw;
                    printf("Collect your cash. New balance: %.2f\n", balance);
                }
                break;
            case 3:
                deposit = get_float("Enter amount to deposit: ");
                if (deposit <= 0.0f)
                    printf("Invalid amount!\n");
                else {
                    balance += deposit;
                    printf("Deposit successful. New balance: %.2f\n", balance);
                }
                break;
            case 4:
                printf("Thank you for using this ATM!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
