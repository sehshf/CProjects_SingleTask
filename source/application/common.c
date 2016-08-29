/*
 * common.c
 *
 *  Created on: 23/08/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "common.h"


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
*      SINWAVE()
*      Create sinusoidal wave signal.
*
*  Inputs:
*      *sinObj    : Pointer to the sin wave object
*      *tiClick   : Pointer to the simulation clock tick
*      sampleTime : Sampling period
*
*  Outputs:
*      y : Return the sin value.
*
*  Author: Ehsan Shafiei
*  		   Aug 2016
*  -------------------------------------------------------  *
*/
real64_T SinWave(sinWave_T *sinObj, timing_T *tiClock, real32_T sampleTime)
{
	real64_T y, arg;

	arg = sinObj->freq * ((tiClock->clockTickL0 + tiClock->clockTickH0 * MAX_UINT32) * sampleTime) + sinObj->phase;
	y   = sinObj->amp * sin(arg) + sinObj->bias;

	return y;

} // END: SinWAVE()


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





















