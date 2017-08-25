"""
Parsing Data from Serial.

The Teensy code is written so as to serial-print in a spesified format.
See seperate [readme.md](Vive Validation Resources/readme.md) for details.
The following mehtod is made to read this information into memory.
"""

class Data(object):
    """Data class to store information."""

    def __init__(self, duration):
        """Initialize arrays."""
        self.AstartTime = []
        self.Aduration = []
        self.ArapidSpikeDown = []

        self.BstartTime = []
        self.BL1 = []
        self.BL2 = []
        self.Bsignal = []
        self.BidentifyedSteps = []
        self.BtimeSinceLast = []

        self.CL1Type = []
        self.CL2Type = []
        self.CsignalType = []
        self.CcalibrationStep = []

        self.DsignalType = []
        self.DsignalAngle = []

        self.angles = []
        self.duration = duration

        self.errors = []

    lastCommaIndex = 0

    @staticmethod
    def readLine(line, d):

        if not d:
            d.append(Data(0))

        def commaIndex(s):
            """Determine index of next comma."""
            for i in range(Data.lastCommaIndex+1, len(s)):
                if s[i] == ',':
                    return i
            return -1

        def pullVar(s):
            """Pull variable."""
            last = Data.lastCommaIndex
            n = commaIndex(s)
            Data.lastCommaIndex = n
            return s[last+1:n]

        def pullInt(s):
            """Pull integer type variable."""
            return int(pullVar(s))

        def pullFloat(s):
            """Pull floating type variable."""
            return float(pullVar(s))

        Data.lastCommaIndex = -1
        tolken = pullVar(line)
        try:
            if tolken == 'A':
                d[-1].AstartTime.append(pullInt(line))
                d[-1].Aduration.append(pullInt(line))
                d[-1].ArapidSpikeDown.append(pullInt(line))
            elif tolken == 'B':
                d[-1].BstartTime.append(pullFloat(line))
                d[-1].BL1.append(pullFloat(line))
                d[-1].BL2.append(pullFloat(line))
                d[-1].Bsignal.append(pullFloat(line))
                d[-1].BidentifyedSteps.append(pullInt(line))
                d[-1].BtimeSinceLast.append(pullInt(line))
            elif tolken == 'C':
                d[-1].CL1Type.append(pullInt(line))
                d[-1].CL2Type.append(pullInt(line))
                d[-1].CsignalType.append(pullInt(line))
                d[-1].CcalibrationStep.append(pullInt(line))
            elif tolken == 'D':
                d[-1].DsignalType.append(pullInt(line))
                d[-1].DsignalAngle.append(pullFloat(line))
            elif tolken == 'E':
                d[-1].angles.append([pullFloat(line), pullFloat(line), pullFloat(line), pullFloat(line)])
            elif tolken == 'X':
                d[-1].errors.append(pullInt(line))
            elif tolken == 'N':
                d.append(Data(pullInt(line)))

        except:
            pass
