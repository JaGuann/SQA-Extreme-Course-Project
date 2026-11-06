for /D %%i in (*) do (
    cd "%%i"
    for /D %%j in (*) do (
        cd "%%j"
        echo running test %%i/%%j
        ..\..\main.exe current_user_accounts.txt available_games.txt game_collection.txt < input.txt > output.txt
        cd ..
    )
    cd ..
)
pause
