//Header files
#include "Priority_Queue.c"
#include <pthread.h>


//Main program
int main()
{
    //Variable for storing option selected by user
    int choice = 0;

    //Variables for storing attributes of queue
    int value,p,size,high;

    //Decalring Threads
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;

    //Creating Function pointer to functions insert and delete so as to pass them as argument to pthread_create function
    void *(*func_ptr_insert)(void *) = insert;
    void *(*func_ptr_delete)(void *) = delete;

    //Flag variable to toggle between the threads
    int flag = 1;
    //Variables to hold return value of pthread_create function 
    int check1 , check2 , check3 , check4;

    //Variable used while pthread_join function to identify which all threads are created and need to be joined  
    int thread_id = 0;

    //Initialising Muteex feature from pthread lib
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
         
    //Fixed Data Set to test Multi Threading functionality
    //if my_choice is '0' then Enqueue is done and if my_choice is '1' then Dequeue is done
    int my_choice[] = {0, 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0};
     
    int my_data[] = {10, 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 20 , 19 , 18 , 17 , 16 , 15 , 14 , 13 , 12 , 11 , 21 , 22};

    int my_priority[] = {1, 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 80 , 90};


    printf("->Enter size of Queue : ");
    scanf("%d",&size);
    printf("\n->Enter High Water Mark : ");
    scanf("%d",&high);
    init(size,high);

    for(int i = 0; i < size; i++)
    {
        //Extracting each data element from the Fixed Data Set and performing Enqueue or Dequeue based on value of my_choice 
    	temp_var->temp_data = my_data[i];
    	temp_var->temp_priority = my_priority[i];
    	if((my_choice[i] == 0) && (flag == 1))
    	{
            //Executing Enqueue by using insert function by Thread1
            check1 = pthread_create(&thread1, NULL, func_ptr_insert,(void *) &temp_var); 
            if(check1 != 0) printf("error : thread1 \n");
            flag = 2;
            thread_id = 1;
    	} 
        else if((my_choice[i] == 0) && (flag == 2))
        {
            //Executing Enqueue by using insert function by Thread2
            check2 = pthread_create(&thread2, NULL, func_ptr_insert,(void *) &temp_var); 
            if(check2 != 0) printf("error : thread2 \n");
            flag = 1;
            thread_id = 2;
        }
    	if((my_choice[i] == 1) && (flag == 1))
    	{
            //Executing Dequeue by using delete function by Thread3
            check3 = pthread_create(&thread3, NULL, func_ptr_delete,(void *) &temp_var);
            if(check3 != 0) printf("error : thread3 \n"); 
            flag = 2;
            thread_id = 3;   
    	}
        else if((my_choice[i] == 1) && (flag == 2))
        {
            //Executing Dequeue by using delete function by Thread4
            check4 = pthread_create(&thread4, NULL, func_ptr_delete,(void *) &temp_var);
            if(check4 != 0) printf("error : thread4 \n");
            flag = 1;
            thread_id = 4;
        }

        //Switch case to select appropriate Thread to join
        switch(thread_id)
        {
            case 1 :
            {
                pthread_join(thread1,NULL);
                break;
            }
            case 2 :
            {
                pthread_join(thread2,NULL);
                break;
            }
            case 3 :
            {
                pthread_join(thread3,NULL);
                break;
            }
            case 4 :
            {
                pthread_join(thread4,NULL);
                break;
            }
            default : break;
        }
        disp();
    }

    //Section which allows user to prompt in terminal and perform operation on Queue based upon diplayed option
    printf("->Enter 1 to insert \n");
    printf("->Enter 2 to delete \n");
    printf("->Enter 3 to display \n");
    printf("->Enter 4 to exit \n");
    while(choice != 4)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:  
			{
                //Enqueu element to queue
				printf("->Enter Data :");
				scanf("%d",&value);
                printf("->Enter its Priority  :\n");
                scanf("%d",&p);
				temp_var->temp_data = value;
				temp_var->temp_priority = p;
                if(flag  == 1)
                {
                    check1 = pthread_create(&thread1, NULL, func_ptr_insert,(void *) &temp_var); 
                    if(check1 != 0) printf("error : thread1 \n");
                    flag = 2;
                    thread_id = 1;
                }
                else if(flag == 2)
                {
                    check2 = pthread_create(&thread2, NULL, func_ptr_insert,(void *) &temp_var); 
                    if(check2 != 0) printf("error : thread2 \n");
                    flag = 1;
                    thread_id = 2;
                }
				break;
			}

			case 2:
			{
                //Dequeue element from queue 
				printf("->Removed from the queue\n");
                if(flag == 1)
                {
                    check3 = pthread_create(&thread3, NULL, func_ptr_delete,(void *) &temp_var);
                    if(check3 != 0) printf("error : thread3 \n"); 
                    flag = 2;
                    thread_id = 3;   
                }
                else if(flag == 2)
                {
                    check4 = pthread_create(&thread4, NULL, func_ptr_delete,(void *) &temp_var);
                    if(check4 != 0) printf("error : thread4 \n");
                    flag = 1;
                    thread_id = 4;
                }
				break;
			}

			case 3:
			{
                //Display the current elements present in Queue
				disp();
				break;
			}

			default :
			{
				printf("->Inavlid input \n");
				break;
			}
		}

        //Switch case to select appropriate Thread to join
        switch(thread_id)
        {
            case 1 :
            {
                pthread_join(thread1,NULL);
                break;
            }
            case 2 :
            {
                pthread_join(thread2,NULL);
                break;
            }
            case 3 :
            {
                pthread_join(thread3,NULL);
                break;
            }
            case 4 :
            {
                pthread_join(thread4,NULL);
                break;
            }
            default : break;
        }

        printf("->Enter 1 to insert \n");
        printf("->Enter 2 to delete \n");
        printf("->Enter 3 to display \n");
        printf("->Enter 4 to exit \n");

	}
	printf("->Program exited !\n");

    //Destroy the initialised Mutex
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    //Terminate all created Threads
    pthread_exit(NULL);
    return 0;
}
