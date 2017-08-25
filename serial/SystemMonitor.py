
# List available serial ports

import sys
import glob
import threading
import time

import serial
from Parsing import Data


import numpy as np               # NumPy (multidimensional arrays, linear algebra, ...)
import matplotlib as mpl         # Matplotlib (2D/3D plotting library)
#import matplotlib.pyplot as plt  # Matplotlib's pyplot: MATLAB-like syntax
from pylab import *              # Matplotlib's pylab interface
# from colour import Color



# def colourRange(n):
#     blue = Color('blue')
#     return list(blue.range_to(Color("green"),n))
#
# def plotCalibrationPulseWidths(data, legend):
#     colours = colourRange(len(data))
#     ion()
#
#     for d in data:
#         plt.hist(d.BL1, bins = 80, normed=False, color=colours.pop().hex_l)
#     plt.legend(legend)
#     plt.xlabel("Length of pulses (us)")
#     plt.ylabel("Count")
#     plt.title("Pulse Width Distribution for Calibration Pulses")
#     plt.show



def serial_ports():
    """List serial port names.
    raises EnvironmentError:
    On unsupported or unknown platforms
    returns:
    A list of the serial ports available on the system
    """
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result


collectData = False

def readSerialData():
    while True:
        if collectData:
            line = ser.readline().rstrip()  # read data from serial
            Data.readLine(line, data)


if __name__ == '__main__':
    myPorts = serial_ports()
    for i in range(len(myPorts)):
        print "port", i, ": ", myPorts[i]

    portNumber = int(raw_input("\nUser port-number: "))

    myPort = myPorts[portNumber] if (0 <= portNumber < len(myPorts)) else None
    print "Opening serial port ", myPort

    # Read from serial

    ser = serial.Serial(myPort, 115200)
    data = []

    serialThread = threading.Thread(target=readSerialData)
    serialThread.start()

    def getDuartionFromUser():
        global collectData
        collectData = False

        time.sleep(0.1)

        #if data:
        #    plotData(data)

        userEntry = raw_input("\nCapture for duration (zero for indefinate): ")
        try:
            duration = int(userEntry)
            if duration > 0:
                Data.readLine('N,' + str(duration) + ',', data)

                collectTimer = threading.Timer(duration, getDuartionFromUser)
                collectTimer.start()
                collectData = True

            elif duration == 0:
                Data.readLine('N,' + str(duration) + ',', data)
                collectData = True

                raw_input("\nPress enter to stop.")
                sys.exit()
        except ValueError:
            sys.exit()

    getDuartionFromUser()
