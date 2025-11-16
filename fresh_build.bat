rmdir /s /q .\windows-debug && call vcvarsall.bat x86_amd64 && cmake . --preset windows-debug && cmake --build .\windows-debug
