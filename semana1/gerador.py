from random import randint

amount = 200000
file = open("testFiles/{}.txt".format(amount),"w")

file.write(str(amount) + "\n")
for i in range(amount):
    file.write(
        "{} {}\n".format(
            randint(0, amount - 1),
            randint(0, amount - 1)
            )
    )

file.write("-1 -1\n")
file.close()