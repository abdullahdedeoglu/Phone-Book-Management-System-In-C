# Phone-Book-Management-System-In-C
This C program implements a simple phone book management system using a circular linked list. It allows users to add contacts, search for contacts by name or number, list all contacts, sort contacts by surname, and delete contacts.
# Functionality:
Add Contact:
Users can add a contact by entering the name, surname, and phone number.
The system avoids adding contacts with duplicate phone numbers.

Search Contact:
Users can search for a contact either by name or by phone number.
The system displays the contact details if found; otherwise, it notifies that the contact doesn't exist.

List All Contacts:
Displays all contacts in the phone book.
Sort Contacts:
Sorts the contacts in the phone book alphabetically by surname.

Delete Contact:
Allows users to delete a contact by entering its phone number.

# File Structure:
phonebook.c: C source file containing the implementation of the phone book management system.
README.md: Documentation file explaining the functionalities of the program and how to use it.

# Usage:
Compile:
Compile the C code using a C compiler (e.g., gcc -o phonebook phonebook.c).
Run:
Execute the compiled program (./phonebook in Linux/Mac or phonebook.exe in Windows).
Select Options:
Choose options (1-5) to perform specific operations as prompted by the program.
Options include adding, searching, listing, sorting, and deleting contacts.

# Notes:
The phone book utilizes a circular linked list for contact management.
The program ensures that no duplicate phone numbers are added to the phone book.
Contacts can be searched by name or phone number.
Sorting is done based on the surnames of the contacts.
Improvements:
Enhancements such as additional search functionalities or alphabetical sorting by name can be implemented.
Error handling for invalid inputs or edge cases can be improved for robustness.
Dependencies:
C compiler (e.g., GCC for Linux/Mac or MinGW for Windows)
Author:
Abdullah Dedeoğlu 
