/*--------------------------------------------------------------------------
File: problem_2.c

Description: Use shared memory to implement the Student/Teacher problem
described in the README.md
--------------------------------------------------------------------------*/

include <stdio.h>
include <stdlib.h>
include <sys/types.h>
include <signal.h>
include <sys/ipc.h>
include <sys/mman.h>

void* create_shared_mem(size_t size){

  int protection = PROT_READ | PROT_WRITE;

  int visibility = MAP_ANONYMOUS | MAP_SHARED;

  return mmap(NULL, size, protection, visibility, 0, 0);
}

//THIS IS A TEST TO MAKE SURE WE HAVE COMMUNICATION BETWEEN THE PROCESSES
int main(){
  char* parent_message = "hello";
  char* child_message = "goodbye";

  void* shmem = create_shared_mem(128);
  memcpy(shmem, parent_message, sizeof(parent_message));

  int pid = fork();

  if(pid == 0){//child
    printf("Child Read: %s\n", shmem);
    memcpy(shmem, child_message, sizeof(child_message));
    printf("Child Wrote: %s\n", shmem);
  } else{//parent
    printf("Parent Read: %s\n", shmem);
    sleep(1);
    printf("After 1s, Parent Read: %s\n", shmem);
  }
}
