#ifndef TYPES_H_
#define TYPES_H_

#include <stdio.h>

#include "trace.h"

#define PTR_SIZE		(sizeof(void*))
#define INT_SIZE		(sizeof(int))

#define UUL_COLUMN_SIZE 	20
#define LI_COLUMN_SIZE 		11


struct trace
{
	/* meta information */
	uint32_t global_time;
	uint32_t thread_time;
	pid_t tid;
	int stop_reason;
	int state;


	/* hpc data */
	uint64_t hw_interrupts;
	uint64_t page_faults;
	uint64_t rbc_up;

	/* register values */
	struct user_regs_struct recorded_regs;
};


struct context {
	pid_t rec_tid; /* thread id recording thread */

	struct trace trace;
	struct hpc_context* hpc;

	/* recorder */
	int exec_state;
	int event;
	int allow_ctx_switch;


	/* shared */
	FILE* inst_dump;
	pid_t child_tid;
	int child_mem_fd;
	int pending_sig;
	int status;


};


#endif /* TYPES_H_ */
