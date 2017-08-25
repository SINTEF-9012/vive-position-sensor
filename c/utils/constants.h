//
//  constants.h
//
//  Created by Morten Kals on 12/05/2017.
//
//
//  File containing all constants used in project.
//
//  Units of time:      microseconds (10^-6 seconds)
//  Units of distance:  meters

#ifndef constants_h
#define constants_h

#include <WProgram.h>


extern bool STOP;

extern bool DEBUG;
extern bool VERBOSE;

#define CALIBRATION_SQUARE_SIDE_LENGTH 0.5
#define NUMBER_OF_POINTS_FOR_CALIBRATION 4

#define MIN_BASE_STATION_DISTANCE_FROM_ORIGIN 1.0
#define MAX_BASE_STATION_DISTANCE_FROM_ORIGIN 1000.0


// Calibration constants
#define CALIBRATION_BUTTON 8
#define MIN_ANGLE -PI/4
#define MAX_ANGLE PI/4
#define POINT_COUNT_PER_AXIS 10
#define POINTS_FOR_CALIBRATION 100
#define POINTS_PER_CALIBRATION_DATA 10

// Signal processing
#define US_TO_CLOCK(us) ((us)*72/2)

#define PERIOD 300000           // US_TO_CLOCK(1000000/120)
#define PERIODS_PER_CLOCK 3579  // 0x100000000/(PERIOD*4) truncated

// #define ANGLE_DEVIATION_SLOPE -0.00455

// Pulses
#define MIN_PULSE_SEPARATION US_TO_CLOCK(100)


// Packages
#define STORED_TIME_STEPS 5 // encoding L1, L2, possible double-detection of L3 and next L1

                                             // Theoretical values
#define L12_SEPARATION_MIN US_TO_CLOCK(350)  // 400
#define L12_SEPARATION_MAX US_TO_CLOCK(450)  // 400
#define L13_SEPARATION_MIN US_TO_CLOCK(1100) // 1222
#define L13_SEPARATION_MAX US_TO_CLOCK(7000) // 6777

#define L12_DURATION_MIN US_TO_CLOCK(50)     // 65
#define L12_DURATION_MAX US_TO_CLOCK(280)    // 135

#define MIN_PACKAGE_SEPARATION US_TO_CLOCK(8000) // 8333, used in package detection
#define MAX_PACKAGE_SEPARATION US_TO_CLOCK(8500)  // used in error-reporting


// Singals
#define CALIBRATION_SAMPLES 6                   // number of consecutive correct cycles required to be detected for calibration to be sucessfull
#define RECALIBRATE_SAMPLES 2                   // number of consecutive start-times outside the expected range to recalibrate
#define STORED_STEPS 22                         // nubmer of elements in array used to determine casification of pulses
#define PULSE_WIDTH_SEPARATION US_TO_CLOCK(7)   // spacing between pulse-legths in calibration signal

#define TIME_DRIFT_CORRECTOIN_THRESHOLD 0.1
#define TIME_DRIFT_CORRECTOIN_CONSTANT 50

#define MAX_VALID_ANGLE_DIFFERENCE 0.2          // (rad) any change in angle larger than this will need two consecutive readings for confirmation


#define MAX_UINT32  0xFFFFFFFF
#define HALF_UINT32 0x80000000

// Other

#define LARGEST_ANGLE_DEVIATION_FOR_SINGLE_MEASURNMENT 0.0015 // (rad) any two angles further apart than this when collecting calibration points causes fail
#define CALIBRATION_POINT_COLLECTION_COUNT 20

#define NO_PACKAGES_TO_ERROR_DISPLAY_DURATION 150 // milliseconds
#define MAX_LINE_SEPARATION 0.20                  // distance separating the closest points on the computed lines. Value above this triggers error.
#define MAX_POINT_1_DEVIATION 0.01                // point 1 need to be within this distance from theoretical location in order for calibration to be considered valid.
#define MAX_POINT_4_DEVIATION 0.10                // point 4 need to be within this distance from theoretical location in order for calibration to be considered valid.
#define MAX_CALIBRATION_POINT_DEVIATION 0.02      // for testing calibration on known points

union udouble {
	double d[12];
	uint8_t b[96];
};


// Calibration

#define NUMBER_OF_POINTS_FOR_CALIBRATION 4
#define CALIBRATION_SQUARE_SIDE_LENGTH 0.5
#endif /* constants_h */


/*
 *  Pulse lengths:
 *  < 60 us => Laser Sweep
 *
 *  Length (us) | Skip | Data | Axis
 *  ---------------------------------
 *   60 -  71   |   0  |   0  |   0
 *   71 -  82   |   0  |   0  |   1
 *   82 -  93   |   0  |   1  |   0
 *   93 - 103   |   0  |   1  |   1
 *  103 - 113   |   1  |   0  |   0
 *  113 - 123   |   1  |   0  |   1
 *  123 - 134   |   1  |   1  |   0
 *  134 - 144   |   1  |   1  |   1
 *
 *  For more info, see:
 *  https://github.com/nairol/LighthouseRedox/blob/master/docs/Light%20Emissions.md
 *  https://github.com/SINTEF-9012/HiOA-drone-project-2017/blob/master/Tracking/Vive/docs/LighthousePulses.md
 */
