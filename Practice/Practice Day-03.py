f=open("Practice/test.txt","w")
write=f.write("Hi everyone!")
f.close()

with open("Practice/test.txt","r") as f:
    content=f.read()
    print(content)
    
try:
    battery=int(input("Enter battery percentage: "))
    print("Battery percentage is:", battery)
except ValueError:
    print("Invalid input! Please enter a valid integer for battery percentage.")
    
try:
    battery=int(input("Enter battery percentage: "))
    with open("Practice/battery.txt","a") as f:
        f.write("battery:" + str(battery) + "\n")
except ValueError:
    print("Invalid input! Please enter a valid integer for battery percentage.")
else:
    print("Battery percentage saved successfully.")
finally:
    print("status check complete.")
    
import random
number=random.randint(1, 10)
print("Random number generated:", number)

actions=["move","wait","scan"]
action=random.choice(actions)
print("Random action selected:", action)