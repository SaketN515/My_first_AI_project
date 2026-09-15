robot = {
    "battery": 65,
    "location": (10, 20),
    "sensors": {
        "camera": True,
        "lidar": True
    },
    "known_people": {"Saket", "Alex"},
    "person_seen": "Alex"
}
print(robot["battery"] )
print(robot["location"][0])
print(robot["location"][1])
print(robot["sensors"]["camera"])
if robot["battery"]<20:
    print("Battery low, please recharge")  
elif robot["person_seen"] in robot["known_people"]:
    print("I know him")
else:
    print("I don't know him")

