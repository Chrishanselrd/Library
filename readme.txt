1. Describe the state of your program, exactly what works and what does not work.
    My program is working fine and able to complete all the required functions for library
    it is able to read data files of books, users/patrons, and commands
    it is able to checkout or return a book.
    it is able to print out all the book and user in the library and the users's history

2. List your hash table(s) that you wrote (not STL) - briefly what they are used for and file they are found in. (Include any factories that are essentially hash tables).
    The hashtable that i used uses an array with a constant integer MAX_SIZE that can be adjusted according to the amount of users.
    It is found only in Library that acts as a container for patrons.

3. State which file and which function you read the book data, just high-level function calls, i.e., how/where it gets into your collections.
    The file that reads the book data is Library and the function is called readBooks(filename) 
    it will read the data and create Items in the Item factory based on the data provided

4. State which file and which function you read the command data, high-level function calls, i.e., how/where you perform the commands.
    The file that reads the command data is Library and the function is called readAction(filename) 
    it will read the data, create Action objects in the Item factory based on the data provided, and executes it from the Action objects

5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.)  If you feel they do not violate the open-closed design principle, explain.
    I used a lot of if statements to check for valid objects or pointers when reading in library even though it is handled in the item and action factory

6. Describe anything you are particularly proud of . . .
    I am proud that everything works and being able to complete this project connecting a lot of different objects and being able to utilize factories