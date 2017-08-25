import numpy as np               # NumPy (multidimensional arrays, linear algebra, ...)
import matplotlib as mpl         # Matplotlib (2D/3D plotting library)
import matplotlib.pyplot as plt  # Matplotlib's pyplot: MATLAB-like syntax
from pylab import *              # Matplotlib's pylab interface

import math
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
from mpl_toolkits.mplot3d import Axes3D
import scipy.optimize as opt
from pandas import DataFrame
from tabletext import to_text
import pandas as pd
from colour import Color
from Parsing import Data

ion()                            # Turned on Matplotlib's interactive mode


def plotData(data):
    plotCalibrationPulseWidths(data)
    plt.show



# Graphing Helper Methods

anglesLabel = ['bh', 'bv', 'ch', 'cv', 'err']
pulseWidthLabel = ['j0', 'k0', 'j1', 'k1', 'j2', 'k2', 'j3', 'k3']

def average(d):
    return sum(d)/len(d)

def colourRange(n):
    blue = Color('blue')
    return list(blue.range_to(Color("green"),n))

def withUnit(val, unit):
    lab = []
    for n in val:
        lab.append(str(n) + ' ' + unit)
    return lab

def plotCalibrationPulseWidths(data):
    plt.figure()
    colours = colourRange(len(data))

    for d in data:
        plt.hist(d.BL1, bins = 80, normed=False, color=colours.pop().hex_l)
    plt.xlabel("Length of pulses (us)")
    plt.ylabel("Count")
    plt.title("Pulse Width Distribution for Calibration Pulses")


def plotSignalCount(data, xValues, xLabel, legend):
    a = np.array(signalBrakedown(data)).astype(float)
    for i in range(len(a)):
        a[i] = a[i] * 1000.0 / float(data[i].duration)

    width = float(np.max(xValues) - np.min(xValues)) / len(xValues) * 0.2

    f, ax1 = plt.subplots(1)
    bottom = np.zeros(len(a))

    for i in range(len(data)):
        ax1.bar(xValues[i], len(data[i].Bsignal)*1000.0/data[i].duration, width = width*0.5, color = "b")

    for i in range(len(a.T)):
        ax1.bar(xValues,
                a.T[i],
                label=legend[i],
                width=width,
                bottom=bottom,
                alpha = 0.8)
        bottom += a.T[i]

    plt.xlabel(xLabel)
    plt.ylabel("Frequency (Hz)")
    plt.legend(loc='upper left')
    plt.title("Number of Detected Packages per Second")



def color(i):
    if i == 0: return 'b'
    if i == 1: return 'g'
    if i == 2: return 'c'
    if i == 3: return 'm'
    return 'r'


def plotAngles(angles, signalType, startTimes):
    diff = len(startTimes) - len(angles)
    if abs(diff) >= 5:
        print 'error'
    if diff == -1:
        angles = angles[1:]
        signalType = signalType[1:]
    col = [color(i) for i in signalType]

    plt.scatter(startTimes[0:len(angles)], angles, c=col, marker='.', s=0.5)
    plt.xlabel("Clock-time (us)")
    plt.ylabel("Angle (rad)")
    plt.title("Angles Recieved")

    l1 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(0))
    l2 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(1))
    l3 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(2))
    l4 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(3))

    plt.legend((l1, l2, l3, l4), anglesLabel[0:4], numpoints=1, loc=1)


def plotSignalValue(data, xValues, xLabel):
    plt.figure()

    for i in range(len(data)):
        col = [color(j) for j in data[i].DsignalType]
        y = data[i].DsignalAngle
        x = np.ones_like(y)*xValues[i]
        plt.scatter(x, y, c=col, marker='.', s=0.5)

    plt.xlabel(xLabel)
    plt.ylabel("Angle (rad)")
    plt.title("Angles Recieved")

    l1 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(0))
    l2 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(1))
    l3 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(2))
    l4 = Line2D(range(1), range(1), color='white', marker='o', markerfacecolor=color(3))

    plt.legend((l1, l2, l3, l4), anglesLabel[0:4], numpoints=1, loc=1)



def pulseWidthClass(x, maxVal, minVal):
    return int((x-minVal+7)*7/(maxVal-minVal))

