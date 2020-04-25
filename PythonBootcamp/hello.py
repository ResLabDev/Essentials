print('Hello from Python!')

def get_planet_name(id):
    return {
        1: "Mercury",
        2: "Venus",
        3: "Earth",
        4: "Mars",
        5: "Jupiter",
        6: "Saturn",
        7: "Uranus", 
        8: "Neptune"
    }.get(id, "None")

for i in range(1,10):
    print('{}: {}' .format(i, get_planet_name(i)))