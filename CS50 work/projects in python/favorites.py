import csv

with open("shows.csv", "r") as file:
    reader = csv.DictReader(file)

    next(reader)

    for row in reader:
        print(row["TV Show"].upper())