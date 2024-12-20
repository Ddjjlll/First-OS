@echo off
where nasm
if %ERRORLEVEL% NEQ 0 (
    echo NASM is not installed or not in PATH
    echo Download NASM from: https://www.nasm.us/pub/nasm/releasebuilds/?C=M;O=D
    exit /b 1
)
