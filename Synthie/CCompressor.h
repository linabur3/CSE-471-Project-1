#include "CEffect.h"
#pragma once

class CCompressor : public CEffect
{
public:
	CCompressor();
	virtual void ProcessAudio(double* audio);
	virtual bool Start();

private:
	double threshold;
	double mSamplePeriod;
	double mRatio;
	double knee;
	double kneeStart;
};

