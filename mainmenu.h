#include <string>
#include "Pet.h"

// Display
void menudisplay();
void mainmenu();

// Picking shelter and adding a pet
void pickshelter(bool& shelterpicked, string& sheltername, Pet* arr[], int& count);
void addpet(string sheltername, Pet* arr[], int& count);

// Print functions
void print_shelter(string sheltername, Pet* arr[], int count);
void print_longest_pet_in_shelter(string sheltername, Pet* arr[], int count);

// File manipulators
void loading_shelter_from_file(Pet* arr[], int& count, string filename);
void writing_shelter_to_file(Pet*arr[], int& count, string filename);

