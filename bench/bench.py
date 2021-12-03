import os

directory = "inputs/"

for file in os.listdir(directory):
    cmd = "./bench_floyd < " + directory + file
    os.system(cmd)
    print(cmd + " --- DONE")