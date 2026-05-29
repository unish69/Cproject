#include<stdio.h>
#include<string.h> 
#include "patient.h"

// Structure to store patient information
struct patient{
    int patient_id; // Unique ID for each patient
    char patient_name[100]; // Full name of the patient
    int patient_age;  // Age of the patient
    char gender[15];  // Gender of the patient
    char address[50]; // Home address
    char phone[15];   // Contact number
    char disease[50]; // Disease or problem reported
    char doctor[50];  // Assigned doctor's name
    char date[50];   // Appointment date
    
    }; 
    
        struct patient p[100]; // Array to store up to 100 patient
        int count = 0; // Tracks the current number of patients
    
        // Function to add a new patient
   void addPatient(){
    // example for first patient
    printf("--ADD PATIENT--\n");
    
    // Take patient details as input
    printf("ENTER PATIENT ID: ");
    scanf(" %d",&p[count].patient_id);
    
    printf("ENTER PATIENT NAME: ");
    scanf(" %[^\n]", p[count].patient_name);

    printf("ENTER PATIENT AGE: ");
    scanf(" %d",&p[count].patient_age);

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
    
    // Display available doctors and let user choose one
    printf("\nSelect Doctor:\n");
    printf("1. Dr. Kiran\n");
    printf("2. Dr. Aman\n");
    printf("3. Dr. Sharma\n");
    printf("4. Dr. Riya\n");
    printf("5. Dr. Monika\n");

    int choice;
   printf("Enter choice: ");
   scanf(" %d", &choice);
    
   // Assign doctor based on user's choice
   switch(choice){
    case 1:
    strcpy(p[count].doctor,"Dr. Kiran");
    break;

    case 2:
    strcpy(p[count].doctor,"Dr. Aman");
    break;

    case 3:
    strcpy(p[count].doctor,"Dr. Sharma");
    break;

    case 4:
    strcpy(p[count].doctor,"Dr. Riya");
    break;

    case 5:
    strcpy(p[count].doctor,"Dr. Monika");
    break;

    default:
    printf("INVALID CHOICE\n");
    strcpy(p[count].doctor, "Not Assigned"); // No doctor assigned if invalid input
    break;
   }
      // Confirm patient was added successfully
   printf("\n--PATIENT ADDED SUCCESSFULLY--\n");
   printf("DOCTOR ASSIGNED = %s\n",p[count].doctor);
   printf("APPOINTMENT DATE = %s\n",p[count].date);
   
   count ++; // Increment patient count
   
} // Function to display all available doctors
   void doctors() {
    printf("\n--- DOCTORS LIST ---\n");
    printf("1. Dr. Kiran\n");
    printf("2. Dr. Aman\n");
    printf("3. Dr. Sharma\n");
    printf("4. Dr. Riya\n");
    printf("5. Dr. Monika\n");
}
 
// Function to display all registered patients
 void viewPatients() {
     
    // Loop through all added patients and print their details
    for(int i = 0; i < count; i++) {

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