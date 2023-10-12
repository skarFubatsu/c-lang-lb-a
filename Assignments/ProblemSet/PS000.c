/*
    Final Task of "Problem Set 0 - Programming Assignment: Implementing a
   Grocery Billing System"
*/

#include <stdio.h>

void greet() {
  // Prints a welcome message to user
  printf("\nWelcome to Handy Mandy Hardware Store!");
}

int getDiscount(float amount) {
  if (amount > 100)
    return 10;
  if (amount >= 50 && amount <= 100)
    return 5;
  return 0;
}

float calcDiscount(float total, float per) {
  return (total * per) / 100;
}

int isLeapYear(int year) {
  return year % 4 == 0;
}

int main() {
  // 1. Greet user
  greet();

  // 2. Register products price and quantity
  float price, quantity, total_price = 0, total_qantity = 0;
  char stop;
  while (1) {
    printf("\n\nEnter product Selling Price: ");
    scanf("%f", &price);
    printf("Enter quantity: ");
    scanf("%f", &quantity);

    total_qantity += quantity;
    total_price += price * quantity;

    printf(
        "\nCurrent Bill Amount = Rs. %.2f"
        "\nItem Quantity = %.f\n",
        total_price, total_qantity);

    // Manually break loop when all items are registered
    printf("\nDo you want to add more items? (y/n): ");
    scanf(" %c", &stop);
    // Exit loop if input is other than ("y", "Y")
    if (stop != 'y' && stop != 'Y')
      break;
  }

  printf("\nThe total amount is Rs. %.2f\n", total_price);

  // 3. Apply discount
  int discPer = getDiscount(total_price);
  float discount = 0;

  switch (discPer) {
    case 10:
      printf("Customer can avail 10%% discount! Applying offer...");
      discount = calcDiscount(total_price, 10.0);
      break;
    case 5:
      printf("Customer can avail 5%% discount! Applying offer...");
      discount = calcDiscount(total_price, 5.0);
      break;
    default:
      break;
  }
  float final_amount = total_price - discount;
  printf(
      "\n\nBill Breakdown after Discount:"
      "\nTotal Amount ------------ Rs %.2f"
      "\nDiscount (%d%%) ----------- Rs. %.2f"
      "\nFinal amount ------------ Rs. %.2f",
      total_price, discPer, discount, final_amount);

  // 4. Ask for membership
  char member;
  printf("\n\nDo you have a Handy Mandy Membership? (y/n): ");
  scanf(" %c", &member);

  float payable = final_amount;

  if (member == 'Y' || member == 'y') {
    printf("Thank you for your patronage, additional discount just for you!");
    float memberDiscount = calcDiscount(final_amount, 5.0);
    payable = final_amount - memberDiscount;
    printf(
        "\n\nBill Breakdown after Membership Discount:"
        "\nTotal Amount ------------ Rs %.2f"
        "\nDiscount (%d%%) ----------- Rs. %.2f"
        "\nFinal amount ------------ Rs. %.2f"
        "\nMembership Discount (5%%) ----- Rs. %.2f",
        total_price, discPer, discount, final_amount, memberDiscount);
  }
  printf("\nPayable Amount ---------- Rs. %.2f", payable);

  // 5. Check for leap year
  int day, month, year;
  printf("\n\nEnter todays date (format: DD MM YYYY): ");
  scanf("%d %d %d", &day, &month, &year);
  if (isLeapYear(year)) {
    printf("\nToday is leap year!!");
  } else {
    printf("\nToday is not leap year.");
  }

  printf("\n\n[Program Finished]");
  return 0;
}
