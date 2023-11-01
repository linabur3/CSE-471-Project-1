#include "CEffect.h"
#pragma once

class CCompressor : public CEffect
{
public:
	CCompressor();
	virtual void ProcessAudio(double* audio);
};

