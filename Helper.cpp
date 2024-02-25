#include "Helper.h"
#include "mainmenu.h"
#include "counter.h"

// Function Greeting
void greeting() {
  string uname;
  string uinput;
  
  spacers(); cout << "Hello, You are? ";
  cin >> uname;

  spacers();
  cout << "Hello " << uname << "!" << endl;
  cout << "Welcome to my small community pet shelter." << endl;
  cout << "Would you like to try? (y/n) ";
  do
    {
      cin >> uinput;
      if (uinput != "y" && uinput != "n" && uinput != "Y" && uinput != "N")
      {
        cout << "Please enter a valid input: (Y/N) " ;
      }
    }
  while (uinput != "Y" && uinput != "y" && uinput != "N" && uinput != "n");

  if (uinput == "Y" || uinput == "y")
  {
    mainmenu();
  }
  else if (uinput == "N" || uinput == "n")
  {
    goodbye();
    exit(1);
  } 
  else // Added this else statement to prevent errors
  {
    cout << "How did we get here?" << endl;
    exit(1);
  }
}

// Good bye user
void goodbye() {
  spacers();
  cout << "Thank you for your time." << endl;
  cout << "Goodbye! The file has been saved." << endl;
  spacers();
}

void spacers() {
  cout << "-----------------------------------------" << endl;
}