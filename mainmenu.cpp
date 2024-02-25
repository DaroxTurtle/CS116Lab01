/*
  Main code for pet shelter program
*/ 

#include "Helper.h"
#include "mainmenu.h"
#include <filesystem>

void menudisplay() {
  spacers();
  cout << "Please choose an option from the menu below." << endl;
  cout << "1. Pick Shelter" << endl;
  cout << "2. Add Pet" << endl;
  cout << "3. View Pets" << endl;
  cout << "4. Print longest pet in Shelter" << endl;
  cout << "5. Done" << endl;
  spacers();
  cout << "Input 1 - 5: ";
}

void mainmenu() {
  bool done = true;
  bool shelterpicked = false;
  bool invalidinput = false;
  string sheltername;
  Pet* arr[SIZE];
  int count = 0;

  while(done) {
    menudisplay();
    int uinput;

    if (!(cin >> uinput)) { // If user does not enter an integer input
      cout << "Please enter valid input from 1-5." << endl;
      invalidinput = true;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch(uinput) {
        case 1: // Picking the shelter
          pickshelter(shelterpicked, sheltername, arr, count);
          break;
        case 2: // Adding a pet to the shelter
          if (shelterpicked == true) {
            addpet(sheltername, arr, count);
          } else { // If shelter has not been picked
            spacers();
            cout << "Please pick a shelter first." << endl;
          }
          break;
        case 3: // Printing thte pets in the shelter
          if (shelterpicked == true) {
            print_shelter(sheltername, arr, count);
          } else {
            spacers();
            cout << "Please pick a shelter first." << endl;
          }
          break;
        case 4: // Printing the longest pet in the shelter
          if (shelterpicked == true) {
            print_longest_pet_in_shelter(sheltername, arr, count);
          } else {
            spacers();
            cout << "Please pick a shelter first." << endl;
          }
          break;
        case 5: // When user decides to end the program, and saves the file
          writing_shelter_to_file(arr, count, sheltername);
          done = false;
          goodbye();
          break;
        default: // If user inputs a number that is not 1-5
          if (invalidinput == false && (uinput < 1 || uinput > 5)) {
            cout << "Please enter valid input from 1-5." << endl;
          }
          break;
      }
  }
}

// Picking shelter function
void pickshelter(bool& shelterpicked, string& sheltername, Pet* arr[], int& count) {
  string uinput;
  string tempfilename;

  string filename;

  spacers();
  do {
    cout << "Would you lke to pick a shelter? (y/n)" << endl;
    cout << "y / Y if shelter exists" << endl;
    cout << "n / N if shelter does not exist, and would like to create one." << endl;
    spacers();
    cout << "Input Y or N: "; cin >> uinput;
    spacers();
  } while (uinput != "Y" && uinput != "y" && uinput != "N" && uinput != "n");

  if (uinput == "y" || uinput == "Y") {
    cout << "Please enter the name of the shelter you would like to pick: ";
    cin >> filename;

    // Check whether the user input has the .txt at the end or not.
    if (filename.find(".") == string::npos) {
        tempfilename = filename + ".txt";
    } else {
      tempfilename = filename;
    }

    // Checking whether the file exists or not in shelters folder.
    ifstream ifs("./shelters/" + tempfilename);
    if (ifs.fail()) {
      cout << "Failed to find shelter " << filename << endl;
    } else {
      spacers();
      cout << "Shelter " << filename << " found." << endl;
      shelterpicked = true;
      sheltername = filename;
    }
    
  } else if (uinput == "n" || uinput == "N") {
    cout << "Please enter the name of the shelter you would like to create: ";
    cin >> filename;
    ofstream ofs("./shelters/" + filename + ".txt");
    cout << "Shelter " << filename << " created, and opened." << endl;
  }
  
  loading_shelter_from_file(arr, count, filename);
}

// Add pet function
void addpet(string sheltername, Pet* arr[], int& count) {
  string name,type;
  int age, id, days;
  int previousidnumber;

  spacers();
  cout << "Please enter the name of the pet: ";
  cin >> name;
  if (count < SIZE) {
    arr[count] = new Pet();
    arr[count]->set_name(name);

    cout << "Please enter what type " << name << " is: ";
    cin >> type;
    arr[count]->set_type(type);

    cout << "Please enter the age of " << name <<": ";
    while (!(cin >> age)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "Age should be a number, please try again: ";
    }
    arr[count]->set_age(age);
    
    previousidnumber = (1001 + count);
    arr[count]->set_id_number(previousidnumber);
    arr[count]->set_days_in_shelter(0);

    spacers();
    cout << "Pet successfully added to the Pet Shelter." << endl;
    count++;
  } else {
    spacers();
    cout << "Unable to add new pet in the pet shelter, as the shelter is full." << endl;
    cout << "Perhaps another pet shelter may be available to shelter, " << name << "?" << endl;
  }
}

// Loading shelter data file to an array.
void loading_shelter_from_file(Pet* arr[], int& count, string filename) {
  string tempfilename;

  if (filename.find(".") == string::npos) {
    tempfilename = filename + ".txt";
  } else {
    tempfilename = filename;
  }
  
  ifstream ifs("./shelters/" + tempfilename);

  string name, type;
  int age, id_number, days_in_shelter;

  while (count < SIZE && ifs >> name >> type >> age >> id_number >> days_in_shelter) {
    arr[count] = new Pet();
    arr[count]->set_name(name);
    arr[count]->set_type(type);
    arr[count]->set_age(age);
    arr[count]->set_id_number(id_number);
    arr[count]->set_days_in_shelter(days_in_shelter);
    arr[count]->increment_days_in_shelter();
    count++;
  }
}

// Printing shelter data
void print_shelter(string sheltername, Pet* arr[], int count) {
  spacers();
  cout << "Shelter: " << sheltername << endl;
  cout << "Number of pets: " << count << endl;
  spacers();
  cout << "Name Type Age ID Days" << endl;
  spacers();
  for (int i = 0; i < count; i++) {
    cout << (i + 1) << " " << arr[i]->get_name() << " " << arr[i]->get_type() << " " << arr[i]->get_age() << " " << arr[i]->get_id_number() << " " << arr[i]->get_days_in_shelter() << endl;
    }
}

void writing_shelter_to_file(Pet*arr[], int& count, string filename) {
  string tempfilename;

  if (filename.find(".") == string::npos) {
    tempfilename = filename + ".txt";
  } else {
    tempfilename = filename;
  }

  ofstream ofs("./shelters/" + tempfilename);

  for (int i = 0; i < count; i++) {
    ofs << arr[i]->get_name() << " " << arr[i]->get_type() << " " << arr[i]->get_age() << " " << arr[i]->get_id_number() << " " << arr[i]->get_days_in_shelter() << endl;
    }
}

// Longest pet in the shelter
void print_longest_pet_in_shelter(string sheltername, Pet* arr[], int count) {
  string name;
  string type;
  int age;
  int id;
  int days = -1;

  if (count > 0) {
    for (int i = 0; i < count; i++) {
      if (days < arr[i]->get_days_in_shelter()) {
        name = arr[i]->get_name();
        type = arr[i]->get_type();
        age = arr[i]->get_age();
        id = arr[i]->get_id_number();
        days = arr[i]->get_days_in_shelter();
      }
    }
  
    spacers();
    cout << "The longest pet in " << sheltername << " is " << name << " which is a " << type << " who is " << age << " years old, and has been in the shelter for " << days << " days." << endl;
  } else {
    cout << "There are no pets in the shelter." << endl;
  }
}