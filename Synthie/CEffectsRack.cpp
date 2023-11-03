#include "pch.h"
#include "CEffectsRack.h"
#include "CCompressor.h"
#include "CNoiseGate.h"

CEffectsRack::CEffectsRack()
{
}

void CEffectsRack::Setup()
{
	// Create compressor and add to signal chain
	CEffect* compressor = new CCompressor();
	compressor->setSampleRate(mSampleRate);
	effects.push_back(compressor);

	// Create noise gate and add to signal chain
	CEffect* gate = new CNoiseGate();
	gate->setSampleRate(mSampleRate);
	effects.push_back(gate);

	// Start all of the components
	for (int i = 0; i < effects.size(); i++)
		effects[i]->Start();

}

void CEffectsRack::SendAudio(double* audio)
{
	// Loop through effects in signal chain to process audio
	for (int i = 0; i < effects.size(); i++)
		effects[i]->ProcessAudio(audio);
}