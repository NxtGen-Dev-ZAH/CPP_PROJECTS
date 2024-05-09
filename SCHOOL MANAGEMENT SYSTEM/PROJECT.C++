#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string address;
    int id; // New attribute

public:
    Person() {}
    Person(const string& name, int age, const string& address, int id)
        : name(name), age(age), address(address), id(id) {}

    virtual void displayDetails() const {
        cout << "ID: " << id << endl; // Display ID
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }

    virtual void saveToFile(ofstream& file) const {
        file << id << endl; // Save ID
        file << name << endl;
        file << age << endl;
        file << address << endl;
    }

    virtual void loadFromFile(ifstream& file) {
        file >> id; // Load ID
        file.ignore();
        getline(file, name);
        file >> age;
        file.ignore();
        getline(file, address);
    }
};

class Student : public Person {
private:
    int studentID;
    float marks;

public:
    Student() {}
    Student(const string& name, int age, const string& address, int id, int studentID, float marks)
        : Person(name, age, address, id), studentID(studentID), marks(marks) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Student ID FOR EXAMS: " << studentID << endl;
        cout << "Marks: " << marks << endl;
    }

    void saveToFile(ofstream& file) const override {
        Person::saveToFile(file);
        file << studentID << endl;
        file << marks << endl;
    }

    void loadFromFile(ifstream& file) override {
        Person::loadFromFile(file);
        file >> studentID;
        file >> marks;
        file.ignore();
    }

    int getStudentID() const {
        return studentID;
    }

    float getMarks() const {
        return marks;
    }


    string getName() const {
        return name;
    }

    void setMarks(float newMarks) {
        marks = newMarks;
    }
};

class Teacher : public Person {
private:
    string qualification;

public:
    Teacher() {}
    Teacher(const string& name, int age, const string& address, int id, const string& qualifi)
        : Person(name, age, address, id) {
        qualification = qualifi;
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Qualification: " << qualification << endl;
    }

    void saveToFile(ofstream& file) const override {
        Person::saveToFile(file);
        file << qualification << endl;
    }

    void loadFromFile(ifstream& file) override {
        Person::loadFromFile(file);
        getline(file, qualification);
    }
    int teacherid() const {
        int teacherID = Person::id;
        return teacherID;
    }
};

class AdministrationOffice {
private:
    vector<Student> students;
    vector<Teacher> teachers;

public:
    void addNewStudent(const string& name, int age, int id, const string& address, int studentID, float marks ) {
        Student student(name, age, address, id, studentID, marks);
        students.push_back(student);
        cout << "New student added successfully!" << endl;
    }

    void displayAllStudents() const {
        cout << endl;
        cout << "**** Students ****" << endl;
        for (const auto& student : students) {
            student.displayDetails();
            cout << "-------------------" << endl;
        }
    }

    void searchStudentDetails(int studentID) const {
        bool found = false;
        for (const auto& student : students) {
            if (student.getStudentID() == studentID) {
                student.displayDetails();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found with ID: " << studentID << endl;
        }
    }

    void updateStudentMarks(int studentID, float newMarks) {
        bool found = false;
        for (auto& student : students) {
            if (student.getStudentID() == studentID) {
                student.setMarks(newMarks);
                cout << "Student marks updated successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found with ID: " << studentID << endl;
        }
    }

    void deleteStudent(int studentID) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getStudentID() == studentID) {
                students.erase(it);
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }

        cout << "Student not found with ID: " << studentID << endl;
    }

    void addNewTeacher(const string& name, int age, const string& address, int id, const string& qualification) {
        Teacher teacher(name, age, address, id, qualification);
        teachers.push_back(teacher);
        cout << "New teacher added successfully!" << endl;
    }

    void displayAllTeachers() const {
        cout << "**** Teachers ****" << endl;
        for (const auto& teacher : teachers) {
            teacher.displayDetails();
            cout << "-------------------" << endl;
        }
    }

