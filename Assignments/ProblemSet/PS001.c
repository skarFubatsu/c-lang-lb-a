/*   Final Task of
"Problem Set 1 - Programming Assignment: Implementing a Course Grade Calculator"

*/

#include <stdio.h>

void greet() {
  /* Greets user on console */
  printf("Welcome to Gray's Grade Calculator ^_^\n");
}

int isLeapYear(int year) {
  return year % 4 == 0;
}

void printLine() {
  for (int i = 0; i < 70; i++) {
    printf("=");
  }
  printf("\n");
}

char* getGrade(float score) {
  if (score >= 90)
    return "A";
  if (score >= 80 && score < 90)
    return "B";
  if (score >= 70 && score < 80)
    return "C";
  if (score >= 60 && score < 70)
    return "D";
  if (score >= 40 && score < 60)
    return "E";
  return "F";
}

//   since 'return' returns pointer not array:
//   we must return a pointer to the first element of the string
char* getComponent(int index) {
  /* Gets the component based on index for easy access during loop operations */
  switch (index) {
    case 0:
      return "quiz";
    case 1:
      return "assignments";
    case 2:
      return "midterm";
    case 3:
      return "final exams";
    default:
      //   Illegal value
      break;
  }
}

/* Helper Functions for debugging */

void printArray(int array[], int length) {
  printf("[");
  for (int i = 0; i < length; i++) {
    printf("%d, ", array[i]);
  }
  printf("]");
}

int main() {
  //   1. Greet user
  printLine();
  greet();
  printLine();

  //   2. Calculate individual grade
  //   Basic Setup
  int components = 4;
  int counts[components], max_marks[components], weightage[components],
      rem_weight = 100;

  /*
  Index Map:
    0: we update quiz vars like number of quiz and max marks
    1: for assignments
    2: midterm
    3: final exams
  which makes all four components mentioned in activity; for more add idex and
  respective values to 'getComponent()' function
  */
  for (int i = 0; i < components; i++) {
    printf(
        "\n\nPlease enter the prompted data for %s\n"
        "   ( * Only integers accepted * )\n",
        getComponent(i));
    printLine();
    printf("\nNumber of %s taken: ", getComponent(i));
    scanf("%d", &counts[i]);
    printf("Maximum marks that can be obtained in a %s: ", getComponent(i));
    scanf("%d", &max_marks[i]);
    printf("Weightage of %s for final evaluation (Remaining weightage: %d%%): ",
           getComponent(i), rem_weight);
    scanf("%d", &weightage[i]);
    rem_weight -= weightage[i];
    printLine();
  }
  printf("\n");

  int number_of_students;
  printf("How many students do you want to grade?: ");
  scanf("%d", &number_of_students);
  printLine();

  //   3. For storing final scores
  float students_final_score[number_of_students];

  // Calculate average of all components
  for (int current_student = 0; current_student < number_of_students;
       current_student++) {
    float components_average[components];

    // Following block completes the objective for 2.
    for (int index = 0; index < components; index++) {
      printf("\nPlease provide followinng details for %s\n   Student #%d\n",
             getComponent(index), current_student + 1);
      float total = 0;
      for (int i = 0; i < counts[index]; i++) {
        float obtained_marks;
        printf("Enter marks obtained in %s #%d: ", getComponent(index), i + 1);
        scanf("%f", &obtained_marks);
        total += obtained_marks;
      }
      float average = total / counts[index];
      printf("\nStudent #%d obtained %.2f/%d in %s. \nAverage Score = %.2f\n",
             current_student + 1, total, max_marks[index] * counts[index],
             getComponent(index), average);
      components_average[index] = average;
      printLine();
    }
    printf("\n");

    // Compute the final grade.
    float final_score = 0, weight_total = 0;
    // weighted grade = Average grade x Weight
    // Overall weighted grade = sum all
    for (int c = 0; c < components; c++) {
      float weight = ((float)weightage[c] / 100);

      final_score += weight * components_average[c];
      weight_total += weight * max_marks[c];
    }
    float final_perecntage = (final_score * 100) / weight_total;

    // 4. Get grades based on final scores
    printf("Final score of Student #%d: %.2f ( %s )\n", current_student + 1,
           final_perecntage, getGrade(final_perecntage));

    printLine();

    // 5. Special conditions.
    int cond = 0;
    printf(
        "Does student # %d have any penalty or extra credit?\n 1) Penalty\n 2) "
        "Extra Credit\n 0) None\nEnter Value: ",
        current_student + 1);
    scanf("%d", &cond);

    switch (cond) {
      case 1:
        final_perecntage -= 5;
        break;
      case 2:
        final_perecntage += 5;
        break;
      default:
        // Do Nothing
        break;
    }

    // Update value and move to next student or exit
    students_final_score[current_student] = final_perecntage;
    printf("\n");
    printLine();
  }

  // 6. Using swap logic
  int len = sizeof(students_final_score) / sizeof(students_final_score[0]);
  if (len >= 2) {
    int student1 = students_final_score[0], student2 = students_final_score[1],
        temp;
    printf("\nGrades before swapping:\nStudent #1 = %s\nStudent #2 = %s",
           getGrade(student1), getGrade(student2));
    //  Swap using third variable
    temp = student1;
    student1 = student2;
    student2 = temp;
    printf("\nGrades after swapping:\nStudent #1 = %s\nStudent #2 = %s\n",
           getGrade(student1), getGrade(student2));
    printLine();
  }

  // 7. Check Leap Year
  int year;
  printf("\n\nEnter Year (format: YYYY): ");
  scanf("%d", &year);
  if (isLeapYear(year)) {
    printf("\nIts a leap year!!");
  } else {
    printf("\nIts not a leap year.");
  }

  printf("\n\n[Program Finished]");
  return 0;
}
