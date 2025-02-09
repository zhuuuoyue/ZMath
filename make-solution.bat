@echo off
set cd=%~dp0
set build_dir=%cd%build
set source_dir=%cd%source

if not exist %build_dir% (
    md %build_dir%
)
cd %build_dir%
cmake %source_dir%