def plotPulseWidths(data, xData, xLabel, station = 'L1'):

    mean = []
    std = []

    for d in data:
        w = d.BL1 if station == 'L1' else d.BL2
        maxVal = max(w)
        minVal = min(w)
        c = [filter(lambda x: pulseWidthClass(x, maxVal, minVal) == i, w) for i in range(8)]
        mean.append([np.mean(c[i]) for i in range(len(c))])
        std.append([np.std(c[i]) for i in range(len(c))])

    for i in range(len(mean[0])):
        plt.errorbar(xData, np.array(mean)[:,i], np.array(std)[:,i], marker='.')

    plt.xlabel(xLabel)
    plt.ylabel("Mean Pulse Width (us)")
    plt.legend(pulseWidthLabel)
    plt.title("Mean Pulse Width Distribution")

    for i in range(len(data)):
        y = data[i].BL1 if station == 'L1' else data[i].BL2
        x = np.ones_like(y)*xData[i]
        plt.plot(x, y, ',', color='black')

def plotPulseWidthsForData(data, distanceL1, distanceL2 = 0):
    if distanceL2 == 0:
        distanceL2 = distanceL1
    plt.figure()
    plt.subplot(121)
    plotPulseWidths(data, distanceL1, "Distance from L1 (m)", 'L1')
    plt.subplot(122)
    plotPulseWidths(data, distanceL2, "Distance from L2 (m)", 'L2')


# Number of signals recieved from each angle/data-scorce

def signalBrakedown(data):
    ret = []
    for d in data:
        counts = []
        for i in range(0,5):
            counts.append(len(filter(lambda x: x == i, d.DsignalType)))
        ret.append(counts)
    return ret

# Dropped Pulse Analysis

def droppedPulseCount(startTime):
    try:
        durations = (startTime - np.roll(startTime, 1))[1:-1]
        count = len(startTime)
        errors = 0
        gaps = 0
        for d in durations:
            if not (8320 < d and d < 8350):
                err = int((d+100)/8333)-1
                if err > 0:
                    errors += err
                gaps += 1

        rate = int(float(errors)/(count+errors)*100) if not count == 0 else 100
        return (count, errors, rate, gaps)

    except:
        return (0,0,0,0)

def droppedPulseCountInList(data):
    vals = []
    for d in data:
        vals.append(droppedPulseCount(d.BstartTime))
    return np.array(vals)

def printDroppedPulseErrors(data):
    title = ("# collected points", "# lost points", "% error rate", "# signal gaps")
    body =  droppedPulseCountInList(data)
    text = np.vstack((title, body))
    print to_text(text)

# Compute standard deviation

def mean(numbers):
    return float(sum(numbers)) / max(len(numbers), 1)

def standardDeviation(numbers):
    average = mean(numbers)
    return sum((numbers - average)**2)**0.5


# Compare angles

def compareAngles(angle, data, enum):
    body = []
    angs = []

    #determine zero index
    zeroIndex = 0
    for i in range(len(angle)):
        if angle[i] == 0:
            zeroIndex = i

    for i in range(len(data)):
        deltaAngle = (np.mean(data[i].angles,0)[enum] - np.mean(data[zeroIndex].angles,0)[enum])/np.pi*180 + angle[zeroIndex]
        deltaAngle = deltaAngle*(1-0.00455)
        angs.append(angle[i]-deltaAngle)
        var = np.var(data[i].angles,0)[enum]
        body.append(["%.2f" % angle[i], "%.5f" % deltaAngle, "%.5f" % (angle[i]-deltaAngle), "%.6f" % var**.5])

    title = ("Angle (deg)", "Measured angle (deg)", "Difference (deg)", "Standard Deviation (deg)")
    text = np.vstack((title, body))
    print to_text(text)

    plt.plot(angle, angs,'o')
    plt.title('Deviation in Angle')
    plt.xlabel('Desired Angle (deg)')
    plt.ylabel('Relative Deviation in Angle (deg)')

    z = np.polyfit(angle, angs, 1)
    def linFit(x):
        return z[0]*x+z[1]
    x0 = angle[0]
    x1 = angle[-1]
    plt.plot([x0,x1], [linFit(x0),linFit(x1)])
    print z
    return z[0]
