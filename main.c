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
    int teatmentType;
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
    printf("\t  Developed by 0xFaysal\n");
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
    fflush(stdin);
    scanf("%[^\n]s", allPatient[*patientCount].name);
    printf("Enter Patient ID: ");
    fflush(stdin);
    scanf("%[^\n]s", allPatient[*patientCount].id);
    printf("Enter Patient Address: ");
    fflush(stdin);
    scanf("%[^\n]s", allPatient[*patientCount].address);
    printf("Enter Patient Phone: ");
    fflush(stdin);
    scanf("%s", allPatient[*patientCount].phone);
    printf("Enter Patient Age: ");
    scanf("%d", &allPatient[*patientCount].age);
    printf("Enter Patient Treatment: ");
    fflush(stdin);
    scanf("%[^\n]s", allPatient[*patientCount].treatment);
    printf("Enter Patient Doctor: ");
    fflush(stdin);
    scanf("%[^\n]s", allPatient[*patientCount].doctor);
    printf("Enter Treatment Type (1 for outdoor treatment, 2 for admission): ");
    int treatmentType;
    scanf("%d", &treatmentType);
    allPatient[*patientCount].teatmentType = treatmentType;
    if (treatmentType == 2)
    {
        printf("Enter Patient Date of Admission: ");
        fflush(stdin);
        scanf("%[^\n]s", allPatient[*patientCount].dateOfAdmission);
        printf("Enter Patient Date of Release: ");
        fflush(stdin);
        scanf("%[^\n]s", allPatient[*patientCount].dateOfRelease);

    }
    else
    {
        allPatient[*patientCount].dateOfAdmission[0] = '\0';
        allPatient[*patientCount].dateOfRelease[0] = '\0';
    }
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
    fflush(stdin);
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

void UpdateDoctor(Doctor allDoctor[], int doctorCount)
{
    char searchDoctor[50];
    printf("Enter Doctor Name: ");
    fflush(stdin);
    scanf("%[^\n]", searchDoctor);
    for (int i = 0; i < doctorCount; i++)
    {
        if (strcmp(searchDoctor, allDoctor[i].name) == 0)
        {
            printf("Enter Doctor Name:");
            fflush(stdin);
            scanf("%[^\n]s", allDoctor[i].name);
            printf("Enter Doctor ID:");
            fflush(stdin);
            scanf("%s", allDoctor[i].id);
            printf("Enter Doctor Address:");
            fflush(stdin);
            scanf("%[^\n]", allDoctor[i].address);
            printf("Enter Doctor Phone:");
            fflush(stdin);
            scanf("%s", allDoctor[i].phone);
            printf("Enter Doctor Specialization:");
            fflush(stdin);
            scanf("%s", allDoctor[i].specialization);
            break;
        }
    }
}

void UpdatePatient(Patient allPatient[], int patientCount)
{
    char searchPatient[50];
    printf("Enter Patient Name: ");
    fflush(stdin);
    scanf("%[^\n]", searchPatient);
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(searchPatient, allPatient[i].name) == 0)
        {
            printf("Enter Patient Name: ");
            fflush(stdin);
            scanf("%[^\n]", allPatient[i].name);
            printf("Enter Patient ID: ");
            fflush(stdin);
            scanf("%s", allPatient[i].id);
            printf("Enter Patient Address: ");
            fflush(stdin);
            scanf("%[^\n]", allPatient[i].address);
            printf("Enter Patient Phone: ");
            fflush(stdin);
            scanf("%s", allPatient[i].phone);
            printf("Enter Patient Age: ");
            scanf("%d", &allPatient[i].age);
            printf("Enter Patient Treatment: ");
            fflush(stdin);
            scanf("%[^\n]", allPatient[i].treatment);
            if(allPatient[i].teatmentType == 1)
            {
                printf("Enter Doctor: ");
                fflush(stdin);
                scanf("%[^\n]", allPatient[i].doctor);
                printf("Enter Bill Amount: ");
                scanf("%f", &allPatient[i].bill);
            }
            else if (allPatient[i].teatmentType == 2)
            {
                printf("Enter Date of Admission: ");
                fflush(stdin);
                scanf("%[^\n]", allPatient[i].dateOfAdmission);
                printf("Enter Doctor: ");
                fflush(stdin);
                scanf("%[^\n]", allPatient[i].doctor);
                printf("Enter Date of Release: ");
                fflush(stdin);
                scanf("%[^\n]", allPatient[i].dateOfRelease);
                printf("Enter Bill Amount: ");
                scanf("%f", &allPatient[i].bill);
            }
            else
            {
                printf("Enter Date of Release: ");
                fflush(stdin);
                scanf("%[^\n]", allPatient[i].dateOfRelease);
                printf("Enter Bill Amount: ");
                scanf("%f", &allPatient[i].bill);
            }
            return;
            break;
        }

    }
    printf("Patient not found\n");
}

