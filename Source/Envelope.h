/*
  ==============================================================================

    Envelope.h
    Created: 1 Oct 2020 8:35:43pm
    Author:  zx130

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Envelope : public juce::Component
    //public Slider::Listener
{
public:
    Envelope(SynthFrameworkAudioProcessor&);
    ~Envelope() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
   Slider attackSlider;
   Slider decaySlider;
   Slider sustainSlider;
   Slider releaseSlider;


   std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackTree;
   std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> decayTree;
   std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sustainTree;
   std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseTree;
   
   SynthFrameworkAudioProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
