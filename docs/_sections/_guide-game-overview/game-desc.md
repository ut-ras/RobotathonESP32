---
layout: default
title: Game Description
nav_include: true
nav_order: 1
---

# Game Description

Welcome to RASpionage: our spy themed robotics competition! Cooperate with Perry the Platypus to take down Dr. Jeffrey Doofenshmirtz’s nefarious collusion with A&M!

## Rounds
Each team will play in 5 minute long rounds with 2 minute setup times in between. Number of rounds is subject to change as competition day rolls closer. Every round will pit two teams against each other to see who can score the most points through various challenges detailed below.

TODO more information about tourney bracket

## Challenges
The premise of this year's game requires each team to break into Dr. Jeffrey Doofenshmirtz’s evil lab, navigate the dangerous traps and obstacles, and finally help Perry destroy the Aggienator! 

You will build a robot around the color, line, wall, and mechanical peripherals to achieve this.

TODO verify this
These 4 challenges will be repeatable until the time limit is up

## Remote Controller
Each team will be provided a Bluetooth controller. You will need to use this controller to manually drive your robot between each challenge and trigger autonomous modes tailored for each sensor.
* You can use your remote controller to drive through the sensor challenges, but you will NOT EARN POINTS
* You are encouraged to use your remote controller in the event that your robot gets stranded in the middle of the field.

## Field
The field is split into two symmetrical loops to accommodate two teams for each round.

Teams will start on opposing corners of the field as shown below:

<img src="{{ '/_assets/images/replace_this_map_with_better_one.png' | prepend: site.baseurl }}" alt="map :(">

{: .highlight}
Do not hardcode your robot according to the above layout for maze or line! The exact layout for those challenges may be different on the actual field.
{: .callout-red}

## Section 1: Breaking into the lab

The robot is tasked with sampling a color, at a far end of the field. 

### Color Challenge
Four colored strips will be placed on the floor. The robot must sample the first strip and remember its color.
Then, test the next three strips to find one that matches the first strip and pick the ping pong ball up.

TODO: add image of map

## Section 2: Navigate the lab

### Wall Challenge
Your robot must navigate through the maze while carrying a ping pong ball and avoid running into the walls.
If your robot gets stuck you may manually reset your robot to the beginning of the maze section.
One side of the field could have a maze with more turns than the other. In the player’s choice rounds, it’s best if the team with the better wall sensor opts to that side.

TODO: add image of map

## Section 3: Dodge the Lasers

### Line Challenge
Requires manual or automated completion of collection but not preparation.
Your robot must follow the path and make it to the end of the line while carrying a ping pong ball
If your robot gets stuck or lost, you may reset your robot, but you must start from the beginning of the path.

TODO: add image of map

{: .highlight}
One side of the field will be more jagged, while the other is curved. The team that met the most checkpoints/deadlines will have the option of choosing which side they want to run.
{: .callout-blue}

## Section 4: Destroying the Aggienator!

### Mechanical Challenge
Launch your ping pong ball into one of the tiers of the Aggienator to score points
Tiers will be smaller the higher they are, but scoring in higher tiers will earn more points.
The bottom tier will be at field level, and teams can place ping pong balls in this bottom tier for minimal points.

TODO: add image of map

