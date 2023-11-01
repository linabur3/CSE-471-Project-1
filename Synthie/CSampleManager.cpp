#include "pch.h"
#include "CSampleManager.h"
#include "audio/DirSoundSource.h"
#include <string>

using namespace std;

CSampleManager::CSampleManager()
{
    LoadSamples();
    m_pedalToggle = false;
}

void CSampleManager::LoadSamples()
{
    m_samples.resize(88);
    CDirSoundSource audioin;

    double SampleRate = 44100.;

    for (int i = 0; i < 88; i++)
    {
        string path = "CompletePiano\\" + to_string(i) + ".wav";

        if (!audioin.Open(path.c_str()))

        {

            // Deal with the error

        }

        int numframes = audioin.NumSampleFrames();
        double file_sample_rate = audioin.SampleRate();

        mFrames_To_Skip = SampleRate / file_sample_rate;

        m_samples[i].resize(numframes);

        for (int j = 0; j < numframes; j++)
        {
            short audio[2];

            audioin.ReadFrame(audio);

            m_samples[i][j] = audio[0];
        }


    }
}