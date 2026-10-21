/******************************************************************************
# Author:           Andy Joy
# Assignment:       Assignment 4
# Date:             10/19/2026
# Description:      
#                   
#                   
# Input:            
#                   
# Output:           
#                   
# Sources:          SampleA04 code, arrayInsertSort (Shawli Sengupta).
#******************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//Constants
const int MAXCHAR = 51;
const int CAP = 20;

//Function prototypes
void welcome();
void readInput(char courseNums[][MAXCHAR], int students[MAXCHAR], int &count);
void readInt(string prompt, int &num);
void printList(char courseNums[][MAXCHAR], int students[], int count);

//Main function
int main() {
  char courseNums[CAP][MAXCHAR] = {0};
  int students[MAXCHAR] = {0};
  int count = 0;

  welcome();
  readInput(courseNums, students, count);
  printList(courseNums, students, count);

  return 0;
}

//Welcome function
void welcome() {
  cout << "Welcome to my Course Rosters program!! " << endl;
  cout << "Enter course number and students enrolled when prompted." << endl;
  cout << "Enter Quit or quit for course number when you are done." << endl;
}

void readInput(char courseNums[][MAXCHAR], int students[], int &count) {
  char tempName[MAXCHAR] = {0};

  cout << "Enter course number: ";
  cin.getline(tempName, MAXCHAR);

  while(strcmp(tempName, "quit") != 0 && strcmp(tempName, "Quit") != 0) {
    if (count < CAP) {
      strcpy(courseNums[count], tempName);
      readInt("Number of students enrolled: ", students[count]);
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

void printList(char courseNums[][MAXCHAR], int students[], int count) {
  for (int r = 0; r < count; r++){
    for (int c = 0; c < MAXCHAR; c++){
      cout << courseNums[r][c];
    }
    cout << "   " << students[r] << endl;
  }
}