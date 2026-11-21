# Account class
class Account:
    def __init__(self, username, type, credit):
        self._username = username
        self._type = type
        self._credit = credit

# Backend Class
class Backend:
    # For now the parameters user_accounts, available_games, games_collection
    # have been left out and will be used and implemented for Phase 5
    def __init__(self):
        self._user_accounts = []
        self._available_games = []
        self._games_collection = []


    # Place holder for some methods will be implemented in phase 5
    def merge_daily_transactions(self):
        pass
        
    def read_old_files(self):
        # read old files of current user accounts, avalible games, and Game Collection Files
        # for now will only focus on user accounts, other two will be implemented in phase 5
        fileCA = "FrontEnd B/FrontEnd B/app/currentaccounts.txt"
        try: # opens the file and reads it
            with open(fileCA, "r") as f:
                for line in f:
                    line = line.rstrip("\n")
                    if line.startswith("END"):
                        break
                    username = line[0:15].strip()
                    acc_type = line[16:18].strip()
                    credit = float(line[19:28].strip())
                    # Pass in type username and credit to match Account.__init__
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
            if accs._username == username:
                print(f"ERROR: Username {username} already exists!") 
                return False 
        return True

if __name__ == "__main__":
    backend = Backend()
    # Render in currentaccounts.txt files 
    if backend.read_old_files():
        print("Loading accounts: ")
        for accs in backend._user_accounts:
            print(f"Username: {accs._username} | {accs._type} | {accs._credit:.2f}")

    # find if in currentaccounts.txt that a username is unique or not
    user_unique = input("Enter username for uniqueness: ").strip()

    if backend.check_unique_usernames(user_unique):
        print(f"Success! {user_unique} is avaliable.")
    
