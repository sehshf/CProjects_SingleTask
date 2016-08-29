/*
 * tasks.h
 *
 *  Created on: 27/08/2016
 *      Author: ses
 */

#ifndef _TASKS_H_
#define _TASKS_H_

/*
 * **************************************************
 * SYSTEM INCLUDE FILES								*
 * **************************************************
 */
#include <pthread.h>
#include <time.h>

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "portable.h"
#include "single_task.h"	// required for SingleTaskStep()

/*
 * **************************************************
 * DEFINITIONS										*
 * **************************************************
 */
// Maximal priority used by base rate thread.
#define MAX_PRIO	(sched_get_priority_min(SCHED_FIFO) + 1)


/*
 * **************************************************
 * MACROS											*
 * **************************************************
 */



/*
 * **************************************************
 * TYPE DEFINITIONS									*
 * **************************************************
 */



/*
 * **************************************************
 * External VARIABLES       						*
 * **************************************************
 */



/*
 * **************************************************
 * PROTOTYPES										*
 * **************************************************
 */
void * baseRate();

pf_T   CreateTask(pthread_t *thread,
				  int16_T prio,
				  void *(*StartRoutine) (void *),
				  void *threadArg
				  );

void   FinishTask(pthread_t thread);


#endif // _TASKS_H_

// EOF: tasks.h
