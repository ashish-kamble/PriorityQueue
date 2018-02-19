This Project Folder has the following file structure
->Priority_Queue
  -> main.c
  -> Priority_Queue.c
  -> Priority_Queue.h
  -> Makefile
  -> Readme.txt

The Project folder contains C Code to demonstrate the working of Priority Queue 

-Implementation is explained below :
The Queue has been designed using HEAP Data Structure.
Specifically a Minimum Heap has been implemented for the Priority Queue.
In this every new Element is added to the end of Heap and based upon its priority it is moved up to the top node 
i.e Root node

****
Note : In our case every node will have a integer priority value and lower the value, higher will be its priority
****

Also 'pthread' library have been used to add Multi Thraeding Functionality for Enqueuing and Dequeuing elements 
from the queue concurently.
Also to avoid disastrous effect of Multi Thraeding on shared data resource Mutex functionality have been used.
Thus making our Priority Queue Thread safe.

This Program have been tested on Linux System
-How to Run the program on Linux system
1> Download the zip file and extract it in your prefered directory.
2> In the terminal go to that directory
3> If you type 'ls' and hit enter you must 5 files (main.c, Priority_Queue.c, Priority_Queue.h, Makefiel, Readme.txt).
4> Now simply type 'make all' in the terminal and hit enter.
5> After successful compilation of C Code an exe file named as 'run' is created in the same directory.
6> Now to see the output type './run' and hit enter
7> To remove the exe file type 'make clean' and hit enter in the terminal.

-Explanation of the Interface
When the exe file 'run' is executed from the terminal, at the begining lots data is printed,before the program is waiting 
for an input from the user.
Those prints represent the activity of Enqueue from two seperate Threads and Dequeue from two seperate Threads happening
concurrently.
For verification that the Enqueue and Dequeue is happening from four independent Threads please check main.c line number 60.
The function calls to insert and delete functions is happening only by using Threads.

Later on the user is given an option to perform operation on the Queue and see the changes.
User needs to select apropriate otpions :
->Enter 1 to insert 
->Enter 2 to delete 
->Enter 3 to display 
->Enter 4 to exit 

****
Note : User will be asked to enter size of Queue . Please enter '20' as only 20 elements have been mentioned in Fixed Data Set
****   specified in main.c. a
       There is no issue in increasing the queue size as much as you want but the Data set for loop need to be commented or 
       removed or else garbage value will be added to the end of Queue.  
  
 
 
