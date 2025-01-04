---
layout: default
title: SYNTAX EXAMPLES LOOKIE HERE NEWBIE GUIDE SLAVES FOR SYNTAX REFERENCE iuytrghj
nav_include: true
nav_order: 1
---

# official docs https://just-the-docs.com/

#### title four
### title three
## title two
# title one

## embedded youtube video:
<iframe width="560" height="315" src="https://www.youtube.com/embed/6Yie6rfXPus?si=EjpjbWOcLFhEjrhk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## embedded google slide:
<iframe src="https://docs.google.com/presentation/d/1h5p9pCGCKSqfrkFSnQQ6bxtwjZGJe90FrfASYaGZwRY/embed?start=false" 
        frameborder="0" 
        width="960" 
        height="569" 
        allowfullscreen="true" 
        mozallowfullscreen="true" 
        webkitallowfullscreen="true">
</iframe>

presentation ID looks something like this: 1h5p9pCGCKSqfrkFSnQQ6bxtwjZGJe90FrfASYaGZwRY

it can be retrieved from the normal google slides link:
https://docs.google.com/presentation/d/**1h5p9pCGCKSqfrkFSnQQ6bxtwjZGJe90FrfASYaGZwRY**/edit#slide=id.g286726c4cfe_3_0

format the link like this to get an embedded version:
https://docs.google.com/presentation/d/[PRESENTATION ID]/embed?start=false" 

## embedded images
<img src="{{ '/_assets/images/ir_sensors.png' | prepend: site.baseurl }}" alt="ir_sensors.png :(">

you have to add the image yourself in the /_assets/images directory before including them int he website

once you have your picture there, just replace "ir_sensors.png" with whatever your image's file name is

PLEASE FOLLOW NAMING CONVENTION WHERE SPACES IN PICTURE NAMES ARE "_"