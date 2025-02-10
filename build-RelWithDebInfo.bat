@echo off
set cd=%~dp0
MSBuild.exe %cd%build/zmath/ZMath.sln /p:Configuration=RelWithDebInfo
