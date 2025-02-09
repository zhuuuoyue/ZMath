
set cd=%~dp0
MSBuild.exe %cd%build/ZMath.sln /p:Configuration=RelWithDebInfo
pause
