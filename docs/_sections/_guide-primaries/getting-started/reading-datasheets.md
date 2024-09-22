---
layout: default
title: Reading Datasheets
nav_include: true
parent: Getting Started
nav_order: 3
---

# Reading Datasheets
The internet! Textbooks! How-to guides! Datasheets are yet another form of references that come in handy when learning more about your team’s electronic parts. Search for a datasheet of a part online- most manufacturers post pdfs that you can easily pull up. 

Datasheets help you understand the component better- whether it’s increasing accuracy or troubleshooting mistakes. For now, don’t worry if you can’t understand everything written in those pages. The topics addressed on this page are the most relevant for Robotathon. 

[Here is a link](https://www.infineon.com/dgdl/Infineon-IPP055N03L-DS-v01_03-en.pdf?fileId=db3a30431441fb5d01148d01ee1c0e91) to the datasheet this page references below. This component is **not** used in Robotathon, but it makes for a good example to dissect.

<div style="text-align: center;">
    <img src="{{ '/_assets/images/datasheet.png' | prepend: site.baseurl }}" alt="datasheet">
</div>

## First Page
Typically, the first page is pretty meta. Areas of interest include:

## <span style="background-color: #DD7E6B;">General Description</span>
* An overview of the features and applications of the part

## <span style="background-color: #f9cb9c;">Specifications</span>
* Numbers that describe what a part needs and can do

## <span style="background-color: #ffe599;">Connection Diagrams</span>
* A pinout lists the part’s pins, where they’re physically located, and their functions. 

## <span style="background-color: #b6d7a8;">Absolute Minimum/Maximum Ratings</span>
* These are the threshold specs that the part can handle before being permanently damaged! Be careful!

## <span style="background-color: #a4c2f4;"> Recommended Operating Conditions</span>
* Performance specs like voltage, ranges, timing info, temperature, etc. 
* Electrical Characteristics: specify particular test conditions which guarantee specific performance limits
* Timing Diagrams:  show how data should be sent to and received from the part, and what speed it should be sent / received

## Application Information
* More specifics on pin functions, how to communicate with the part, commands, memory tables, and more. 

{: .highlight}
Note: manufacturers might use different wording to describe what was mentioned above (i.e. pinout = connection diagram). 
{: .callout-toby}

Just like a Wikipedia page, datasheets tell you a lot of information that may or may not pertain to what you’re looking for. By knowing generally where to look and what you’re interested in, it’s faster for you to find the details you need!



