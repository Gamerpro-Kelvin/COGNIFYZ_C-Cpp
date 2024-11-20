#include <stdio.h>
#include <stdlib.h>

int main() {
    int numSubjects;
    float *grades, sum = 0.0, average;

    // Prompt for number of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    // Dynamically allocate memory for grades
    grades = (float *)malloc(numSubjects * sizeof(float));
    if (grades == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input grades
    for (int i = 0; i < numSubjects; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%f", grades + i);
        sum += *(grades + i);
    }

    // Calculate and display average
    average = sum / numSubjects;
    printf("The average grade is: %.2f\n", average);

    // Free allocated memory
    free(grades);

    return 0;
}

