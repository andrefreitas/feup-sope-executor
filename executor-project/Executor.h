#ifndef EXECUTOR_H
#define	EXECUTOR_H
#include "Process.h"
#include "Activity.h"
/**
 * Executor.h - A struct for describing a program that allows a user to launch, 
 * terminate and get information about commands that he gave.
 */
struct Executor {
    int runningProcesses;
    int terminatedProcesses;
    char* logFileName;
    char* errorFileName;
    struct Process** processes;
    int processLastIndex;
    struct Activity** activities;
    int activityLastIndex;
};
/**
 * Create a new executor
 * @param e the executor pointer
 * @param logFileName the name of the log file
 * @param errorFileName the name of the error file
 */
void executor_create(struct Executor *e,char* logFileName, char* errorFileName);

// Main cycle functions
void executor_run(struct Executor *e);
void executor_printHeader(struct Executor *e);
char executor_receiveOrder(struct Executor *e);

// User orders
void executor_launch(struct Executor *e);
void executor_inform(struct Executor *e);
void executor_terminate(struct Executor *e);
void executor_exit(struct Executor *e);

// Management of processes and activities
void executor_addProcess(struct Executor *e,struct Process *p);
void executor_addActivity(struct Executor *e,struct Activity *a);

// Other methods
void executor_printlogs(struct Executor *e);

#endif	/* EXECUTOR_H */

