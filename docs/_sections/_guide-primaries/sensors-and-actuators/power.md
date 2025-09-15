<!-- ---
layout: default
title: Powering the System
nav_include: true
parent: Hardware
nav_order: 1
--- -->

<!-- TODO write this -->


- How do basic circuits work? (i.e. current only flows in a closed loop, what is voltage, what is ground, etc.)
- What is a breadboard?
  - Power rails (very important), connections
  - include picture of breadboard with highlighted connections
- Note that many pictures in the Robotathon guide depict sensors directly attache to the ESP32 power pin rather than to a power rail. Would be good to mention
- Power ORring with diode how
  - Is the single diode blocking DC input through the ESP32 good enough for power ORring? wouldnt that just damage the USB device
 
- Include diagram of USBC breakout board

# Intro to Power

Electricity is an amazing property of physics that allows us to create infinite new technologies. Here you'll be learning about how it works, how to control it, and how it can destroy your components if you use it the wrong way!

## Conductors, Voltage, and Current

Conductors are materials that easily allow electricity to flow through them. You probably know a few, like metals and salt water. These materials 'conduct' electricity because electrons are shared between atoms in the material, creating a "sea of electrons". This "sea" allows electrons to bump into one another in the material, kind of like a Newton's Cradle.

Voltage is the difference in electron density between two points in a conductor. If point A in a copper wire has less electrons and point B down the wire has lots, we say the "Voltage" between point A and point B is some number, say 3 Volts (the unit of measurement of voltage). We notate a single point in a circuit as 'ground', which has a voltage of 0 Volts relative to the rest of the circuit. This is to make measuring voltages at various points in the circuit easier. On the copper wire, we'll notate point B as ground, meaning we can say point A is at 3 Volts.

Let's keep imagining the copper wire, with points A and B. When there's a 3 Volt difference between points A and B, the electrons will want to rush from point B to point A to equalize the voltage in the wire, and this movement is called Current. Current is measured in Amperes (Amps), which is the number of electrons flowing perpendicular to a cross-section of a conductor. In the case of the copper wire, the current's positive direction is from point A to point B, even though the electrons are flowing the opposite way. This is because elctrons have a negative charge, and current is notated in the direction of positive charge flow (real fun, right?)

One last concept in electric flow is Resistance, measured in Ohms. Resistance is the opposition to the flow of current, and it's how we control how much current we put into our components. Let's imagine our copper wire one last time. We have 3 Volts from point A to point B, and let's add a Resistor (a circuit component that adds resistance) between the two points. We can now find numeric values of Voltage, Current, and Resistance with the relationship V=I*R, where V=Voltage in Volts, I=Current in Amps, and R=Resistance in Ohms.

## Driving Ciruits with Voltage

Voltage is the key property to know when wiring your robot, and these are the supplies we give you to handle it:
* USBC Breakout Board, separates power and ground from USBC cable
* Solderless Breadboard, provides organized terminals to access power and ground, and connect components to your ESP32
* Power Bank, supplies the voltage to your robot
* Wires, carries voltage from one place to another

Your Breadboard will be the main connection between all of your components