    // New function to generate fee challan of students
    void generateFeeChallan(int studentID) {
        bool found = false;
        for (const auto& student : students) {
            if (student.getStudentID() == studentID) {
                cout << "\t Fee Challan for Student ID: " << studentID << endl;
                int choose;
                do
                {
                    cout << "          WHICH CLASS STUDENT FEE CHALLAN YOU WANT TO GENERATE.... \n";
                    cout << " 1.        CLASS 1 - CLASS 4 " << endl;
                    cout << " 2.        CLASS 5 - CLASS 7" << endl;
                    cout << " 3.        CLASS 8 - CLASS 10" << endl;
                    cout << " 4.        KG,PREP " << endl;
                    cout << " 5.          EXIT" << endl;
                    cin >> choose;
                    switch (choose)
                    {
                        case 1:
                            cout << " THE FEES OF THE DESIRED STUDENT IS 5000";
                            break;
                        case 2:
                            cout << " THE FEES OF THE DESIRED STUDENT  IS 7000";
                            break;
                        case 3: 
                            cout << " THE FEES OF THE DESIRED STUDENT IS 8000";
                            break;
                        case 4: 
                            cout << " THE FEES OF THE DESIRED  STUDENT IS 3000";
                            break;
                        case 5:
                            break;
                }
                } while (choose != 5);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found with ID: " << studentID << endl;
        }
    }

    // New function to pay salary of teachers
    void payTeacherSalary(const  int& teacherid) {
        bool found = false;
        for (auto& teacher : teachers) {
            if (teacher.teacherid() == teacherid) {
                cout << "Paying salary to Teacher: " << teacherid << endl;
                int choose;
                do
                {
                    cout << "          WHICH CLASS TEACHER SALARY ARE YOU  PAYING...."<<endl;
                    cout << "1.        CLASS 1 - CLASS 4 " << endl;
                    cout << "2.        CLASS 5 - CLASS 7" << endl;
                    cout << "3.        CLASS 8 - CLASS 10" << endl;
                    cout << "4.        KG,PREP " << endl;
                    cout << "5.          EXIT" << endl;
                    cin >> choose;
                    switch (choose)
                    {
                    case 1:
                        cout << " THE SALARY OF THE DESIRED TEACHER IS 35000 RS";
                        break;
                    case 2:
                        cout << " THE SALARY OF THE DESIRED TEACHER  IS 40000 RS";
                        break;
                    case 3:
                        cout << " THE SALARY OF THE DESIRED TEACHER IS 60000 RS";
                        break;
                    case 4:
                        cout << " THE SALARY OF THE DESIRED  TEACHER IS 30000 RS";
                        break;
                    case 5:
                        break;
                    }
                } while (choose != 5);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Teacher not found with name: " << teacherid << endl;
        }
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << students.size() << endl;
            for (const auto& student : students) {
                student.saveToFile(file);
            }

            file << teachers.size() << endl;
            for (const auto& teacher : teachers) {
                teacher.saveToFile(file);
            }

            file.close();
            cout << "Data saved to file successfully!" << endl;
        }
        else {
            cout << "Error opening file for saving!" << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            students.clear();
            teachers.clear();

            int numStudents;
            file >> numStudents;
            file.ignore();
            for (int i = 0; i < numStudents; ++i) {
                Student student;
                student.loadFromFile(file);
                students.push_back(student);
            }

            int numTeachers;
            file >> numTeachers;
            file.ignore();
            for (int i = 0; i < numTeachers; ++i) {
                Teacher teacher;
                teacher.loadFromFile(file);
                teachers.push_back(teacher);
            }

            file.close();
            cout << "Data loaded from file successfully!" << endl;
        }
        else {
            cout << "Error opening file for loading!" << endl;
        }
    }
};

void login() {
    int password = 0;
    std::cout << "\n\t  WELCOME!!!";
    std::cout << "\n   =======================================\n";
    std::cout << "\n    THIS IS THE ACCOUNT OFFICE FOR MANAGING SCHOOL DEPARTMENTS ";
    std::cout << "\n   =============================================================\n";
    while (password != 7890) {
        std::cout << "\n\nPlease enter the password to Login to your account .";
        std::cout << "\n\n\tPassword: ";
        std::cin >> password;
        if (password == 7890) {
            cout << "\nLogin Success!!!\n";
            break;
        }

        else {
            std::cout << "\nIncorrect Password!!! Please try again.";
        }
    }
}

int main()
{
    try{
    AdministrationOffice office;
    int choice;
    login();

    do {
        cout << "\n                   **** SCHOOL MANAGEMENT SYSTEM  ****" << endl;
        cout << "1.        Add New Student" << endl;
        cout << "2.        Display All Students" << endl;
        cout << "3.        Search Student Details" << endl;
        cout << "4.        Update Student Marks" << endl;
        cout << "5.        Delete Student" << endl;
        cout << "6.        Add New Teacher" << endl;
        cout << "7.        Display All Teachers" << endl;
        cout << "8.        Generate Fee Challan" << endl;
        cout << "9.        Pay Teacher Salary" << endl;
        cout << "10.       Save to File" << endl;
        cout << "11.       Load from File" << endl;
        cout << "12.       Quit" << endl;
        cout << "       Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name, address;
            int age, studentID;
            float marks;
            int id;

            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student age: ";
            cin >> age;
            cout << "enter student  id :";
            cin >> id;
            cin.ignore();
            cout << "Enter student address: ";
            getline(cin, address);
            cout << "Enter PERMENANT student ID: ";
            cin >> studentID;
            cout << "Enter student marks: ";
            cin >> marks;
            cin.ignore();

            office.addNewStudent(name, age, id, address, studentID, marks);
            break;
        }
        case 2:
            office.displayAllStudents();
            break;
        case 3: {
            int studentID;
            cout << "Enter PERMENANT student ID: ";
            cin >> studentID;
            cin.ignore();
            office.searchStudentDetails(studentID);
            break;
        }
        case 4: {
            int studentID;
            float newMarks;
            cout << "Enter PERMENANT student ID: ";
            cin >> studentID;
            cout << "Enter new marks: ";
            cin >> newMarks;
            cin.ignore();
            office.updateStudentMarks(studentID, newMarks);
            break;
        }
        case 5: {
            int studentID;
            cout << "Enter PERMENANT student ID : ";
            cin >> studentID;
            cin.ignore();
            office.deleteStudent(studentID);
            break;
        }
        case 6: {
            string name, address, qualification;
            int age, id;
            cout << "Enter teacher name: ";
            getline(cin, name);
            cout << "Enter teacher age: ";
            cin >> age;
            cout << "Enter teacher Id : ";
            cin >> id;
            cin.ignore();
            cout << "Enter teacher address: ";
            getline(cin, address);
            cout << "Enter teacher qualification: ";
            getline(cin, qualification);

            office.addNewTeacher(name, age, address, id, qualification);
            break;
        }
        case 7:
            office.displayAllTeachers();
            break;
        case 8: {
            int studentID;
            cout << "Enter PERMENANT student ID: ";
            cin >> studentID;
            cin.ignore();
            office.generateFeeChallan(studentID);
            break;
        }
        case 9: {
            int teacherid;
            cout << "Enter teacher id: ";
            cin >> teacherid;
            office.payTeacherSalary(teacherid);
            break;
        }
        case 10: {
            string filename;
            cout << "Enter file name: ";
            getline(cin, filename);
            office.saveToFile(filename);
            break;
        }
        case 11: {
            string filename;
            cout << "Enter file name: ";
            getline(cin, filename);
            office.loadFromFile(filename);
            break;
        }
        case 12:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 12);
    }
    catch (exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
    catch (...) {
        cout << "An unknown exception occurred." << endl;
    }

    return 0;
}
