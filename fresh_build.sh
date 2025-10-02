#!/usr/bin/env bash
rm -rf ./linux-debug && cmake . --preset linux-debug && cmake --build ./linux-debug && cd ./linux-debug
