//Header files
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//Declare a struct to hold our each data element and its priority
struct queue_element
{
	int data , priority;
};


//Declare a struct for the priority queue
struct queue
{
	struct queue_element *array;
	int alloc, current_size, high_water_mark;
}*new_queue;



//Declare a struct to hold input from user and pass it to the function like insert and delete using pointer to the struct
struct temp
{
   int  temp_data;
   int temp_priority;
   int temp_id;
}*temp_var;


//Function Decalration
void init(int ,int );

void insert(void *);

void delete(void *);

void disp();



