#!/usr/bin/env bash
cmake . --preset linux-debug && cmake --build ./linux-debug && cd ./linux-debug
