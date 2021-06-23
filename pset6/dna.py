import csv
from sys import argv, exit

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
    database = argv[1]
    with open(database) as dtb_file:
        data = csv.reader(dtb_file)
        all_sequences = next(data)[1:]

        sequences = argv[2]
        with open(sequences) as seq_file:
            string = seq_file.read()
            times = [calculate_STR(string, seq) for seq in all_sequences]
        print_match(data, times)
        
        
def calculate_STR(string, sub_string):
    n = [0] * len(string)
    for i in range(len(string) - len(sub_string), -1, -1):
        if string[i: i + len(sub_string)] == sub_string:
            if i + len(sub_string) > len(string) - 1:
                n[i] = 1
            else:
                n[i] = 1 + n[i + len(sub_string)]
    return max(n)
    
    
def print_match(data, times):
    for line in data:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == times:
            print(person)
            return
    print("No match")


if __name__ == "__main__":
    main()
