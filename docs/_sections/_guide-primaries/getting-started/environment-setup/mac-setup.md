---
layout: default
title: macOS Setup
nav_include: true
parent: Environment Setup
grand_parent: Getting Started
nav_order: 1
---

# macOS Setup
https://docs.espressif.com/projects/vscode-esp-idf-extension/en/latest/installation.html



https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/linux-macos-setup.html
TODO figure out what to do the setup script installs the CLI for esp-idf isntead of VS Code extension
proly just gona make them go through the install manually

### __Install VSCode__
Download VSCode from the [online download for Mac](https://code.visualstudio.com/download)

### __Installing Git__
This is a source-control application that is very useful for sharing projects with many files.

1. Open the Terminal and type 

`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"` 

and press `enter`. This will make it extremely easy to install Git.


1. Enter `brew install git` to install Git

1. Go to the [GitHub website](https://github.com/) and create an account if you do not have one already. 

### __Fork RobotathonESP32 Repository__
Forking a repository creates a copy that you control on your GitHub account. Teams will use our RobotathonESP32 repo as the template. 

{: .highlight}
Note: only **one** person in each team has to fork the repository and invite their teammates to it on Github. **Everybody** that wants to code __including the person that forks__ has to clone the repo to their local computer storage!
{: .callout-red}

1. Go to the [ut-ras RobotathonESP32 repository hosted on GitHub](https://github.com/ut-ras/RobotathonESP32)
1. Click the `Fork` button on the right and then click `+ Create a new fork` 
<img src="{{ '/_assets/images/github_fork.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Change the Repository name to whatever you like
1. Click the green `Create fork` button at the bottom
1. Share repository access to your teammates by navigating to the settings of your newly forked repository and clicking collaborators in the left menu [(How do I invite teammates to my forked repository?)](TODO WRITE THIS)

### __Set Up Git SSH Authentication__

{: .highlight}
This SSH section is **optional**, but it will make your life easier down the road by letting you push code to your remote repository without manually typing credentials
{: .callout-blue}

See the [official GitHub tutorial](https://docs.github.com/en/enterprise-cloud@latest/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent) if you want more information. Otherwise just follow these instructions:

#### Generate SSH key

{: .highlight}
Git Bash is finicky and doesn't support Ctrl + V for paste. Use `Shift + Insert` or `Right Click > Paste` to paste text.
{: .callout-blue}

1. Open Git Bash
1. Paste `ssh-keygen -t ed25519 -C "your_email@example.com"`, change the email to the one tied to your Github account (keep the quotes), and press `Enter`.
1. You will be prompted to specify a location to save the SSH key. Press `Enter` to specify the default location.
1. You will likely be prompted to enter a passcode. Press `Enter` twice to specify no passcode.

{: .highlight}
Note that you can add a passcode if you'd like, but it is not recommended. If you do, keep in mind that the Bash terminal does _not_ show your passcode as you type it out. Just continue (accurately) typing and press `Enter` when done.
{: .callout-blue}

#### Add SSH key to SSH-agent
1. Paste `eval "$(ssh-agent -s)"` into the terminal and press `Enter` to start the SSH-agent
1. Paste `ssh-add ~/.ssh/id_ed25519` into the terminal and press `Enter` to add your key to the SSH-agent

#### Add SSH key to Github
1. Paste `cat ~/.ssh/id_ed25519.pub` into the terminal and press `Enter` to display your public SSH key
1. Copy the entire key
{: .highlight}
The key should look something like `ssh-ed25519 SFNJNAFNEJKFNJNJKNFJHFJAHOHiowuroiuwr/sfjeher+KX/rH email@gmail.com`
{: .callout-blue}
1. Navigate to the upper-right corner of any page on [GitHub](https://github.com/), click your profile photo, then click Settings (gear icon)
<img src="{{ '/_assets/images/github_settings.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. In the `Access` section of the sidebar, click `SSH and GPG keys`
1. Click the green `New SSH key` button on the right
<img src="{{ '/_assets/images/github_ssh_gpg.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Put whatever you want for the key title name
1. Select the key type to be `Authentication`
1. Paste in the key you copied earlier into the `Key` section
1. Click `Add SSH Key`

### __Clone Forked Repository__
Cloning is the process of copying a Git repository onto your local computer storage


1. Go to your team's newly forked repository
<img src="{{ '/_assets/images/github_repo.png' | prepend: site.baseurl }}" alt="my_image.png :(">
1. Click the green `<> Code` button
1. If you did the previous section, copy the SSH git link. Otherwise copy the HTTPS link. [What is the difference?](https://ut-ras.github.io/RobotathonESP32/technical#what-is-the-difference-between-cloning-using-https-and-ssh)
<img src="{{ '/_assets/images/ssh_link_copy.png' | prepend: site.baseurl }}" alt="my_image.png w=200 h=400 :(">
1. Open Git Bash and navigate to where you want to keep your code for the competition, such as your Documents or Desktop. [How do I do that?](TODO write this)
1. Run the following command in your Git terminal: `git clone [PASTE GIT LINK HERE]` without the square brackets

### __Install USB-UART Bridge Driver__
This allows your computer to recognize and program your ESP32 when you plug it in.

1. Go to [SiLabs installer webpage](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)
1. Download the file named `CP210x VCP Mac OSX Driver`
1. Extract the downloaded zip file and open the installer
1. Agree and use default configuration

###__Install ESP-IDF Extension__

