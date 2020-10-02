/*
  ==============================================================================

    Envelope.cpp
    Created: 1 Oct 2020 8:35:43pm
    Author:  zx130

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Envelope.h"
#include "PluginProcessor.h"
//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p): audioProcessor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(200,200);

    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    addAndMakeVisible(&attackSlider);

    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(1.0f, 2000.0f);
    decaySlider.setValue(1.0f);
    decaySlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    addAndMakeVisible(&decaySlider);

    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0.0f, 1.0f);
    sustainSlider.setValue(0.8f);
    sustainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    addAndMakeVisible(&sustainSlider);

    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    addAndMakeVisible(&releaseSlider);

    attackTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "attack", attackSlider);
    decayTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "decay", decaySlider);
    sustainTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "sustain", sustainSlider);
    releaseTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "release", releaseSlider);
    //connect to AudioProcessorValueTreeState in pluginProcessor
    
}

Envelope::~Envelope()
{
}

void Envelope::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::black);   // clear the background

}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    juce::Rectangle<int> area = getLocalBounds().reduced(40);

    attackSlider.setBounds(10, 10, 40, 100);
    decaySlider.setBounds(40, 10, 40, 100);
    sustainSlider.setBounds(70, 10, 40, 100);
    releaseSlider.setBounds(110, 10, 40, 100);
}
