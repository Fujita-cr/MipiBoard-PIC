Set projectDir=%~1

REM Extract the parts separated by backslashes as tokens
for %%I in ("%projectDir%") do (
    set "filename=%%~nxI"
    set "folderpath=%%~dpI"
)

REM Get the last folder name from the folder path
for %%I in ("%folderpath:~0,-1%") do (
    set "outputname=%%~nxI"
)

del "..\%outputname%.hex"