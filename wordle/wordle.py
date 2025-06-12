import random
import requests


def get_word_meaning(word):
    try:
        response = requests.get(f"https://api.dictionaryapi.dev/api/v2/entries/en/{word}")
        if response.status_code == 200:
            data = response.json()
            # Get the first definition
            meaning = data[0]['meanings'][0]['definitions'][0]['definition']
            return meaning
        else:
            return "Sorry, no meaning found."
    except Exception as e:
        return "Could not fetch meaning."

def load_dictionary(file_path):
    with open(file_path) as f:
        words = [line.strip() for line in f] #creates a list of all words in the file 
    return words

def is_valid(guess,guesses):
    return guess in guesses # checks whether the guess is present in the guesses.txt

def evaluate_guess(guess,word):
    str = ""
    for i in range(5):
        if guess[i] == word[i]:
            str += "\033[32m" + guess[i] # makes letter green
        else:
            if guess[i] in word:
                str+= "\033[33m" + guess[i] # yellow
            else:
                str += "\033[90m" + guess[i]  # grey
    return str + "\033[0m"

def print_keyboard(letter_status):
    keyboard_rows = ["q w e r t y u i o p", "a s d f g h j k l", "z x c v b n m"]
    for row in keyboard_rows:
        for letter in row.split():
            color = letter_status.get(letter, "\033[0m")
            print(f"{color}{letter.upper()}\033[0m", end=" ")
        print()


def update_letter_status(letter_status, guess, secret_word):
    for i in range(5):
        letter = guess[i]
        if letter == secret_word[i]:
            letter_status[letter] = "\033[32m"  # green
        elif letter in secret_word:
            # Only update to yellow if not already green
            if letter_status.get(letter) != "\033[32m":
                letter_status[letter] = "\033[33m"  # yellow
        else:
            # Only update to grey if not already green or yellow
            if letter_status.get(letter) not in ("\033[32m", "\033[33m"):
                letter_status[letter] = "\033[90m"  # grey

def wordle(guesses , answers):
    print("\n\nWelcome to Wordle!!\n")
    print("You have 6 tries to guess the secret 5-letter word.\nGood Luck!\n")
    print("If a letter is \033[32mgreen\033[0m then its present in wordle and is in correct position.")
    print("If a letter is \033[33myellow\033[0m then its present in wordle but its not in correct position.")
    print("If a letter is \033[90mgrey\033[0m then its not present in wordle.\n")
    print("Type \033[31mshow\033[0m to show the wordle(forfeit the game).")
    secret_word = random.choice(answers) # selects randon word from answers.txt
    attempts  = 1
    max_attempts = 6
    letter_status = {}  # Track color for each letter
    while attempts <= max_attempts:
        guess = input(f"\nEnter Guess #{str(attempts)}:").lower() # if accidently typed in upper case

        if guess == "show":
            print(f"The wordle was: \033[31m{secret_word}\033[0m") #red
            print("\033[33mMeaning:\033[0m", get_word_meaning(secret_word))
            print()
            break

        if not is_valid(guess,guesses):
            print("\033[31mPlease enter a valid 5-letter English word.\033[0m")
            continue
        elif guess==secret_word:
            print(evaluate_guess(guess,secret_word))
            if attempts == 1:
                print("🤯 UNBELIEVABLE! You got it on your very first try! Either you're a genius, a psychic, or just incredibly lucky! 🍀🎉")
            elif attempts == max_attempts:
                print(f"😅 Phew! That was a close one—you got it on your very last attempt! Well done!")
            elif attempts <= 3:
                print(f"👏 Impressive! You guessed the wordle in just {attempts} attempts! 🥳")
            else:
                print(f"Good job! You solved it in {attempts} attempts.")
            print("\033[33mMeaning:\033[0m", get_word_meaning(secret_word))
            print()
            break
        else:
            print(evaluate_guess(guess,secret_word))
            update_letter_status(letter_status, guess, secret_word)
            print_keyboard(letter_status)
            attempts+=1

    if attempts > max_attempts:
        print("\033[31mGame over!\033[0m You have ran out of guesses.\n")
        print(f"The wordle was : \033[31m{secret_word}\033[0m")
        print("\033[33mMeaning:\033[0m", get_word_meaning(secret_word))
        print()


guesses = load_dictionary("guesses.txt")
answers = load_dictionary("answers.txt")

wordle(guesses , answers)