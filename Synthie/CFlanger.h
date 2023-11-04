#pragma once
#include "CEffect.h"
#include <vector>
class CFlanger :
    public CEffect
{
public:
    CFlanger();
    virtual void ProcessAudio(double* audio);
    virtual bool Start();

private:
    double mSamplePeriod;
    double m_resonB;
    double m_resonf;
    int wrloc;
    std::vector<double> xqueue;
    std::vector<double> yqueue;
    double mRateFactor;
};

