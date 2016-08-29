/*
 * tasks.c
 *
 *  Created on: 27/08/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "tasks.h"


/*
 * **************************************************
 * LOCAL DECLARATIONS								*
 * **************************************************
 */



/*
 * **************************************************
 * GLOBAL VARIABLES (extern)						*
 * **************************************************
 */



/*
 * **************************************************
 * FILE SCOPE VARIABLES (static)					*
 * **************************************************
 */



/*
 * **************************************************
 * LOCAL PROTOTYPES									*
 * **************************************************
 */



/*
 * **************************************************
 * PUBLIC FUNCTIONS									*
 * **************************************************
 */

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      BASERATE()
*      The base (fastest) task period.
*
*  Inputs:
*
*  Outputs:
*
*
*  Author:
*
*  -------------------------------------------------------  *
*/
void * baseRate()
{

	struct timespec now, next;

	clock_gettime(CLOCK_MONOTONIC, &next);

	// Main loop, running until all the threads are terminated
	while (1)
	{
		// Execute task step ********************************** get it as an input arg
		SingleTaskStep();

		do
		{
			next.tv_sec += period.tv_sec;
			next.tv_nsec += period.tv_nsec;
			if (next.tv_nsec >= 1000000000)
			{
				next.tv_sec++;
				next.tv_nsec -= 1000000000;
			}

			clock_gettime(CLOCK_MONOTONIC, &now);

			if (now.tv_sec > next.tv_sec ||	(now.tv_sec == next.tv_sec && now.tv_nsec > next.tv_nsec))
			{
				uint32_T usec = (now.tv_sec - next.tv_sec) * 1000000 + (now.tv_nsec - next.tv_nsec) / 1000;
				fprintf(stderr, "Base rate (0.01s) overrun by %lu us\n", usec);
				next = now;
				continue;
			}
		} while (0);

		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, NULL);
	}

} // END: BaseRate()

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      CreateTask()
*      Create a real-time task.
*
*  Inputs:
*      *thread 		: Pointer to the thread ID of the new task
*      prio	   		: Task priority
*      StartRoutine : Task function
*      *threadArg   : Pointer to the task argument
*
*  Outputs:
*	   Return 0 when succeeded.
*
*  Author: Ehsan Shafiei
*  		   Aug 2016
*  -------------------------------------------------------  *
*/
pf_T CreateTask(pthread_t *thread,
				int16_T prio,
				void *(*StartRoutine) (void *),
				void *threadArg
				)
{
	pthread_attr_t attr;
	struct sched_param schedParam;

	// Prepare task attributes
	if (pthread_attr_init(&attr) != 0)
	{
		fprintf(stderr, "pthread_attr_init failed\n");
		return FAILED;
	}

	if (pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED) != 0)
	{
		fprintf(stderr, "pthread_attr_setinheritsched failed\n");
		return FAILED;
	}

	if (pthread_attr_setschedpolicy(&attr, SCHED_FIFO) != 0)
	{
		fprintf(stderr, "pthread_attr_setschedpolicy SCHED_FIFO failed\n");
		return FAILED;
	}

	schedParam.sched_priority = prio;

	if (pthread_attr_setschedparam(&attr, &schedParam) != 0)
	{
		fprintf(stderr, "pthread_attr_setschedparam failed\n");
		return FAILED;
	}

	if (pthread_create(thread, &attr, StartRoutine, threadArg) != 0)
	{
		fprintf(stderr, "cannot start the real-time task\n");
		return FAILED;
	}
	pthread_attr_destroy(&attr);

	return PASSED;

} // END: CreateThread()

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      FINISHTASK()
*      Wait for threads to finish.
*
*  Outputs:
*
*
*  Author:
*
*  -------------------------------------------------------  *
*/
void FinishTask(pthread_t thread)
{
	// Wait for threads to finish
    pthread_join(thread, NULL);

} // END: FinishTask()


/*
 * **************************************************
 * LOCAL FUNCTIONS									*
 * **************************************************
 */
/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      PUBLICFUCTION()
*      What this function is doing.
*
*  Inputs:
*      x : Input
*
*  Outputs:
*      y : Return 0 when succeeded.
*
*  Author: Ehsan Shafiei
*  		   Aug 2016
*  -------------------------------------------------------  *
*/
//static type LocalFunction(type x)
//{
//    return y;
//} // END: LocalFunction()

// EOF: source_code_template.c
