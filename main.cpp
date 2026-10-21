/******************************************************************************
# Author:           Andy Joy
# Assignment:       Assignment 4
# Date:             10/19/2026
# Description:      This program takes up to 20 classes via course ID, and the 
#                   number of students enrolled. The program will "cancel" 
#                   (remove from array) any class with less than 10 students 
#                   enrolled. The program then outputs a full list of courses, 
#                   and a separate list with classes after cancellations.
# Input:            courseNums (2d char array), students (int array).
# Output:           courseNums (2d char array), students (int array).
# Sources:          zyBooks 11.12 - 11.13, SampleA04 code, arrayInsertSort
#                   (Shawli Sengupta).
#******************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Constants
const int MAXCHAR = 51;
const int CAP = 20;

//Function prototypes
void welcome();
void readInput(char courseNums[][MAXCHAR], int students[MAXCHAR], int &count);
void readInt(string prompt, int &num);
void printList(char courseNums[][MAXCHAR], int students[], int count);
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count);

//Main function
int main() {
  char courseNums[CAP][MAXCHAR] = {0};
  int students[MAXCHAR] = {0};
  int count = 0;

  welcome();
  readInput(courseNums, students, count);  
  cout << "\nList of courses and students:" << endl;
  printList(courseNums, students, count);
  cout << "\nList after cancellations:" << endl;
  cancelCourses(courseNums, students, count);
  printList(courseNums, students, count);
  cout << "\nThank you for checking out my Course Rosters program!" << endl;

  return 0;
}

//Welcome function
void welcome() {
  cout << "Welcome to my Course Rosters program!! " << endl;
  cout << "Enter course number and students enrolled when prompted." << endl;
  cout << "Enter Quit or quit for course number when you are done." << endl;
}

//Read input function, used to get all input from user.
//Validates that number of courses are under 20, and number of students are under 25.
//Uses insert sorting for course names and associated student count.
void readInput(char courseNums[][MAXCHAR], int students[], int &count) {
  char tempName[MAXCHAR] = {0};

  cout << "Enter course number: ";
  cin.getline(tempName, MAXCHAR);

  while(strcmp(tempName, "quit") != 0 && strcmp(tempName, "Quit") != 0) {
    if (count < CAP) {
      int i = 0;

      while (i < count && strcmp(courseNums[i], tempName) < 0) {
        i++;
      }
      for (int j = count; j > i; j--) {
        strcpy(courseNums[j], courseNums[j - 1]);
        students[j] = students[j - 1];
      }
      strcpy(courseNums[i], tempName);
      readInt("Number of students enrolled: ", students[i]);
      while (students[i] > 25){
        cout << "Invalid number!! Please enter a number between 0 and 25." << endl;
        readInt("Number of students enrolled: ", students[i]);
      }
      count++;
    }
    if (count == CAP) {
      cout << "List full!!" << endl;
      strcpy(tempName, "quit");
    }
    else {
      cout << "Enter course number: ";
      cin.getline(tempName, MAXCHAR);
    }
  }
}

//Read integer function
void readInt(string prompt, int &num) {
  cout << prompt;
  cin >> num;
  while (!cin || (num < 0)) {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(10, '\n');
}

//Print list function
void printList(char courseNums[][MAXCHAR], int students[], int count) {
  for (int r = 0; r < count; r++) {
    cout << left << setw(16) << courseNums[r] << students[r] << endl;
  }
}

//Cancel courses function, removes classes with < 10 students
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count) {
  for (int i = 0; i < count; i++) {
    if (students[i] < 10) {
      for (int r = i; r < count - 1; r++) {
        students[r] = students[r+1];
        for (int c = 0; c < MAXCHAR; c++){
          courseNums[r][c] = courseNums[r+1][c];
        }
      }
      count--;
      students[count] = 0;
      i--;
    }
  }
}