Set projectDir=%~1
Set imageDir=%~2
Set imageName=%~3
hexmate r0-1DFF,"..\bootloader\exp16_pic24fj64gb004_pim.x\dist\PIC24FJ64GB004_PIM\production\exp16_pic24fj64gb004_pim.x.production.hex" r1E00-ABF7,"%projectDir%\%imageDir%\%imageName%" rABF8-FFFFFFFF,"%projectDir%\%imageDir%\%imageName%" -addressing=2 -O"..\combined.production.hex"