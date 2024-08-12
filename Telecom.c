#include <stdio.h>
#include <string.h>

void putstr(const char *str) {
    while (*str) {
        putchar(*str);  // Print each character of the string
        str++;
    }
}

struct Customer {
    char name[50];
    char phoneNumber[11];
    float usage;
    float totalBill;
};

struct Customer customers[100]; 
  
// Global variable to keep track of the number of customers 
int customerCount = 0;

void addRecord() 
{ 
    if (customerCount < 100) { 
        printf("\nEnter name: "); 
        putstr(customers[customerCount].name);
        printf("Enter phone number: "); 
        scanf("%s", customers[customerCount].phoneNumber); 
        printf("Enter usage (in minutes): "); 
        scanf("%f", &customers[customerCount].usage); 
        customers[customerCount].totalBill 
            = customers[customerCount].usage * 0.1; 
        customerCount++; 
        printf("\nRecord added successfully!\n"); 
    } 
    else { 
        printf("\nMaximum number of records reached!\n"); 
    } 
}

void viewRecords() 
{ 
    printf("\nName\tPhone Number\tUsage(min)\tTotal "
           "Bill($)\n"); 
    for (int i = 0; i < customerCount; i++) { 
        printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, 
               customers[i].phoneNumber, customers[i].usage, 
               customers[i].totalBill); 
    } 
}

void modifyRecord(char phoneNumber[]) 
{   
    int i = 0;  // Initialize the loop counter

    while (i < customerCount) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) { 
            // Phone number matches, modify the record
            printf("\nEnter new usage (in minutes) for %s: ", customers[i].name); 
            scanf("%f", &customers[i].usage); 
            customers[i].totalBill = customers[i].usage * 0.1;
            printf("\nRecord modified successfully!\n");
            return;  // Exit after modifying the record
        }
        i++;  // Move to the next customer
    }

    // If no matching record is found
    printf("\nRecord not found!\n"); 
}

void viewPayment(char phoneNumber[]) 
{ 
    for (int i = 0; i < customerCount; i++) { 
        if (strcmp(customers[i].phoneNumber, phoneNumber) 
            == 0) { 
            printf("\nTotal Bill for %s: $%.2f\n", 
                   customers[i].name, 
                   customers[i].totalBill); 
            return; 
        } 
    } 
    printf("\nRecord not found!\n"); 
}

void searchRecord(char phoneNumber[]) 
{ 
    printf("\nName\tPhone Number\tUsage(min)\tTotal Bill($)\n"); 
    for (int i = 0; i < customerCount; i++) { 
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) { 
            printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, customers[i].phoneNumber, customers[i].usage, customers[i].totalBill); 
            return; 
        } 
    } 
    printf("\nRecord not found!\n"); 
}

void deleteRecord(char phoneNumber[]) { 
    for (int i = 0; i < customerCount; i++) { 
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) { 
            for (int j = i; j < customerCount - 1; j++) { 
                customers[j] = customers[j + 1]; 
            } 
            customerCount--; 
            printf("\nRecord deleted successfully!\n"); 
            return; 
        } 
    } 
    printf("\nRecord not found!\n"); 
}

void displayMenu() 
{ 
    printf("\n1. Add New Record\n"); 
    printf("2. View List of Records\n"); 
    printf("3. Modify Record\n"); 
    printf("4. View Payment\n"); 
    printf("5. Delete Record\n"); 
    printf("6. Exit\n"); 
} 

int main() 
{ 
    int choice; 
    char phoneNumber[13]; 
  
    while (1) { 
        displayMenu(); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
  
        switch (choice) { 
        case 1: 
            addRecord(); 
            break; 
        case 2: 
            viewRecords(); 
            break; 
        case 3: 
            printf( 
                "\nEnter phone number to modify record: "); 
            scanf("%s", phoneNumber); 
            modifyRecord(phoneNumber); 
            break; 
        case 4: 
            printf( 
                "\nEnter phone number to view payment: "); 
            scanf("%s", phoneNumber); 
            viewPayment(phoneNumber); 
            break; 
        case 5: 
            printf( 
                "\nEnter phone number to delete record: "); 
            scanf("%s", phoneNumber); 
            deleteRecord(phoneNumber); 
            break; 
        case 6: 
            return 0; 
        default: 
            printf("\nInvalid choice! Please try again.\n"); 
        } 
    } 
  
    return 0; 
}