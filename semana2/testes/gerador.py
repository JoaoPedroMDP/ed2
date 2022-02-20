# coding: utf-8

from urllib import request


def generate_entry(words: list):
    """
    Gera um conjunto de números aleatórios de tamanho amount.
    """
    from random import randint
    import urllib.request
    seconds = "{}".format(randint(0, 60)).rjust(2, '0')
    minutes = "{}".format(randint(0, 60)).rjust(2, '0')
    hours = "{}".format(randint(0, 24)).rjust(2, '0')
    name = words[
        randint(
            0, 
            len(words) - 1
        )
    ].title()
    return "{}:{}:{} {}".format(hours, minutes, seconds, name)

if __name__ == "__main__":
    amount = 80000
    entries = []
    file = open("words.txt", 'r')
    words = file.readlines()
    for i in range(amount):
        entries.append(generate_entry(words))
    
    print(entries)
    test = open("{}_test".format(amount), "w")
    test.writelines(entries)
    test.write("-1:-1:-1 00000000")
    test.close()