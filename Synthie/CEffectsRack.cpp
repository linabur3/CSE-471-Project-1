#include "pch.h"
#include "CEffectsRack.h"
#include "CCompressor.h"

CEffectsRack::CEffectsRack()
{
	Setup();
}

void CEffectsRack::Setup()
{
	// Create compressor and add to signal chain
	CEffect* compressor = new CCompressor();
	effects.push_back(compressor);

}

void CEffectsRack::SendAudio(double* audio)
{
	// Loop through effects in signal chain to process audio
	for (int i = 0; i < effects.size(); i++)
		effects[i]->ProcessAudio(audio);
}