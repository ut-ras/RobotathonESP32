---
layout: default
title: LOOKIE HERE NEWBIE GUIDE SLAVES FOR SYNTAX REFERENCE
nav_include: true
nav_order: 2
---

# official syntax docs [https://just-the-docs.com/](https://just-the-docs.com/)
^ hyperlinked text example

see official docs for more standard syntax like titles, ordered lists, bullet points tables, etc.

## callouts

{: .highlight}
nice and blue callout
{: .callout-blue}

{: .highlight}
angry and red callout
{: .callout-red}

## highlights

<span style="background-color:rgb(57, 255, 229);">highlighted text</span>


## embedded images
<img src="{{ '/_assets/images/my_image.png' | prepend: site.baseurl }}" alt="my_image.png :(">

you have to add the image file in the /_assets/images directory before including them in the website

once you have your picture there, just replace "my_image.png" in the path and alt message with whatever your image's file name is

PLEASE FOLLOW NAMING CONVENTION WHERE SPACES IN PICTURE NAMES ARE "_"

## embedded youtube video:
<iframe 
        width="560" 
        height="315" 
        src="https://youtube.com/embed/Eqw_Muh5Mnc" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        referrerpolicy="strict-origin-when-cross-origin" 
        allowfullscreen>
</iframe>

normal youtube links have an ID in them:
https://www.youtube.com/watch?v=**Eqw_Muh5Mnc**

append the ID to 
https://youtube.com/embed/

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

format the link like this to get an embedded link version:
https://docs.google.com/presentation/d/[PRESENTATION ID]/embed?start=false" 

## code blocks

```cpp
#include <stdio.h>

int main() {
        printf("colins clowns takeover when");
}

```