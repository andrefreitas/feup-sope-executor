#ifndef EXECUTOR_H
#define	EXECUTOR_H
#include "Process.h"
#include "signal.h"
struct Executor *currentExecutor;
/**
 * Executor.h - A struct for describing a program that allows a user to launch, 
 * terminate and get information about commands that he gave.
 * Authors: André Freitas and Vasco Gonçalves
 * Emails: p.andrefreitas@gmail.com, vascofg@gmail.com
 */
struct Executor {
    int runningProcesses;
    int terminatedProcesses;
    struct Process** processes;
    int processLastIndex;
    char* logFileName;
    char* errorFileName;
    pid_t logWindowPID;
    pid_t errorWindowPID;
    int errorDescriptor;
    
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

// Management of processes
void executor_addProcess(struct Executor *e,struct Process *p);
void executor_printProcesses(struct Executor *e);
struct Process *  executor_getProcessbyPID(struct Executor *e,int pid);
void executor_killAll(struct Executor *e);
void executor_printActiveProcesses(struct Executor *e);
void executor_printActiveProcessesWithTimes(struct Executor *e);

//Sigchild handler
void executor_sigchildHandler(int sig);

// Log handling
void executor_addLog(struct Executor *e,char *log);
void executor_initLogWindow(struct Executor *e);
void executor_printLogFile(struct Executor *e);

// Error handling
void executor_initErrorWindow(struct Executor *e);
void executor_printError(struct Executor *e, char *error);

#endif	/* EXECUTOR_H */

