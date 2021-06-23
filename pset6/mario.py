from cs50 import get_int
# Checks user input
while True:
    height = get_int("Height: ")

    if height > 0 and height < 9:
        break

# Number of spaces
space = height - 1

# Prints the pyramid
for i in range(height):
    # Puts the spaces
    for j in range(space):
        print(" ", end="")
    space -= 1
        
    # Prints the left pyramid  
    for k in range(i):
        print("#", end="")
        
    print("#  #", end="")
    
    # Prints the right pyramid
    for l in range(i):
        print("#", end="")
    print()
