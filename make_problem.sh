#!/bin/bash

read -p "Enter problem number: " problem

mkdir $problem
cp Makefile $problem
touch $problem/$problem.c
