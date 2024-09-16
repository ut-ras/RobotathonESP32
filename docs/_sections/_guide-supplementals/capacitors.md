---
layout: default
title: Bypass & Decoupling Capactitors
nav_include: true
# parent: Resources
nav_order: 1
---

# Bypassing Pain and Hunger... Use a Bypass or Decoupling Capacitor

You will be using a bypass capacitor to **stabilize the output of your IR sensors.** Generally, bypass or decoupling capacitors are placed between VDD and GND like so!  
  
<img src="{{ '/_assets/images/bypass_cap.jpg' | prepend: site.baseurl }}" alt="bypass_cap.jpg" width=450 height=450>


## What are Bypass and Decoupling Capacitors?
Bypass capacitors and decoupling capacitors are important components in electronic circuits, and while they are often used interchangeably, they serve slightly different purposes.

### Bypass Capacitors:
- **What they do:** Bypass capacitors remove noise. They provide a "shortcut" for high-frequency noise in the power supply to GND. This noise can come from things like fast-switching digital circuits (e.g., microcontrollers or processors).

- **How they work:** The capacitor sits between the power supply (Vcc) and ground. When there’s noise, instead of passing through the sensitive parts of the circuit, the noise is bypassed directly to ground, leaving the circuit cleaner and more stable.

### Decoupling Capacitors:
- **What they do:** Decoupling capacitors provide quick power and protect the circuit from sudden changes in current. You can use them to isolate different parts of the circuit, and they also help supply a steady current to components, especially when there are sudden changes in current demand.

- **How they work:** When a component needs a quick burst of power, the decoupling capacitor provides it, reducing the load on the main power supply and preventing voltage drops. It “decouples” the component from disturbances in the power supply.

---

## Why They Matter:
Both capacitors help ensure that the power supply stays clean and stable, which is important for keeping circuits working correctly. Without them, the noise or sudden changes in current could cause the circuit to behave unpredictably or fail.
