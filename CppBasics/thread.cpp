/**
**Multithreading is a specialized form of multitasking and a multitasking is the feature that allows your
computer to run two or more programs concurrently
**In general, there are two types of multitasking: process-based and thread-based.
**Process-based multitasking handles the concurrent execution of programs. Thread-based multitasking
deals with the concurrent execution of pieces of the same program
**Creating Threads
The following routine is used to create a POSIX thread −
    #include <pthread.h>
        pthread_create (thread, attr, start_routine, arg)
        // Here, pthread_create creates a new thread and makes it executable.
                 /**
                 Parameter & Description
                   1 thread
                       An opaque, unique identifier for the new thread returned by the subroutine.
                   2  attr
                       An opaque attribute object that may be used to set thread attributes.
                       You can specify a thread attributes object, or NULL for the default values.
                   3  start_routine
                        The C++ routine that the thread will execute once it is created.
                   4  arg
                        A single argument that may be passed to start_routine. It must be passed by reference
                        as a pointer cast of type void. NULL may be used if no argument is to be passed.
**Terminating Threads
There is following routine which we use to terminate a POSIX thread −
    #include <pthread.h>
        pthread_exit (status)
**/
#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;

   for( i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}


/**
Passing Arguments to Threads
This example shows how to pass multiple arguments via a structure.
You can pass any data type in a thread callback because it points to
void as explained in the following example
**/
/**
#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data {
   int  thread_id;
   char *message;
};

void *PrintHello(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;

   cout << "Thread ID : " << my_data->thread_id ;
   cout << " Message : " << my_data->message << endl;

   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;

   for( i = 0; i < NUM_THREADS; i++ ) {
      cout <<"main() : creating thread, " << i << endl;
      td[i].thread_id = i;
      td[i].message = "This is message";
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);

      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
**/

/**
Joining and Detaching Threads
There are following two routines which we can use to join or detach threads −
                  pthread_join (threadid, status)
                  pthread_detach (threadid)
The pthread_join() subroutine blocks the calling thread until the specified threadid
thread terminates. When a thread is created, one of its attributes defines whether it is
joinable or detached. Only threads that are created as joinable can be joined. If a thread is created as detached, it can never be joined.
This example demonstrates how to wait for thread completions by using the Pthread join routine.
**/
/**
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

void *wait(void *t) {
   int i;
   long tid;

   tid = (long)t;

   sleep(1);
   cout << "Sleeping in thread " << endl;
   cout << "Thread with id : " << tid << "  ...exiting " << endl;
   pthread_exit(NULL);
}

int main () {
   int rc;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;

   // Initialize and set thread joinable
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for( i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, wait, (void *)i );

      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }

   // free attribute and wait for the other threads
   pthread_attr_destroy(&attr);
   for( i = 0; i < NUM_THREADS; i++ ) {
      rc = pthread_join(threads[i], &status);
      if (rc) {
         cout << "Error:unable to join," << rc << endl;
         exit(-1);
      }

      cout << "Main: completed thread id :" << i ;
      cout << "  exiting with status :" << status << endl;
   }

   cout << "Main: program exiting." << endl;
   pthread_exit(NULL);
}
**/
