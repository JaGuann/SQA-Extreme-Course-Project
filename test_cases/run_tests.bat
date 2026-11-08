@REM  For each directory inside test_cases directory
for /D %%i in (*) do (
    @REM  Change into the current directory in %%i variable
    cd "%%i"
    for /D %%j in (*) do (
        @REM  Change into each test case inside either success or failure directory
        @REM  and run the program on the input.txt and output to output.txt
        cd "%%j"
        echo running test %%i/%%j
        echo %cd%
        ..\..\..\main.exe < input.txt > output.txt
        cd ..
    )
    cd ..
)
@REM  pause