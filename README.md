# ThingML Implementation of HTC Vive Positioning System *VPS*
This prototype has been developed using [ThingML](https://github.com/TelluIoT/ThingML) which is a code-generation language built around state-machines and asynchronous communication-messages.

Inspired by [ashtuchkin/vive-diy-position-sensor](https://github.com/ashtuchkin/vive-diy-position-sensor) but re-implemented in ThingML and including full on-board calibration and setup.


## &#x1F539; Advertiser
This project requires the following repositories:
- The Teensy Core from [cores](https://github.com/PaulStoffregen/cores) for general functionality.
- The Adafruit NeoPixel from [NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) for colored status-LED.

To clone project with these dependencies you must enable the recursive flag in git
```
git clone --recursive https://github.com/SINTEF-9012/vive-position-sensor.git
```

If you already have these repositories on your computer you can clone normally (without --recursive) and edit the Configuration file to set the path in your computer.


## &#x1F539; Architecture
The functionality is split into 3 levels:
- The backbone represents the controller of the software - all messages passing form one part of functionality to another is handled by the backbone.
- The applicative models are abstractions for the backbone. These models transform raw data and compute required elements like position.
- The accessories level handles implementation-details for inputs and outputs. This includes sensors data, persistent storage in EEPROM and LED status indicators.


## &#x1F539; Operation
The Teensy can be put into different operating modes - "Run" and "Calibrate". On launch, the system will try to load a calibration from EEPROM.
 - If it succeeds, it will go directly to "Run" where it computes and outputs position.
 - If if fails, it will go to to "Calibration" where the base-station are to be computed.

- Calibrate by placing the base-station at the corners of a square that you use to define your coordinate-system and pressing the button to record a point:
    1. Point at origin (0, 0, 0)
    2. Point at 0.5 meters distance on the positive y-axis (0, 0.5, 0)
    3. Point at 0.5 meters distance on the positive x-axis (0.5, 0, 0)
    4. Point at 0.5 meters distance on the x-axis and y-axis (0.5, 0.5, 0)
- A green light indicates the point has been recorded, a red light indicates the point must be recorded again.
- When all 4 points have been recorded the LED will:
    - flash dark green if calibration is successful.
        - The calibration will be stored to EEPROM automatically before the system transfers to the running mode.
    - red if the calibration failed and must be redone.
- Long-pressing the button at any time will start a new calibration (this can also be used to restart the calibration if an incorrect data-point has been collected).


### &#x1F539; Debugging and Verbose mode
There is debugging-functionality in place using serial-prints to communicate computed values, states and alert about events. The verbose-mode can be used for outputting data in a format that can be read by [Parsing.py](docs/Vive%20Validation%20Resources/Parsing.py) in order to produce an array of Data-classes that contain all the information and that can be used to diagnose the operation of the system. The file [Visualizing.py](docs/Vive%20Validation%20Resources/Visualizing.py) has multiple methods to quickly produce useful output (see [Validation](docs/Vive%20Validation.ipynb) for details).
- Use a jumper-cable to short pins 11 and 12 on startup to enter "debug" mode and get serial-prints.
- Double press the button to toggle verbose printing.


## &#x1F539; States

| ID  | Color  |        State         |
| --- | ------ | -------------------- |
| 1   | ORANGE | Load_Calibration     |
| 2   | YELLOW | Calibration          |
| 3   | ORANGE | Validate_Calibration |
| 4   | GREEN  | Runner               |


## &#x1F539; Status Messages

| ID  |   Color    | Priority |                 Information                  | Sentiment |                       Required action                       |
| --- | ---------- | -------- | -------------------------------------------- | --------- | ----------------------------------------------------------- |
| 0   | RED        | 1        | Computed lines do not intersect              | Severe    | Recalibrate                                                 |
| 1   | BLUE       | 0        | One or more angles not received              | Fatal     | Remove obstruction/reduce angles                            |
| 2   | LIME       | 1        | Recording data-point for calibration         | Good      | Wait with sensor stationary                                 |
| 3   | LAVENDER   | -1       | Reflection present                           | Handled   | None                                                        |
| 4   | DARK_GREEN | 4        | Base station calibration successful          | Good      | None                                                        |
| 5   | DARK_GREEN | 3        | Loading calibration from EEPROM succeeded    | Good      | None                                                        |
| 6   | DARK_RED   | 3        | Loading calibration from EEPROM failed       | Not ready | Perform manual calibration                                  |
| 7   | DARK_RED   | 4        | Calibration failed                           | Retry     | Recalibrate                                                 |
| 8   | GREEN      | 2        | Calibration point collected                  | Good      | Proceed with calibration on next point                      |
| 9   | RED        | 2        | Calibration point not collected              | Retry     | Retry at this point                                         |
| 10  | YELLOW     | 0        | Unexpected package arrival time              | Handled   | None                                                        |
| 11  | BROWN      | 1        | Consistently unexpected package arrival time | Severe    | Wait for automatic recalibration of package arrival times   |
| 12  | CIAN       | 0        | Calibrating package arrival times            | Not ready | Wait and ensure good reception                              |
| 13  | DARK_GREEN | 0        | Package arrival times calibrated             | Good      | System is operating normally                                |
| 14  | PURPLE     | -1       | No signals received                          | Fatal     | Turn on/move closer to base stations/check sensor           |
| 15  | GREY       | 0        | Signal type not recognized (12 not done)     | Severe    | Move sensor away from base stations, check for interference |
| -   | -          | -        | LED stops flashing - from loop or crash      | Fatal     | Restart Teensy, debug if persistent                         |

### In Summary
- READ: recalibrate
- GREEN: things are working well
- BLUE/PURPLE: remove obstructions and ensure sensor is in operating-volume
- others: check above table and serial-print



## &#x1F539; Verbose Print Format
| Designator |                                   Trigger-event                                   |            Information            |
| ---------- | --------------------------------------------------------------------------------- | --------------------------------- |
| A          | in PulseReader every time a falling edge is detected                              | start time (microseconds)         |
|            |                                                                                   | duration (microseconds)           |
|            |                                                                                   | rapid spike down? (1 if detected) |
| B          | in PulseReader every time a package is detected                                   | start time (microseconds)         |
|            |                                                                                   | L1 duration (microseconds)        |
|            |                                                                                   | L2 duration (microseconds)        |
|            |                                                                                   | pulse signal (microseconds)       |
|            |                                                                                   | identified steps (count)          |
|            |                                                                                   | time since last (microseconds)    |
| C          | in AngleReader for every iteration                                                | L1 type ([0,3])                   |
|            |                                                                                   | L2 type ([0,3])                   |
|            |                                                                                   | signal type ([0,4])               |
|            |                                                                                   | calibration step (count)          |
| D          | in AngleReader for every iteration after pulse-calibration is accomplished        | signal type ([0,4])               |
|            |                                                                                   | signal angle (rad)                |
| E          | in AngleReader for every time angle BH is collected                               | angle BH  (rad)                   |
|            |                                                                                   | angle BV (rad)                    |
|            |                                                                                   | angle CH (rad)                    |
|            |                                                                                   | angle CV (rad)                    |
| F          | in Calibration when average of angles received for calibrating have been computed | angle BH  (rad)                   |
|            |                                                                                   | angle BV (rad)                    |
|            |                                                                                   | angle CH (rad)                    |
|            |                                                                                   | angle CV (rad)                    |
| G          | in Calibration to indicate difference (largest - smallest) of averaging in F      | max BH - min BH                   |
|            |                                                                                   | max BV - min BV                   |
|            |                                                                                   | max CH - min CH                   |
|            |                                                                                   | max CV - min CV                   |
| H          | in all parts of system, sends events in system with number ID                     | status ID                         |
| I          | in Backbone, alerts of all main state-changes                                     | state ID                          |
| J          | in Runner when position has been computed with distance between lines             | x-coordinate                      |
|            |                                                                                   | y-coordinate                      |
|            |                                                                                   | z-coordinate                      |
|            |                                                                                   | distance between lines            |
| K          | in Calibration when base-station positions have been computed                     | b: x-coordinate                   |
|            |                                                                                   | b: y-coordinate                   |
|            |                                                                                   | b: z-coordinate                   |
|            |                                                                                   | b: x-rotation                     |
|            |                                                                                   | b: y-rotation                     |
|            |                                                                                   | b: z-rotation                     |
|            |                                                                                   | c: x-coordinate                   |
|            |                                                                                   | c: y-coordinate                   |
|            |                                                                                   | c: z-coordinate                   |
|            |                                                                                   | c: x-rotation                     |
|            |                                                                                   | c: y-rotation                     |
|            |                                                                                   | c: z-rotation                     |
|            |                                                                                   | error in position of point 4      |
| L          | in Calibration when error in position of point 4 is too large (calibration fails) | error in position of point 4      |
| N          | new data-collection started                                                       | duration for data-collection      |
