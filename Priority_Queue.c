//Header files
#include "Priority_Queue.h"
#include <pthread.h>


//Decalre and Initialise Mutex for synchronising threads while accessing shared data resource
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;


//Function to Initialise our Queue
void init(int max,int water_mark)
{
	new_queue = (struct queue *)malloc(sizeof(struct queue));
	new_queue->array = (struct queue_element *)malloc(sizeof(struct queue_element) * max);
    temp_var = (struct temp *)malloc(sizeof(struct temp));
	new_queue->alloc = max;
	new_queue->current_size = 0; 
    new_queue->high_water_mark = water_mark;
}

//Function to Enqueue new node i.e. element in Queue
void insert(void *point)
{
    //Lock the Thread for preventing shared data resource from being corrupt
	pthread_mutex_lock( &mutex1 );
    //Declare a struct variable to accese the struct elements passed by reference 

    //Check if Queue size has reached high water mark limit
	if((((new_queue->current_size + 1)*100)/(new_queue->alloc)) >= new_queue->high_water_mark) 
		printf("->Queue size has reached high limit !  Dequeue some elements before inserting new elements\n");
	//If not add the new element to the Queue
    else
	{
        //Forming a binary tree for cratina a min Heap
		int child , parent;
		new_queue->current_size++;
        //Initialise the child and parent parent node of the Heap
		child = new_queue->current_size - 1;
		parent = (child - 1)/2;
        //Check if priority of new node to be added has higher priority than current parent node
		while((child > 0) && (temp_var->temp_priority < new_queue->array[parent].priority))
		{
            //If yes then assign the values of current parent node to the new child node
			new_queue->array[child] = new_queue->array[parent];
            //Update the values of child and parent index 
			child = parent;
			parent = (child - 1)/2;
		}
        //Assigning new values to the node
		new_queue->array[child].data = temp_var->temp_data;
		new_queue->array[child].priority = temp_var->temp_priority;
        printf("->After Inserting new element the Highest priority node available is having Data : %d  and Priority : %d \n",new_queue->array[0].data , new_queue->array[0].priority);
        int percent;
        percent = (((new_queue->current_size)*100)/(new_queue->alloc));
        printf("->Queue is %d percent filled \n",percent);
	}
    //Unlock the Thread for allowing waiting threads to get access to data resource 
	pthread_mutex_unlock( &mutex1 );
}



//Fucntion to Dequeue highes priority node
void delete(void *flag)
{
    //Lock the Thread for preventing shared data resource from being corrupt
	pthread_mutex_lock( &mutex2 );
    //Declare a struct variable to access the struct elements by reference
    //Check if Queue is empty
	if(new_queue->current_size == 0)
	{
		printf("->Queue is empty ! Enter some elements in the Queue\n");
	}
    //If not we can Dequeue the highest priority element
	else 
	{  
        //Check if Queue contains only one element
		if(new_queue->current_size == 1)	
		{
            //If yes then change the index of current size to remove the first node from Queue
			new_queue->current_size = 0;
		}
        //If Queue contians more than one element then remove first node and rearrange the remaining node based on priority
		else
        {
            //Initialise the child and parent node indx values for Dequeuing
            int par = 0;
            int ch1 = 1;
            int ch2 = 2;
            
            //Check which the two child of Root node have higher priority 

            if((ch2 > (new_queue->current_size - 1)) || (new_queue->array[ch1].priority < new_queue->array[ch2].priority))
            {
                //If child1 have higher priority than child2 then assign Root node the value of child1 node 
                new_queue->array[par] = new_queue->array[ch1];
                par = ch1;
            }
            else
            {
                //Assign Root node th value of child2 node
                new_queue->array[par] = new_queue->array[ch2];
                par = ch2;
            }
            
            //Update the child and parent index values
            ch1 = 2*par + 1;
            ch2 = 2*par + 2;
            
            //Now after Dequeuing the root node rearrange the rest of the node as per priority
            int length = new_queue->current_size;
            int current = par + 1;
            while(current != length)
            {
                new_queue->current_size = current - 1;

            //Forming a binary tree for cratina a min Heap
            int child , parent;
            new_queue->current_size++;
            //Initialise the child and parent parent node of the Heap
            child = new_queue->current_size - 1;
            parent = (child - 1)/2;
            //Check if priority of new node to be added has higher priority than current parent node
            while((child > 0) && (new_queue->array[current].priority < new_queue->array[parent].priority))
            {
                //If yes then assign the values of current parent node to the new child node
                new_queue->array[child] = new_queue->array[parent];
                //Update the values of child and parent index 
                child = parent;
                parent = (child - 1)/2;
            }
            //Assigning new values to the node
            new_queue->array[child].data = new_queue->array[current].data;
            new_queue->array[child].priority = new_queue->array[current].priority;
            current++;
            }
                new_queue->current_size = length - 1;    
            printf("->After Deleting the node with Highest priority available is having Data : %d  and Priority : %d \n",new_queue->array[0].data , new_queue->array[0].priority);
        }
	}
    //Unlock the Thread for allowing waiting threads to get access to data resource
	pthread_mutex_unlock( &mutex2 );
}



//Function to display current elements present inside the Queue
void disp()
{
    printf("-> \t Data       priority \n");
    for (int i = 0; i < new_queue->current_size; i++)
    {
        printf("\t %d \t", new_queue->array[i].data);
        printf("\t %d \n", new_queue->array[i].priority);
    }    
}
