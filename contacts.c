/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"
#include "contacts.h"


// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+


// getName:
void getName(struct Name *name) {
  int option;
  printf("Please enter the contact's first name: ");
  scanf("%30[^\n]s", name->firstName);
  clearKeyboard();

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  option = yes();  // calling yes function for input of (y or n) option

  if (option == 1) {

    printf("Please enter the contact's middle initial(s): ");
    scanf("%6[^\n]s", name->middleInitial);
    clearKeyboard();
  }

  printf("Please enter the contact's last name: ");
  scanf("%35[^\n]s", name->lastName);
  clearKeyboard();
}


// getAddress:
void getAddress(struct Address *address) {
  int option;
  printf("Please enter the contact's street number: ");
  address->streetNumber = getInt(); // calling getInt for getting valid integer as a strret number

  printf("Please enter the contact's street name: ");
  scanf("%40[^\n]s", address->street);
  clearKeyboard();

  printf("Do you want to enter an apartment number? (y or n): ");
  option = yes();  // calling yes function for input of (y or n) option

  if (option == 1)
  {
    printf("Please enter the contact's apartment number: ");
    address->apartmentNumber = getInt();  // calling getInt for getting valid integer as a strret number
  }
  printf("Please enter the contact's postal code: ");
  scanf(" %7[^\n]s", address->postalCode);
  clearKeyboard();

  printf("Please enter the contact's city: ");
  scanf("%40[^\n]s", address->city);
  clearKeyboard();
}

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable

void getNumbers(struct Numbers *numbers) {
  int option;
  printf("Please enter the contact's cell phone number: ");
  getTenDigitPhone(numbers->cell);
  
  printf("Do you want to enter a home phone number? (y or n): ");
  option = yes();  // calling yes function for input of (y or n) option
  if (option == 1)
  {
    printf("Please enter the contact's home phone number: ");
    getTenDigitPhone( numbers->home);
    
  }
  printf("Do you want to enter a business phone number? (y or n): ");
  option = yes(); // calling yes function for input of (y or n) option

  if (option == 1)
  {
    printf("Please enter the contact's business phone number: ");
    getTenDigitPhone(numbers->business);
    
  }
}
// getContact
void getContact(struct Contact *contact) {
  getName(&contact->name);
  getAddress(&contact->address);
  getNumbers(&contact->numbers);
}


