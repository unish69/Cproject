#include<stdio.h>
#include<string.h>
#include "patient.h"
int main(){
    int choice;

    // Keep showing the menu until user chooses to exit
    while(1) {
        // Display main menu options
        printf("\n1. Add Patient\n");
        printf("2. Available Doctors\n");
        printf("3. View Patients\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handle user's menu selection
        switch(choice) {
            case 1:
                addPatient(); // Call function to add a new patient
                break;

                case 2:
                doctors(); // Call function to show doctors list
                break;

            case 3:
                viewPatients(); // Call function to display all patients
                break;

            case 4:
                return 0; // Exit the program

            default:
                printf("Invalid choice\n"); // Handle invalid input
        }
    }
}

