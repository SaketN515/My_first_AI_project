class Robot:
    def __init__(self, name, battery, location, person_detected):
        self.name = name
        self.battery = battery
        self.location = location
        self.person_detected = person_detected

    def introduce_self(self):
        print(f"My name is {self.name}, I am at {self.location}.")

    def use_battery(self):
        self.battery -= 10

    def decide(self):
        if self.battery < 20:
            return "charge"
        elif self.person_detected is True:
            return "Follow"
        else:
            return "continue"

    def charge(self):
        print("Going to charge station.")

    def follow(self):
        print("Following the person.")

    def continue_moving(self):
        print("Continuing on my path.")


robot = Robot("R2D2", 100, "lab", False)
action = robot.decide()

if action == "charge":
    robot.charge()
elif action == "Follow":
    robot.follow()
elif action == "continue":
    robot.continue_moving()
