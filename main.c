#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct
{
    char name[50];
    char id[10];
    char address[100];
    char phone[15];
    int age;
    char treatment[100];
    char doctor[50];
    char dateOfAdmission[20];
    char dateOfRelease[20];
    float bill;
} Patient;

typedef struct
{
    char name[50];
    char id[10];
    char address[100];
    char phone[15];
    char specialization[50];
} Doctor;

void title()
{
    printf("*****************************************\n");
    printf("     Hospital Management System\n");
    printf("\t   United Hospital\n");
    printf("    Madani Aviniue,Vatara,Dhaka-1212\n");
    printf("\t   +880123456789\n");
    printf("*****************************************\n");
}

void option()
{
    printf("1. Display All Doctor Information\n");
    printf("2. Display All Patient Information\n");
    printf("3. Add New Doctor\n");
    printf("4. Add New Patient\n");
    printf("5. Search Doctor\n");
    printf("6. Search Patient\n");
    printf("7. Update a Doctor's Information\n");
    printf("8. Delete a Doctor's Information\n");
    printf("9. Update a patient's information\n");
    printf("10. Calculate total bill amount of a patient\n");
    printf("11. Check if payment is cleared\n");
    printf("12. Display total number of patients and doctors\n");
    printf("13. Exit\n");
    printf("Enter your choice: ");
}

void addDoctor(Doctor allDoctor[], int* doctorCount)
{
    printf("\t--Add New Doctor--\n");
    printf("Enter Doctor Name:");
    fflush(stdin);
    scanf("%[^\n]s", allDoctor[*doctorCount].name);
    printf("Enter Doctor ID:");
    fflush(stdin);
    scanf("%s", allDoctor[*doctorCount].id);
    printf("Enter Doctor Address:");
    fflush(stdin);
    scanf("%[^\n]", allDoctor[*doctorCount].address);
    printf("Enter Doctor Phone:");
    fflush(stdin);
    scanf("%s", allDoctor[*doctorCount].phone);
    printf("Enter Doctor Specialization:");
    fflush(stdin);
    scanf("%s", allDoctor[*doctorCount].specialization);
    (*doctorCount)++;
}

void addPatient(Patient allPatient[], int* patientCount)
{
    printf("Enter Patient Name: ");
    scanf("%s", allPatient[*patientCount].name);
    printf("Enter Patient ID: ");
    scanf("%s", allPatient[*patientCount].id);
    printf("Enter Patient Address: ");
    scanf("%s", allPatient[*patientCount].address);
    printf("Enter Patient Phone: ");
    scanf("%s", allPatient[*patientCount].phone);
    printf("Enter Patient Age: ");
    scanf("%d", &allPatient[*patientCount].age);
    printf("Enter Patient Treatment: ");
    scanf("%s", allPatient[*patientCount].treatment);
    printf("Enter Patient Doctor: ");
    scanf("%s", allPatient[*patientCount].doctor);
    printf("Enter Patient Date of Admission: ");
    scanf("%s", allPatient[*patientCount].dateOfAdmission);
    printf("Enter Patient Date of Release: ");
    scanf("%s", allPatient[*patientCount].dateOfRelease);
    printf("Enter Patient Bill: ");
    scanf("%f", &allPatient[*patientCount].bill);
    (*patientCount)++;
}

void printDoctor(Doctor doctor)
{
    printf("Doctor name : %s\n", doctor.name);
    printf("Doctor ID : %s\n", doctor.id);
    printf("Doctor Address : %s\n", doctor.address);
    printf("Doctor Phone : %s\n", doctor.phone);
    printf("Doctor Specialization : %s\n\n", doctor.specialization);
}

void printPatient(Patient patient)
{
    printf("Patient name : %s\n", patient.name);
    printf("Patient ID : %s\n", patient.id);
    printf("Patient Address : %s\n", patient.address);
    printf("Patient Phone : %s\n", patient.phone);
    printf("Patient Age : %d\n", patient.age);
    printf("Patient Treatment : %s\n", patient.treatment);
    printf("Patient Doctor : %s\n", patient.doctor);
    printf("Patient Date of Admission : %s\n", patient.dateOfAdmission);
    printf("Patient Date of Release : %s\n", patient.dateOfRelease);
    printf("Patient Bill : %.2f\n\n", patient.bill);
}

void storeDoctor(Doctor allDoctor[], int doctorCount)
{
    FILE* file = fopen("doctor.txt", "w");
    if (file == NULL)
    {
        printf("File could not be opened\n");
        return;
    }
    for (int i = 0; i < doctorCount; i++)
    {
        fprintf(file, "%s\n%s\n%s\n%s\n%s\n", allDoctor[i].name, allDoctor[i].id, allDoctor[i].address,
                allDoctor[i].phone,
                allDoctor[i].specialization);
    }
    fclose(file);
}

