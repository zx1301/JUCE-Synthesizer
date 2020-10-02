/*
  ==============================================================================

    SynthVoice.h
    Created: 25 Sep 2020 12:54:53am
    Author:  zx130

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "maximilian.h"
#include "windows.h"
using namespace juce;

class SynthVoice : public SynthesiserVoice
{
public:

    bool canPlaySound (SynthesiserSound* sound)
    {
        //returns if it can play sound
        //cast into our SynthSound and if cast is successful return true
        return dynamic_cast<SynthSound*>(sound) != nullptr;

    }
    
    void getEnvParams(float* attack, float* decay, float* sustain, float* release)
    {
        env1.setAttack(double(*attack));
        env1.setDecay(double(*decay));
        env1.setSustain(double(*sustain));
        env1.setRelease(double(*release));
    }
    
    void getOscType(float* selection)
    {
        theWave = *selection;

    }

    double setOscType()
    {
        if (theWave == 0)
        {
            return osc1.sinewave(frequency);
        }
        if (theWave == 1)
        {
            return osc1.saw(frequency);
        }
        if (theWave == 2)
        {
            return osc1.square(frequency);
        }
        else
        {
            return osc1.sinewave(frequency);
        }
    }

    //==========================================
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);

    }

    void stopNote(float velocity, bool allowTailOff)
    {
        env1.trigger = 0;
        allowTailOff = true;

        if (velocity == 0)
            clearCurrentNote();

    }

    void pitchWheelMoved(int newPitchWheelValue)
    {
    }

    void controllerMoved(int controllerNumber, int newControllerValue)
    {
    }

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
    {
        for (int sample = 0; sample < numSamples; ++sample) {
            double theSound = env1.adsr(setOscType(), env1.trigger) * level;
            double filteredSound = filter1.lores(theSound, 200, 0.1);
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                outputBuffer.addSample(channel, startSample, filteredSound);
            }
            ++startSample;
        }
    }

private:
    double level;
    double frequency;
    int theWave;

    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
};