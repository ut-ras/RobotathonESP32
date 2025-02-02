---
layout: default
title: LOOKIE HERE NEWBIE GUIDE SLAVES FOR JEKYLL SETUP
permalink: /
nav_include: true
nav_order: 1
---

scroll down for syntax ref

# windows setup
good luck linux losers and macos mucks (im sure its 90% the same but gl)

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


## Opening the Containerized Repository
* Open Git Bash
* Navigate to `RobotathonESP32` by using `ls` and `cd`
* Type `git checkout newbie-guide-2025` to switch to the Newbie Guide branch
* Open `RobotathonESP32` in VS Code
* Click the `><` icon in the bottom left corner of VS Code

<img src="{{ '/_assets/images/the_vscode_thing.png' | prepend: site.baseurl }}" alt="my_image.png :(">

* Click `Reopen in Container` from the popup at the top of VS Code

<img src="{{ '/_assets/images/reopen.png' | prepend: site.baseurl }}" alt="my_image.png :(">

## Setting Up and Using Jekyll (viewing local changes)
* Once everything has loaded, open a terminal within VS Code (View > Terminal, `Ctrl + ` `, etc.)
* Type `cd docs`
* Type `bundle install`
* Type `bundle exec jekyll serve --force_polling --livereload`
* This allows you to view your local changes (not on live website)

{: .highlight}
You do not need to rerun any terminal commands to view changes if you use the `--force_polling` and `--livereload` flags. If your computer is blowing up with constant autoreload, you can just use `bundle exec jekyll serve`, but you'll have to recompile each time you want to render new local changes 
{: .callout-blue}

* `Ctrl` + `Left Click` on the server address link to open the site locally
<img src="{{ '/_assets/images/server_link.png' | prepend: site.baseurl }}" alt="my_image.png :(">

## Writing to Live Website
* Make change
* Navigate to `RobotathonESP32` in Git Bash
* Commit and push changes ([How?](https://ut-ras.github.io/RobotathonESP32/getting-started/git))
* Observe changes on live website in about a minute