void storePatient(Patient allPatient[], int patientCount)
{
    FILE* file = fopen("patient.txt", "w");
    if (file == NULL)
    {
        printf("File could not be opened\n");
        return;
    }
    for (int i = 0; i < patientCount; i++)
    {
        fprintf(file, "%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%f\n", allPatient[i].name, allPatient[i].id,
                allPatient[i].address,
                allPatient[i].phone, allPatient[i].age, allPatient[i].treatment, allPatient[i].doctor,
                allPatient[i].dateOfAdmission, allPatient[i].dateOfRelease, allPatient[i].bill);
    }
    fclose(file);
}

void retiveDoctorData(Doctor allDoctor[], int* doctorCount)
{
    FILE* file = fopen("doctor.txt", "r");
    if (file == NULL)
    {
        printf("File not found\n");
        return;
    }
    while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", allDoctor[*doctorCount].name,
                  allDoctor[*doctorCount].id,
                  allDoctor[*doctorCount].address, allDoctor[*doctorCount].phone,
                  allDoctor[*doctorCount].specialization) == 5)
    {
        (*doctorCount)++;
    }
    fclose(file);
}

void retivePatientData(Patient allPatient[], int* patientCount)
{
    FILE* file = fopen("patient.txt", "r");
    if (file == NULL)
    {
        printf("File not found\n");
        return;
    }
    while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%f\n",
                  allPatient[*patientCount].name, allPatient[*patientCount].id,
                  allPatient[*patientCount].address, allPatient[*patientCount].phone, &allPatient[*patientCount].age,
                  allPatient[*patientCount].treatment, allPatient[*patientCount].doctor,
                  allPatient[*patientCount].dateOfAdmission, allPatient[*patientCount].dateOfRelease,
                  &allPatient[*patientCount].bill) == 10)
    {
        (*patientCount)++;
    }
    fclose(file);
}

void searchDoctor(Doctor allDoctor[], int doctorCount)
{
    char searchDoctor[50];
    printf("Enter Doctor Name: ");
    fflush(stdin);
    scanf("%[^\n]", searchDoctor);
    for (int i = 0; i < doctorCount; i++)
    {
        if (strcmp(searchDoctor, allDoctor[i].name) == 0)
        {
            printDoctor(allDoctor[i]);
            break;
        }
    }
}

void searchPatient(Patient allPatient[], int patientCount)
{
    char searchPatient[50];
    printf("Enter Patient Name: ");
    scanf("%[^\n]", searchPatient);
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(searchPatient, allPatient[i].name) == 0)
        {
            printPatient(allPatient[i]);
            break;
        }
    }
}


int main()
{
    int doctorCount = 0, patientCount = 0;
    Doctor allDoctor[100];
    Patient allPatient[100];
    int optionChoice;
    retiveDoctorData(allDoctor, &doctorCount);
    retivePatientData(allPatient, &patientCount);

    while (1)
    {
        system("cls");
        title();
        option();
        scanf("%d", &optionChoice);
        switch (optionChoice)
        {
        case 1:
            {
                system("cls");
                title();
                printf("\t--All Doctor Information--\n\n");
                for (int i = 0; i < doctorCount; i++)
                {
                    printDoctor(allDoctor[i]);
                }
                printf("Click any key to return menu\n");
                getch();
                break;
            }
        case 2:
            {
                system("cls");
                title();
                printf("\t--All Patient Information--\n\n");
                for (int i = 0; i < patientCount; i++)
                {
                    printPatient(allPatient[i]);
                }
                printf("Click any key to return menu\n");
                getch();
                break;
            }


        case 3:

            {
                system("cls");
                title();
                addDoctor(allDoctor, &doctorCount);
                storeDoctor(allDoctor, doctorCount);
                break;
            }
        case 4:
            {
                system("cls");
                title();
                addPatient(allPatient, &patientCount);
                storePatient(allPatient, patientCount);
                break;
            }
        case 5:
            {
                system("cls");
                title();
                printf("\t--Search Doctor--\n\n");
                searchDoctor(allDoctor, doctorCount);
                printf("Click any key to return menu\n");
                getch();
                break;
            }
        case 6:
            {
                system("cls");
                title();
                printf("\t--Search Patient--\n\n");
                searchPatient(allPatient, patientCount);
                printf("Click any key to return menu\n");
                getch();
                break;
            }


        default: printf("Invalid choice\n");
        }
    }
    return 0;
}

// exit(1);
// break;
