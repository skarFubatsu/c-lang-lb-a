/*
  Final Task of
  "Problem Set 3 - Programming Assignment: Implementing a Banking System"
*/

#include <conio.h>
#include <stdio.h>
// https://stackoverflow.com/a/35377180
#include <string.h>

void greet() {
  /* Greets user on console */
  printf("Welcome to Chit Fund Bank: Apki seva me tatpar uwu\n");
}

void printLine() {
  for (int i = 0; i < 70; i++) {
    printf("=");
  }
  printf("\n");
}

int authentic(int account_number, char password[]) {
  return (account_number == 177013) && (strcmp(password, "Meta") == 0);
}

void printFibonacciSeries(int num) {
  int first_term = 0, second_term = 1, next;
  if (num == 0) {
    printf("Error: Enter a positive number");
    return;
  }
  if (num == 1) {
    printf("%d, %d,", first_term, second_term);
    return;
  }
  while (first_term <= num) {
    printf("%d, ", first_term);
    next = first_term + second_term;
    first_term = second_term;
    second_term = next;
  }
}

int main() {
  // 1. Greet user
  printLine();
  greet();
  printLine();

  // 2. User Login.
  int ac_num;
  char password[5];
  printf("\nEnter your bank account number: ");
  scanf("%d", &ac_num);
  printf("Enter Password: ");
  scanf("%s", &password);
  printf("\n");
  printLine();

  if (authentic(ac_num, password) == 0) {
    // Quit; ivalid login
    printf("You are not authorized to access bank portal.");
    return 0;
  }

  // Continue user is authenticated
  // 3. Main Menu
  float current_balance = 452125.00;  // For later use

  while (1) {
    printf(
        "\nHello! Glad to have you back. How can we help you today?"
        "\n\t 1) Check Balance"
        "\n\t 2) Deposit Money"
        "\n\t 3) Withdraw Money"
        "\n\t 4) Numbers divisible by 5 in given range"
        "\n\t 5) Sum of numbers in given range"
        "\n\t 6) Count number of digits in your account number"
        "\n\t 0) Exit");
    printf("\n");
    printLine();

    int choice;
    printf("Enter the corresponding number from above menu: ");
    scanf("%d", &choice);

    printLine();

    if (choice == 0) {
      // Exit loop
      printf("Thank You! Exiting...");
      break;
    }

    float withdraw_amt, deposit_amt;
    int start, end, temp, sum, count;

    switch (choice) {
      case 1:
        // 4. Check Balance
        printf("\nYour current bank balance is Rs. %.2f", current_balance);
        break;

      case 2:
        // 5. Deposit Money
        printf("\nEnter the amount you wish to deposit: ");
        scanf("%f", &deposit_amt);
        current_balance += deposit_amt;
        printf("\nUpdated balance: Rs. %.2f", current_balance);
        break;

      case 3:
        // 6. Withdraw Money
        printf("\nEnter the amount you wish to withdraw: ");
        scanf("%f", &withdraw_amt);
        if (withdraw_amt > current_balance) {
          printf(
              "\nInsufficent funds. You cant withdraw Rs. %.2f "
              "(Current Balance: Rs. %.2f)",
              withdraw_amt, current_balance);
        } else {
          current_balance -= withdraw_amt;
          printf("\nWithdrawed amount: Rs. %.2f\nUpdated Balance: Rs. %.2f",
                 withdraw_amt, current_balance);
        }
        break;

      case 4:
        // 7. Numbers Divisible by 5 (in range)
        printf("\nProvide following details for divisibility test of 5");
        printf("\nEnter first number: ");
        scanf("%d", &start);
        printf("Enter second number: ");
        scanf("%d", &end);
        if (start > end) {
          temp = start;
          start = end;
          end = temp;
        }
        printf("\nNumbers divisible by 5 between given range %d and %d: ",
               start, end);
        for (int i = start; i <= end; i++) {
          if (i % 5 == 0)
            printf("%d, ", i);
        }
        break;

      case 5:
        // 8. Sum of Numbers (in range)
        printf("\nProvide following details for summation");
        printf("\nEnter first number: ");
        scanf("%d", &start);
        printf("Enter second number: ");
        scanf("%d", &end);
        if (start > end) {
          temp = start;
          start = end;
          end = temp;
        }

        sum = 0;
        for (int i = start; i <= end; i++) {
          sum += i;
        }
        printf("\nSum of all numbers between %d and %d: %d", start, end, sum);
        break;

      case 6:
        // 9. Counting Digits (a/c no.)
        count = 0, temp = ac_num;
        while (temp != 0) {
          temp /= 10;
          count++;
        }
        printf("There are %d digits in your account number.", count);
        break;

      default:
        // 10.2 Fibonacci Series (Easter Egg)
        printf(
            "Hooray!! You found an Easter Egg.\nPrinting Fibonacci Series upto "
            "%d: ",
            choice);
        printFibonacciSeries(choice);
        break;
    }
    printf("\n");
    printLine();
    printf("Press return to go back to main menu...");
    getch();
    printf("\n");
    printLine();
  }

  printf("\n");
  printLine();

  // 10.1 Print Fibonacci Series
  int num;
  printf("Enter a number to print Fibonacci Series: ");
  scanf("%d", &num);
  printf("Printing Fibonacci Series upto %d: ", num);
  printFibonacciSeries(num);

  printf("\n\n[Program Finished]");
  return 0;
}
