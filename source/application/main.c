/*
 * main.c
 *
 *  Created on: 22/08/2016
 *      Author: ses
 */

/*
 * **************************************************
 * SYSTEM INCLUDE FILES								*
 * **************************************************
 */
#include <stdio.h>
#include <sys/mman.h>

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "portable.h"
#include "single_task.h"
#include "tasks.h"

/* Error checking */
//#define STRINGIZE(num)                 #num
//#define POS(line)                      __FILE__ ":" STRINGIZE(line)
//#define CHECK0(expr)                   do { int __err = (expr); if (__err) { fprintf(stderr, "Error: %s returned '%s' at " POS(__LINE__) "\n", #expr, strerror(__err)); exit(1); } } while (0);
//#define CHECKE(expr)                   do { if ((expr) == -1) { perror(#expr " at " POS(__LINE__)); exit(1); } } while (0);






int main()
{
	pthread_t baseRateThread;

	if (mlockall(MCL_CURRENT | MCL_FUTURE) < 0)		// *** is that necessary? Why?
	{
		fprintf(stderr, "Error: mlockall failed - cannot lock application in memory\n");
		return FAILED;
	}
	printf("memory locked successfully\n");
	sleep(1);

	// Initialize the task
	SingleTaskInit();
	printf("Task initialized successfully\n");
	sleep(1);

	CreateTask(&baseRateThread, (int16_T) MAX_PRIO, baseRate, NULL);

	FinishTask(baseRateThread);

	return PASSED;

} // END: main()

// EOF: main.c
