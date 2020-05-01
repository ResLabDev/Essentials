def moduleFunc():
    from colorama import init
    init()
    from colorama import Fore
    print(Fore.GREEN + "I am a module from the package.")
