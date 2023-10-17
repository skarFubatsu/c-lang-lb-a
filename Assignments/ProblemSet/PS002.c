/*
    Final Task of "Problem Set 2 - Programming Assignment:
        Implementing a Travel Budget Calculator"
*/

#include <stdio.h>

void greet() {
  /* Greets user on console */
  printf("Welcome to Traxxie: Travel Expense Calculator\n");
}

void printLine() {
  for (int i = 0; i < 70; i++) {
    printf("=");
  }
  printf("\n");
}

void range(int start, int end) {
  if (end > start) {
    for (int i = start; i <= end; i++) {
      printf("%d, ", i);
    }
  } else {
    // user gets what they ask for ^-^
    printf(
        "( first number > second number. Numbers will be printed in reverse "
        "order )\n");
    for (int i = start; i >= end; i--) {
      printf("%d, ", i);
    }
  }
}

void oddRange(int start, int end) {
  if (end > start) {
    for (int i = start; i <= end; i++) {
      if (i % 2 == 0)
        // skip even values, dont print them
        continue;
      printf("%d, ", i);
    }
  } else {
    printf(
        "( first number > second number. Numbers will be printed in reverse "
        "order )\n");
    for (int i = start; i >= end; i--) {
      if (i % 2 == 0)
        continue;
      printf("%d, ", i);
    }
  }
}

int main() {
  // 1. Greet user
  printLine();
  greet();
  printLine();

  // 2. Input Budget
  float travel_budget, expenses = 0;
  printf("\nEnter your travel budget: ");
  scanf("%f", &travel_budget);

  // 3. Travel Expenses
  float travel_expense = 0, temp;
  printf(
      "\nEnter the esitmated cost of travel by bus, airline, train tickets "
      "etc: ");
  scanf("%f", &temp);
  travel_expense += temp;
  printf(
      "\nEnter the esitmated cost of travel by taxi or personal car (enter 0 "
      "if not applicable): ");
  scanf("%f", &temp);
  travel_expense += temp;
  printf("\nTotal Travel Expense: Rs. %.2f", travel_expense);

  // 4. accommodation expenses
  float accommodation_expense, days;
  printf("\n\nEnter the charge of accommodation for a night: ");
  scanf("%f", &temp);
  printf("\nHow many days do you plan to stay?: ");
  scanf("%f", &days);
  accommodation_expense = temp * days;

  // 5. daily expenses
  float daily_expenses;
  printf("\nEnter all the daily expenses such as food, entertainment, etc: ");
  scanf("%f", &temp);
  daily_expenses = temp * days;
  printf("\n");
  printLine();

  // 6. Calculate the total expenses and compare them with the budget
  expenses = travel_expense + accommodation_expense + daily_expenses;
  if (expenses > travel_budget) {
    temp = expenses - travel_budget;
    printf("\nYou are over budget. You'll need Rs. %.2f more!!", temp);
  } else {
    temp = travel_budget - expenses;
    printf("\nYou saved Rs. %.2f!! Extra money for your travel.", temp);
  }
  printf("\n\n");
  printLine();

  // 7. Using the logic you learned to print numbers between two values, ask the
  //    user for a range and print all numbers between them.
  printf("\nLets print some numbers!");
  int start, end;
  printf("\nEnter first number: ");
  scanf("%d", &start);
  printf("Enter second number: ");
  scanf("%d", &end);
  printf("\nNumbers between %d and %d: ", start, end);
  range(start, end);

  // 8. Modify the above logic to print only odd numbers between the given
  // range.
  printf("\nOdd Numbers between %d and %d: ", start, end);
  oddRange(start, end);

  printf("\n");
  printLine();

  // 9. determine the travel insurance cost based on the trip's total cost.
  int cutoff_amount = 20000;
  printf(
      "\nApplying Travel Insurance premium on following terms:\n\t- amount "
      "upto Rs. %d - 10%%\n\t- amount above Rs. %d - 15%%",
      cutoff_amount, cutoff_amount);
  float default_premium_perct = 10, travel_insurance_cost, overall_travel_cost;

  if (expenses > cutoff_amount) {
    default_premium_perct = 15;
  }
  travel_insurance_cost = (expenses * default_premium_perct) / 100;
  printf("\nPremium Amount for Travel Insurance: Rs. %.2f\n",
         travel_insurance_cost);
  overall_travel_cost = expenses + travel_insurance_cost;
  printf("\n");
  printLine();
  printf("Overall Expense for your travel: Rs. %.2f", overall_travel_cost);
  printf("\n");
  printLine();

  printf("\n\n[Program Finished]");
  return 0;
}
