---
layout: default
title: NEWBIE GUIDE JEKYLL SETUP (remove during comp)
permalink: /
nav_include: true
nav_order: 1
---

# windows setup
gl to linux/macos people. its mostly the same so u got it :)

## Download VS Code 
1. Click big download button for Windows
[https://code.visualstudio.com/download](https://code.visualstudio.com/download)        
1. Download the **Dev Container** extension

<img src="{{ '/_assets/images/dev_container.png' | prepend: site.baseurl }}" alt="my_image.png :(">

## Download WSL
See official documentation here: [https://learn.microsoft.com/en-us/windows/wsl/install](https://learn.microsoft.com/en-us/windows/wsl/install)
1. Open Powershell
1. Type `wsl --set-default-version 2`
1. Type `wsl --install`
   - If you are prompted to put in credentials, put something you will remember

{: .highlight}
Unix systems do not show input while you are typing passwords by default! (type carefully :D ) 
{: .callout-red}

## Download Docker
-  [https://docs.docker.com/desktop/setup/install/windows-install/](https://docs.docker.com/desktop/setup/install/windows-install/)

{: .highlight}
Make sure to have Docker running for later!
{: .callout-blue}

## Download Git
- [https://git-scm.com/downloads](https://git-scm.com/downloads)

## Set up SSH Authentication for GitHub
- See existing Newbie Guide doc [here](https://ut-ras.github.io/RobotathonESP32/getting-started/environment-setup/windows-setup#set-up-git-ssh-authentication)

## Clone RobotathonESP32 Repository 
1. Go to the [Robotathon repository](https://github.com/ut-ras/RobotathonESP32/tree/main)
1. Click the green `<> Code` button

<img src="{{ '/_assets/images/ssh_link_copy.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Copy the SSH Link (HTTPS bad and sucks 👎)
1. Open Git Bash and navigate to where you want to keep the code by using `ls` and `cd`
1. Run the following command in your Git terminal: `git clone [LINK HERE]` without the square brackets


## Opening the Container
1. Navigate to `RobotathonESP32` by using `ls` and `cd`
1. Type `git checkout newbie-guide-2025` to switch to the Newbie Guide branch
1. Open `RobotathonESP32` in VS Code
1. Click the `><` icon in the bottom left corner of VS Code
      <img src="{{ '/_assets/images/the_vscode_thing.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Click `Reopen in Container` from the popup at the top of VS Code
      <img src="{{ '/_assets/images/reopen.png' | prepend: site.baseurl }}" alt="my_image.png :(">

## Setting Up and Using Jekyll (viewing local changes)
1. Once everything has loaded, open a terminal within VS Code (View > Terminal, `Ctrl + ` `, etc.)
1. Type `cd docs` and press `Enter`
1. Type `bundle install` and press `Enter`
1. Type `bundle exec jekyll serve --force_polling --livereload` and press `Enter`
1. `Ctrl` + `Left Click` on the server address link to open the site locally after it is done compiling

{: .highlight}
You do not need to rerun any terminal commands to view changes if you use the `--force_polling` and `--livereload` flags. If your computer is blowing up with constant autoreload, you can just use `bundle exec jekyll serve`, but you'll have to rerun the command each time you want to render new local changes 
{: .callout-blue}

<img src="{{ '/_assets/images/server_link.png' | prepend: site.baseurl }}" alt="my_image.png :(">

## Writing to Live Website
1. Make change
1. Navigate to `RobotathonESP32` in Git Bash
1. Commit and push changes ([How?](https://ut-ras.github.io/RobotathonESP32/getting-started/git))
1. Observe changes on live website in about a minute