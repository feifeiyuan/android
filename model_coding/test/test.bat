@echo on
adb root
adb remount
adb push Y:\xx\my_service /system/bin/
adb shell "./system/bin/my_service"
pause



