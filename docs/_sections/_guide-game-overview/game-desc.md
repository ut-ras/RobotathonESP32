---
layout: default
title: Game Description
nav_include: true
nav_order: 1
---

# Game Description

Welcome to wRAStling: our Sumo Wrestling themed competition! Build your robot from the ground up and compete against other wrastlers in the ring!


## Rounds
Each team will play in 8 minute long rounds with 2 minute setup times in between. Number of rounds is subject to change as competition day rolls closer. Every round will pit four teams against each other to see who can score the most points by navigating challenges and pushing opponents out of the ring!

The competition will be double-elimination style which means if your team is beat once, you still have a chance to win Robotathon! However if your team is defeated two times, you will be eliminated.

<!-- TODO include image of map and have it in its own subcategory -->

## Challenges

The premise of this year's game requires each team to navigate obstacles and a steep ramp to reach the challenger ring and face off in a wRAStling match!

You will build a robot around the color, line, and mechanical peripherals to achieve this.

Every sensor challenge your team completes autonomously will earn your team points and challenges can be repeated until the round is over. 

Within the ring is the driver challenge. Operators must use their controllers to manually face off. Time spent in the ring and opponents knocked out is rewarded with points.

Challenges will be completed in the order below:
* Color challenge -> Line challenge -> Mechanical and Driver challenge

After one of these routes is completed, teams will manually drive back to the start location to repeat the challenges.

No flashing code during the round! You may do so during setup or between rounds.


## Remote Controller
Each team will be provided a Bluetooth controller. You will need to use this controller to manually operate your robot within challenger ring (MANUAL CHALLENGE).
* Note that the line and color challenges are AUTONOMOUS challenges. You can use your remote controller to drive through the sensor challenges, but you will NOT EARN POINTS.
* You are encouraged to use your remote controller in the event that your robot gets stranded in the middle of the field.


## Field
The field is split into four symmetrical courses to accommodate four teams for each round.

<!-- Teams will start on opposing corners of the field as shown below: -->

<!-- TODO replace this map with better one
<img src="{{ '/_assets/images/replace_this_map_with_better_one.png' | prepend: site.baseurl }}" alt="map :("> -->

{: .highlight}
Do not hardcode your robot according to the above layout for maze or line! The exact layout for those challenges may be different on the actual field.
{: .callout-red}


## Section 1: Journeying to the ring

### Color Challenge
Colored blocks will form a track. During the challenge, the robot must sample the first block and second block and remember both colors.

Then, the robot must move forward until it reaches the first color and turn to find the direction of the block of the second color, and move so forth until the last block (of the first color).

### Line Challenge
Your robot must follow the path and make it to the end of the line.

If your robot gets stuck or lost, you may reset your robot, but you must start from the beginning of the path.


## Section 2: Climb the walls

### Mechanical Challenge
Your robot must traverse the ramp leading up to the raised ring.
If your robot falls off, you may reset your robot, but you must start from the beginning of the path.

Keep in mind to design your robot to handle a small fall!


## Section 3: Destroy your opponents

### Driver Challenge
Fight to stay the longest in the ring! Push off as many opponents as possible. 

If pushed off or in the ring for over a minute, the competitors must drive back to the start (may be manual) and complete another lap of the challenges.

Note that robots are not permitted to intentionally damage the field or other robots. "Smashing" mechanisms are not allowed and the objective is to simply push other robots out of the ring.
