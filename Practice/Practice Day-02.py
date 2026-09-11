def calculate_age(birth_year, current_year=2026):
    return current_year - birth_year
print(calculate_age(2008))   # Output: 18

def response_robot(mood):
    if mood == "happy":
        return "I'm feeling great!"
    elif mood == "sad":
        return "I'm feeling down."
    elif mood == "excited":
        return "I'm feeling excited!"
    else:
        return "I'm not sure how I feel."
dict_info = {
    "name": "Robo",
    "mood": "happy",
    "battery": 85
}
print(dict_info["name"])  # Output: Robo