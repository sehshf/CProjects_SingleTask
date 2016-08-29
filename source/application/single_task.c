/*
 * SingleTask.c
 *
 *  Created on: 23/08/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "single_task.h"


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
struct timespec period = { 0U, 10000000U };


/*
 * **************************************************
 * FILE SCOPE VARIABLES (static)					*
 * **************************************************
 */
sinWave_T sinObj;
timing_T  tiClock;
real32_T  sampleTime;


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
*      SINGLETASKINIT()
*      Initialize the single task.
*
*  Inputs:
*
*  Outputs:
*
*  Author: Ehsan Shafiei
*  		   Aug 2016
*  -------------------------------------------------------  *
*/
void SingleTaskInit(void)
{
	sinObj.amp   = 1.0;
	sinObj.bias  = 0.0;
	sinObj.freq  = 2.5;
	sinObj.phase = -M_PI / 8;

	tiClock.clockTickL0 = 0ul;
	tiClock.clockTickH0 = 0ul;

	period.tv_sec  = 1U; //0U;
	period.tv_nsec = 0U; //10000000U;

	sampleTime = period.tv_sec + period.tv_nsec / 1000 / 1000 / 1000;
} // END: SingleTaskInit()

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      SINGLETASKSTEP()
*      Execute the next step of the single task.
*
*  Inputs:
*
*  Outputs:
*
*  Author:
*
*  -------------------------------------------------------  *
*/
void SingleTaskStep(void)
{
	static real64_T sinVal, sinValOld = 0;

	// Sin wave generator
	sinVal = SinWave(&sinObj, &tiClock, sampleTime);

	// Detect rise positive
	if (sinVal > 0 && sinValOld <= 0)
		printf("sinVal = %lf\n", sinVal);

	sinValOld = sinVal;

	// Update absolute time for base rate
	/* The "clockTick0" counts the number of times the code of this task has
	* been executed. The resolution of this integer timer is 0.005, which is the step size
	* of the task. Size of "clockTick0" ensures timer will not overflow during the
	* application lifespan selected.
	* Timer of this task consists of two 32 bit unsigned integers.
	* The two integers represent the low bits Timing.clockTick0 and the high bits
	* Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
	*/
	tiClock.clockTickL0++;
	if (!tiClock.clockTickL0)
		tiClock.clockTickH0++;
} // END: SingleTaskStep()


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
