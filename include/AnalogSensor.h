#pragma once

class AnalogSensor {
  protected:
    bool calibrationActive;
    bool lowerLimitSet;
    bool upperLimitSet;
    double upperLimit;
    double lowerLimit;

    virtual double getRawValue(bool blocking = true) = 0;

  public:
    static double linearMap(double input, double inputStart, double inputEnd,
                            double outputStart, double outputEnd) {
        double slope =
            1.0 * (outputEnd - outputStart) / (inputEnd - inputStart);
        double output = outputStart + slope * (input - inputStart);

        return output;
    }

    /*
        1st call: Activate calibration
        2nd call: Set lower limit
        3nd call: Set upper limit
    */
    void calibrate() {
        if (calibrationActive) {
            if (lowerLimitSet) {
                upperLimit = getRawValue();
                upperLimitSet = true;
                calibrationActive = false;
            } else {
                lowerLimit = getRawValue();
                lowerLimitSet = true;
            }
        } else {
            calibrationActive = true;
            lowerLimitSet = false;
            upperLimitSet = false;
        }
    }

    void setLowerLimit(double limit) {
        lowerLimit = limit;
        lowerLimitSet = true;
    }

    void setUpperLimit(double limit) {
        upperLimit = limit;
        upperLimitSet = true;
    }

    bool isCalibrationActive() { return calibrationActive; }

    bool isLowerLimitSet() { return lowerLimitSet; }

    bool isUpperLimitSet() { return upperLimitSet; }

    double getLowerLimit() { return lowerLimit; }

    double getUpperLimit() { return upperLimit; }

    virtual double getValue(bool blocking = true) = 0;
};