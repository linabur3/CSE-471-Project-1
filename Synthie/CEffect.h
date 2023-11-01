#pragma once
class CEffect
{
public:
	CEffect() {}
	virtual void ProcessAudio(double* audio) = 0;
};

