threads = ["2", "4", "6", "8", "10", "12", "14", "16"]

inputs = [
    "100 4900 1 17",
    "250 31100 1 168",
    "500 124700 1 369",
    "1000 499500 1 302",
    "1500 1124000 1 728",
    "2000 1999000 1 455",
    "2500 3123000 1 1316",
    "3000 4498000 1 349",
    "3500 6123000 1 3374",
    "4000 7998000 1 3723",
    "4500 10122000 1 679",
    "5000 12497000 1 644",
]

count = 1

for t in threads:
    for i in inputs:
        if count < 10:
            filename = "../inputs/input_0" + str(count) + ".txt"
        else:
            filename = "../inputs/input_" + str(count) + ".txt"
        
        with open(filename, "w") as f:
            content = t + " " + i
            f.write(content)
        count += 1