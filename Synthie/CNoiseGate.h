#pragma once
#include "CEffect.h"
class CNoiseGate :
    public CEffect
{
public:
    CNoiseGate();
    virtual void ProcessAudio(double* audio);
    virtual bool Start();
    
private:
    double threshold;
    double mSamplePeriod;
};

