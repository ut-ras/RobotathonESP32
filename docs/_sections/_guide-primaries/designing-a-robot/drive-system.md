---
layout: default
title: Drive System
nav_include: true
parent: Designing a Robot
nav_order: 2
---

# Drive System
Remember, you have an external budget that you can use to buy more servos and casters if you wish. Additionally, you have access to the TIW makerspace 3D printers and laser cutters (free training required) to design and print your own wheels and hubs.

Now let’s look at the drive system. In this article, we’ll be looking specifically at two wheeled drive. With two wheels, you’re pretty limited in how you can drive. Typically, a robot with two wheels has the wheels on the sides, like below. The red regions are where you can put the wheel axles.

<img src="{{ '/_assets/images/wheel_placement.png' | prepend: site.baseurl }}" alt="wheel placement">

Can you think of any ways that having two wheels may affect the balance of your robot? What if the wheels were in the front and the back side had a heavy battery on it? Additionally, another thing your team should consider is: how will the robot move with your wheel configuration? Will it drive in straight lines? Rotate? How can you error correct for tilting? 

As you can see, the wheel positions will immensely affect the design of your mechanical systems and software algorithms. Your decisions are very important since reliable movement is a key factor in the competition courses.

After you’ve decided upon your wheels placement, how you drive your wheels (software) can also result in different movements. See the below two diagrams and observe their center of movement (the white circle). You can drive both sides at once, or a single side. You can drive them in opposite directions, and you can drive them at different rates. There are so many options!

<img src="{{ '/_assets/images/chassis_rotation.png' | prepend: site.baseurl }}" alt="chassis rotation">

Remember, you aren’t limited to any configuration. In fact, we recommend you try them all out! 
