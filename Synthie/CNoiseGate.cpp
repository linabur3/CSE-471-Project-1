#include "pch.h"
#include "CNoiseGate.h"
#include <float.h>
#include <cstdlib>


CNoiseGate::CNoiseGate()
{
	threshold = 10000;
	mState = Bypass;
}

bool CNoiseGate::Start()
{
	// Set initial params
	threshold = 10000;
	mState = Bypass;
	m_time = 0;
	mSamplePeriod = 1 / mSampleRate;
	mAttack = .05;
	mRelease = .05;
	return true;
}

void CNoiseGate::ProcessAudio(double* audio)
{
	switch (mState)
	{
		// If we arent active, dont do anything but watch for when we fall below threshold
	case Bypass:
		if (audio[0] < threshold)
		{
			// Switch to attacking state if we go under threshold
			mState = Attack;
			mAttackStart = m_time;
		}
		break;

		// If we are attacking
	case Attack:

		if ((m_time - mAttackStart) > mAttack)
		{
			// If we past the attack window, turn noise gate on
			mState = Active;
			mAttackStart = 0;
		}

		// Ramp out
		audio[0] = audio[0] * fabs((m_time - mAttackStart - mAttack)) / mAttack;
		audio[1] = audio[0];
		break;

		// Noise gate is on
	case Active:
		// if we go back above threshold, start to release
		if (audio[0] > threshold)
		{
			mState = Release;
			mReleaseStart = m_time;
		}

		// Mute audio while active and under the threshold
		audio[0] = 0;
		audio[1] = 0;
		break;

		// We are releasing to go back to full gain
	case Release:
		if ((m_time - mReleaseStart) > mRelease)
		{
			// Once release ends, go back to bypass mode
			mState = Bypass;
			mReleaseStart = 0;
		}

		// Ramp back in
		audio[0] = audio[0] * (m_time - mReleaseStart) / mRelease;
		audio[1] = audio[0];
		break;


	
	}

	// Add time elapsed
	m_time += mSamplePeriod;
}

