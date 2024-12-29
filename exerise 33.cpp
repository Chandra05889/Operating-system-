#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100  // Maximum number of records in the file

// Function to read the records
void readRecords(char file[][100], int totalRecords) {
    printf("\nFile records:\n");
    for (int i = 0; i < totalRecords; i++) {
        printf("Record %d: %s\n", i + 1, file[i]);
    }
}

// Function to access a specific record in the file
void accessRecord(char file[][100], int recordNumber, int totalRecords) {
    if (recordNumber > 0 && recordNumber <= totalRecords) {
        // Simulate reading all the previous records first
        printf("\nReading all previous records...\n");
        for (int i = 0; i < recordNumber; i++) {
            printf("Record %d: %s\n", i + 1, file[i]);
        }
    } else {
        printf("\nError: Invalid record number!\n");
    }
}

int main() {
    int totalRecords, recordToAccess;

    // Input the total number of records in the file
    printf("Enter the total number of records in the file (max %d): ", MAX_RECORDS);
    scanf("%d", &totalRecords);

    // Ensure that the number of records does not exceed the maximum limit
    if (totalRecords > MAX_RECORDS || totalRecords <= 0) {
        printf("Error: Invalid number of records. The number should be between 1 and %d.\n", MAX_RECORDS);
        return 1;
    }

    // Create a file array to hold the records (array of strings)
    char file[MAX_RECORDS][100];  // Array to hold up to 100 records, each up to 99 characters long

    // Input the file records
    for (int i = 0; i < totalRecords; i++) {
        printf("Enter record %d: ", i + 1);
        getchar();  // To clear any leftover newline character from previous input
        fgets(file[i], sizeof(file[i]), stdin);
        file[i][strcspn(file[i], "\n")] = '\0';  // Remove the newline character at the end of input
    }

    // Display the records
    readRecords(file, totalRecords);

    // Ask the user which record they want to access
    printf("\nEnter the record number you want to access: ");
    scanf("%d", &recordToAccess);

    // Access the specified record and read all previous records
    accessRecord(file, recordToAccess, totalRecords);

    return 0;
}

