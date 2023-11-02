import itertools
import json

# Define the distinct items
items = ['A', 'B', 'C', 'D', '_', 'F']

# Generate all permutations
permutations = list(itertools.product(items, repeat=8))
# print(permutations)

# Initialize a 2D array to store the values
binary_values = []
# Generate binary numbers from 0 to 16 with fixed 4-digit length
for i in range(16):
    binary = format(i, '04b')
    binary_values.append(binary)

# for entry in permutations:
    

# Less Than - returns a dictionary of order {format'ABCD' : 0/1}
def produceOutputs(array, input):
    # First 4 digits
    input1 = []
    for i in range(4):
        if array[i] == "A":
            input1.append(input[0])
        elif array[i] == "B":
            input1.append(input[1])
        elif array[i] == "C":
            input1.append(input[2])
        elif array[i] == "D":
            input1.append(input[3])
        elif array[i] == "F":
            input1.append("1")
        else:
            input1.append("0")
    input1 = ''.join(input1)

    # Last 4 Digits
    input2 = []
    for i in range(4,8):
        if array[i] == "A":
            input2.append(input[0])
        elif array[i] == "B":
            input2.append(input[1])
        elif array[i] == "C":
            input2.append(input[2])
        elif array[i] == "D":
            input2.append(input[3])
        elif array[i] == "F":
            input2.append("1")
        else:
            input2.append("0")
    input2 = ''.join(input2)

    # X < Y configuration
    res = input1 < input2
    if res == False:
        res = 0
    else:
        res = 1

    return (array, input, input1, input2, res)
    
if __name__ == "__main__":
    # array = ["A", "A", "A", "A", "C", "C", "C", "C"]
    total = []
    for config in permutations:
        # config - entry of ["X", "X", ..., "X"]
        temp = []
        for instance in binary_values:
            curr = produceOutputs(config, instance)
            temp.append(curr)
        total.append(temp)

    arrayOfDicts = []

    for t in total:
        '''
        t - length(16)
        total - array of [
            [t - (array, input, input1, input2, res)],
            ...
        ]
        '''
        tempDict = {}
        for entry in t:
            tempDict[entry[1]] = entry[4]

        arrayOfDicts.append(tempDict)

    # 'ABCD' : 'res'
    targetDictionary = {
        '0000': 0,
        '0001': 1,
        '0010': 1,
        '0011': 1,
        '0100': 0,
        '0101': 0,
        '0110': 0,
        '0111': 0,
        '1000': 1,
        '1001': 1,
        '1010': 1,
        '1011': 1,
        '1100': 0,
        '1101': 0,
        '1110': 0,
        '1111': 0
    }

    # print(targetDictionary == targetDictionary)

    # print(arrayOfDicts[135423])

    targetIndexes = []


    # print(permutations[46671])

    i = 0
    for d in arrayOfDicts:
        if d == targetDictionary:
            targetIndexes.append(i)
        i += 1

    # print(len(targetIndexes))

    combinationsArray = []
    for val in targetIndexes:
        combinationsArray.append(permutations[val])

    with open("data.json", "w") as json_file:
        json.dump(combinationsArray, json_file)
    print("Data has been saved to data.json")

    with open('data.json', 'r') as file:
        data = json.load(file)

    # Format the 2D array to display each entry on a new line
    formatted_data = '\n'.join(' '.join(map(str, row)) for row in data)

    # Write the formatted data back to the JSON file
    with open('data.json', 'w') as file:
        file.write(formatted_data)
    print("Data is been formatted and saved to data.json")

    # print(len(targetIndexes))
    

    # print(targetIndexes)

    # # binary_values - list(<string>)
    # arr = produceOutputs(array, ['0011'])
    # print(arr)

