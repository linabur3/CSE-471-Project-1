#include <vector>
#include "CEffect.h"
#pragma once
class CEffectsRack
{
public:
	CEffectsRack();
	void Setup();
	void SendAudio(double*);
	void setSampleRate(double rate) { mSampleRate = rate; }

private:
	std::vector<CEffect*> effects;  // The signal chain of effects
	double mSampleRate;
};

