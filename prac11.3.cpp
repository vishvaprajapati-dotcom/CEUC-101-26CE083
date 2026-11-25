#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct Student {
    string enrollmentNumber;
    string name;
    string branch;
    int semester{};
    double percentage{};
    string grade;
};

int main() {
    cout << "********************************************\n";
    cout << "     STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "********************************************\n";

    // Create/truncate the sequential record file. Check that it opened.
    ofstream recordFile("StudentRecords.txt", ios::out | ios::trunc);
    if (!recordFile.is_open()) {
        cerr << "Error: StudentRecords.txt could not be created.\n";
        return EXIT_FAILURE;
    }
    recordFile.close();
    cout << "StudentRecords.txt Created Successfully\n";
    cout << "--------------------------------------------\n";

    int count;
    cout << "Enter Number of Students : ";
    if (!(cin >> count) || count < 0) {
        cerr << "Error: Enter a valid non-negative number of students.\n";
        return EXIT_FAILURE;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Store one student per line, with pipe separators, in sequential order.
    recordFile.open("StudentRecords.txt", ios::out | ios::app);
    if (!recordFile.is_open()) {
        cerr << "Error: StudentRecords.txt could not be opened for writing.\n";
        return EXIT_FAILURE;
    }

    for (int i = 0; i < count; ++i) {
        Student student;
        cout << "Student " << i + 1 << "\n";
        cout << "Enrollment Number : ";
        getline(cin, student.enrollmentNumber);
        cout << "Student Name : ";
        getline(cin, student.name);
        cout << "Branch : ";
        getline(cin, student.branch);
        cout << "Semester : ";
        if (!(cin >> student.semester)) {
            cerr << "Error: Semester must be a whole number.\n";
            recordFile.close();
            return EXIT_FAILURE;
        }
        cout << "Percentage : ";
        if (!(cin >> student.percentage)) {
            cerr << "Error: Percentage must be a number.\n";
            recordFile.close();
            return EXIT_FAILURE;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Grade : ";
        getline(cin, student.grade);

        recordFile << student.enrollmentNumber << '|'
                   << student.name << '|'
                   << student.branch << '|'
                   << student.semester << '|'
                   << fixed << setprecision(2) << student.percentage << '|'
                   << student.grade << '\n';
        if (!recordFile) {
            cerr << "Error: A student record could not be written.\n";
            recordFile.close();
            return EXIT_FAILURE;
        }
        cout << "--------------------------------------------\n";
    }
    recordFile.close();
    if (!recordFile) {
        cerr << "Error: StudentRecords.txt could not be saved correctly.\n";
        return EXIT_FAILURE;
    }
    cout << "Student Records Stored Successfully\n";
    cout << "--------------------------------------------\n";

    cout << "Reading StudentRecords.txt\n";
    ifstream inputFile("StudentRecords.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: StudentRecords.txt could not be opened for reading.\n";
        return EXIT_FAILURE;
    }

    string line;
    while (getline(inputFile, line)) {
        Student student;
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        size_t p4 = line.find('|', p3 + 1);
        size_t p5 = line.find('|', p4 + 1);
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos ||
            p4 == string::npos || p5 == string::npos) {
            cerr << "Error: StudentRecords.txt contains a malformed record.\n";
            inputFile.close();
            return EXIT_FAILURE;
        }

        student.enrollmentNumber = line.substr(0, p1);
        student.name = line.substr(p1 + 1, p2 - p1 - 1);
        student.branch = line.substr(p2 + 1, p3 - p2 - 1);
        student.semester = stoi(line.substr(p3 + 1, p4 - p3 - 1));
        student.percentage = stod(line.substr(p4 + 1, p5 - p4 - 1));
        student.grade = line.substr(p5 + 1);

        cout << "Enrollment : " << student.enrollmentNumber << '\n';
        cout << "Name : " << student.name << '\n';
        cout << "Branch : " << student.branch << '\n';
        cout << "Semester : " << student.semester << '\n';
        cout << "Percentage : " << fixed << setprecision(2) << student.percentage << '\n';
        cout << "Grade : " << student.grade << '\n';
        cout << "--------------------------------------------\n";
    }
    if (!inputFile.eof()) {
        cerr << "Error: A problem occurred while reading StudentRecords.txt.\n";
        inputFile.close();
        return EXIT_FAILURE;
    }
    inputFile.close();
    cout << "End of File Reached Successfully\n";
    cout << "--------------------------------------------\n";

    cout << "Creating BackupStudentRecords.txt\n";
    ofstream backupFile("BackupStudentRecords.txt", ios::out | ios::trunc);
    if (!backupFile.is_open()) {
        cerr << "Error: BackupStudentRecords.txt could not be created.\n";
        return EXIT_FAILURE;
    }

    // Reopen the source and copy each line to the backup in sequence.
    inputFile.open("StudentRecords.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: StudentRecords.txt could not be opened for backup.\n";
        backupFile.close();
        return EXIT_FAILURE;
    }
    while (getline(inputFile, line)) {
        backupFile << line << '\n';
        if (!backupFile) {
            cerr << "Error: A record could not be written to the backup file.\n";
            inputFile.close();
            backupFile.close();
            return EXIT_FAILURE;
        }
    }
    if (!inputFile.eof()) {
        cerr << "Error: A problem occurred while reading records for backup.\n";
        inputFile.close();
        backupFile.close();
        return EXIT_FAILURE;
    }
    inputFile.close();
    backupFile.close();
    if (!backupFile) {
        cerr << "Error: BackupStudentRecords.txt could not be saved correctly.\n";
        return EXIT_FAILURE;
    }

    cout << "Backup Completed Successfully\n";
    cout << "--------------------------------------------\n";
    cout << "Program Executed Successfully\n";
    cout << "--------------------------------------------\n";
    return EXIT_SUCCESS;
}
