#!/bin/bash

cd ./MuduleA
make
cd ..
cd ./MuduleB
make
cd ..
cd ./MuduleC
make
cd ..
make
./main

