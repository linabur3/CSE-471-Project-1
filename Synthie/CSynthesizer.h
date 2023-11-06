#pragma once
#include "msxml2.h"
#include <list>
#include "CInstrument.h"
#include <string>
#include "CNote.h"
#include<vector>
#include "CSampleManager.h"
#include "CEffectsRack.h"

using namespace std;

class CSynthesizer
{
public:

	CSynthesizer();
	//! Number of audio channels
	int GetNumChannels() { return m_channels; }

	//! Sample rate in samples per second
	double GetSampleRate() { return m_sampleRate; }

	//! Sample period in seconds (1/samplerate)
	double GetSamplePeriod() { return m_samplePeriod; }

	//! Set the number of channels
	void SetNumChannels(int n) { m_channels = n; }

	//! Set the sample rate
	void SetSampleRate(double s) { m_sampleRate = s;  m_samplePeriod = 1.0 / s; }

	void Start();

	bool Generate(double*);

	//! Get the time since we started generating audio
	double GetTime() { return m_time; }

	void Clear();

	void OpenScore(CString&);

	void XmlLoadNote(IXMLDOMNode* xml, std::wstring& instrument);

	void setManager(CSampleManager* newmanager) { manager = newmanager; }

private:
	int		m_channels;
	double	m_sampleRate;
	double	m_samplePeriod;
	double m_time;
	std::list<CInstrument*>  m_instruments;
	double  m_bpm;                  //!< Beats per minute
	int     m_beatspermeasure;  //!< Beats per measure
	double  m_secperbeat;        //!< Seconds per beat
	std::vector<CNote> m_notes;
	CEffectsRack* rack;          // the effects rack

	void XmlLoadScore(IXMLDOMNode* xml);

	void CSynthesizer::XmlLoadInstrument(IXMLDOMNode* xml);
	int m_currentNote;          //!< The current note we are playing
	int m_measure;              //!< The current measure
	double m_beat;              //!< The current beat within the measure
	CSampleManager* manager;

};

#pragma comment(lib, "msxml2.lib")
