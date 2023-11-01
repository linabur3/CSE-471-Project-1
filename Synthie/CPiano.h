#pragma once
#include "CInstrument.h"
#include <vector>
#include "CSampleManager.h"

class CPiano :
    public CInstrument
{
public:
    CPiano();
    virtual void Start();
    virtual bool Generate();
    void SetDuration(double d) { m_duration = d; }

private:
    std::vector<short> mcurrSample;
    void LoadSamples();
    void SetNote(CNote* note);
    double m_duration;
    double m_time;
    int curFrame;
    int mFrames_To_Skip;
    int skippedFrames;
    double m_releaseEnvelope;
};

