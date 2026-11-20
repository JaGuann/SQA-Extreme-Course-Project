# Account class
class Account:
    def __init__(self, type, username, credit):
        self._type = type
        self._username = username
        self._credit = credit

# Backend Class
class Backend:
    def __init__(self, user_accounts, available_games, games_collection):
        self._user_accounts = []
        self._available_games = []
        self._games_collection = []


    # Place holder for some methods will be implemented in phase 5
    def merge_daily_transactions(self):
        pass
        
    def read_old_files(self):
        # read old files of current user accounts, avalible games, and Game Collection Files
        # for now will only focus on user accounts, other two will be implemented in phase 5
        fileCA = "currentacount.txt"
        try: # opens the file and reads it
            with open(fileCA, "r") as f:
                for line in f:
                    line = line.rstrip("\n")
                    if line.startswith("END"):
                        break
                    username = line[0:15].strip()
                    acc_type = line[16:18].strip()
                    credit = float(line[19:28].strip())
                    self._user_accounts.append(Account(username, acc_type, credit))
                return True
        except Exception as e:
            print(f"ERROR! Fatal error reading {fileCA}: {e}")

        
    def apply_transactions(self):
        pass
        
    def write_out_files(self):
        pass
        
    def check_negative_balances(self, transaction):
        pass

    def check_unique_usernames(self, username):
        # checks if new username is unique among account that exist. Shows error if not
        for accs in self._user_accounts:
            if accs.username == username:
                print(f"ERROR: Username {username} already exists!") 
                return False
        return True
