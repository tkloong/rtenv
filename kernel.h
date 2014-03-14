#ifndef KERNEL_H
#define KERNEL_H

#define MAX_CMDNAME 19
#define MAX_ARGC 19
#define MAX_CMDHELP 1023
#define HISTORY_COUNT 20
#define CMDBUF_SIZE 100
#define MAX_ENVCOUNT 30
#define MAX_ENVNAME 15
#define MAX_ENVVALUE 127
#define STACK_SIZE 512 /* Size of task stacks in words */
#define TASK_LIMIT 8  /* Max number of tasks we can handle */
#define PIPE_BUF   64 /* Size of largest atomic pipe message */
#define PATH_MAX   32 /* Longest absolute path */
#define PIPE_LIMIT (TASK_LIMIT * 2)

#define PATHSERVER_FD (TASK_LIMIT + 3) 
	/* File descriptor of pipe to pathserver */

#define PRIORITY_DEFAULT 20
#define PRIORITY_LIMIT (PRIORITY_DEFAULT * 2 - 1)

#define TASK_READY      0
#define TASK_WAIT_READ  1
#define TASK_WAIT_WRITE 2
#define TASK_WAIT_INTR  3
#define TASK_WAIT_TIME  4

#define S_IFIFO 1
#define S_IMSGQ 2

#define O_CREAT 4

/* Enumeration for command types. */
typedef enum {
	CMD_ECHO = 0,
	CMD_EXPORT,
	CMD_HELP,
	CMD_HISTORY,
	CMD_MAN,
	CMD_PS,
	CMD_GREET,
	CMD_COUNT
} CMD_TYPE;

/* Structure for environment variables. */
typedef struct {
	char name[MAX_ENVNAME + 1];
	char value[MAX_ENVVALUE + 1];
} evar_entry;

#endif
