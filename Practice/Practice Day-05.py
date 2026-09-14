objects=["chair", "table", "person", "door", "bottle"]
for obj in objects:
    if obj == "person":
        print("Found a person!")
        
for i in range(len(objects)):
    print(f"Object {i}: {objects[i]}")
    if objects[i] == "person":
        print("Found a person!")