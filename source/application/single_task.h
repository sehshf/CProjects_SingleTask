/*
 * single_task.h
 *
 *  Created on: 23/08/2016
 *      Author: ses
 */

#ifndef _SINGLE_TASK_H_
#define _SINGLE_TASK_H_

/*
 * **************************************************
 * SYSTEM INCLUDE FILES								*
 * **************************************************
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "common.h"

/*
 * **************************************************
 * DEFINITIONS										*
 * **************************************************
 */



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
extern struct timespec period;

/*
 * **************************************************
 * PROTOTYPES										*
 * **************************************************
 */
void SingleTaskInit( void);

void SingleTaskStep(void);


#endif // _SINGLE_TASK_H_

// EOF: single_task.h

