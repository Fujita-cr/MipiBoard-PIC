Set projectDir=%~1
Set imageDir=%~2
Set imageName=%~3

REM Extract the parts separated by backslashes as tokens
for %%I in ("%projectDir%") do (
    set "filename=%%~nxI"
    set "folderpath=%%~dpI"
)

REM Get the last folder name from the folder path
for %%I in ("%folderpath:~0,-1%") do (
    set "outputname=%%~nxI"
)

hexmate r0-1DFF,"..\bootloader\exp16_pic24fj64gb004_pim.x\dist\PIC24FJ64GB004_PIM\production\exp16_pic24fj64gb004_pim.x.production.hex" r1E00-ABF7,"%projectDir%\%imageDir%\%imageName%" rABF8-FFFFFFFF,"%projectDir%\%imageDir%\%imageName%" -addressing=2 -O"..\%outputname%.hex"