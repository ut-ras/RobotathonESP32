---
layout: default
title: How to Use Git
nav_include: true
parent: Getting Started
nav_order: 5
---

# How to use Git

## What is Git?
**Git** is a tool used for source/version control, which is the process of tracking changes to files over time.

It allows you to:

* Easily share code or other files (i.e. KiCad files) with teammates
* Keep a history of your project
* Revert to previous versions if needed
* Work on new ideas or features without affecting the main project

A **repository** (or **repo**) is where all your files and their history are stored. Repositories can be stored locally on your computer or in a cloud service like GitHub or GitLab.

Git is especially helpful for team projects because it tracks who made what changes and makes it easier to collaborate without overwriting each other’s work. This ability is indispensable for developing larger projects, especially in industry.

Note that Robotathon aims to give you a *basic* understanding of how Git/GitHub works. The whole picture is a lot more complicated and can take a bit of effort to learn!

## How do I make changes to my repository on GitHub?

1. Make changes to your local files
1. Navigate to your repo's root directory in Git Bash (i.e. `RobotathonESP32` by default or whatever you named your repository)
1. Run `git status` to verify that Git will change what you want it to change (i.e. file actually edited or deleted, file does not belong, etc.)
1. Run `git add .` to stage your changes [(What is staging?)](TODO write this)
1. Run `git commit -m "message here"` (keep quotes) to **commit** your change to your *local* repository
1. Run `git push` to write your changes to the *remote* repository on GitHub

TODO add picture

## What is staging in Git?
Instead of having to push every little change to your repository, you can group them into a collection of changes called a **commit**, which serve as a snapshot of the project's state.

The **staging area** in Git is where you can manage your changes before saving them to your commit.

For example, if you accidentally stage a file or change that you don't want in your commit (i.e. a build directory), you can simply remove it from the staging area by running `git restore --staged <file>`.

Once you verify that everything you want to commit is shown in `git status`, you can proceed to **commit** to your local  repository and then **push** your local repository to GitHub.

## What is a Git branch?
In Git, a **branch** is essentially a separate line of development within your project. Think of it like a parallel path you can take to work on something without affecting the main line of development.

You can then make changes and commit them to this branch without affecting the original branch (can be any).

Once you're finished working on a branch (i.e. a new feature, bug fix), you can **merge** it back into the original branch by starting a **pull request** on GitHub [(How do I do that?)](TODO write this)

Oftentimes this original branch is your `main` or `master` branch (though `main` is the recommended and default GitHub name), which is your project's stable version.

TODO MAKE PICTURE

## What is a Git clone?

`git clone` is a command that creates a copy or _clone_ of a repository from a hosting service (i.e. GitHub, GitLab) to your computer's local storage.

When you clone a repository, you’re downloading all the files, the commit history, and the current state of the project so that you can work on it locally. It’s like taking a snapshot of a project from the remote server (like GitHub) and bringing it into your workspace.

{: .highlight}
Note that a cloned repository does **not** automatically update to reflect newly pushed commits to GitHub! To update and merge any changes, simply run `git pull` in your repostiory's root directory (i.e. `RobotathonESP32`)
{: .callout-blue}


## What is a Git fork?
A repo fork is like making your own personal copy of someone else’s project. When you fork a repository, you’re creating a separate version of it in your GitHub account so that you can make changes without affecting the original project.

You might fork a repo to experiment, add new features, fix bugs, or contribute to an open-source project. It lets you work independently of the original repo while still having access to its code and history.

## What is the difference between a Git repo fork and clone?
Forks are copies of a repo on GitHub (remote), while clones are repos stored on your computer (local).

## How to deal with merge conflicts

## How do I initiate a pull request on GitHub?
