#include "pch.h"
#include "CCompressor.h"
#include <float.h>

CCompressor::CCompressor()
{

}

void CCompressor::ProcessAudio(double* audio)
{
	double gain_reduction;

	switch (mState)
	{
		// If we arent active, dont do anything but watch for when we go over threshold
	case Bypass:
		if (audio[0] > threshold)
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
			mState = Knee;
			mAttackStart = 0;
			kneeStart = m_time;
		}

		// Let transient through if attacking
		break;

	case Knee:
		if ((m_time - kneeStart) > knee)
		{
			// Once we pass knee window, turn compressor on 
			mState = Active;
			kneeStart = 0;
		}

		// Reduce gain gradually throughout Knee window
		if (audio[0] > threshold)
		{
			gain_reduction = (audio[0] - threshold) * (1 / mRatio) * fabs((m_time - kneeStart - knee)) / knee;
			audio[0] = audio[0] - gain_reduction;
			audio[1] = audio[0];
		}
		break;

		// Compressor is engadged
	case Active:
		// if we go back below threshold, start to release
		if (audio[0] < threshold)
		{
			mState = Release;
			mReleaseStart = m_time;
		}

		// Dampen audio according to the threshold
		// Compressor with ratio a - reduce gain by factor of a for amount over the threshold (multiply by 1/a)
		else
		{
			gain_reduction = (audio[0] - threshold) * (1 / mRatio);
			audio[0] = audio[0] - gain_reduction;
			audio[1] = audio[0];
		}
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
		if (audio[0] > threshold)
		{
			gain_reduction = (audio[0] - threshold) * (1 / mRatio) * audio[0] * (m_time - mReleaseStart) / mRelease;
			audio[1] = audio[0];
		}
		break;



	}

	// Add time elapsed
	m_time += mSamplePeriod;
}

bool CCompressor::Start()
{
	// Set initial params
	m_time = 0;
	threshold = 800;
	mState = Bypass;
	mSamplePeriod = 1 / mSampleRate;
	mAttack = .05;
	mRelease = .2;
	mRatio = 6;
	knee = .5;
	return true;
}