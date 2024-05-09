# School Management System

This project implements a School Management System in C++. It allows administrators to manage students, teachers, and various administrative tasks. Here's a breakdown of the features and functionalities:

## Features:

1. **Student Management:** Administrators can add new students, display all students, search for student details, update student marks, and delete students.

2. **Teacher Management:** Administrators can add new teachers and display all teachers.

3. **Fee Challan Generation:** Administrators can generate fee challans for students based on their class.

4. **Salary Payment:** Administrators can pay salaries to teachers based on their class.

5. **Data Persistence:** Student and teacher data can be saved to and loaded from files for persistent storage.

6. **Password Protected Login:** The system features a password-protected login for security.

## Classes:

### 1. Person:
- Represents a generic person with attributes such as name, age, address, and ID.

### 2. Student (Inherits from Person):
- Represents a student with additional attributes such as student ID and marks.
- Provides functionalities to display student details, save to file, and load from file.

### 3. Teacher (Inherits from Person):
- Represents a teacher with an additional qualification attribute.
- Provides functionalities to display teacher details, save to file, and load from file.

### 4. AdministrationOffice:
- Manages the administration tasks including student and teacher management.
- Provides functionalities to add, display, search, update, and delete students and teachers.
- Allows fee challan generation and teacher salary payment.
- Supports saving and loading data to and from files.

## Usage:

1. **Add New Student (Option 1):** Add a new student to the system by providing relevant details such as name, age, address, student ID, and marks.

2. **Display All Students (Option 2):** View details of all students currently in the system.

3. **Search Student Details (Option 3):** Search for a student's details by entering their student ID.

4. **Update Student Marks (Option 4):** Update a student's marks by entering their student ID and the new marks.

5. **Delete Student (Option 5):** Delete a student from the system by entering their student ID.

6. **Add New Teacher (Option 6):** Add a new teacher to the system by providing relevant details such as name, age, address, and qualification.

7. **Display All Teachers (Option 7):** View details of all teachers currently in the system.

8. **Generate Fee Challan (Option 8):** Generate a fee challan for a student by entering their student ID.

9. **Pay Teacher Salary (Option 9):** Pay salary to a teacher by entering their teacher ID.

10. **Save to File (Option 10):** Save student and teacher data to a file for future reference.

11. **Load from File (Option 11):** Load previously saved student and teacher data from a file into the system.

12. **Quit (Option 12):** Exit the program.

## Security:
- The system features a password-protected login mechanism to ensure authorized access.

## File Handling:
Student and teacher data can be saved to and loaded from files specified by the user.

## Error Handling:
The program includes exception handling to handle errors gracefully and provide informative error messages in case of unexpected events.

