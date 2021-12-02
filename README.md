# Dining - Philosophers

## Problem Statement

The Dining Philosopher Problem states that K philosophers seated around a circular table with one chopstick between each pair of philosophers. There is one chopstick between each philosopher. A philosopher may eat if he can pick up the two chopsticks adjacent to him. One chopstick may be picked up by any one of its adjacent followers but not both.

## Pre-requisites

You need to install GNU g++ complier 

`sudo apt-get install g++`

## Installation

Go to the project directory and run 

`g++ main.cpp -o main -lpthread -lrt`.

This will generate the output file and to run the application execute: 

`./main`
