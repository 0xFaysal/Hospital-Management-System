# Hospital Management System

A comprehensive console-based Hospital Management System developed in C for managing doctors and patients efficiently. This system provides a complete solution for hospital administration, including patient records, doctor information, billing, and more.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [System Requirements](#system-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Data Storage](#data-storage)
- [Menu Options](#menu-options)
- [Contributing](#contributing)
- [License](#license)

## 🏥 Overview

The Hospital Management System is designed to streamline hospital operations by providing an easy-to-use interface for managing:
- **Doctor Records**: Store and manage information about medical professionals
- **Patient Records**: Maintain comprehensive patient information including treatment details
- **Billing System**: Track and manage patient bills and payment status
- **Treatment Tracking**: Monitor outdoor and admission-based treatments

This system is ideal for small to medium-sized clinics and hospitals looking for a simple, efficient management solution.

## ✨ Features

### Doctor Management
- ➕ Add new doctor records with complete information
- 📋 Display all registered doctors
- 🔍 Search for doctors by name
- ✏️ Update existing doctor information
- 🗑️ Delete doctor records

### Patient Management
- ➕ Register new patients with detailed information
- 📋 View all patient records
- 🔍 Search for patients by name
- ✏️ Update patient information
- 🏥 Support for both outdoor and admission-based treatments
- 📅 Track admission and release dates for hospitalized patients

### Financial Management
- 💰 Calculate total bill amount for patients
- ✅ Check payment clearance status
- 📊 Track due amounts

### Statistics
- 📈 Display total number of doctors and patients
- 📊 View comprehensive hospital statistics

## 💻 System Requirements

### Software Requirements
- **Operating System**: Windows (uses `conio.h` and `system("cls")`)
- **Compiler**: GCC or any C compiler supporting C11 standard
- **Build Tool**: CMake 3.28 or higher (optional)

### Hardware Requirements
- **Processor**: Any modern processor
- **RAM**: Minimum 512 MB
- **Storage**: 10 MB free space

## 🔧 Installation

### Method 1: Using CMake (Recommended)

1. **Clone the repository**
   ```bash
   git clone https://github.com/0xFaysal/Hospital-Management-System.git
   cd Hospital-Management-System
   ```

2. **Build using CMake**
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

3. **Run the application**
   ```bash
   ./project
   ```

### Method 2: Direct Compilation

1. **Clone the repository**
   ```bash
   git clone https://github.com/0xFaysal/Hospital-Management-System.git
   cd Hospital-Management-System
   ```

2. **Compile the source code**
   ```bash
   gcc main.c -o hospital_system
   ```

3. **Run the application**
   ```bash
   ./hospital_system
   ```

## 🚀 Usage

1. **Launch the Application**
   - Run the compiled executable
   - The main menu will be displayed

2. **Navigate the Menu**
   - Enter the number corresponding to your desired operation
   - Follow the on-screen prompts

3. **Data Entry**
   - When adding or updating records, carefully enter all required information
   - Press Enter after each field

4. **Exiting the Application**
   - Select option 13 to exit the program
   - All data is automatically saved to text files

## 📁 Project Structure

```
Hospital-Management-System/
│
├── main.c              # Main source code file
├── CMakeLists.txt      # CMake configuration file
├── README.md           # Project documentation
├── doctor.txt          # Persistent storage for doctor records (auto-generated)
└── patient.txt         # Persistent storage for patient records (auto-generated)
```

### Key Components

#### Data Structures

**Patient Structure:**
```c
typedef struct {
    char name[50];
    char id[10];
    char address[100];
    char phone[15];
    int age;
    char treatment[100];
    char doctor[50];
    int treatmentType;
    char dateOfAdmission[20];
    char dateOfRelease[20];
    float bill;
} Patient;
```

**Doctor Structure:**
```c
typedef struct {
    char name[50];
    char id[10];
    char address[100];
    char phone[15];
    char specialization[50];
} Doctor;
```

## 💾 Data Storage

The system uses text files for persistent data storage:

- **doctor.txt**: Stores all doctor information
  - Each doctor record is stored with fields separated by newlines
  - Format: Name, ID, Address, Phone, Specialization

- **patient.txt**: Stores all patient information
  - Each patient record contains complete medical and billing information
  - Format: Name, ID, Address, Phone, Age, Treatment, Doctor, Admission Date, Release Date, Bill Amount

Data is automatically loaded when the program starts and saved after each modification.

## 📋 Menu Options

The system provides 13 main operations:

1. **Display All Doctor Information** - View complete list of all registered doctors
2. **Display All Patient Information** - View complete list of all registered patients
3. **Add New Doctor** - Register a new doctor in the system
4. **Add New Patient** - Register a new patient with treatment details
5. **Search Doctor** - Find a specific doctor by name
6. **Search Patient** - Find a specific patient by name
7. **Update Doctor's Information** - Modify existing doctor records
8. **Delete Doctor's Information** - Remove a doctor from the system
9. **Update Patient's Information** - Modify existing patient records
10. **Calculate Total Bill Amount** - View billing details for a patient
11. **Check Payment Clearance** - Verify if a patient's bill is paid
12. **Display Statistics** - View total number of doctors and patients
13. **Exit** - Close the application

### Treatment Types

The system supports two types of patient treatments:

- **Type 1: Outdoor Treatment**
  - For patients receiving treatment without admission
  - No admission/release dates required

- **Type 2: Admission-Based Treatment**
  - For hospitalized patients
  - Includes admission and release date tracking

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/YourFeature
   ```
3. **Commit your changes**
   ```bash
   git commit -m "Add your feature"
   ```
4. **Push to the branch**
   ```bash
   git push origin feature/YourFeature
   ```
5. **Open a Pull Request**

### Contribution Guidelines

- Follow the existing code style
- Add comments for complex logic
- Test your changes thoroughly
- Update documentation as needed

## 📄 License

This project is open source and available for educational purposes.

## 👨‍💻 Developer

Developed by **0xFaysal**

---

## 🐛 Known Issues

- The system uses Windows-specific functions (`conio.h`, `system("cls")`)
- Maximum capacity: 100 doctors and 100 patients
- Input validation is minimal

## 🔮 Future Enhancements

Potential improvements for future versions:

- [ ] Cross-platform compatibility (Linux/Mac support)
- [ ] Graphical User Interface (GUI)
- [ ] Database integration (MySQL/PostgreSQL)
- [ ] Enhanced input validation
- [ ] Password-protected access
- [ ] Report generation and printing
- [ ] Appointment scheduling system
- [ ] Medical inventory management
- [ ] Dynamic memory allocation for unlimited records
- [ ] Backup and restore functionality

## 📞 Support

For questions, issues, or suggestions, please:
- Open an issue on GitHub
- Contact the development team at United Hospital

---

**Made with ❤️ for better healthcare management**
