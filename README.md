# ZMath

## 参与开发

双击 `make-solution.bat` 使用 CMake 配置生成 Visual Studio 解决方案，生成的解决方案位置 `build` 目录下。

双击 `start.bat` 使用 Visual Studio 打开解决方案进行开发。如果 `devenv.exe` 找不到，请确保 `devenv.exe` 所在目录已被正确地添加到环境变量中。

若不需要开发，想直接编译，双击 `build-RelWithDebInfo.bat` 使用 `msbuild.exe` 进行编译。若找不到 `msbuild.exe`，请确保 `msbuild.exe` 所在目录路径被正确添加到环境变量，如 `C:\Program Files\Microsoft Visual Studio\2022\Enterprise\MSBuild\Current\Bin\`。
