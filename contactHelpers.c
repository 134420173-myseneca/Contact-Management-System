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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"
// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5 


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
  while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void) {
  printf("(Press Enter to Continue)");
  clearKeyboard();
  printf("\n");
}
// getInt: Empty function definition goes here:
int getInt(void) {
  char NL = 'x';
  int value;
  do {
    scanf("%d%c", &value, &NL);
    if (NL != '\n') {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      scanf("%d%c", &value, &NL);
    }
  } while (NL != '\n');
  return value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int max, int min) {
  int value;
  do {
    value = getInt();

    if (value < min || value > max) {
      printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    }
  } while (value < min || value > max);
  return value;
}
// getchar() function definition goes here 
char getChar(void)
{
  char ch;
  char NL;
  do
  {
    scanf("%c%c", &ch, &NL);
    if (NL != '\n')
    {
      clearKeyboard();
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    }
  } while (NL != '\n');
  return ch;
}
// yes: Empty function definition goes here:
int yes(void) {
  int result;
  char ch;
  do {
    ch = getChar();
    if (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n')) {
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
      ch = getChar();
    }
  } while (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n'));
  if (ch == 'N' || ch == 'n')
    result = 0;
  else
    result = 1;
  return result;
}
// menu: Empty function definition goes here:
int menu(void) {

  int option;

  printf("Contact Management System\n");
  printf("-------------------------\n");
  printf("1. Display contacts\n");
  printf("2. Add a contact\n");
  printf("3. Update a contact\n");
  printf("4. Delete a contact\n");
  printf("5. Search contacts by cell phone number\n");
  printf("6. Sort contacts by cell phone number\n");
  printf("0. Exit\n\n");
  printf("Select an option:> ");
  option = getIntInRange(6, 0);
  return option;
}


void ContactManagerSystem(void) {

  struct Contact contacts[MAXCONTACTS] = { { { "Rick",{ '\0' },"Grimes" } ,{ 11,"Trailer Park",0, "A7A 2J2", "King City" } ,{ "4161112222", "4162223333", "4163334444" } } ,
  { { "Maggie","R.", "Greene" } ,{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" } ,{ "9051112222", "9052223333", "9053334444" } } ,
  { { "Morgan", "A.", "Jones" } ,{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" } ,{ "7051112222", "7052223333", "7053334444" } } ,
  { { "Sasha",{ '\0' }, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }, };
  int feature;
  int selection = 0;
  do {

    feature = menu();
   
    switch (feature) {

    case 1:
      printf("\n");
      displayContacts(contacts, MAXCONTACTS);
      pause();
      break;

    case 2:
      printf("\n");
      addContact(contacts, MAXCONTACTS);
      pause();
      break;

    case 3:
      printf("\n");
      updateContact(contacts, MAXCONTACTS);
      pause();
      break;

    case 4:
      printf("\n");
      deleteContact(contacts, MAXCONTACTS);
      pause();
      break;

    case 5:
      printf("\n");
      searchContacts(contacts, MAXCONTACTS);
      printf("\n");
      pause();
      break;

    case 6:
      printf("\n");
      sortContacts(contacts, MAXCONTACTS);
      pause();
      break;

    case 0:
      printf("\n");
      printf("Exit the program? (Y)es/(N)o: ");
      selection = yes();
      printf("\n");
      if (selection == 1) {

        printf("Contact Management System: terminated\n");
      }
      break;
    default:
      printf("ERROR: Incorrect Option: Try Again\n");
    }
  } while (selection == 0);

}
// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
  int needInput = 1;

  while (needInput == 1) {
    scanf("%10s", telNum);
    clearKeyboard();

    // (String Length Function: validate entry of 10 characters)
    if (strlen(telNum) == 10)
      needInput = 0;
    else
      printf("Enter a 10-digit phone number: ");
  }
}

// findContactIndex:


int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{

  int index = 0;
  int result = -1;

  for (index = 0; index < size; index++) {
    if (strcmp(contacts[index].numbers.cell, cellNum) == 0) {
      result = index;
    }
  }
 
    return result;
  }


// displayContactHea

// Put empty function definition below:

void displayContactHeader(void) {
  printf("+-----------------------------------------------------------------------------+\n");
  printf("|                              Contacts Listing                               |\n");
  printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:

void displayContactFooter(int footer) {
  printf("+-----------------------------------------------------------------------------+\n");
  printf("Total contacts: %d\n\n", footer);
}
// displayContact:
// Put empty function definition below:


void displayContact(const struct Contact* contacts)
{
  if (contacts->name.middleInitial[0] == '\0')
    printf(" %s %s\n", contacts->name.firstName, contacts->name.lastName);

  else
    printf(" %s %s %s\n", contacts->name.firstName, contacts->name.middleInitial, contacts->name.lastName);
 printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);

  if (contacts->address.apartmentNumber > 0)
    printf("       %d %s, Apt# %d, %s, %s\n", contacts->address.streetNumber, contacts->address.street, contacts->address.apartmentNumber, contacts->address.city, contacts->address.postalCode);

  else
    printf("       %d %s, %s, %s\n", contacts->address.streetNumber, contacts->address.street, contacts->address.city, contacts->address.postalCode);

}



// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
  int index;
  int validcounts = 0;

  displayContactHeader();
  for (index = 0; index < size; index++) {
    if (strlen(contacts[index].numbers.cell) > 0) {

      displayContact(&contacts[index]);
      validcounts++;
    }
  }
  displayContactFooter(validcounts);

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {
  char cellNum[11];
  int index;

  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cellNum);
  printf("\n");
  index = findContactIndex(contacts, size, cellNum);

  if (index != -1) {
    displayContact(&contacts[index]);

  }
  if (index == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
  int index;
  int result=-1 ;

  for (index = 0; index < size; index++) {
    if (strlen(contacts[index].numbers.cell) == 0) // first check if strlen calculate string length if 0 mean empty slot avaiable
      result = index;                            // return index on which empty slot available  if its 0
  }

  if (result != -1) {
    getContact(&contacts[result]); 
    printf("--- New contact added! ---\n");
  }
   
  else
    printf("*** ERROR: The contact list is full! ***\n");
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {
   struct Contact empty = { { { 0 } } };
  char option;
  char cellNum[11];
  int index = 0;

  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cellNum);
  index = findContactIndex(contacts, size, cellNum);

  if (index == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }

  else {
    printf("\nContact found:\n");
    displayContact(&contacts[index]);
    printf("\n");
    printf("Do you want to update the name? (y or n): ");
    option = yes();
    if (option == 1) {
      contacts[index].name = empty.name;
      getName(&contacts[index].name);
    }
    printf("Do you want to update the address? (y or n): ");
    option = yes();
    if (option == 1) {
      contacts[index].address = empty.address;
      getAddress(&contacts[index].address);
    }
    printf("Do you want to update the numbers? (y or n): ");
    option = yes();
    if (option == 1) {
      contacts[index].numbers = empty.numbers;
      getNumbers(&contacts[index].numbers);
    }
    printf("--- Contact Updated! ---\n");
  
  }

}
// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
  int option;
  char cellNum[11];
  int index;
  struct Contact empty = { { { 0 } } };

  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cellNum);
  index = findContactIndex(contacts, size, cellNum);

  if (index == -1)
    printf("*** Contact NOT FOUND ***\n");

  else {
    printf("\nContact found:\n");
    displayContact(&contacts[index]);
    printf("\n");
    printf("CONFIRM: Delete this contact? (y or n): ");
    option = yes();

    if (option == 1) {
      contacts[index].numbers.cell[0] = '\0';
      contacts[index] = empty;

      printf("--- Contact deleted! ---\n");

    }

  }
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
  int round ;
  int index ;
  struct Contact tempArray = { { { 0 } } };

  for (round = size - 1; round > 0; round--) {
    for (index = 0; index < round; index++) {
      if (strcmp(contacts[index].numbers.cell, contacts[index + 1].numbers.cell) > 0) {

        tempArray = contacts[index];
        contacts[index] = contacts[index + 1];
        contacts[index + 1] = tempArray ;

      }
    }
  }

  printf("--- Contacts sorted! ---\n");
}