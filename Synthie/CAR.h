#pragma once
#include "CAudioNode.h"
#include "CSineWave.h"

class CAR :
    public CAudioNode
{
private:
    double m_attack;
    double m_release;
    double m_duration;
    double m_time;
    double m_samplerate;
    CAudioNode* m_source;

public:
    CAR();
    void SetSource(CAudioNode* source);
    void Start();
    virtual bool Generate();
    void SetDuration(double d) { m_duration = d; }
};

