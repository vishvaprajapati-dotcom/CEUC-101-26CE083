#include<iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string fileName = "Document.txt";
    const string backupName = "BackupDocument.txt";

    cout << "********************************************\n";
    cout << "FILE ORGANIZATION & FILE OPERATIONS UTILITY\n";
    cout << "********************************************\n";

    // Part A: Create the file and write multiple lines.
    ofstream outputFile(fileName);
    if (!outputFile) {
        cout << "Error: Unable to create Document.txt\n";
        return 1;
    }

    cout << "Document.txt Created Successfully\n";
    cout << "--------------------------------------------\n";
    cout << "Enter File Contents\n";

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;  // Press Enter on an empty line to finish.
        }
        outputFile << line << '\n';
    }
    outputFile.close();

    cout << "Data Written Successfully\n";
    cout << "--------------------------------------------\n";

    // Part B: Read and display the complete file.
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Error: Unable to open Document.txt for reading\n";
        return 1;
    }

    cout << "Reading Document.txt\n";
    while (getline(inputFile, line)) {
        cout << line << '\n';
    }

    if (inputFile.eof()) {
        cout << "--------------------------------------------\n";
        cout << "End of File Reached Successfully\n";
    }
    inputFile.close();

    cout << "--------------------------------------------\n";

    // Part C: Copy the contents to a backup file.
    cout << "Creating BackupDocument.txt\n";

    ifstream sourceFile(fileName);
    if (!sourceFile) {
        cout << "Error: Unable to open Document.txt for copying\n";
        return 1;
    }

    ofstream backupFile(backupName);
    if (!backupFile) {
        cout << "Error: Unable to create BackupDocument.txt\n";
        return 1;
    }

    backupFile << sourceFile.rdbuf();
    sourceFile.close();
    backupFile.close();

    cout << "Contents Copied Successfully\n";

    ifstream verifyBackup(backupName);
    if (verifyBackup) {
        cout << "Backup File Created Successfully\n";
    } else {
        cout << "Error: Backup file could not be verified\n";
        return 1;
    }
    verifyBackup.close();

    cout << "--------------------------------------------\n";

    // Part D: Show file position, seek, read, and reset.
    ifstream randomFile(fileName);
    if (!randomFile) {
        cout << "Error: Unable to open Document.txt for random access\n";
        return 1;
    }

    randomFile.seekg(0, ios::end);
    streampos fileSize = randomFile.tellg();
    cout << "Current File Position : " << fileSize << '\n';

    // Return to the beginning, then move to the second line.
    randomFile.clear();
    randomFile.seekg(0, ios::beg);

    string firstLine;
    getline(randomFile, firstLine);
    streampos secondLinePosition = randomFile.tellg();

    if (secondLinePosition != streampos(-1)) {
        randomFile.seekg(secondLinePosition);
        cout << "Moving File Pointer...\n";
        cout << "Displaying Contents after Repositioning\n";

        while (getline(randomFile, line)) {
            cout << line << '\n';
        }
    } else {
        cout << "Not enough content to move to a second line.\n";
    }

    // Reset the pointer and display the whole file again.
    randomFile.clear();
    randomFile.seekg(0, ios::beg);

    cout << "--------------------------------------------\n";
    cout << "Resetting File Pointer\n";
    while (getline(randomFile, line)) {
        cout << line << '\n';
    }

    randomFile.close();

    cout << "--------------------------------------------\n";
    cout << "Observation: Sequential files are read in order. "
            "Seeking lets the program reposition the file pointer "
            "and read from another location.\n";
    cout << "--------------------------------------------\n";
    cout << "Program Executed Successfully\n";
    cout << "--------------------------------------------\n";

    return 0;
}
