from cs50 import get_float

while True:
    dollar = get_float("Owed: ")
    
    if dollar > 0:
        break
    
cents = dollar * 100

quarters = cents // 25
dimes = (cents % 25) // 10
nickels = ((cents % 25) % 10) // 5
pennis = ((cents % 25) % 10) % 5

print(int(quarters+dimes+nickels+pennis))
