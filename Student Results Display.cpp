#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cerrno>     // add with your other #include lines
#include <cstring>    // add with your other #include lines
using namespace std;
const int NUM_STUDENTS = 10;

int main()
{ 
	// CALLING FUNCTIONS
    string name[NUM_STUDENTS];
    string grade[NUM_STUDENTS];
    float marks[NUM_STUDENTS][5];
    float total[NUM_STUDENTS];
    float average[NUM_STUDENTS];
    float percentage[NUM_STUDENTS];
    float Total_marks;
    float Average_Marks;
    float Percentage;
    float classTotalMarks = 0;
    
   ofstream out("C:\\Users\\PC\\OneDrive\\Documents\\results.txt");
 if (!out) {
    cout << "Error: could not create results.txt" << endl;
    cout << "Reason: " << strerror(errno) << endl;
    return 1;
 }
 
  out << fixed << setprecision(2);
    cout << fixed << setprecision(2);

    for (int s = 0; s < NUM_STUDENTS; s++) {
        cout << "\n--- Student " << s + 1 << " ---" << endl;
        cout << "Enter name: ";
        cin >> name[s];

        Total_marks = 0;

        cout << "Enter the marks for the five subjects: ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[s][i];
            Total_marks += marks[s][i];
        }

        Average_Marks = Total_marks / 5;
        Percentage = (Total_marks / 500) * 100;
        classTotalMarks += Total_marks;
        total[s] = Total_marks;
        average[s] = Average_Marks;
        percentage[s] = Percentage;

        // STORING GRADES
        if (Percentage >= 80)      grade[s] = "A";
        else if (Percentage >= 70) grade[s] = "B";
        else if (Percentage >= 60) grade[s] = "C";
        else if (Percentage >= 50) grade[s] = "D";
        else                       grade[s] = "Fail";

        cout << "\nResults for " << name[s] << endl;
        cout << "Total Marks: " << Total_marks << endl;
        cout << "Average Marks: " << Average_Marks << endl;
        cout << "Percentage: " << Percentage << "%" << endl;
        cout << "Grade: " << grade[s] << endl;
    
    // WRITING RESULTS IN A FILE
        out << "\nResults for " << name[s] << endl;
        out << "Total Marks: " << Total_marks << endl;       // line 64
        out << "Average Marks: " << Average_Marks << endl;
        out << "Percentage: " << Percentage << "%" << endl;
        out << "Grade: " << grade[s] << endl;
	}
    // SORTING STUDENT TOTAL MARKS USING BUBBLE SORT
    int order[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) { 
	order[i] = i;
	}
	for (int i = 0; i < NUM_STUDENTS - 1; i++) {
        for (int j = 0; j < NUM_STUDENTS -1 - i; j++) {
            if (total[order[j]] < total[order[j + 1]]) {
                int temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }

    cout << "\n=================== CLASS LIST ===================" << endl;
    cout << left << setw(5) << "Pos"
         << setw(12) << "Name"
         << setw(8) << "S1"
         << setw(8) << "S2"
         << setw(8) << "S3"
         << setw(8) << "S4"
         << setw(8) << "S5"
         << setw(10) << "Total"
         << setw(10) << "Average"
         << setw(10) << "%"
         << setw(6) << "Grade" << endl;

    for (int p = 0; p < NUM_STUDENTS; p++) {
        int s = order[p];   // STUDENT POSITON
        cout << left << setw(5) << p + 1
             << setw(12) << name[s];
        for (int i = 0; i < 5; i++) {
            cout << setw(8) << marks[s][i];
        }
        cout << setw(10) << total[s]
             << setw(10) << average[s]
             << setw(10) << percentage[s]
             << setw(6) << grade[s] << endl;
    }

    float classAverageMarks = classTotalMarks / NUM_STUDENTS;
    float classPercentage = (classAverageMarks / 500) * 100;

    cout << "\n===== CLASS RESULTS =====" << endl;
    cout << "Class Total Marks: " << classTotalMarks << endl;
    cout << "Class Average Marks: " << classAverageMarks << endl;
    cout << "Class Percentage: " << classPercentage << "%" << endl;

    if (classPercentage >= 80) {
        cout << "Class Grade: A" << endl;
    } else if (classPercentage >= 70) {
        cout << "Class Grade: B" << endl;
    } else if (classPercentage >= 60) {
        cout << "Class Grade: C" << endl;
    } else if (classPercentage >= 50) {
        cout << "Class Grade: D" << endl;
    } else {
        cout << "Class Grade: Fail" << endl;
    }
   out.close();
    return 0;
}