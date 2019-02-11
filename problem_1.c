/*--------------------------------------------------------------------------
File: problem_1.c

Description:  This program creates multiple levels of processes culminating at
12 total processes across 4 levels.
LEVEL 0: 1 Process
LEVEL 1: 4 Processes
LEVEL 2: 5 Processes
LEVEL 3: 2 Processes

At each level, the process should retain the following information:
1) It's process ID
2) What level the process resides in.
3) "Who" it's ancestoral processes are.

Visualize the process tree created by the program by drawing it with correct
process ID's.
--------------------------------------------------------------------------*/
include <stdio.h>
include <stdlib.h>
include <sys/types.h>
include <signal.h>

//Should all happen within the main method.

int main(int argc, char **argv){
  int pid, level, ppid, tpid;
  char pidStr[32], ppidStr[32], name[10];
  name = "[0,1]";

//Checks to make sure arguments from the command line are correct.
  if(argc != 1){
    printf("Usage: problem_1\n Opens the program.\n Check the system Tree.");
    exit(-1);
  }
// 1 at level 0 and 1 at level 1.
  pid = fork();

  if(pid == 0){//Child 1 at lvl1 [1,1] (create [2,1], [2,2])
    level = 1;
    name = "[1,1]";
    ppid = getppid();
    tpid = getpid();
    sprintf(pidStr, "%d", tpid);
    sprintf(ppidStr, "%d", ppid);
    //PRINT???

    //1lv0, 1lvl1, 1lvl2
    if(fork() == 0){//Child 1 at lvl2 [2,1] (No task)
      level = 2;
      name = "[2,1]";
      ppid = getppid();
      tpid = getpid();
      sprintf(pidStr, "%d", tpid);
      sprintf(ppidStr, "%d", ppid);
      //PRINT???

    } else{//Parent at Level 1 [1,1] (create [2,2])
      if(fork() == 0){ //Child 2 at lvl2 [2,2] (No task)
        level = 2;
        name = "[2,2]";
        ppid = getppid();
        tpid = getpid();
        sprintf(pidStr, "%d", tpid);
        sprintf(ppidStr, "%d", ppid);
        //PRINT???
      }
      //[1,1] has finished its tasks so it is done.
      //Tree Update: 1lvl0, 2lvl2, 0lvl3
    }

  } else{//Parent at lvl 0 [0,1] (create [1,2])
    //1lv0, 1lvl1, 2lvl2, 0lvl3
    pid = fork();
    if(pid == 0){//Child at level 1 [1,2] (creates [2,3])
      level = 1;
      name = "[1,2]";
      ppid = getppid();
      tpid = getpid();
      sprintf(pidStr, "%d", tpid);
      sprintf(ppidStr, "%d", ppid);
      //PRINT???

      if(fork() == 0){//Child at level 2 [2,3] (create [3,1])
        level = 2;
        name = "[2,3]";
        ppid = getppid();
        tpid = getpid();
        sprintf(pidStr, "%d", tpid);
        sprintf(ppidStr, "%d", ppid);
        //PRINT???
        if(fork() == 0){//Child at [3,1] (No Task)
          level = 3;
          name = "[3,1]";
          ppid = getppid();
          tpid = getpid();
          sprintf(pidStr, "%d", tpid);
          sprintf(ppidStr, "%d", ppid);
          //PRINT???
        }
        //[3,1] has no task.
      }  //[1,2] has no other tasks
        //Tree Update: 1lvl0, 2lvl1, 3lvl2, 1lvl3
    } else{//Parent at lvl0 [0,1] (create [1,3])
      if(fork() == 0){//Child at level 1 [1,3]
        level = 1;
        name = "[1,3]";
        ppid = getppid();
        tpid = getpid();
        sprintf(pidStr, "%d", tpid);
        sprintf(ppidStr, "%d", ppid);
        //PRINT???

        if(fork() == 0){//Child at level 2 [2,4] (create [3,2])
          level = 2;
          name = "[2,4]";
          ppid = getppid();
          tpid = getpid();
          sprintf(pidStr, "%d", tpid);
          sprintf(ppidStr, "%d", ppid);
          //PRINT???
          if(fork() == 0){//Child at [3,2] (No Task)
            level = 3;
            name = "[3,2]";
            ppid = getppid();
            tpid = getpid();
            sprintf(pidStr, "%d", tpid);
            sprintf(ppidStr, "%d", ppid);
            //PRINT???
          }//No task for [3,2]
        } //No outside task for [2,4]

      } else{//Parent [0,1] (create [1,4])
        if(fork() == 0){//Child at level 1 [1,4] (create [2,5])
          level = 1;
          name = "[1,4]";
          ppid = getppid();
          tpid = getpid();
          sprintf(pidStr, "%d", tpid);
          sprintf(ppidStr, "%d", ppid);
          //PRINT???
          if(fork == 0){//Child at level 2 [2,5] (No Task)
            level = 2;
            name = "[2,5]";
            ppid = getppid();
            tpid = getpid();
            sprintf(pidStr, "%d", tpid);
            sprintf(ppidStr, "%d", ppid);
            //PRINT???
          }
        }
      }

    }


  }



return 0;
}
