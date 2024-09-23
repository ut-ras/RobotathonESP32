---
layout: default
title: Advanced Debugging
nav_include: true
# parent: Resources
nav_order: 1
---
<!-- tbh how relevant is oscilloscopes for robotathon lol -->
# To Debug or not to Debug? Debugging with Oscilloscopes and Other Tools
Effective debugging is an important skill when working with electronic circuits, whether on a breadboard, PCB, or in a system. One of best tools for debugging is the oscilloscope, aka scope, which allows us to visualize transient behavior of electrical signals. Additionally, multimeters, logic analyzers, and signal generators play crucial roles in the debugging process.

<img src="{{ '/_assets/images/oscilloscope.jpg' | prepend: site.baseurl }}" alt="oscilloscope.jpg" width=300 height=300>

If you do not have an oscilloscope available to you, check out a **multimeter**. They do about the same thing and are much easier to use but provide less data. If you want to measure voltage, set the multimeter into voltimeter mode and connect the positive/negative leads across the component you want to measure! Measuring current is a different process because you will need to put the multimeter into ammeter mode and put it in series with the component you want to test. 
<img src="{{ '/_assets/images/multimeter.jpg' | prepend: site.baseurl }}" alt="multimeter.jpg" width=150 height=150>

[How to Use a Multimeter](https://www.electronicshub.org/how-to-use-a-multimeter/)

# Using an Oscilloscope to Debug Circuits
To effectively debug with a scope, follow these steps. For more details, check out Sparkfun's in-depth tutorial on using the oscilloscope!  
[How to Use an Oscilloscope](https://learn.sparkfun.com/tutorials/how-to-use-an-oscilloscope/all)

{: .highlight}
**Scope probe:**  
<img src="{{ '/_assets/images/scope_probe.jpg' | prepend: site.baseurl }}" alt="scope_probe.jpg" width=150 height=150>
{: .callout-toby}

### Step 1: Probe the Circuit at Key Nodes
Attach the oscilloscope probes to important points in the circuit, such as input and output pins of the ESP32 microcontroller. Make sure to connect GND to the circuit’s GND to prevent floating measurements. (Floating measurements are unreliable or inaccurate readings due to improper voltage referencing.)

<img src="{{ '/_assets/images/debug_circuit.png' | prepend: site.baseurl }}" alt="debug_circuit.png" width=200 height=200>  
*For example, if I want to measure the output of the circuit, attach the short lead (REF) to GND and the probe tip at the output. See the image above for the the short lead and probe tip.*

### Step 2: Examine Waveforms
Observe the waveforms at different points to verify that the signals are as expected.

 - **Digital Signals**: Should show clean transitions between high (1) and low (0) states.
 - **Analog Signals**: Should correspond to the expected signal shape, such as sine waves or pulse signals. Look for excessive noise, incorrect timing, or unexpected signal levels.

### Step 3: Identify Signal Distortions or Noise
If a signal appears distorted or has noise, it may indicate problems like poor grounding, interference from nearby components, or faulty wiring. Using the oscilloscope’s noise-filtering features, you can isolate the problem.

### Step 4: Verify Timing and Synchronization
Oscilloscopes are especially useful for diagnosing timing-related issues in circuits. In digital circuits, you can compare clock signals with data signals to ensure proper synchronization. Check for issues like clock drift, missed signals, or incorrect duty cycles in pulse-width modulated signals. 

*In the case with the robot you are building, testing for timing is a little excessive and out of the scope of the competition.*

### Step 5: Check Power Supply Integrity
A faulty power supply can cause many issues. Use the oscilloscope to measure the power rail voltages and observe any ripples or drops, which may indicate the need for better decoupling capacitors or power filtering.

---

# Common Issues and How to Address Them
- ### No Signal or Flatline on Scope:
If the oscilloscope shows no signal or a flatline, it might indicate a bad connection, a broken wire, or a dead component. Check the circuit connections and ensure the scope probe is properly attached.

- ### Unexpected Noise:
High levels of noise can be caused by poor grounding, electromagnetic interference (EMI), or switching power supplies. Use short ground leads on the scope probes and try to isolate potential sources of noise.

- ### Incorrect Signal Levels:
If the signal levels are too high or too low, the issue might be related to incorrect component values (e.g., resistors, capacitors) or a problem with the power supply. Use a multimeter to confirm the supply voltages and check component values.


# Best Practices for Debugging
- ### 1. Document Your Process:
Keep notes on which parts of the circuit you have tested and the results. This will help you keep track of progress and avoid re-testing the same parts.

- ### 2. Test One Section at a Time:
If you are debugging a complex circuit, focus on one section at a time. Verify each block of the circuit (power supply, digital logic, analog signals) individually to isolate problems.

- ### 3. Work Systematically:
Start with the basics, such as checking power and ground connections, before moving on to more complex components. A systematic approach will save time and help you find bugs more quickly.

---

# Other Debugging Tools
While oscilloscopes are powerful, they aren’t the only tool available for debugging. Combining multiple tools enhances your ability to find and fix problems efficiently:

- #### Multimeter:
A multimeter is the most basic but essential debugging tool. It measures voltage, current, and resistance. Use it to check for shorts, verify power supply voltages, or measure component values.

- #### Logic Analyzer:
A logic analyzer is used to capture and analyze digital signals over time. It's helpful for debugging digital communication protocols (like I2C, SPI, or UART), where multiple signals need to be examined simultaneously for timing and data errors.

- #### Signal Generator:
A signal generator creates specific signals (sine, square, pulse) that can be place at the input into a circuit to simulate test responses. This is useful when a specific input condition needs to be recreated for testing.
