---
layout: default
title: LOOKIE HERE NEWBIE GUIDE SLAVES FOR SETUP AND SYNTAX REFERENCE 
permalink: /
nav_include: true
nav_order: 1
---

scroll down for syntax ref

# windows setup
good luck lonux losersa nd macos mucks (im sure its 90% the same but gl)

## Download VS Code 
- Click big download button for Windows
[https://code.visualstudio.com/download](https://code.visualstudio.com/download)        
- Download the **Dev Container** extension

<img src="{{ '/_assets/images/dev_container.png' | prepend: site.baseurl }}" alt="my_image.png :(">

## Download WSL
- Open **Powershell**
- Type `wsl --set-default-version 2`
- Type `wsl --install`
   - If you are prompted to put in credentials, put something you will remember

{: .highlight}
Unix systems do not show input while you are typing passwords by default! (type carefully :D ) 
{: .callout-red}

## Download Docker
- [https://docs.docker.com/desktop/setup/install/windows-install/](https://docs.docker.com/desktop/setup/install/windows-install/)
- Make sure to have Docker running for later

## Download Git
- [https://git-scm.com/downloads](https://git-scm.com/downloads)

## Set up SSH Authentication for GitHub
- See existing Newbie Guide doc [here](https://ut-ras.github.io/RobotathonESP32/getting-started/environment-setup/windows-setup#set-up-git-ssh-authentication)

## Clone RobotathonESP32 Repository 
- [https://github.com/ut-ras/RobotathonESP32/tree/main](https://github.com/ut-ras/RobotathonESP32/tree/main)


## Actual stuff after downloading everything
* Open Git Bash
* Navigate to `RobotathonESP32` by using `ls` and `cd`
* Type `git checkout newbie-guide-2025` to switch to the Newbie Guide branch
* Open `RobotathonESP32` in VS Code
* Click the `><` icon in the bottom left corner of VS Code

<img src="{{ '/_assets/images/the_vscode_thing.png' | prepend: site.baseurl }}" alt="my_image.png :(">

* Click `Reopen in Container` from the popup at the top of VS Code

<img src="{{ '/_assets/images/reopen.png' | prepend: site.baseurl }}" alt="my_image.png :(">

* Once everything has loaded, open a terminal within VS Code (View > Terminal, `Ctrl + ` `, etc.)
* Type `cd docs`
* Type `bundle install`
* Type `bundle exec jekyll serve --force_polling --livereload`
 - This allows you to view your local changes (not on live website)
 - Note that you do not need to rerun any terminal commands to view changes if you use the `--force_polling` and `--livereload` flags
 - If your computer is blowing up with constant autoreload, you can just use `bundle exec jekyll serve`, but you'll have to recompile each time you want to see render local changes 
* `Ctrl + Click` on the server address link to open the site locally
<img src="{{ '/_assets/images/server_link.png' | prepend: site.baseurl }}" alt="my_image.png :(">

* Make change
* Navigate to `RobotathonESP32` in Git Bash
* Commit and push changes ([How?](https://ut-ras.github.io/RobotathonESP32/getting-started/git))
* Observe changes on live website in about a minute


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