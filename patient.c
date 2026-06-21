#include<stdio.h>
#include<string.h>
#include "patient.h"

// Structure to store patient information
struct patient{
    int patient_id;       // Unique ID for each patient
    char patient_name[100]; // Full name of the patient
    int patient_age;      // Age of the patient
    char gender[15];      // Gender of the patient
    char address[50];     // Home address
    char phone[15];       // Contact number
    char disease[50];     // Disease or problem reported
    char doctor[50];      // Assigned doctor's name
    char date[50];        // Appointment date
};

struct patient p[100]; // Array to store up to 100 patients
int count = 0;         // Tracks the current number of patients

// Track which doctors are booked (0 = free, 1 = booked)
int doctorBooked[5] = {0, 0, 0, 0, 0};

// Doctor names list
char doctorNames[5][30] = {
    "Dr. Kiran",
    "Dr. Aman",
    "Dr. Sharma",
    "Dr. Riya",
    "Dr. Monika"
};

// Function to add a new patient
void addPatient(){
    printf("--ADD PATIENT--\n");

    // Check for duplicate patient ID
    int duplicate;
    do {
        duplicate = 0;
        printf("ENTER PATIENT ID: ");
        scanf(" %d", &p[count].patient_id);
        for(int i = 0; i < count; i++){
            if(p[i].patient_id == p[count].patient_id){
                duplicate = 1;
                printf("This ID already exists! Please enter a different ID.\n");
                break;
            }
        }
    } while(duplicate);

    printf("ENTER PATIENT NAME: ");
    scanf(" %[^\n]", p[count].patient_name);
    printf("ENTER PATIENT AGE: ");
    scanf(" %d", &p[count].patient_age);
    printf("ENTER PATIENT GENDER: ");
    scanf(" %[^\n]", p[count].gender);
    printf("ENTER PATIENT ADDRESS: ");
    scanf(" %[^\n]", p[count].address);
    printf("ENTER PATIENT PHONE NUMBER: ");
    scanf(" %[^\n]", p[count].phone);
    printf("ENTER THE DISEASE/PROBLEM: ");
    scanf(" %[^\n]", p[count].disease);
    printf("APPOINTMENT DATE: ");
    scanf(" %[^\n]", p[count].date);

    // Display only available doctors and let user choose one
    printf("\nSelect Doctor:\n");
    for(int i = 0; i < 5; i++){
        if(doctorBooked[i] == 0){
            printf("%d. %s\n", i+1, doctorNames[i]);
        }
    }

    int choice;
    printf("Enter choice: ");
    scanf(" %d", &choice);

    // Assign doctor based on user's choice
    if(choice >= 1 && choice <= 5 && doctorBooked[choice-1] == 0){
        strcpy(p[count].doctor, doctorNames[choice-1]);
        doctorBooked[choice-1] = 1; // Mark doctor as booked
    } else {
        printf("Invalid choice or doctor already booked!\n");
        strcpy(p[count].doctor, "Not Assigned");
    }

    // Confirm patient was added successfully
    printf("\n--PATIENT ADDED SUCCESSFULLY--\n");
    printf("DOCTOR ASSIGNED = %s\n", p[count].doctor);
    printf("APPOINTMENT DATE = %s\n", p[count].date);

    count++; // Increment patient count
}

// Function to display all available doctors
void doctors(){
    printf("\n--- DOCTORS LIST ---\n");
    printf("1. Dr. Kiran  - %s\n",  doctorBooked[0] ? "BOOKED" : "AVAILABLE");
    printf("2. Dr. Aman   - %s\n",  doctorBooked[1] ? "BOOKED" : "AVAILABLE");
    printf("3. Dr. Sharma - %s\n",  doctorBooked[2] ? "BOOKED" : "AVAILABLE");
    printf("4. Dr. Riya   - %s\n",  doctorBooked[3] ? "BOOKED" : "AVAILABLE");
    printf("5. Dr. Monika - %s\n",  doctorBooked[4] ? "BOOKED" : "AVAILABLE");
}

// Function to display all registered patients
void viewPatients(){
    if(count == 0){
        printf("\nNo patients registered yet.\n");
        return;
    }
    // Loop through all added patients and print their details
    for(int i = 0; i < count; i++){
        printf("\nPATIENT ID = %d", p[i].patient_id);
        printf("\nNAME = %s", p[i].patient_name);
        printf("\nAGE = %d", p[i].patient_age);
        printf("\nGENDER = %s", p[i].gender);
        printf("\nADDRESS = %s", p[i].address);
        printf("\nPHONE = %s", p[i].phone);
        printf("\nDISEASE = %s", p[i].disease);
        printf("\nDOCTOR = %s", p[i].doctor);
        printf("\nAPPOINTED DATE = %s\n", p[i].date);
        printf("------------------------\n");
    }
}

// Function to edit an existing patient
void editPatient(){
    if(count == 0){
        printf("\nNo patients registered yet.\n");
        return;
    }

    int id, found = -1;
    printf("--EDIT PATIENT--\n");
    printf("Enter Patient ID to edit: ");
    scanf(" %d", &id);

    // Search for the patient by ID
    for(int i = 0; i < count; i++){
        if(p[i].patient_id == id){
            found = i;
            break;
        }
    }

    if(found == -1){
        printf("Patient with ID %d not found!\n", id);
        return;
    }

    printf("Patient found: %s\n", p[found].patient_name);
    printf("What do you want to edit?\n");
    printf("1. Name\n");
    printf("2. Age\n");
    printf("3. Gender\n");
    printf("4. Address\n");
    printf("5. Phone\n");
    printf("6. Disease\n");
    printf("7. Appointment Date\n");
    printf("8. Doctor\n");
    printf("Enter choice: ");

    int choice;
    scanf(" %d", &choice);

    switch(choice){
        case 1:
            printf("Enter new Name: ");
            scanf(" %[^\n]", p[found].patient_name);
            break;
        case 2:
            printf("Enter new Age: ");
            scanf(" %d", &p[found].patient_age);
            break;
        case 3:
            printf("Enter new Gender: ");
            scanf(" %[^\n]", p[found].gender);
            break;
        case 4:
            printf("Enter new Address: ");
            scanf(" %[^\n]", p[found].address);
            break;
        case 5:
            printf("Enter new Phone: ");
            scanf(" %[^\n]", p[found].phone);
            break;
        case 6:
            printf("Enter new Disease: ");
            scanf(" %[^\n]", p[found].disease);
            break;
        case 7:
            printf("Enter new Appointment Date: ");
            scanf(" %[^\n]", p[found].date);
            break;
        case 8:
            // Free the old doctor first
            for(int i = 0; i < 5; i++){
                if(strcmp(p[found].doctor, doctorNames[i]) == 0){
                    doctorBooked[i] = 0;
                    break;
                }
            }
            // Show available doctors
            printf("Select new Doctor:\n");
            for(int i = 0; i < 5; i++){
                if(doctorBooked[i] == 0){
                    printf("%d. %s\n", i+1, doctorNames[i]);
                }
            }
            int dc;
            printf("Enter choice: ");
            scanf(" %d", &dc);
            if(dc >= 1 && dc <= 5 && doctorBooked[dc-1] == 0){
                strcpy(p[found].doctor, doctorNames[dc-1]);
                doctorBooked[dc-1] = 1;
            } else {
                printf("Invalid choice!\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("\n--PATIENT UPDATED SUCCESSFULLY--\n");
}
