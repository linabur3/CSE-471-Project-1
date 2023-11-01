#include <vector>
#include "CEffect.h"
#pragma once
class CEffectsRack
{
public:
	CEffectsRack();
	void Setup();
	void SendAudio(double*);

private:
	std::vector<CEffect*> effects;  // The signal chain of effects
};