void deleteDoctor(Doctor allDoctor[], int* doctorCount)
{
    char searchDoctor[50];
    printf("Enter Doctor Name: ");
    fflush(stdin);
    scanf("%[^\n]", searchDoctor);
    for (int i = 0; i < *doctorCount; i++)
    {
        if (strcmp(searchDoctor, allDoctor[i].name) == 0)
        {
            for (int j = i; j < *doctorCount - 1; j++)
            {
                allDoctor[j] = allDoctor[j + 1];
            }
            (*doctorCount)--;
            return;
            break;
        }
    }
    printf("Doctor not found\n");

}

void checkPayment(Patient allPatient[], int patientCount)
{
    char searchPatient[50];
    printf("Enter Patient Name:");
    fflush(stdin);
    scanf("%[^\n]", searchPatient);
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(searchPatient, allPatient[i].name) == 0)
        {
            if (allPatient[i].bill == 0)
            {
                printf("Payment is cleared\n");
            }
            else
            {
                printf("Payment is not cleared\n");
                printf("Due amount: %.2f\n", allPatient[i].bill);
            }
            break;
        }
    }
}

void totalbill(Patient allPatient[], int patientCount)
{
    char searchPatient[50];
    printf("Enter Patient Name: ");
    fflush(stdin);
    scanf("%[^\n]", searchPatient);
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(searchPatient, allPatient[i].name) == 0)
        {
            printf("Patient name: %s\n", allPatient[i].name);
            printf("Patient ID: %s\n", allPatient[i].id);
            printf("Total bill amount: %.2f\n", allPatient[i].bill);
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

        case 7:
            {
                system("cls");
                title();
                printf("\t--Update Doctor Information--\n\n");
                UpdateDoctor(allDoctor, doctorCount);
                storeDoctor(allDoctor, doctorCount);
                break;
            }
        case 8:
            {
                system("cls");
                title();
                printf("\t--Delete Doctor Information--\n\n");
                deleteDoctor(allDoctor, &doctorCount);
                storeDoctor(allDoctor, doctorCount);
                break;
            }
        case 9:
            {
                system("cls");
                title();
                printf("\t--Update Patient Information--\n\n");
                UpdatePatient(allPatient, patientCount);
                storePatient(allPatient, patientCount);
                break;
            }
        case 10:
            {
                system("cls");
                title();
                printf("\t--Calculate total bill amount of a patient--\n\n");
                totalbill(allPatient, patientCount);
                break;
            }
        case 11:
            {
                system("cls");
                title();
                printf("\t--Check if payment is cleared--\n\n");
                checkPayment(allPatient, patientCount);
                printf("Click any key to return menu\n");
                getch();
                break;
            }
        case 12:
            {
                system("cls");
                title();
                printf("\t--Total number of patients and doctors--\n\n");
                printf("Total number of doctors: %d\n", doctorCount);
                printf("Total number of patients: %d\n", patientCount);
                printf("Click any key to return menu\n");
                getch();
                break;
            }
        case 13:
            {
                exit(0);
                break;
            }
        default: printf("Invalid choice\n");
        }
    }
    return 0;
}

