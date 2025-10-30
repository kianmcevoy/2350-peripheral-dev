#!/bin/sh

print_usage() {
    echo "Usage: setup.sh <name> <git-url>"
    echo "<name>": this is the name of your project. It should contain only alphanumeric characters and "-_~" but no spaces or filepath symbols "e.g. /*.\\" etc.
    echo "<git-url>": URL of the empty GitHub repository which will be targetted as the git remote for this local repository.
}

if [ $# -eq 0 ]
then
    echo RP2350 blank-project setup script
    print_usage
    exit 0
fi

if [ $# -ne 2 ]
then
    echo "Incorrect number of arguments given: $#, expected 2"
    print_usage
    exit 1
fi

PROJECT_NAME=$1
GIT_REMOTE_URL=$2

echo "Setting up project '$PROJECT_NAME' with remote url '$GIT_REMOTE_URL'..."

echo Performing local git setup...
git init
git branch -m main

rm -rf shared/isl firmware/system

git submodule add https://github.com/InstruoModular/isl.git shared/isl
git submodule add https://github.com/InstruoModular/rp2350-system.git firmware/system

git submodule update --init --recursive

echo Configuring project name...
sed -i "s/blank_pico_project/$PROJECT_NAME/g" firmware/CMakeLists.txt

git add .
git commit -m "Initial commit"


echo Connecting to remote git repository...
git ls-remote $GIT_REMOTE_URL
if [ $? -ne 0 ]
then
    echo Could not find remote repository.
    exit 2
fi
git remote add origin $GIT_REMOTE_URL
git push origin main