/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicpluginAudioProcessorEditor::BasicpluginAudioProcessorEditor (BasicpluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{

    setSize (200, 200);
    
    midiVolume.setSliderStyle(Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, false, this);
    midiVolume.setTextValueSuffix("Volume");
    midiVolume.setValue(1.0);
    
    midiVolume.addListener(this);
    addAndMakeVisible(&midiVolume);
}

BasicpluginAudioProcessorEditor::~BasicpluginAudioProcessorEditor()
{
}

//==============================================================================
void BasicpluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("MIDI Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void BasicpluginAudioProcessorEditor::resized()
{
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}

void BasicpluginAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    processor.noteOnVel = midiVolume.getValue();
}
