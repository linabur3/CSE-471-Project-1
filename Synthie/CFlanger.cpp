#include "pch.h"
#include "CFlanger.h"
#include <vector>

const double pi = 3.14159265359;
const int QUEUESIZE = 200000;
const double DELAY = 1.0;
const double GAIN = 2;

CFlanger::CFlanger()
{
}

bool CFlanger::Start()
{
	// Set initial params
	mState = Bypass;
	m_time = 0;
	mSamplePeriod = 1 / mSampleRate;
	mAttack = .05;
	mRelease = .1;
	wrloc = 0;
	xqueue.resize(QUEUESIZE);
	yqueue.resize(QUEUESIZE);
	m_resonf = .2;
	m_resonB = .1;
	mRateFactor = 5;
	return true;
}

void CFlanger::ProcessAudio(double* audio)
{
	// Flange audio
	m_resonf =  .3 + (.4 * sin(mRateFactor * m_time));

	// Calculate values for Reson Filter
	double R = 1 - (m_resonB / 2);
	double cos_theta = (2 * R * cos(2 * pi * m_resonf)) / (1 + (R * R));
	double A = (1 - (R * R)) * sqrt((1 - (cos_theta * cos_theta)));

	A = A * 2;

	wrloc = (wrloc + 2) % QUEUESIZE;
	xqueue[wrloc] = audio[0];
	xqueue[wrloc + 1] = audio[1];

	// Calculate first term in reson filter equation
	int rdloc = (wrloc + QUEUESIZE - 0) % QUEUESIZE;
	double term1L = A * xqueue[rdloc];
	double term1R = A * xqueue[rdloc + 1];

	// Calculate second term in reson filter equation
	rdloc = (wrloc + QUEUESIZE - 2) % QUEUESIZE;
	double term2L = 2 * R * cos_theta * yqueue[rdloc];
	double term2R = 2 * R * cos_theta * yqueue[rdloc + 1];

	// Calculate third term in reson filter equation
	rdloc = (wrloc + QUEUESIZE - 4) % QUEUESIZE;
	double term3L = R * R * yqueue[rdloc];
	double term3R = R * R * yqueue[rdloc + 1];

	audio[0] = term1L + term2L - term3L;
	audio[1] = term1R + term2R - term3R;

	// Apply Gain
	audio[0] = audio[0];
	audio[1] = audio[0];

	// Add to feedback queue
	yqueue[wrloc] = audio[0];
	yqueue[wrloc + 1] = audio[1];

	m_time += mSamplePeriod;

}